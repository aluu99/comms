#include <LoRa.h>
#include <SPI.h>

const int csPin = 7;
const int resetPin = 6;
const int irqPin = 1;
int count = 0;

byte localAddress = 0xBB;
byte destinationAddress = 0xAA;
long lastSendTime = 0;

//figure out how to say Hello World!

// See if our code functions (can transmit & send sensor data)
void fnTest(int recipient, byte sender, byte incomingLength, String incoming);
// prints signal strength
void signalStrengthTest();
//prints signal to noise ratio
void snrTEST();

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
    // receiving
    receiveMessage(LoRa.parsePacket());
}

void receiveMessage(int packetSize) {
    if (packetSize == 0){
      return;
    }

    byte recipient = LoRa.read();
    byte sender = LoRa.read();
    byte incomingLength = LoRa.read();

    String incoming = "";

    while (LoRa.available()) {
      incoming += (char)LoRa.read();
    }

    // Error checking
    fnTest(recipient, sender, incomingLength, incoming);
    // signalStrengthTest(incoming);
    // snrTest(incoming);
}

void fnTest(byte recipient, byte sender, byte incomingLength, String incoming){
  if (incomingLength != incoming.length()) {
    Serial.println("Error: Message length does not match length.");
  }

  if (recipient != localAddress) {
    Serial.println("Error: Recipient address does not match local address.");
  }

  Serial.print("Received data: " + incoming);
  Serial.print(" from 0x" + String(sender, HEX));
  Serial.println(" to 0x" + String(recipient, HEX));
}

void signalStrengthTest(String incoming){
  int rssi = LoRa.packetRssi();

  Serial.println(String(rssi) + ',' + incoming);
}

void snrTest(String incoming){
  int snr = LoRa.packetSnr();

  Serial.println(String(snr) + ',' + incoming);
}
