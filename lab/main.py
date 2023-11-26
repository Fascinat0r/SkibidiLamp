from smbus2 import SMBus
import time
import math

def main():
   ADDR = 10
   bus = SMBus(1)
   while True:
      bus.write_i2c_block_data(10, 0, [0, 0, 0xAA])# зааттачить
      time.sleep(1)
      bus.write_i2c_block_data(10, 0, [90, 90])# задать углы
      time.sleep(1)
      bus.write_i2c_block_data(10, 0, [180, 180])
      time.sleep(1)
      bus.write_i2c_block_data(10, 0, [0, 0, 0xBB])# задетачить
      #print(angle,' out:' ,bus.read_byte_data(ADDR, 0))
      time.sleep(0.1)

if __name__ == '__main__':
    main()
