import serial
import random
from pygame import mixer
from time import sleep

s = serial.Serial("dev/ttyACM0", 9600)
mixer.init()

MAX_DISTANCE = 200
MIN_DISTANCE = 10
group1 = [mixer.Sound(f"Song{i}.wav") for i in range(1, 9)]
group2 = [mixer.Sound(f"Song{i}.wav") for i in range(9, 17)]
contemplativ_song = mixer.Sound("SoundGroups/Contemplativa.mp3") 
played_songs = []
song_playing = False
crowded = False
last_played_song = None
contemplativ_song_playing = False
visitors_left = 0
visitors_right = 0
visitors_middle = 0

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

while True:
    imported_data = s.readline().decode("utf-8").strip()
    distances = [float(x) for x in imported_data.split(",")]
    
    is_in_middle = ((distances[2] > MIN_DISTANCE and distances[2] < MAX_DISTANCE)or(distances[3] > MIN_DISTANCE and distances[3] < MAX_DISTANCE))
    is_in_left = ((distances[0] > MIN_DISTANCE and distances[0] < MAX_DISTANCE)or(distances[1] > MIN_DISTANCE and distances[1] < MAX_DISTANCE))
    is_in_right = ((distances[4] > MIN_DISTANCE and distances[4] < MAX_DISTANCE) or (distances[5] > MIN_DISTANCE and distances[5] < MAX_DISTANCE))

    if is_in_middle:
        visitors_middle += 1
    else:
        visitors_middle = max(0, visitors_middle-1) #Pois o menor valor possivel e 0
    
    if is_in_left:
        visitors_left += 1
    else:
        visitors_left = max(0, visitors_left-1)
    
    if is_in_right:
        visitors_right += 1
    else:
        visitors_right = max(0, visitors_right-1)
    
    


    if is_in_left:
        select_song(group1, played_songs)
    
    if is_in_middle:
        if crowded:
            select_song(group2, played_songs)
        else:
            select_song(group1, played_songs)

    if is_in_right:
        if crowded:
            select_song(group2, played_songs)
        else: 
            select_song(group2, played_songs)
