#!/usr/bin/env python

import socket
import sys
import curses
from time import sleep

TCP_IP = '192.168.0.100'
# TCP_IP = "localhost"
TCP_PORT = 5005
BUFFER_SIZE = 1024
MESSAGE = ""

stdscr = curses.initscr()


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((TCP_IP, TCP_PORT))
stdscr.keypad(1)
while True:
    key = stdscr.getch()
    MESSAGE = str(key)
    s.send(bytearray(MESSAGE, "utf-8"))

s.close()