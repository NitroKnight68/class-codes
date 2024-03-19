from RPi import GPIO
from time import sleep

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)

BUTTON_GPIO = 37

GPIO.setup(3, GPIO.OUT, initial = GPIO.LOW)
GPIO.setup(5, GPIO.OUT, initial = GPIO.LOW)
GPIO.setup(10, GPIO.OUT, initial = GPIO.LOW)
GPIO.setup(12, GPIO.OUT, initial = GPIO.LOW)
GPIO.setup(13, GPIO.OUT, initial = GPIO.LOW)
GPIO.setup(16, GPIO.OUT, initial = GPIO.LOW)
GPIO.setup(19, GPIO.OUT, initial = GPIO.LOW)

GPIO.setup(BUTTON_GPIO, GPIO.IN, pull_up_down = GPIO.PUD_UP)

gpin = [3, 5, 10, 12, 13, 16, 19]
digitclr = [0, 0, 0, 0, 0, 0, 0]
digit0 = [1, 1, 1, 1, 1, 1, 0]
digit1 = [0, 1, 1, 0, 0, 0, 0]
digit2 = [1, 1, 0, 1, 1, 0, 1]
digit3 = [1, 1, 1, 1, 0, 0, 1]
digit4 = [0, 1, 1, 0, 0, 1, 1]
digit5 = [1, 0, 1, 1, 0, 1, 1]
digit6 = [1, 0, 1, 1, 1, 1, 1]
digit7 = [1, 1, 1, 0, 0, 0, 0]
digit8 = [1, 1, 1, 1, 1, 1, 1]
digit9 = [1, 1, 1, 1, 0, 1, 1]

def displayDigit(digit):
    for x in range(0, 7):
        GPIO.output(gpin[x], digitclr[x])
    for x in range(0, 7):
        GPIO.output(gpin[x], digit[x])

count = 0

while True:
    if not GPIO.input(BUTTON_GPIO):
        if(count == 0):
            displayDigit(digit0)
        elif(count == 1):
            displayDigit(digit1)
        elif(count == 2):
            displayDigit(digit2)
        elif(count == 3):
            displayDigit(digit3)
        elif(count == 4):
            displayDigit(digit4)
        elif(count == 5):
            displayDigit(digit5)
        elif(count == 6):
            displayDigit(digit6)
        elif(count == 7):
            displayDigit(digit7)
        elif(count == 8):
            displayDigit(digit8)
        else:
            displayDigit(digit9)
        sleep(1)
        count += 1
        count %= 10

