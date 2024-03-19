#include "DHT.h"
#define DHTPIN 14     
#define DHTTYPE DHT11 
//libreria para el nodemcu wifi
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

// Definir las redes
const char *ssid ="Contraseña";
const char *password ="Contraseña";  

float t;
float h;
ESP8266WebServer server(80):



DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
  Wifi.softAp(assid,password)
  server.on("/",handleRoot)
  server.begin();
}

void loop() {
  LecturaTh();
  server.handleClient();
  
void handleRoot(){
    server.send(200,"text/html","<html><head><meta name='viewport' content='width=device-width,user-scalable=no'>"
    "<meta http-equiv='refresh' content='5' charset='UTF-8'><title>Comprobador_de_temperatura</title>"
    "<style>body{font-family: monospace;background-color:beige;}"
    "h1{color: black;text-align: center;margin: 50px;font-size: 18px;}"
    ".barraTemp{height: 200px;width: 200px;background-color: yellow;margin: auto;border-radius: 50%;overflow: hidden;}"
    ".cont{height: 100px;width: 200px;}"
    ".circulo_medio{width: 150px;height: 150px;background-color: beige;border-radius: 50%;margin: auto;position: relative;margin: -175px auto 50px;}"
    ".rectangulo{width: 200px;height: 100;background-color: beige;position: relative;margin: -125px auto 50px;}"
    "</style></head>"
    "<body><h1>Toma-de-temperatura</h1><h1>Temperatura</h1>"
    "<div class='barraTemp' style='transform: rotate("+String(map(t,0,100,180))+"deg);'>"
    "<div class="cont"style='background-color: rgb(143, 136, 126);'>"
    "</div><div class='cont' style='background-color: rgb(253, 0, 0);'></div>"
    "</div><div class='circulo_medio'></div><div class='rectangulo'></div>"
    "<h1 style='font-size: 22px;  position: relative;"
    "margin: -125px auto 50px;">"+String(t)+" °C </h1>"
    "<h1>Humedad</h1><div class='barraTemp' style='transform: rotate("+String(map(t,0,100,180))+"deg);'>"
    "<div class='cont' style='background-color: rgb(143, 136, 126);'></div>"
    "<div class='cont' style='background-color: rgb(253, 0, 0);'></div></div>
    "<div class='circulo_medio'></div><div class='rectangulo'></div>"
    "<h1 style='font-size: 22px;  position: relative; margin: -125px auto 50px;'>"+String(h)+" % </h1>"
    "</body></html>")
            
    } 
 void LecturaTh(){
  delay(2000);
  h = dht.readHumidity();
  t = dht.readTemperature();
  f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }


  float hif = dht.computeHeatIndex(f, h);
 
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}
  
