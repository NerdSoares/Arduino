//Código para 4 sensores 

#include <OneWire.h>
#include <DallasTemperature.h>
 
OneWire pino(3);
const int RelePin = 9;
DallasTemperature barramento(&pino);
DeviceAddress sensor1;
DeviceAddress sensor2;
DeviceAddress sensor3;
DeviceAddress sensor4;


 
void setup(void)
{
  Serial.begin(9600);
  barramento.begin();
  barramento.getAddress(sensor1, 0);
  barramento.getAddress(sensor2, 1);
  barramento.getAddress(sensor3, 2);
  barramento.getAddress(sensor4, 3);
  Serial.println("Medidas de Temperatura dos Sensores (ºC):");  
  Serial.print(" sensor verde ");
  Serial.print(" ");
  Serial.print(" sensor preto ");
  Serial.print(" ");
  Serial.print(" sensor ver ver ");
  Serial.print(" ");
  Serial.println(" sensor vermelho ");
 
  pinMode(RelePin, OUTPUT); // seta o pino como saída
  digitalWrite(RelePin, LOW); // seta o pino com nivel logico baixo


}
void loop()
{
  barramento.requestTemperatures();
  float  green = barramento.getTempC(sensor1);
  float black = barramento.getTempC(sensor2);
  float gr = barramento.getTempC(sensor3);
  float red = barramento.getTempC(sensor4);
 
  Serial.print(green);
  Serial.print(" ");
  Serial.print(black);
  Serial.print(" ");
  Serial.print(gr);
  Serial.print(" ");
  Serial.println(red);


 if (black > 30) {     //se for A
      digitalWrite(RelePin, HIGH); //aciona o pino
    }


  if (black < 30) {     //se for D
      digitalWrite(RelePin, LOW);}  //desativa o pino


delay(500);
}
















