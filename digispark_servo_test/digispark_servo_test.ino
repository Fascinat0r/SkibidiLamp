#include <Servo_ATTinyCore.h>
#include <TinyWire.h>

Servo servo1;
Servo servo2;
byte own_address = 10;

void attachServos() {
  servo1.attach(4);  // attaches the servo on pin 4 to the servo object
  servo2.attach(1);
}

void detachServos() {
  servo1.detach();
  servo2.detach();
}

void setup() {
  TinyWire.begin(own_address);
  TinyWire.onReceive(onI2CReceive);
}

void loop() {
  delay(5);
}

void onI2CReceive(int howMany) {
  uint8_t cmds[3];
  int count = 0;
  while (TinyWire.available() > 0) {
    cmds[count] = TinyWire.read();
    count++;
  }
  if(cmds[0]==0xAA){ 
    attachServos();
  }else if(cmds[0]==0xBB){
    detachServos();
  }
  servo1.write(cmds[1]);
  servo2.write(cmds[2]);
}
