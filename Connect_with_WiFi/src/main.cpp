#include <Arduino.h>
#include <WiFi.h>
#include <../../credentials.h>

// put function declarations here:
#define WIFI_TIMEOUT_MS 20000
#define LED_PIN 22

void ConnectToWifi(){
  Serial.print("Connecting to WiFi");
  WiFi.mode(WIFI_STA); //set station mode for already existing wifi, Other mode is AP=Acess Point mode.
  WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD);
  unsigned long startAttemptTime=millis();//return uptime of esp32
  while(WiFi.status() != WL_CONNECTED && (millis()-startAttemptTime < WIFI_TIMEOUT_MS)){
    Serial.print(".");
    delay(100);
  }
  if(WiFi.status() != WL_CONNECTED){
    Serial.println(" Failed!");
  }else{
    Serial.print("Connected! IP is: ");
    Serial.println(WiFi.localIP());
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  ConnectToWifi();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_PIN, WiFi.status() == WL_CONNECTED); // turn LED ON when wifi is connected
}