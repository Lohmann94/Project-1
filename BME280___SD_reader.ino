
#include <SD.h>
#include <SPI.h>
#include "SparkFunBME280.h"
#include "Wire.h"
#include "SPI.h"
#include <stdint.h>

int measurementNumber = 1;
int pinCS = 4;
String dataString = "";

File myFile;
File secondFile;

BME280 mySensor;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(pinCS, OUTPUT);

  SD.begin();

  //Serial.begin(9600); //ændret fra 57600 til 9600 for at have samme som sd-card-reader
  //pinMode(pinCS, OUTPUT);
  //SD.begin();
  
  // put your setup code here, to run once:

  //commInterface can be I2C_MODE or SPI_MODE
  //specify chipSelectPin using arduino pin names
  //specify I2C address.  Can be 0x77(default) or 0x76

  //For I2C, enable the following and disable the SPI section
  //mySensor.settings.commInterface = I2C_MODE;
  //mySensor.settings.I2CAddress = 0x76;

  //For SPI enable the following and dissable the I2C section
  mySensor.settings.commInterface = SPI_MODE;
  mySensor.settings.chipSelectPin = 10;

  //runMode can be:
  //  0, Sleep mode
  //  1 or 2, Forced mode
  //  3, Normal mode
  mySensor.settings.runMode = 3; //Forced mode

  //tStandby can be:
  //  0, 0.5ms
  //  1, 62.5ms
  //  2, 125ms
  //  3, 250ms
  //  4, 500ms
  //  5, 1000ms
  //  6, 10ms
  //  7, 20ms
  mySensor.settings.tStandby = 0;

  //filter can be off or number of FIR coefficients to use:
  //  0, filter off
  //  1, coefficients = 2
  //  2, coefficients = 4
  //  3, coefficients = 8
  //  4, coefficients = 16
  mySensor.settings.filter = 0;

  //tempOverSample can be:
  //  0, skipped
  //  1 through 5, oversampling *1, *2, *4, *8, *16 respectively
  mySensor.settings.tempOverSample = 1;

  //pressOverSample can be:
  //  0, skipped
  //  1 through 5, oversampling *1, *2, *4, *8, *16 respectively
  mySensor.settings.pressOverSample = 1;

  //humidOverSample can be:
  //  0, skipped
  //  1 through 5, oversampling *1, *2, *4, *8, *16 respectively
  mySensor.settings.humidOverSample = 1;
  delay(10);  //Make sure sensor had enough time to turn on. BME280 requires 2ms to start up.         Serial.begin(57600);



  Serial.print("Starting BME280... result of .begin(): 0x");
  //Calling .begin() causes the settings to be loaded
  Serial.println(mySensor.begin(), HEX);

  //initializing outer tab-functions:
}

/*
void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  
  float tilfaeldig = random(100);
  float tilfaeldig2 = random(50);
  float tilfaeldig3 = random(10);
  float tilfaeldig4 = random(1000);

  saveStuff(tilfaeldig, tilfaeldig2, tilfaeldig3, tilfaeldig4);

  delay(1000);
*/
/*
  secondFile = SD.open("test2.csv", FILE_WRITE);
 
  dataString = String(sensorValue) + "," + String(measurementNumber) + "," + String(voltage);
  saveData();
 
  secondFile.close();

  secondFile = SD.open("test2.csv");
  
  if (secondFile) {
    Serial.println("Reading: ");
    while (secondFile.available()) {
      Serial.write(secondFile.read());
    }
    secondFile.close();
  } else {
    Serial.println("error opening!");
  }
  //Serial.println(measurementNumber);
  //Serial.println(sensorValue);

  measurementNumber = measurementNumber + 1;
  delay(5000);
}

void saveData() {
  if (SD.exists("test2.csv")) {
    secondFile = SD.open("test2.csv", FILE_WRITE);
    if (secondFile) {
      secondFile.println(dataString);
      secondFile.close();
    } else {
      Serial.println("indre fejl");
    }
  } else {
    Serial.println("ydre fejl");
  }

}
*/
