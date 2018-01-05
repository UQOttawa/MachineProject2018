#!/usr/bin/env python

import socket
import serial
import sys

ser = serial.Serial('/dev/ttyACM0')
ser.baudrate = 9600
if not ser.isOpen():
    sys.exit()

print('connected to arduino on: ', ser.port)

TCP_IP = '192.168.0.100'
# TCP_IP = "localhost"
TCP_PORT = 5005
BUFFER_SIZE = 1024  # Normally 1024, but we want fast response

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)
print('listenting for connections on... ', TCP_IP, ':', TCP_PORT)

conn, addr = s.accept()
print('connected to client on: ', addr)
while True:
    data = conn.recv(BUFFER_SIZE)
    for command in data.split('|')[:-1]:
        if(command == b'23'): # ctrl + backspace
            conn.close()
        elif(int(command) < 257):
            ser.write(chr(int(command)))
        else:
            print('You fucked up ', command)
