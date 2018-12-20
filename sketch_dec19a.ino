#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>
#include <ESP8266WiFi.h>


#define WIFI_SSID       "PserLvlNA"
#define WIFI_PASSWORD   "ghosterhtd"
#define FIREBASE_HOST "wio-link-d6bXX.firebaseio.com"
#define FIREBASE_AUTH "qUohEtHyvCcOzgxq95ZheaVsaMePi2P5FDd8XXXX"

const int ledPin = 14;
int incomingByte = 0;
int rdata = 0 ;
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
  Firebase.setInt("LED", 0);



}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    

    incomingByte = Serial.read(); // read the incoming byte:
    if(incomingByte == 1){
      
      rdata = 0;
     
    }
    else {
      rdata = 3;
    }

    //Serial.print(incomingByte);

  }
   Serial.print(rdata);
  //Serial.write(rdata);
  //digitalWrite(ledPin, Firebase.getInt("LED"));
  delay(500);


}
