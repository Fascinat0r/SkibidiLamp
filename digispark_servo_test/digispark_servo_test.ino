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
  randomSeed(analogRead(0));
  attachServos();
  TinyWire.begin(own_address);
  TinyWire.onReceive(onI2CReceive);
}

void loop() {}

void onI2CReceive(int howMany) {
  int *cmds = new int[3];
  int count = 0;
  while (TinyWire.available() > 0) {
    cmds[count++] = TinyWire.read();
  }
  if (count > 2) {
    if (cmds[2] == 0xAA) {
      attachServos();
    }
    else if (cmds[2] == 0xBB) {
      detachServos();
    }
  }
  else {
    servo1.write(cmds[0]);
    servo2.write(cmds[1]);
  }
  delete[] cmds;
}
