import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

LED_RED = 22
LED_YELLOW = 16
LED_GREEN = 8

PIN_TRIGGER = 7
PIN_ECHO = 11

GPIO.setup(LED_RED, GPIO.OUT, initial = GPIO.LOW)
GPIO.setup(LED_YELLOW, GPIO.OUT, initial = GPIO.LOW)
GPIO.setup(LED_GREEN, GPIO.OUT, initial = GPIO.LOW)

GPIO.setup(PIN_TRIGGER, GPIO.OUT)
GPIO.setup(PIN_ECHO, GPIO.IN)

GPIO.output(PIN_TRIGGER, GPIO.LOW)
print ("Waiting for sensor to settle")
time.sleep(2)

while True:    
    print("Calculating Distance")
    GPIO.output(PIN_TRIGGER, GPIO.HIGH)
    time.sleep(0.00001)
    GPIO.output(PIN_TRIGGER, GPIO.LOW)
    
    while GPIO.input(PIN_ECHO) == 0:
        pulse_start_time = time.time()
    while GPIO.input(PIN_ECHO) == 1:
        pulse_end_time = time.time()
        
    pulse_duration = pulse_end_time - pulse_start_time
    distance = round(pulse_duration * 17150, 2)
    
    if(distance > 100):
        GPIO.output(LED_GREEN, GPIO.HIGH)
        GPIO.output(LED_YELLOW, GPIO.LOW)
        GPIO.output(LED_RED, GPIO.LOW)
    if(distance > 20 and distance < 100):
        GPIO.output(LED_GREEN, GPIO.LOW)
        GPIO.output(LED_YELLOW, GPIO.HIGH)
        GPIO.output(LED_RED, GPIO.LOW)
    if(distance < 20):
        GPIO.output(LED_GREEN, GPIO.LOW)
        GPIO.output(LED_YELLOW, GPIO.LOW)
        GPIO.output(LED_RED, GPIO.HIGH)
    
    print("Distance is " + str(distance) + "cm")
    
    time.sleep(1)