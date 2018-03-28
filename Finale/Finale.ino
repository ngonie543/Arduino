#include <Servo.h>                           // Use the Servo library (included with Arduino IDE)  
Servo servoL;                                // Define the left and right servos
Servo servoR;
// Perform these steps with the Arduino is first powered on


#include <SoftwareSerial.h>
#define Rx 10 // DOUT to pin 10
#define Tx 11 // DIN to pin 11
SoftwareSerial Xbee (Rx, Tx);
int time=millis();




void setup()
{
  Serial.begin(9600);                        // Set up Arduino Serial Monitor at 9600 baud
  servoL.attach(13);                         // Attach (programmatically connect) servos to pins on Arduino
  servoR.attach(12);
  Xbee.begin(9600);
}
void loop()
{
 for(int i = 4; i<8; i++){
     pinMode(i, OUTPUT);
     digitalWrite(i, HIGH);
 }
 delayMicroseconds(230);
 for(int i = 4; i<8; i++){
   pinMode(i, INPUT);
   digitalWrite(i, LOW);
 }
 delayMicroseconds(340);
 int pins = digitalRead(4)+2*digitalRead(5)+4*digitalRead(6)+8*digitalRead(7);                           // Get values of pins D0-D7
 Serial.println(pins);
 int vL, vR, k, d;
 switch(pins)             
 { case 0:                    
     vL = 75;
     vR = 75;
     break;
   case 6:                        
     vL = 75;
     vR = 75;
     break;
   case 9:                        
     vL = 75;
     vR = 75;
     break;
   case 8:                        
     vL = -75;                             // -100 to 100 indicate course correction values
     vR = 75;
     // -100: full reverse; 0=stopped; 100=full forward
     break;
   case 12:                        
     vL = 0;
     vR = 75;
     break;
   case 14:                        
     vL = -50;
     vR = 75;
     break;
   case 7:                        
     vL = 100;
     vR = -75;
     break;
   case 3:                        
     vL = 100;
     vR = -50;
     break;
   case 1:                        
     vL = 75;
     vR = -75;
     break;
   case 15:
     servoL.writeMicroseconds(1500);      // Steer robot to recenter it over the line
     servoR.writeMicroseconds(1500);
     delay(500);
     servoL.writeMicroseconds(1600);      // Steer robot to recenter it over the line
     servoR.writeMicroseconds(1400);
     delay(140);
     break;
   case 10:
     vL = -50;
     vR = 75;
     break;
   case 5:
    vL = 100;
    vR = -75;
    break; 
   case 2:
    vL = 100;
    vR = -75;
    break; 
   case 11:
    delay(500);
  servoL.writeMicroseconds(1400);
  servoR.writeMicroseconds(1400);
  delay(100);
  servoL.writeMicroseconds(1600);
  servoR.writeMicroseconds(1400);
  delay(1500);
  servoL.writeMicroseconds(1500);
  servoR.writeMicroseconds(1500);
  delay(500);

    default:
    vL = 75;
    vR = 75;
    break;
 }
 servoL.writeMicroseconds(1500 + vL);      // Steer robot to recenter it over the line
 servoR.writeMicroseconds(1500 - vR);
 delay(25);


//Serial.println(wRight);

if (digitalRead(9)==LOW){
servoL.detach();
servoR.detach();
while(1){
//digitalWrite (2,HIGH);
//digitalWrite(3,LOW);
Serial.println("YES");
Xbee.print('C');
}
} if(digitalRead(9) == HIGH && time > 17000){
 while(1){
servoL.detach();
servoR.detach();
//digitalWrite (2,HIGH);
//digitalWrite(3,LOW);
Serial.println("NO");
Xbee.print('c');
 }
}
}
