#include <LoRa.h>
#include <SPI.h>

const int csPin = 7;
const int resetPin = 6;
const int irqPin = 1;

byte localAddress = 0xAA;
byte destinationAddress = 0xBB;

long lastSendTime = 0;
int interval = 200;

//figure out how to say Hello World!

void setup()
{
    Serial.begin(9600);

    LoRa.setPins(csPin, resetPin, irqPin);

    if(!LoRa.begin(915E6)) {
      Serial.println("LoRa init failed.");
      while (true) {}
    }else
      Serial.println("LoRa init succeeded");

}//void setup


void loop(){

  if(millis() - lastSendTime > interval){

    // String sensorData = String(count++);

    sendMessage("Hello World");

    Serial.print("Sending data " + sensorData);
    Serial.print(" from 0x" + String(localAddress,HEX));
    Serial.println(" to 0x" + String(destinationAddress,HEX));


    lastSendTime = millis();

    interval = random(2000) + 1000;

  } //millis

  //receiving

}//void loop


void sendMessage(String outgoing){

  LoRa.beginPacket();

  LoRa.write(destinationAddress);

  LoRa.write(localAddress);

  LoRa.write(outgoing.length());

  LoRa.print(outgoing);

  LoRa.endPacket();

}
