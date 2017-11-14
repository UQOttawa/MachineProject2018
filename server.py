#!/usr/bin/env python

import socket
import serial
import sys

ser = serial.Serial()
ser.baudrate = 19200
ser.port = 'COM1'
ser.open()
if !ser.open():
    sys.exit()

#print('connected to arduino on: ', ser.port)

TCP_IP = '192.168.0.100'
TCP_PORT = 5005
BUFFER_SIZE = 1024  # Normally 1024, but we want fast response

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
s.listen(1)
print ('listenting for connections on... ', TCP_IP, ':', TCP_PORT)

conn, addr = s.accept()
print ('connected to client on: ', addr)
while True:
    data = conn.recv(BUFFER_SIZE)
    if not data: break
    print ('forwarded: ', data)
    ser.write(data)

conn.close()
