from smbus import SMBus
import time
import random
import RPi.GPIO as GPIO

address = 0x40
bus = SMBus(1)



try:
    while True:
        rnd = random.randint(1, 5)
        bus.write_byte(address, rnd)

        time.sleep(1)
        

except KeyboardInterrupt:
    GPIO.cleanup()