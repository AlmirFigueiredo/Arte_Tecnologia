import serial
import random
from pygame import mixer
from time import sleep

s = serial.Serial("dev/ttyACM0", 9600)
mixer.init()

group1 = []
group2 = []

group1.append(mixer.Sound("SoundGroups/Birds1.wav"))

    
