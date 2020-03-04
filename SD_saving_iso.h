class SD_saving {

  private:
    float temperature;
    float pressure;

  public:

    void saveValueOnSD(float temperature, float pressure) {
      String dataStringPartA = "";

      Serial.begin(9600);

      Serial.print("Initializing SD card...!");
      //pinMode(CSpin, OUTPUT); maybe needs to be set according to which port your SD-card is attached to
      if (!SD.begin(10)) {//Keep an eye for this port)
        Serial.println("Initialization failed");
        while (1);
      }
      dataStringPartA = String(temperature) + "," + String(pressure); // inkluder på et tidspunkt kode så man også får tiden
      saveData();

      if (SD.exists("data.csv")) {
        if (partAData) {
          sensorData.println(dataStringPartA);
          sensorData.close();
        }
      } else {
        Serial.println("error writing to file!");
      }
    }

}
