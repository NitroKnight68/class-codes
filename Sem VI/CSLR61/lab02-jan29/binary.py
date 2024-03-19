from RPi import GPIO
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)

GPIO.setup(3,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(7,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(11,GPIO.OUT,initial=GPIO.LOW)
GPIO.setup(15,GPIO.OUT,initial=GPIO.LOW)

pins = [3, 7, 11, 15]

val = int(input('Enter an Integer Number : '))
if(val < 0 or val > 15):
    print('Invalid Number')
    
binVal = str(bin(val))
binVal = binVal[2:]

if(len(binVal) == 1):
    binVal = '000' + binVal
if(len(binVal) == 2):
    binVal = '00' + binVal
if(len(binVal) == 3):
    binVal = '0' + binVal
    
print('Value in Binary is ' + binVal)

for i in range(4):
    if binVal[i] == '1':
        GPIO.output(pins[i], GPIO.HIGH)
time.sleep(2)

for i in range(4):
    GPIO.output(pins[i], GPIO.LOW)

                                                     


