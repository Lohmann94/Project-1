void saveStuff(float temperature, float pressure, float humidity, float timeStamp) {
  //File secondFile;

  float temperatureValue = temperature;
  float pressureValue = pressure;
  float humidityValue = humidity;
  float timeStampValue = timeStamp;
  
  secondFile = SD.open("test3.csv", FILE_WRITE);
 
  dataString = String(1) + "," + String(1) + "," + String(1) + "," + String(1);
  //dataString = String(temperatureValue) + "," + String(pressureValue) + "," + String(humidityValue) + "," + String(timeStampValue);
  
  if (SD.exists("test3.csv")) {
    secondFile = SD.open("test3.csv", FILE_WRITE);
    if (secondFile) {
      secondFile.println(dataString);
      secondFile.close();
    } else {
      Serial.println("indre fejl");
    }
  } else {
    Serial.println("ydre fejl");
  }
 
  secondFile.close();
}

//indre fejl-funktion fungerer ikke, eksekverer både else og if statement
