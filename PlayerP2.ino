//for pixy: ball signature is 1, goal (which we are aiming for) signature is 2, our goal (which we are defending) signature is 3
//for pixy positions: 1 if left, 2 is middle, 3 is right, -1 is else
#include "PlayerBase.h"
#include "PlayerPixy.h"




//REMEMBER TO CHANGE BOARD!!!!!!!!!!!!!

//pixy2 https://docs.pixycam.com/wiki/doku.php?id=wiki:v2:hooking_up_pixy_to_a_microcontroller_-28like_an_arduino-29

PlayerBase *base;
PlayerPixy *pixy;

 int goal;
 int ballX;
 int ballAge;
 int ballArea;
 int ballPosition;
 int ballY;
 int blueGoalX; 
 int yellowGoalX;
 int previousBallX;
 bool ballRepeat;
 bool blueGoalRepeat;
 bool yellowGoalRepeat;
 int previousBallAge;
 int previousBlueGoalAge;
 int previousYellowGoalAge;
 
  



void setup(){
    base = new PlayerBase();
    pixy = new PlayerPixy();
    base->AFMS.begin();
    ballRepeat = false;
    blueGoalRepeat = false;
    yellowGoalRepeat = false;
    ballAge = 0;
    previousBallAge = 0;
    previousBlueGoalAge= 0;
    previousYellowGoalAge= 0;

    goal = 1; //put in 1(blue), 2(yellow) or 3(none) for which goal we are going towards
    
    Serial.begin(9600);
  
    
    }


/***********************************************************************

void circleBall(int count){
  for(count=0;count<5;count++){
  base->movePlayerLeft(base->MAX_SPEED);
  delay(300);
  base->rotatePlayerLeft(base->THREE_QUARTER_SPEED);
 delay(300);
  }
   base->stopPlayerAfter(10);
 }


***********************************************************************

if(previousBallAge<ballAge || previousBallAge>ballAge){      //working test for repeat
    previousBallAge = ballAge;
    repeat = false;
    Serial.println("repeat false");
  }
else{
    repeat = true;
    Serial.println("repeat true");
  }

***********************************************************************/
  
  
void loop(){


  
//REMEMBER TO CHANGE BOARD!!!!!!!!!!!!!


    int ballAge = pixy->ballAge();                              //assigning values every loop so that you don't have to repeatedly get values for things throughout the code
    int ballX = pixy->ballX();
    int ballY = pixy->ballY();
    int blueGoalX = pixy->blueGoalX();
    int yellowGoalX = pixy->yellowGoalX();
    int ballPosition = pixy->ballPosition();
    int blueGoalPosition = pixy->blueGoalPosition();
    int yellowGoalPosition = pixy->yellowGoalPosition();
    int blueGoalAge = pixy->blueGoalAge();
    int yellowGoalAge = pixy->yellowGoalAge();

    //Serial.println(pixy->ballAngle());
    //pixy->lightsOff();
    
   if(previousBallAge<ballAge || previousBallAge>ballAge){      //this piece of codes tests if the value recieved for ballAge is the same as the previous value recieved
    previousBallAge = ballAge;                                  //if it is, the ball is out of pixy's view
    ballRepeat = false;
    pixy->lightsOff();
   }
   else{
    ballRepeat = true;
    pixy->lightsOn();
   }

   if(previousBlueGoalAge<blueGoalAge || previousBlueGoalAge>blueGoalAge){     //this piece of codes tests if the value recieved for blueGoalAge is the same as the previous value recieved
    previousBlueGoalAge= blueGoalAge;
    blueGoalRepeat = false;
    pixy->lightsOff();
   }
   else{
    blueGoalRepeat = true;
    pixy->lightsOn();
   }

   
   if(previousYellowGoalAge<yellowGoalAge || previousYellowGoalAge>yellowGoalAge){   //this piece of codes tests if the value recieved for yellowGoalAge is the same as the previous value recieved
    previousYellowGoalAge= yellowGoalAge;
    yellowGoalRepeat = false;
    pixy->lightsOff();
   }
   else{
    yellowGoalRepeat = true;
    pixy->lightsOn();
   }

   


 
switch(goal){                                            //a switch is used so that only one program is needed for each diferent scenario of goals
  
  case 1:                                                //case 1 = we are going towards BLUE goal
     if(ballRepeat == true){                             //if ballRepeat is true, it means that the ball has gone out of the pixy's field of view and we need to rotate
      Serial.println("ballRepeat = true");
      if(ballX<158){                                 
        base->rotatePlayerLeft(base->MAX_SPEED);
      }
      if(ballX>157){
        base->rotatePlayerRight(base->MAX_SPEED);
      }
     }
     else{                                              //if ballRepeat is not true, the robot is seeing the ball so we need to drive towards it
      Serial.println("ballRepeat = false");
      if(ballPosition == 1){                             //each ball position (1,2,3) is a different range of X values (check PlayerPixy.cpp for exact ranges) 
        Serial.println("ball to left");
        base->rotatePlayerLeft(base->MAX_SPEED);        
      }
      if(ballPosition = 2){                             //if we have the ball in middle, we then need to get it in the goal
        Serial.println("ball to middle");
        if(ballY<80){
        if(blueGoalRepeat = false){                                      //is the blueGoalRepeat is false, then we are seeing the goal
         if(blueGoalPosition == 2){                                      //if the goal is in the middle, then move forward                 
            base->movePlayerForward(base->MAX_SPEED);
           Serial.print("  goal seen  "); //Serial.println(blueGoalX); 
          }
          if(blueGoalPosition == 1){                                     //if the goal is to the left, move around the ball
             Serial.println("goal to left");
           for(int a=0; a<35; a++){
             base->movePlayerForward(base->MAX_SPEED);
            }
           for(int a=0; a<30; a++){
             base->rotatePlayerLeft(base->THREE_QUARTER_SPEED);
            }    
          }
          if(blueGoalPosition == 3){                                     //if the goal is to the right, move around the bal
            Serial.println("goal to right");
           for(int a=0; a<35; a++){
             base->movePlayerForward(base->MAX_SPEED);
            }
           for(int a=0; a<35; a++){
             base->rotatePlayerRight(base->THREE_QUARTER_SPEED);
            } 
          }
        }
        else{                                                               //if we don't see the goal
          Serial.println("blueGoalRepeat = true, no goal seen"    ) ;
        }
        }
        else{
          base->movePlayerForward(base->MAX_SPEED);
        }
      }
      if(ballPosition == 3){                                                //if the ball is to the right, rotate                                                
        base->rotatePlayerRight(base->MAX_SPEED);
        Serial.println("ball to right");
      }
      else{
        base->rotatePlayerRight(base->MAX_SPEED);
      }
     }
  break;

   
  case 2:                                           //case 2 = we are going towards YELLOW goal
                                                    //this case is the same as case 1, except the blue goal has been changed to the yellow goal since we are going the other way
     if(ballRepeat == true){                                
      if(ballX<158){
        base->rotatePlayerLeft(base->MAX_SPEED);
      }
      if(ballX>157){
        base->rotatePlayerRight(base->MAX_SPEED);
      }
     }
     else{                                              
      Serial.println("ballRepeat = false");
      if(ballPosition == 1){                             
        Serial.println("ball to left");
        base->rotatePlayerLeft(base->MAX_SPEED);        
      }
      if(ballPosition = 2){                            
        Serial.println("ball to middle");
        if(ballY<80){
         if(yellowGoalPosition == 2){                      
            base->movePlayerForward(base->MAX_SPEED);
           Serial.print("  goal seen  "); //Serial.println(blueGoalX); 
          }
          if(yellowGoalPosition == 1){
             Serial.println("goal to left");
           for(int a=0; a<35; a++){
             base->movePlayerForward(base->MAX_SPEED);
            }
           for(int a=0; a<30; a++){
             base->rotatePlayerLeft(base->THREE_QUARTER_SPEED);
            }    
          }
          if(yellowGoalPosition == 3){
            Serial.println("goal to right");
           for(int a=0; a<35; a++){
             base->movePlayerForward(base->MAX_SPEED);
            }
           for(int a=0; a<35; a++){
             base->rotatePlayerRight(base->THREE_QUARTER_SPEED);
            } 
          }
          else{
            Serial.println("no goal seen");
          }
        }
        else{
          base->movePlayerForward(base->MAX_SPEED);
        }
      }
      if(ballPosition == 3){
        base->rotatePlayerRight(base->MAX_SPEED);
        Serial.println("ball to right");
      }
      else{
        base->rotatePlayerRight(base->MAX_SPEED);
      }
     }
  break;


      
  case 3:                                               //case 3 = for NO goal, only follow ball
                                                        //this case is different alltogether because we are not using the goals at all, only following the ball
     if(ballRepeat == true){                            //if ballRepeat is true, it means that the ball has gone out of the pixy's field of view and we need to rotate                               
      if(ballX<158){
        base->rotatePlayerLeft(base->MAX_SPEED);
      }
      if(ballX>157){
        base->rotatePlayerRight(base->MAX_SPEED);
      }
     }
     else{                                              //if ballRepeat is not true, the robot is seeing the ball so we need to drive towards it                                          
      if(ballPosition == 1){                            
        base->rotatePlayerLeft(base->MAX_SPEED);       
      }
      if(ballPosition == 2){
        base->movePlayerForward2(base->MAX_SPEED, base->HALF_SPEED, base->THREE_QUARTER_SPEED);
      }
      if(ballPosition == 3){
        base->rotatePlayerRight(base->MAX_SPEED);
      }
      else{
        base->rotatePlayerRight(base->MAX_SPEED);
      }
     }
 break;

 default:
     base->stopPlayer();
     Serial.println("error...no goal inputed");
    }
    

}
  
}
}
      
    /*

   base->movePlayerForward(base->MAX_SPEED);            //these are some of the main functions to make the robot move
   base->movePlayerBackward(base->MAX_SPEED);
   base->movePlayerRight(base->HALF_SPEED);
   base->movePlayerLeft(base->MAX_SPEED);
   base->rotatePlayerRight(base->MIN_SPEED);
   base->rotatePlayerLeft(base->HALF_SPEED);
   base->stopPlayerAfter(1000)
   base->moveDiagonallyLeft(base->MIN_SPEED);
   delay(5000);

    */
  
 
