#include <SPI.h>  
#include <Pixy2.h>
#include"PlayerPixy.h"

//yellow goal = signature 3
//blue goal = signature 2
//ball = signature 1
                                               //this has all the different functions for the pixy on spud, and what they do
PlayerPixy::PlayerPixy(void) {
  myPixy.init();
 }

void PlayerPixy::getData(){  
  blocks = myPixy.ccc.getBlocks();  

 } 

void PlayerPixy::lightsOn(){
  myPixy.setLamp(true,true); 
}

void PlayerPixy::ballAngle(){
   getData();
 if (blocks){      
      for (int j=0; j<blocks; j++){        
        if (myPixy.ccc.blocks[j].m_signature == 12){
           return pixy.ccc.blocks[12].m_angle 
        }
         else{
          return -1;
        }
      }
 }
}

void PlayerPixy::lightsOff(){
  myPixy.setLamp(false,false); 
}

int PlayerPixy::ballAge(){
  getData();
 if (blocks){      
      for (int j=0; j<blocks; j++){        
        if (myPixy.ccc.blocks[j].m_signature == 1){
          return myPixy.ccc.blocks[j].m_age;
        }
        else{
          return -1;
        }
      }
 }
}

int PlayerPixy::blueGoalAge(){
  getData();
 if (blocks){      
      for (int j=0; j<blocks; j++){        
        if (myPixy.ccc.blocks[j].m_signature == 2){
          return myPixy.ccc.blocks[j].m_age;
        }
        else{
          return -1;
        }
      }
 }
}

int PlayerPixy::yellowGoalAge(){
  getData();
 if (blocks){      
      for (int j=0; j<blocks; j++){        
        if (myPixy.ccc.blocks[j].m_signature == 3){
          return myPixy.ccc.blocks[j].m_age;
        }
        else{
          return -1;
        }
      }
 }
}

int PlayerPixy::ballIndex(){
   getData();
 if (blocks){      
      for (int j=0; j<blocks; j++){        
        if (myPixy.ccc.blocks[j].m_signature == 1){
          return myPixy.ccc.blocks[j].m_index;
        }
        else{
          return -1;
        }
        }
}
}


bool PlayerPixy::ballSeen(){
  getData();
  if(blocks){
    for (int j=0; j<blocks; j++){
    if (myPixy.ccc.blocks[j].m_signature == 1) {
      return true;
    }
    else{
      return false;
    }
  }
}
else{
  return false;
}
}

bool PlayerPixy::blueGoalSeen(){
  getData();
  if(blocks){
    for (int j=0; j<blocks; j++){
    if (myPixy.ccc.blocks[j].m_signature == 2) {
      return true;
    }
    else{
      return false;
    }
  }
}
else{
  return false;
}
}

bool PlayerPixy::yellowGoalSeen(){
  getData();
  if(blocks){
    for (int j=0; j<blocks; j++){
    if (myPixy.ccc.blocks[j].m_signature == 3) {
      return true;
    }
    else{
      return false;
    }
  }
}
else{
  return false;
}
}


int PlayerPixy::ballArea(){
   getData();
	if (blocks){  
    for (int j=0; j<blocks; j++){
    if (myPixy.ccc.blocks[j].m_signature == 1) {     
        return myPixy.ccc.blocks[j].m_width*myPixy.ccc.blocks[j].m_height;   
		}
	}
	}else{
			return -1;
		}	
}

int PlayerPixy::blueGoalArea(){
   getData();
  if (blocks){      
      for (int j=0; j<blocks; j++){  
      if (myPixy.ccc.blocks[j].m_signature == 2) {
        return myPixy.ccc.blocks[j].m_width*myPixy.ccc.blocks[j].m_height;   
    }
   }
  }else{
      return -1;
    } 
}

int PlayerPixy:: yellowGoalArea(){
   getData();
  if (blocks){      
      for (int j=0; j<blocks; j++){  
        if (myPixy.ccc.blocks[j].m_signature == 3) {
        return myPixy.ccc.blocks[j].m_width*myPixy.ccc.blocks[j].m_height;   
        }
    }
  }else{
      return -1;
    } 
}

int PlayerPixy::ballY(){
  getData();
  if (blocks){      
      for (int j=0; j<blocks; j++){        
        if (myPixy.ccc.blocks[j].m_signature == 1) {
        return myPixy.ccc.blocks[j].m_y;  
        } 
        else{
          return 0;
        }
    }
    }else{
      return -1;
    } 
  }


int PlayerPixy::ballX(){               //test this one
  getData();
	if (blocks){      
      for (int j=0; j<blocks; j++){        
          if(myPixy.ccc.blocks[j].m_x != -1 && myPixy.ccc.blocks[j].m_x != 0){
        return myPixy.ccc.blocks[j].m_x;  
        }
        }
		}
		}
	

 int PlayerPixy::blueGoalX(){
  getData();
 if (blocks){      
      for (int j=0; j<blocks; j++){        
        if (myPixy.ccc.blocks[j].m_signature == 2) {
        return myPixy.ccc.blocks[j].m_x;   
      }
     }
    }else{
      return -1;
    } 
  }

int PlayerPixy::yellowGoalX(){
  getData();
 if (blocks){      
      for (int j=0; j<blocks; j++){        
        if (myPixy.ccc.blocks[j].m_signature == 3) {
        return myPixy.ccc.blocks[j].m_x;   
      }
     }
    }else{
      return -1;
    } 
  }


int PlayerPixy::ballPosition(){
  getData();
  if (blocks){
    for (int j=0; j<blocks; j++){        
        if (myPixy.ccc.blocks[j].m_signature == 1) {        
    if(myPixy.ccc.blocks[j].m_x > 0 && myPixy.ccc.blocks[j].m_x < 120){
      return 1;      
    }if(myPixy.ccc.blocks[j].m_x > 119 && myPixy.ccc.blocks[j].m_x < 180){    //in middle
      return 2;
    }if(myPixy.ccc.blocks[j].m_x > 179){
      return 3;
    }
        }
          else{
  return -1;
 }
}
}
}


int PlayerPixy::blueGoalPosition(){
  getData();
  if (blocks){
    for (int j=0; j<blocks; j++){        
    if (myPixy.ccc.blocks[j].m_signature == 2) {        
    if(myPixy.ccc.blocks[j].m_x > 0 && myPixy.ccc.blocks[j].m_x < 81){
      return 1;      
    }if(myPixy.ccc.blocks[j].m_x > 80 && myPixy.ccc.blocks[j].m_x < 280){
      return 2;
    }if(myPixy.ccc.blocks[j].m_x > 279){
      return 3;
    }
        }
        else{
  return -1;
}
 }
}
}

int PlayerPixy::yellowGoalPosition(){
   getData();
  if (blocks){   
    for (int j=0; j<blocks; j++){        
    if (myPixy.ccc.blocks[j].m_signature == 3) {     
    if(myPixy.ccc.blocks[j].m_x > 0 && myPixy.ccc.blocks[j].m_x < 120){
      return 1;      
    }if(myPixy.ccc.blocks[j].m_x > 119 && myPixy.ccc.blocks[j].m_x < 180){
      return 2;
    }if(myPixy.ccc.blocks[j].m_x > 179){
      return 3;
    }
}else{
  return -1;
 }
}
  }
  else{
    return -1;
  }
 
}
