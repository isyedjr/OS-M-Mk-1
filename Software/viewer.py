# Viewer.py
# Controls PiCam and video feedback
# Imaad Syed, Aaban Syed
# 12/24/2020


from picamera import PiCamera
from time import sleep
import keyboard
invert = 0
toggleVid = 0

cam.start_preview()

while(a): # main loop
  if keyboard.is_pressed('q'): # capture when q pressed
    cam.capture('/home/pi/Desktop/view%s.jpg' % i)
    i = i + 1
  
  if keyboard.is_pressed('x'): # quit when x pressed
    a = False
  
  if keyboard.is_pressed('i'): # toggle inverted color scheme with i
    if(invert == 0):
      cam.image_effect = 'negative'
      invert = 1
    else:
      cam.image_effect = 'none'
      invert = 0
    sleep(0.3)
      
  if keyboard.is_pressed('r'):# toggle inverted color scheme with i
      if(toggleVid == 0):
        cam.start_recording('/home/pi/Desktop/view%s.h264' % j)
        toggleVid = 1
      else:
        cam.stop_recording()
        j = j + 1
        toggleVid = 0
      sleep(0.3)
cam.stop_preview()

cam = PiCamera() # new camera object

a = True
i = 1
j = 1

invert = 0
toggleVid = 0

cam.start_preview()

while(a): # main loop
  if keyboard.is_pressed('q'): # capture when q pressed
    cam.capture('/home/pi/Desktop/view%s.jpg' % i)
    i = i + 1
  
  if keyboard.is_pressed('x'): # quit when x pressed
    a = False
  
  if keyboard.is_pressed('i'): # toggle inverted color scheme with i
    if(invert == 0):
      cam.image_effect = 'negative'
      invert = 1
    else:
      cam.image_effect = 'none'
      invert = 0
    sleep(0.3)
      
  if keyboard.is_pressed('r'):# toggle inverted color scheme with i
      if(toggleVid == 0):
        cam.start_recording('/home/pi/Desktop/view%s.h264' % j)
        toggleVid = 1
      else:
        cam.stop_recording()
        j = j + 1
        toggleVid = 0
      sleep(0.3)
cam.stop_preview()
