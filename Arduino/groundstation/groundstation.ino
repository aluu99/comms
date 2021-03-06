// Frequency for input and output
const double RFM69_FREQUENCY = 915.0;

// Pins setup for UNO based on recommendations; subject to change
const int LED = 13;
const int RFM95_IRQ = 3; // input pin; must be interrupt-capable pin
const int RFM95_CS = 4; // output pin
const int RFM95_RST = 2; // output pin; used to reset radio at beginning of sketch

// Necessary extra constants; subject to change
const long int SPEED = 9600; // speed in which data will be transferred

long lastSendTime = 0;
int interval = 10000;


RH_RF95 rf95(RFM95_CS, RFM95_IRQ);


void setup()
{
  Serial.begin(SPEED);

  pinmode(LED, OUTPUT);
  pinmode(RFM95_RST, OUTPUT);
  digitalWrite(RFM95_RST, LOW);

  // manual reset
  digitalWrite(RFM95_RST, HIGH);
  delay(10);
  digitalWrite(RFM95_RST, LOW);
  delay(10);

  while(!rf95.init())
  {
    if(millis - lastSendTime > interval)
    {
      Serial.println("RFM95 Radio initialization failed")

    }

  }

}
