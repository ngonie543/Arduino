#include <SoftwareSerial.h>
#define Rx 10 // DOUT to pin 10
#define Tx 11 // DIN to pin 11

SoftwareSerial Xbee (Rx, Tx);

void setup() {
  Serial.begin(9600);
  Xbee.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  pinMode(9, INPUT); //Button Pin
  int RedPin=13;
  int ButtonPin=6;
}
void loop() {


  byte wRight = digitalRead(9);

  if(wRight==0){
  //COMMUNICATION CODE
  int outgoing = 0;
 // if(digitalRead(6) == LOW)
 if(wRight==0){
  
  for (int k=0; k>10; k++){ // If state:1
    outgoing = 'B';  
  }
  }
  
  else{
        outgoing = 'b';  
}
    Xbee.print(outgoing);
    digitalWrite(13, HIGH);
    //Serial.println(outgoing);
  }
  int incoming = 0;
  if(Xbee.available()){
    incoming = Xbee.read();
    Serial.println(incoming);
  }
  int aA=0;
  int bB=0;
  int cC=0;
  int dD=0;
  int eE=0;
  int fF=0;
  if(((incoming == 'A')||(incoming == 'a'))&&(aA==0)){
bool A=isUpperCase(incoming);
digitalWrite(13, LOW);
aA=1;
  }
 else if(((incoming == 'B')||(incoming == 'b'))&&(bB==0)){
bool B=isUpperCase(incoming);
digitalWrite(13, LOW);
bB=1;
  }
  
  else if(((incoming == 'D')||(incoming == 'D'))&&(dD==0)){
bool D=isUpperCase(incoming);
digitalWrite(13, LOW);
dD=1;
  }
  else if(((incoming == 'E')||(incoming == 'e'))&&(eE==0)){
bool E=isUpperCase(incoming);
digitalWrite(13, LOW);
eE=1;
  }
  else if(((incoming == 'F')||(incoming == 'f'))&&(fF==0)){
bool F=isUpperCase(incoming);
digitalWrite(13, LOW);
fF=1;
  }

 int Count1=aA+bB+cC+dD+eE+fF;
// int Count2=A+B+C+D+E+F;

  delay(50);
  digitalWrite(13, LOW);
  Serial.println(Count1);

digitalWrite(4,HIGH);
 SoftwareSerial mySerial = SoftwareSerial(255, 4);
 mySerial.begin(9600);
 delay(100);
 mySerial.write(12);
 delay(5);
 mySerial.write(17);
 mySerial.print(Count1);
 //Serial.print("Magnet is not present.");
 delay(5000);
 mySerial.write(18);

  
  }
