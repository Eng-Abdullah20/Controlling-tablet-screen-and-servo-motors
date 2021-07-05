// include Servo Library
#include <SoftwareSerial.h> // include the library for bluetooth module
#include <Servo.h> // include the library for servo motors

SoftwareSerial Myserial(0,1); //Tx=0, Rx=1 // declare pins for bluetooth module
//Define the servos
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

// define ultrasonic pins on the arduino board
int trigger=3;
int echo=2;

// define duration and distance variables 

long duration;
long distance;


int LED=8;

void setup() {  
Myserial.begin(9600);  
pinMode(trigger,OUTPUT);
pinMode(echo, INPUT); 
pinMode(LED, OUTPUT);
servo1.attach(7);
servo2.attach(7);
servo3.attach(7);
servo4.attach(6);
servo5.attach(6);
servo6.attach(6);
}

void loop (){
  
// in this loop the LED and servos will be enabled based on the signal recieved from the ultrasonic sensor. If the ultrasonic sensor senses a standing object for 3 secs, it will send a signal to the servos to move from the intial point in an angle of 45 and the signal will be saved in the bluetooth to be sent to turn on the screen (in this case it is the LED)
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
delayMicroseconds(10);

duration=pulseIn(echo,1);
distance=(duration*0.034)/2;

  if(distance<=30){
    Myserial.available();
 
    digitalWrite(LED,1);//in this case LED is the screen

    int pos =45;
   
          servo1.write(pos);              // tell servo to go to position in variable 'pos'
          delay(500);
          
          servo2.write(pos);
          delay(500);
         
          servo3.write(pos);             
          delay(500);
         
          servo4.write(pos);
          delay(500);
          servo5.write(pos);              
          delay(500);
          servo6.write(pos);
          delay(500);
    
         
   }
  


  if(distance >30){  //if there is no standing object sesnsed by the ultrasonic the servos will return to the intial position and the screen will remain off
    
    digitalWrite(LED, LOW);
    Myserial.available();
    int pos0=0;
      
          servo1.write(pos0);              // tell servo to go to position in variable 'pos0'
          delay(500);
         
          servo2.write(pos0);
          delay(500);
          
          servo3.write(pos0);              
          delay(500);
         
          servo4.write(pos0);
          delay(500);
          
          servo5.write(pos0);              
          delay(500);
          
          servo6.write(pos0);
          delay(500);
    
    }
  
 
  }
