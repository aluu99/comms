#include <LoRa.h>
#include <SPI.h>

const int csPin = 7;
const int resetPin = 6;
const int irqPin = 1;

byte localAddress = 0xAA;
byte destinationAddress = 0xBB;

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




}
