
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiManager.h>

unsigned int localPort = 8888;

WiFiUDP     Udp;

void startWiFi(){
  
    WiFiManager wifiManager;

    String ssid = "EbbNFlow-" + String(ESP.getChipId());
    wifiManager.autoConnect(ssid.c_str());
  
    Serial.println("Connected!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println("Starting UDP");
    Udp.begin(localPort);
    
}
