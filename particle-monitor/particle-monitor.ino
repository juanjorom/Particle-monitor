// ---------------------------------
// HPMA115S0 dust sensor example
// for use with devices with SoftSerial
// on boards like Arduino Uno
//
// IMPORTANT!!!
// When using Arduino Uno boards, 
// a logic level converter for 
// TX and RX lines is mandatory
// (I used BOB-12009 from Sparkfun)
// ---------------------------------

#include "read.h"
#include "conexion.h"

void setup() {
  Serial.begin(9600);
  read_initialize();
}

 float pm10=0;
 float pm25=0;
 float tempCel=0;
 float tempFar=0;
 float humidity=0;
 float heatCel=0;
 float heatFar=0;
void loop() {
    if(conexion_check()){
      // Read the particle data every fifteen seconds
      tempCel = read_temperatureCel();
      tempFar = read_temperatureFar();
      humidity = read_humidity();
      heatCel = read_heatIndexCel(tempCel, humidity);
      heatFar = read_heatIndexFar(tempFar, humidity);
      read_particles(&pm25,&pm10);
      String preparada="";
      preparada = conexion_prep(tempCel, tempFar, humidity, heatCel, heatFar, pm10, pm25);
      conexion_send(preparada);
    }
    delay(15000);
}
