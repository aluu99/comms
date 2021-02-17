#include <RH_RF95.h>

// Pins setup for Mega based on recommendations; subject to change
const int RFM69_INT = 3;
const int RFM69_CS = 4;
const int RFM69_RST = 2;


// Frequency for input and output
const double RFM69_FREQUENCY = 915.0;

//Amanda's Board
// Pins setup for UNO based on recommendations; subject to change
const int LED = 13;
const int IRQPin = 0; // input pin; must be interrupt-capable pin
const int RFM95_CS = 7; // output pin
const int RFM95_RST = 6; // output pin; used to reset radio at beginning of sketch

// Necessary extra constants; subject to change
const long int baudrate = 9600; // speed in which data will be transferred

long lastSendTime = 0;
int interval = 10000;


RH_RF95 rf95(RFM95_CS, RFM95_IRQ);

//figure out how to say Hello World!

//init()
//available()
//setFrequency()
//send()
//setModeTx()
//setTxPower()
//sleep()
//isChannelActive()
//maxMessageLength()
//lastSNR()
//frequencyError()
// setSpreadingFactor()
// setSignalBandwidth()

void setup()
{
	  Serial.begin(baudrate);

    //set I/Os
  	pinmode(LED, OUTPUT);
  	pinmode(RFM95_RST, OUTPUT);

  	// manual reset
  	digitalWrite(RFM95_RST, HIGH);
  	delay(10);
  	digitalWrite(RFM95_RST, LOW);
  	delay(10);

    do{
			Serial.println("RFM95 Radio initialization failed\n");
		}while(!rf95.init());

    Serial.println("RFM95 Radio initialized!\n");


}//void setup
