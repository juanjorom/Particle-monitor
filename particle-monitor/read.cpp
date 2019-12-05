#include <DHT.h>

#include <Adafruit_Sensor.h>

#include <hpma115s0.h>
#include <SoftwareSerial.h>


#define DHTPIN 2
#define DHTTYPE    DHT11     // DHT 11  
float p25;
float p10;

SoftwareSerial mySerial(10, 11); // RX, TX
HPMA115S0 my_hpm(mySerial);
DHT dht(DHTPIN, DHTTYPE);
  

void read_initialize(){
  mySerial.begin(9600);
  dht.begin();
  //Serial.println(F("DHT OK"));
  delay(100);
 
   // Stop autosend
  if (my_hpm.stop_autosend()){
    //Serial.println(F("CONFIG HPMA..."));
  }
  else{
  //Serial.print("Error");  
  }
  delay(500);
  
  // Start fan (and measurement mode)
    
  if (my_hpm.start_measurement()){
    //Serial.println(F("HPMA OK"));
  }
  delay(5000);
}


float read_humidity(){
  float h = dht.readHumidity();

  if(isnan(h)){
    //Serial.println(F("Error"));
    return 0;
  }
  else
  {
    return h;
  }
}

float read_temperatureCel(){
  float t= dht.readTemperature();

  if(isnan(t)){
    //Serial.println("Error");
    return 0;
  }
  else
  {
    return t;
  }
}

float read_temperatureFar(){
  float t= dht.readTemperature(true);

  if(isnan(t)){
    //Serial.println(F("Error"));
    return 0;
  }
  else
  {
    return t;
  }
}

float read_heatIndexCel(float temperature, float humidity){
  float heat = dht.computeHeatIndex(temperature, humidity, false);
  return heat;
}

float read_heatIndexFar(float temperature, float humidity){
  float heat = dht.computeHeatIndex(temperature, humidity);
  return heat;
}

byte read_particles(float *p_pm25, float *p_pm10){
  byte exito=0; 
  float pm25, pm10;
  if (my_hpm.read(&pm25,&pm10))
  {
    *p_pm25=pm25;
    *p_pm10=pm10;
     exito=1;
  }
  // Wait 15 seconds
  return exito;
}
