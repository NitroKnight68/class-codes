import adafruit_dht
import sqlite3
import time
import board
import RPi.GPIO as GPIO

conn = sqlite3.connect('sensor-data.db')
c = conn.cursor()

c.execute('''CREATE TABLE IF NOT EXISTS sensor_data
          (timestamp DATETIME, temperature REAL, temperaturef REAL, humidity REAL)''')
conn.commit()

sensor = adafruit_dht.DHT22(board.D4, use_pulseio = False)
GPIO.setmode(GPIO.BCM)

while True:
    try:
        while True:
            humidity, temperature = sensor.humidity, sensor.temperature
            if humidity is not None and temperature is not None:
                timestamp = time.strftime('%Y-%m-%d %H:%M:%S')
                temperaturef = temperature * (9/5) + 32
                c.execute('INSERT INTO sensor_data VALUES (?, ?, ?, ?)',
                          (timestamp, temperature, temperaturef, humidity))
                conn.commit()
                print(f'Timestamp: {timestamp}, Temperature: {temperature} C & {temperaturef} F, Humidity: {humidity} %')
            else:
                print('Failed to retrieve data from the sensor')
            time.sleep(2)

            result = c.execute('SELECT * FROM sensor_data')
            for row in result:
                print(row)
    except KeyboardInterrupt:
        print('Interrupted')
        break
    
conn.close()