#include <Arduino.h>


unsigned char conexion_check(){
  Serial.println("INIT");
  if(Serial.available()>0){
    String rec=Serial.readStringUntil('\n');
    if(rec.length()>0){
      if(rec.charAt(0)=='O' && rec.charAt(1)=='K'){
        return 1;
      }
    }
  }
  return 0;
}


String conexion_prep(float temp_c, float temp_f, float hum, float index_c, float index_f, float pm10, float pm25){
  String result= "DT,";
  result.concat(temp_c);
  result.concat(',');
  result.concat(temp_f);
  result.concat(',');
  result.concat(hum);
  result.concat(',');
  result.concat(index_c);
  result.concat(',');
  result.concat(index_f);
  result.concat(',');
  result.concat(pm10);
  result.concat(',');
  result.concat(pm25);
  
  return result;
}

void conexion_send(String data){
  Serial.println(data);
  if(Serial.available()>0){
    String rec= Serial.readStringUntil('\n');

    if(rec.length()>0){
      if(rec.charAt(0)=='S' && rec.charAt(1)=='E'){
      }
    }
  }
}
