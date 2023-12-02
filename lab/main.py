from smbus2 import SMBus
import time
import math

def main():
   ADDR = 10
   bus = SMBus(0)
   while True:
      bus.write_i2c_block_data(10, 0xAA, [0, 0])# зааттачить
      time.sleep(1)
      bus.write_i2c_block_data(10, 0, [90, 90])# задать углы
      time.sleep(1)
      bus.write_i2c_block_data(10, 0, [180, 180])
      time.sleep(1)
      bus.write_i2c_block_data(10, 0xBB, [0, 0,])# задетачить
      time.sleep(1)

if __name__ == '__main__':
    main()
