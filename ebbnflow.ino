
#include <EEPROM.h>

#include <ESP8266WiFi.h>
#include <PubSubClient.h>


#define PIN_FORWARD D1
#define PIN_BACKWARD D2

void neutral(){
  Serial.println("Neutral");
  digitalWrite(PIN_FORWARD, LOW);
  digitalWrite(PIN_BACKWARD, LOW);
}

void forward(){
  Serial.println("Forward");
  digitalWrite(PIN_BACKWARD, LOW);
  digitalWrite(PIN_FORWARD, HIGH);
}
void backward(){
  Serial.println("Backward");
  digitalWrite(PIN_FORWARD, LOW);
  digitalWrite(PIN_BACKWARD, HIGH);
}


void callback(byte* payload, unsigned int length) {

  Serial.print("Payload: ");
  for(int a=0; a<length; a++){
    Serial.print((char)payload[a]);
  }
  Serial.println();

  switch(payload[0]){

      case 'n': 
      neutral();
      break;

      case 'f':
      forward();
      break;

      case 'b':
      backward();
      break;
  }

}




void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_FORWARD, OUTPUT);
  pinMode(PIN_BACKWARD, OUTPUT);
  
  neutral();


  Serial.begin(115200);
  Serial.println("init");
  
  startWiFi();
  Serial.println("init WiFi");
  
  doOta();
  Serial.println("init OTA");
  

  MQTT_init("ebbnflow", callback);
  Serial.println("init MQTT");
}


long lastMsg = 0;
char msg[50];
int value = 0;

void loop() {
  //Serial.println("loop");
  
  MQTT_loop();
  
}




