#ifndef PLAYERPIXY_H
#define PLAYERPIXY_H

#include <SPI.h>  
#include <Pixy2.h>

class PlayerPixy{
  
  public:

  Pixy2 myPixy;
  uint16_t blocks;
      
  
  int ballX();
  int ballY();
  int yellowGoalX();
  int blueGoalX();
  
  int ballArea();
  int blueGoalArea();
  int yellowGoalArea();
  
  int ballPosition();
  int blueGoalPosition();
  int yellowGoalPosition();

  int ballAge();
  int blueGoalAge();
  int yellowGoalAge();
  int ballIndex();

  bool ballSeen();
  bool blueGoalSeen();
  bool yellowGoalSeen();

  void getData();
  void lightsOn();
  void lightsOff();

  PlayerPixy();

};

#endif 
