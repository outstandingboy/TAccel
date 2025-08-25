#include "koalamodule.h"

koalamodule mymodule;
//koalamodule mymodule2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000);
  mymodule.attach(8,2,5);
  mymodule.attachSwitch(9);
  mymodule.setStepspermm(100);
  mymodule.invertdirection();
  mymodule.toOrigin();
  delay(1000);
  mymodule.toPosition(50,3000);
  delay(1000);
}

void loop() {
  mymodule.toPosition(20,60000);
  delay(200);
  mymodule.toPosition(40,36000);
  delay(200);
  mymodule.toPosition(60,36000);
  delay(200);
  mymodule.toPosition(80,36000);
  delay(200);
  mymodule.toPosition(100,36000);
  delay(200);
  mymodule.toPosition(120,36000);
  delay(200);
  mymodule.toPosition(140,36000);
  delay(200);
  mymodule.toPosition(160,36000);
  delay(200);
  mymodule.toPosition(180,36000);
  delay(200);
  mymodule.toPosition(200,36000);
  delay(200);
  mymodule.toPosition(220,36000);
  delay(200);

}
