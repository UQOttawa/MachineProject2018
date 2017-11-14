#!/usr/bin/env python

import socket


TCP_IP = '192.168.0.100'
TCP_PORT = 8080
BUFFER_SIZE = 1024
MESSAGE = "Hello, World!"

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(TCP_IP, TCP_PORT)

while 1: 
    MESSAGE = input("")
    s.send(bytearray(MESSAGE, "utf-8"))
    data = s.recv(BUFFER_SIZE)
s.close()

print ("received data:", data)