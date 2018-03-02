#include <IRremote.h>
const int light = 13;
int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(light,OUTPUT);  
}

void loop() {
  if (irrecv.decode(&results)) {
    int data = (results.value);
    irrecv.resume();
    int d = abs(data);
    Serial.println(d);
    switch(d){
      case 18615:
            digitalWrite(light,HIGH);
            Serial.println("on");
            break;
      case 19492:
            digitalWrite(light,LOW);
            Serial.println("off");
            break;
  }
  }
  delay(100);
}
