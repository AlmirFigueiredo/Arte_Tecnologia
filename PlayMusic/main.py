import serial
import random
from pygame import mixer
from time import sleep

s = serial.Serial("dev/ttyACM0", 9600)
mixer.init()

MAX_DISTANCE = 70
MIN_DISTANCE = 10
group1 = [mixer.Sound(f"Song{i}.wav") for i in range(1, 9)]
group2 = [mixer.Sound(f"Song{i}.wav") for i in range(9, 17)]
contemplativ_song = mixer.Sound("SoundGroups/Contemplativa.mp3") 
played_songs = []
song_playing = False
crowded = False
last_played_song = None
contemplative_song_playing = False
visitors_left = 0
visitors_right = 0
visitors_middle = 0
visitors_total = 0

def play_song(song):
    global last_played_song
    last_played_song = song
    played_songs.append(song)
    song.play()

def select_song(group, played_songs):
    available_songs = []
    for song in group:
        if song not in played_songs:
            available_songs.append(song)
    if not available_songs:
        return None
    selected_song = random.choice(available_songs)
    play_song(selected_song)

def reset_played_songs():
    global played_songs
    played_songs = []

while True:
    imported_data = s.readline().decode("utf-8").strip()
    distances = [float(x) for x in imported_data.split(",")]
    
    is_in_middle = ((distances[2] > MIN_DISTANCE and distances[2] < MAX_DISTANCE))
    is_in_left = ((distances[0] > MIN_DISTANCE and distances[0] < MAX_DISTANCE))
    is_in_right = ((distances[1] > MIN_DISTANCE and distances[1] < MAX_DISTANCE))

    visitors_left = visitors_left + 1 if is_in_left else max(0, visitors_left - 1) # Pois o menor valor possivel e 0
    visitors_middle = visitors_middle + 1 if is_in_middle else max(0, visitors_middle - 1)
    visitors_right = visitors_right + 1 if is_in_right else max(0, visitors_right - 1)
    visitors_total = visitors_left + visitors_middle + visitors_right
    crowded = visitors_total > 1

    if is_in_middle and not contemplative_song_playing:
        if last_played_song and mixer.get_busy():  
            pass  
        else:
            contemplative_song_playing = True
            play_song(contemplativ_song)
    elif not is_in_middle and contemplative_song_playing:
        contemplativ_song_playing = False
        contemplativ_song.stop()

    if not is_in_middle and not mixer.get_busy():
        selected_song = None
        if is_in_left or is_in_right:
            if len(played_songs) == 16:
                reset_played_songs()
            if len(played_songs) < 8:
                selected_song = select_song(group1, played_songs)
            elif len(played_songs) >= 8 and len(played_songs) < 16:
                selected_song = select_song(group2, played_songs)
            if selected_song:
                sleep(selected_song.get_length())
    sleep(1)