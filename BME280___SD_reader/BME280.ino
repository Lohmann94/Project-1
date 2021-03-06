
//#include "SparkFunBME280.h"
//#include "Wire.h"
//#include "SPI.h"
//#include <stdint.h>

//#include <SPI.h>
//#include <SD.h>

//String dataString = "";
//int pinCS = 4;

//File myFile;
//File secondFile;

//BME280 mySensor;
/*
void setup() {

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
*/
void loop() {

  // put your main code here, to run repeatedly:

  Serial.print("Temperature: ");
  Serial.print(mySensor.readTempC(), 2);
  Serial.println(" degrees C");

  Serial.print("Pressure: ");
  Serial.print(mySensor.readFloatPressure(), 2);
  Serial.println(" Pa");

  Serial.print("%RH: ");
  Serial.print(mySensor.readFloatHumidity(), 2);
  Serial.println(" %");

  Serial.println();

  float tid = 0;
  float tilfaeldig = random(100);
  float tilfaeldig2 = random(50);
  float tilfaeldig3 = random(10);
  float tilfaeldig4 = random(1000);
  //saveStuff(mySensor.readTempC(),mySensor.readFloatPressure(),mySensor.readFloatHumidity(),tid);
  saveStuff(tilfaeldig, tilfaeldig2, tilfaeldig3, tilfaeldig4);
  delay(1000);
}
