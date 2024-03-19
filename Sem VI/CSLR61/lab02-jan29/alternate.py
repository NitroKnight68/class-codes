from RPi import GPIO
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

GPIO.setup(3,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(7,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(11,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(15,GPIO.OUT,initial=GPIO.LOW)

while True:
    GPIO.output(3,GPIO.HIGH)
    GPIO.output(11,GPIO.HIGH)
    time.sleep(0.5)
    GPIO.output(3,GPIO.LOW)
    GPIO.output(11,GPIO.LOW)
    
    GPIO.output(7,GPIO.HIGH)
    GPIO.output(15,GPIO.HIGH)
    time.sleep(0.5)
    GPIO.output(7,GPIO.LOW)
    GPIO.output(15,GPIO.LOW)

                                                     

