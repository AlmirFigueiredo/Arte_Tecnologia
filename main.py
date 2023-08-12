import serial
import random
import pygame

SERIAL_PORT = "/dev/ttyACM0"
SERIAL_BAUDRATE = 9600
DISTANCIA_MINIMA = 2
DISTANCIA_MAXIMA = 30

playlist = {
    "A": ["musicaA1.mp3", "musicaA2.mp3", "musicaA3.mp3"],
    "B": ["musicaB1.mp3", "musicaB2.mp3", "musicaB3.mp3", "musicaB4.mp3"],
    "C": ["musicaC1.mp3", "musicaC2.mp3", "musicaC3.mp3"],
    "AB": ["musicaAB1.mp3", "musicaAB2.mp3", "musicaAB3.mp3"],
    "AC": ["musicaAC1.mp3", "musicaAC2.mp3", "musicaAC3.mp3"],
    "BC": ["musicaBC1.mp3", "musicaBC2.mp3", "musicaBC3.mp3"],
    "ABC": ["musicaABC1.mp3"]
}

musicas_tocadas = {
    "A": [],
    "B": [],
    "C": [],
    "AB": [],
    "AC": [],
    "BC": [],
    "ABC": []
}

def sensor_acionado(distancia):
    return DISTANCIA_MINIMA <= distancia <= DISTANCIA_MAXIMA

def determinar_grupo(distancias):
    sensores = ['A', 'B', 'C']
    grupo = ''.join([sensores[i] for i, distancia in enumerate(distancias) if sensor_acionado(distancia)])
    return grupo

def play_music(file_path):
    pygame.mixer.init()
    pygame.mixer.music.load(file_path)
    pygame.mixer.music.play()
    while pygame.mixer.music.get_busy():
        pygame.time.Clock().tick(10)

def tocar_musica(grupo):
    musicas_disponiveis = [m for m in playlist[grupo] if m not in musicas_tocadas[grupo]]
    if not musicas_disponiveis:
        musicas_tocadas[grupo] = []
        musicas_disponiveis = playlist[grupo]
    
    musica_selecionada = random.choice(musicas_disponiveis)
    musicas_tocadas[grupo].append(musica_selecionada)
    play_music(musica_selecionada)

def main():
    with serial.Serial(SERIAL_PORT, SERIAL_BAUDRATE) as ser:
        while True:
            line = ser.readline().decode('utf-8').strip()
            distancias = [float(d) for d in line.split(",")]
            grupo = determinar_grupo(distancias)
            if grupo in playlist:
                tocar_musica(grupo)

if __name__ == "__main__":
    main()
