// here i m using adrafruit motor shiled u can use any motor drive.
// here will use 3 ir sensor 1- left | 2- centre | 3- Right
#include<AFMotor.h>
AF_DCMotor mtrLeft (1); /// it means we have connect the motor to M1 terminal of motor shield ...
AF_DCMotor mtrRight (2);
int irLeft = A1;
int irCentre = A2;
int irRight = A4;
void setup() {
  // put your setup code here, to run once:
 // initialization of bandrate bcz we serial moniter here ... 
//Serial.begin(9600);
//initialization of pinmode...

pinMode (irLeft, INPUT);
pinMode (irCentre, INPUT);
pinMode (irRight, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int leftSensor = digitalRead(irLeft);// digitalread means it gave 1 or 0...
int centreSensor  = digitalRead(irCentre); 
int rightSensor = digitalRead(irRight);
if((leftSensor == 0) && (centreSensor == 1) && (rightSensor == 0) )
{
  run();
  delay(500);
  accelerate();
   }
  else if ((leftSensor == 1) && (centreSensor == 1) && (rightSensor == 0))
  {
   
    rightTurn();
  }
    else if ((leftSensor == 0) && (centreSensor == 1) && (rightSensor == 1))
  {
      
       leftTurn();
 }
  else if ((leftSensor == 0) && (centreSensor == 0) && (rightSensor == 1))
  {
    leftTurn();
  }
  else if ((leftSensor == 1) && (centreSensor == 0) && (rightSensor == 0))
  {
    
    rightTurn();
  }
   else if ((leftSensor == 0) && (centreSensor == 0) && (rightSensor == 0))
  {
    rotate();
  }
   else if ((leftSensor == 1) && (centreSensor == 1) && (rightSensor == 1))
  {
     stop();
  }


}
// defining the fxn-
 void stop ()
 {
     mtrLeft.run(RELEASE);
     mtrRight.run(RELEASE);
  
  }
 void run ()
 {
      mtrLeft.setSpeed(50);
      mtrLeft.run(FORWARD);
      mtrRight.setSpeed(50);
      mtrRight.run(FORWARD);
  
  }
  void rightTurn ()
 {
      mtrLeft.run(RELEASE);
      mtrRight.setSpeed(40);
      mtrRight.run(FORWARD);
  
  }
   void leftTurn ()
 {
   
     mtrLeft.setSpeed(40);
     mtrLeft.run(FORWARD);
     mtrRight.run(RELEASE);
   
  }
  void accelerate()
  {
    for (int i = 45; i<= 255; i++)
    {
      mtrLeft.setSpeed(i);
      mtrLeft.run(FORWARD);
      mtrRight.setSpeed(i);
      mtrRight.run(FORWARD); 
    }
    }
     
 void rotate ()
 {
     mtrLeft.setSpeed(45);
     mtrLeft.run(FORWARD);
     mtrRight.run(45);
     mtrRight.run(BACKWARD);
  
  }
