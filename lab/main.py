from smbus2 import SMBus
import time
import math

def main():
   ADDR = 10
   bus = SMBus(1)
   while True:
      angle = 45 + int(90 * abs(math.sin(time.time()*0.5)))
      bus.write_byte_data(10, 0, angle)
      #print(angle,' out:' ,bus.read_byte_data(ADDR, 0))
      time.sleep(0.1)

if __name__ == '__main__':
    main()
