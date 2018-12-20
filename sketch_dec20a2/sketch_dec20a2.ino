#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>
#include <ESP8266WiFi.h>


#define WIFI_SSID       "PserLvlNA"
#define WIFI_PASSWORD   "ghosterhtd"
#define FIREBASE_HOST "nodemcu-aa998.firebaseio.com"
#define FIREBASE_AUTH "ioqefskzFZyoRxCytvGnYuyTbE06rbXtxvjAujob"

const int ledPin = 14;
int incomingByte = 0;
int rdata = 99 ;
String st="";
const String deviceNumber = "nodemcu-aa998";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println(WiFi.localIP());
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  pinMode(ledPin, OUTPUT);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
void loop() {
  if (incomingByte) st="Ready";
  else st="Waiting";
  Firebase.setString(deviceNumber+"/status", st);
  rdata = (Firebase.getString(deviceNumber+"/number")).toInt();
  // put your main code here, to run repeatedly:
  if (Serial.available()) {  
    incomingByte = Serial.read(); // read the incoming byte:
    //rdata number
    //incomingByte 0 empty, 1 using
    //Serial.print(incomingByte);
  }
  Serial.println(Firebase.getString(deviceNumber+"/number"));
  Serial.println(rdata);
  delay(500);
}
