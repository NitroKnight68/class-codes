import time
import Adafruit_CharLCD as LCD

lcd_rs = 21
lcd_en = 20
lcd_d4 = 6
lcd_d5 = 13
lcd_d6 = 19
lcd_d7 = 26
lcd_bl = 4

lcd_columns = 16
lcd_rows = 2

lcd = LCD.Adafruit_CharLCD(lcd_rs, lcd_en, lcd_d4, lcd_d5, lcd_d6, lcd_d7, lcd_columns, lcd_rows, lcd_bl)

lcd.message("Good Afternoon\nAmbati Sir")
time.sleep(5)
lcd.clear()

lcd.message("Waiting...")
text = input("Type Something..")
lcd.clear()
lcd.message(text)
time.sleep(5)
lcd.clear()

lcd.message("Goodbye\nAmbati Sir")
time.sleep(5)
lcd.clear()
