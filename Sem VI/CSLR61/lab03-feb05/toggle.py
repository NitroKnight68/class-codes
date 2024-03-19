import time
import RPi.GPIO as GPIO

BUTTON_GPIO_1 = 3
LED_GPIO = 7

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

GPIO.setup(BUTTON_GPIO_1, GPIO.IN,pull_up_down=GPIO.PUD_UP)
GPIO.setup(LED_GPIO, GPIO.OUT, initial=GPIO.LOW)

pressed = False
toggle = False

while True:
    if not GPIO.input(BUTTON_GPIO_1):
        if not pressed:
            if not toggle:
                GPIO.output(LED_GPIO, GPIO.HIGH)
                print("Turned On")  
                toggle = True
            else:
                GPIO.output(LED_GPIO, GPIO.LOW)
                print("Turned Off")                
                toggle = False
            pressed = True
        else:
            pressed = False
        time.sleep(1)
