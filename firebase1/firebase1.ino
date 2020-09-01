

#include "FirebaseESP8266.h"


#include <ESP8266WiFi.h>
// defining the tocken and wifi passworld //
#define FIREBASE_HOST "automation-fdf49.firebaseio.com"
#define FIREBASE_AUTH "xxxxxxxxxxxxxxxxxxxxxxx"
#define WIFI_SSID "Shreenidhi"
#define WIFI_PASSWORD "97388624188884176800"

#define Relay1 2
String rel1;
  FirebaseData firebaseData; // declaring a variable //
void setup() {
  Serial.begin(115200);                                                   // Select the same baud rate if you want to see the datas on Serial Monitor
  pinMode(Relay1,OUTPUT);
   
   WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected:");
  Serial.println(WiFi.localIP());
   Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
Firebase.setInt( firebaseData, "ledcontroll",0);    
  
  
  // put your setup code here, to run once:

}

void loop() {
 
 Firebase.getString(firebaseData, "ledcontroll/led");  //Reading the value of the varialble Status from the firebase
rel1=firebaseData.stringData();
delay(1100);
 if(rel1 == "0")                                                             // If, the Status is 1, turn on the Relay1
     {
      digitalWrite(Relay1,LOW);
     delay(1000);
    }
 if(rel1== "1")                                                      // If, the Status is 0, turn Off the Relay1
    {                                      
      digitalWrite(Relay1,HIGH);
      delay(1000);
    }  // put your main code here, to run repeatedly:

}
