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
last_played_song = None
contemplativ_song_playing = False

def play_song(song):
    global last_played_song
    last_played_song = song
    played_songs.append(song)
    sound.play()

def select_song(gruop, played_songs):
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

