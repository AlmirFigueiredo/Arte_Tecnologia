import serial
import random
import pygame

SERIAL_PORT = "/dev/ttyACM0"
SERIAL_BAUDRATE = 9600
DISTANCIA_MINIMA = 5
DISTANCIA_MAXIMA = 20

playlist = {
    "A": ["SoundGroups/A/one.wav", "SoundGroups/A/two.wav", "SoundGroups/A/three.wav"],
    "B": ["SoundGroups/B/one.wav", "SoundGroups/B/two.wav", "SoundGroups/B/three.wav", "SoundGroups/B/four.wav"],
    "C": ["SoundGroups/C/one.wav", "SoundGroups/C/two.wav", "SoundGroups/C/three.wav"],
    "AB": ["SoundGroups/AB/one.wav", "SoundGroups/AB/two.wav", "SoundGroups/AB/three.wav"],
    "AC": ["SoundGroups/AC/one.wav", "SoundGroups/AC/two.wav", "SoundGroups/AC/three.wav"],
    "BC": ["SoundGroups/BC/one.wav", "SoundGroups/BC/two.wav", "SoundGroups/BC/three.wav"],
    "ABC": ["SoundGroups/ABC/Contemplativa.wav"]
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
