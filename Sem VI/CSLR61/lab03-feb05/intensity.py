import time
import RPi.GPIO as GPIO

BUTTON_GPIO_1 = 3
LED_GPIO = 7
BUTTON_GPIO_2 = 11

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

GPIO.setup(BUTTON_GPIO_1, GPIO.IN,pull_up_down=GPIO.PUD_UP)
GPIO.setup(LED_GPIO, GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(BUTTON_GPIO_2, GPIO.IN,pull_up_down=GPIO.PUD_UP)

pressed1 = False
pressed2 = False

p = GPIO.PWM(LED_GPIO, 100)
p.start(0)

val = 0

while True:
    if not GPIO.input(BUTTON_GPIO_1):
        if not pressed1:
            val += 20
            p.ChangeDutyCycle(val)
            print("Increased Intensity")
            pressed1 = True
        else:
            pressed1 = False
        time.sleep(1)
    if not GPIO.input(BUTTON_GPIO_2):
        if not pressed2:
            val -= 20
            p.ChangeDutyCycle(val)
            print("Decreased Intensity")
            pressed1 = True
        else:
            pressed2 = False
        time.sleep(1)
