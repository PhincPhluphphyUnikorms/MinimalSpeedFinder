#fra https://github.com/sudar/Arduino-Makefile


#Kan findes ved at køre make show_boards
BOARD_TAG = uno

#Space separated set of libraries that are used by your sketch
ARDUINO_LIBS = LiquidCrystal PID_v1


PROJECT_DIR   = $(shell pwd)

#USER_LIB_PATH := $(realpath $(PROJECT_DIR)/../PID) #Adds the home of the project so we can use classes from their 

#Use dmesg if unsure about this
ARDUINO_PORT = /dev/ttyACM3

USER_LIB_PATH = /home/daniel/sketchbook/libraries

IDIR = ../PID


include /home/daniel/arduino-mk-1.3.1/Arduino.mk


# compile med: make
#uplaod med: make upload

# se http://hardwarefun.com/tutorials/compiling-arduino-sketches-using-makefile
