// This program shown how to control arduino from PC Via Bluetooth
// Connect ...
// arduino>>bluetooth
// D11   >>>  Rx
// D10   >>>  Tx
//Written By Mohannad Rawashdeh
//for http://www.genotronex.com/

// you will need arduino 1.0.1 or higher to run this sketch

#include <SoftwareSerial.h>// import the serial library
#include <Servo.h> // import the servo library

SoftwareSerial Genotronex(10, 11); // RX, TX
int ledpin=5; // led on D13 will show blink on / off
int servoPin = 3;
int servoPin2 = 6;
int servoPin3 = 9;
int BluetoothData; // the data given from Computer
int angle = 0;
int servoDelay = 10;
Servo servo1;
Servo servo2;
Servo servo3;

void setup() {
  // put your setup code here, to run once:
  Genotronex.begin(9600);
  Genotronex.println("Bluetooth On please press 1 or 0 blink LED ..");
  pinMode(ledpin,OUTPUT);
  servo1.attach(servoPin);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
}

void loop() {
  // put your main code here, to run repeatedly:
   if (Genotronex.available()){
     BluetoothData=Genotronex.read();
     if(BluetoothData=='1'){   // if number 1 pressed ....
       Genotronex.println("Servo 1 is ON! ");
       for(angle = 0; angle < 180; angle++)  
       {                                  
         servo1.write(angle);               
         delay(servoDelay);                   
       }
     }
     
     if(BluetoothData=='2'){   // if number 2 pressed ....
       Genotronex.println("Servo 2 is ON! ");
       for(angle = 0; angle < 180; angle++)  
       {                                  
         servo2.write(angle);               
         delay(servoDelay);                   
       }
     }
     
     if(BluetoothData=='3'){   // if number 3 pressed ....
       Genotronex.println("Servo 3 is ON! ");
       for(angle = 0; angle < 180; angle++)  
       {                                  
         servo3.write(angle);               
         delay(servoDelay);                   
       }
     }
     if (BluetoothData=='0'){// if number 0 pressed ....
       Genotronex.println("Servos are OFF! ");
       for(angle = 180; angle > 0; angle--)    
       {
         servo1.write(angle);
         servo2.write(angle);                     
         servo3.write(angle);           
         delay(servoDelay);       
       } 
    }
  }
delay(100);// prepare for next data ...
}

