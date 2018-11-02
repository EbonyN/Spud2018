/*************************************************************
* this is the robot base control class which is designed for a 
* four wheel robot construction using an Adafruit_DCMotor controller
* and and arduino Uno 
**************************************************************/
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "PlayerBase.h"
                                                //this has all the moving functions for Spud and what they do
  PlayerBase::PlayerBase(void) { 
      AFMS = Adafruit_MotorShield();
      AFMS.begin();
      myMotorM1 = AFMS.getMotor(1);     
      myMotorM2 = AFMS.getMotor(2);
      myMotorM3 = AFMS.getMotor(3);      
      myMotorM4 = AFMS.getMotor(4);	
      
    	     } 

  void PlayerBase:: stopPlayer(){
      myMotorM1->run(RELEASE); 
      myMotorM2->run(RELEASE); 
      myMotorM3->run(RELEASE); 
      myMotorM4->run(RELEASE);
  }
  void  PlayerBase::stopPlayerAfter(int time){
      delay(time);
      myMotorM1->run(RELEASE); 
      myMotorM2->run(RELEASE); 
      myMotorM3->run(RELEASE); 
      myMotorM4->run(RELEASE);   
  }
	void PlayerBase::movePlayerForward(int inSpeed){
    //Serial.print("In moveForward");Serial.println(inSpeed, DEC);
  	  myMotorM1->setSpeed(inSpeed); 
  	  myMotorM1->run(BACKWARD);
  	  myMotorM2->setSpeed(inSpeed); 
  	  myMotorM2->run(FORWARD);
  	  myMotorM3->setSpeed(inSpeed); 
  	  myMotorM3->run(FORWARD);
  	  myMotorM4->setSpeed(inSpeed); 
  	  myMotorM4->run(BACKWARD);
	  }
	void PlayerBase::movePlayerBackward(int inSpeed){
  	  myMotorM1->setSpeed(inSpeed); 
  	  myMotorM1->run(FORWARD);
  	  myMotorM2->setSpeed(inSpeed); 
  	  myMotorM2->run(BACKWARD);
  	  myMotorM3->setSpeed(inSpeed); 
  	  myMotorM3->run(BACKWARD);
  	  myMotorM4->setSpeed(inSpeed); 
  	  myMotorM4->run(FORWARD);
	  }
	 void PlayerBase::movePlayerLeft(int inSpeed){
  	  myMotorM1->setSpeed(inSpeed); 
  	  myMotorM1->run(FORWARD);
  	  myMotorM2->setSpeed(inSpeed); 
  	  myMotorM2->run(FORWARD);
  	  myMotorM3->setSpeed(inSpeed); 
  	  myMotorM3->run(BACKWARD);
  	  myMotorM4->setSpeed(inSpeed); 
  	  myMotorM4->run(BACKWARD);
	  }
	 void PlayerBase::movePlayerRight(int inSpeed){
  	  myMotorM1->setSpeed(inSpeed); 
  	  myMotorM1->run(BACKWARD);
  	  myMotorM2->setSpeed(inSpeed); 
  	  myMotorM2->run(BACKWARD);
  	  myMotorM3->setSpeed(inSpeed); 
  	  myMotorM3->run(FORWARD);
  	  myMotorM4->setSpeed(inSpeed); 
  	  myMotorM4->run(FORWARD);
	  }
   void PlayerBase::rotatePlayerLeft(int inSpeed){
      myMotorM1->setSpeed(inSpeed); 
      myMotorM1->run(FORWARD);
      myMotorM2->setSpeed(inSpeed); 
      myMotorM2->run(FORWARD);
      myMotorM3->setSpeed(inSpeed); 
      myMotorM3->run(FORWARD);
      myMotorM4->setSpeed(inSpeed); 
      myMotorM4->run(FORWARD);
    }
  void PlayerBase::rotatePlayerRight(int inSpeed){
      myMotorM1->setSpeed(inSpeed); 
      myMotorM1->run(BACKWARD);
      myMotorM2->setSpeed(inSpeed); 
      myMotorM2->run(BACKWARD);
      myMotorM3->setSpeed(inSpeed); 
      myMotorM3->run(BACKWARD);
      myMotorM4->setSpeed(inSpeed); 
      myMotorM4->run(BACKWARD);
    }
   void PlayerBase::moveDiagonallyLeft(int inSpeed){//eb start
    myMotorM1->setSpeed(inSpeed);
    myMotorM1->run(BACKWARD);
    myMotorM2->run(RELEASE);  
    myMotorM3->setSpeed(inSpeed); 
    myMotorM3->run(FORWARD);
    myMotorM4->run(RELEASE);  
   } 
   void PlayerBase::moveDiagonallyRight(int inSpeed){
    myMotorM1->run(RELEASE);  
    myMotorM2->setSpeed(inSpeed); 
    myMotorM2->run(FORWARD);
    myMotorM3->run(RELEASE);  
    myMotorM4->setSpeed(inSpeed); 
    myMotorM4->run(BACKWARD);
   }

   void PlayerBase::movePlayerForward2(int inSpeed, int inSpeed2, int inSpeed3){
    myMotorM1->setSpeed(inSpeed2); 
    myMotorM1->run(BACKWARD);
    myMotorM2->setSpeed(inSpeed); 
    myMotorM2->run(FORWARD);
    myMotorM3->setSpeed(inSpeed3); 
    myMotorM3->run(FORWARD);
    myMotorM4->setSpeed(inSpeed); 
    myMotorM4->run(BACKWARD);
   }

