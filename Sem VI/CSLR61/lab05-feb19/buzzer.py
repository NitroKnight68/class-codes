import RPi.GPIO as GPIO
from time import sleep

PIR_GPIO = 3
BUZZER_GPIO = 7
LED_GPIO = 11

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)

GPIO.setup(PIR_GPIO, GPIO.IN)
GPIO.setup(BUZZER_GPIO, GPIO.OUT)
GPIO.setup(LED_GPIO, GPIO.OUT, initial = GPIO.LOW)

p = GPIO.PWM(BUZZER_GPIO, 100)
p.start(0)

while True:
    if GPIO.input(PIR_GPIO):
        GPIO.output(LED_GPIO, GPIO.HIGH)
        print('Motion Detected')
        
        for x in range(0, 100, 5):
            p.ChangeDutyCycle(x)
            print('Buzzer On')
            sleep(0.1)
        sleep(1)

        GPIO.output(LED_GPIO, GPIO.LOW)
        p.ChangeDutyCycle(0)
        print('Motion Not Detected')
        sleep(2)
        