/**
 * Author: 
Inclusão das bibliotecas
 * 
 * vcc -> vermelho, vin
 * gnd -> cinza, gnd
 * 2   -> azul, trigger
 * 27  -> amarelo, echo 
 * 
 */
 
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "t8V1fV8WVyRFOUPmBJRKtXvgDlk3u23k";

char ssid[] = "RLE-Niflheim";
char pass[] = "kamehameha";



float distancia;

float verificaPerimetro(){
 
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);

  
  digitalWrite(2, LOW);

  float distancia = pulseIn(27, HIGH)/50.00;
  delay(10);
  
  return distancia;
}

void setup() {
 
  distancia = 0;
  
  pinMode(2, OUTPUT);//azul
  pinMode(27, INPUT);//amarelo
  Blynk.begin(auth, ssid, pass);
}

void loop() {

  Blynk.run();
  
  distancia = verificaPerimetro();

  if(distancia < 50){
    Blynk.email("erivelton84ribeiro@gmail.com", "Alerta", "Entrou alguém");
    Blynk.email("elaineschwane@gmail.com"

    
  }

  Blynk.virtualWrite(V1, distancia);
  delayMicroseconds(3000);

}
