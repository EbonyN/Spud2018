#ifndef ROBOTBASE_H
#define ROBOTBASE_H

#include <Wire.h>
#include <Adafruit_MotorShield.h>

	class PlayerBase{
  
		public:
			const int MAX_SPEED = 255;
			const int THREE_QUARTER_SPEED = 190;
			const int HALF_SPEED = 127;
			const int QUARTER_SPEED = 90;
			const int MIN_SPEED = 30;
      Adafruit_MotorShield AFMS; 
     
			PlayerBase();
			
			void movePlayerForward(int inSpeed);
      void movePlayerForward2(int inSpeed, int inSpeed2, int inSpeed3);
			void movePlayerBackward(int inSpeed);
			void movePlayerLeft(int inSpeed);
			void movePlayerRight(int inSpeed);
			void rotatePlayerRight(int inSpeed);
			void rotatePlayerLeft(int inSpeed);
      void moveDiagonallyRight(int inSpeed);
      void moveDiagonallyLeft(int inSpeed);
			void stopPlayerAfter(int time);
      void stopPlayer();

	protected:      
			Adafruit_DCMotor *myMotorM1;
			Adafruit_DCMotor *myMotorM2;
			Adafruit_DCMotor *myMotorM3;
			Adafruit_DCMotor *myMotorM4;

			
	};
#endif

