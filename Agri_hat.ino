#include<DHT.h>
DHT dht(23,DHT11);

String result;

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float h=dht.readHumidity();
  float t=dht.readTemperature();

  if(isnan(h)||isnan(t))
  return;

  if((h>60 && h<90) && (t>20 && t<33)){
    result="Low Temperature";
     
  }else if((h>90) && (t>33)){
    result="High Temperature";
  }else{
    result="neutral";
  }

  Serial.print("#");
  Serial.print(",");
  Serial.print(h);
  Serial.print(",");
  Serial.print(t);
  Serial.print(",");
  Serial.print(result);
  Serial.print(",");
  Serial.println("~");
  delay(4000);

}
