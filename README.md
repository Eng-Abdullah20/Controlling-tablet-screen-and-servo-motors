# Controlling-tablet-screen-and-servo-motors
this repository contains hardware and software description with implementation method for controlling tablet screen and servo motors with ultrasonic sensor and bluetooth module

# Hardware Description
In this task, the circuit has been designed to be composed of a 9V DC voltage source to power the circuit, an ultrasonic sensor to measure the distance of the standing user, a Bluetooth module to connect the Arduino to the tablet, a microcontroller (Arduino Uno) and six servo motors tom move the robot arms. 

# Implementation 
To construct the circuit, first connect al servos to the power source (9V battery) and take three servo motors and connect them in parallel to pin 7 and the other three to pin 6. In this construction each three motors are controlling one robot arm. Secondly, connect VCC to the battery, GND to ground and the ultrasonic sensor’s pins Trigger and Echo to pins 3 and 2 respectively. Finally, connect the VCC to the battery, GND with ground and the pins TX and RX to the pins 0 and respectively. *Note connect pins TX and RX after powering the circuit to avoid any errors in the signal sent. 

# Programing Description
The circuit was programmed to send a signal to turn on the screen of the tablet and welcome the user via the Bluetooth module (in this case an LED was used), if the user is standing in the parameter of the ultrasonic sensor for 3 seconds. After that, a signal is sent to the motors will move from initial position 0 degrees to 45 degrees to welcome the user and have his attention. However, if there is no user is standing in the parameter of the ultrasonic sensor, the screen will remain off and the servo motors will remain in the initial position.

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
