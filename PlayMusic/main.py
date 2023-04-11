import serial

s = serial.Serial("dev/ttyACM0", 9600)

while True:
    distances_string = s.redline().decode().strip()
    distances = distances_string.split()

    distanceUS1 = int(distances[0])
    distanceUS2 = int(distances[1])
    distanceUS3 = int(distances[2])
    distanceUS4 = int(distances[3])
    distanceUS5 = int(distances[4])
    
    
