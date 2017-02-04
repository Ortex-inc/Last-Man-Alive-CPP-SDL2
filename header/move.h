
#ifndef MOVE_H
#define MOVE_H

#include "class.h"
#include "object.h"

///////////////////////////////////////////////////////////////////////
					//	ENEMY MOVE
//////////////////////////////////////////////////////////////////////


	void enemyManager(int max){
int number=0;
srand(time(NULL));
number= rand() % max+1;
		for(int x=0;x<=number;x++){
			zombie.push_back(Enemy("rt",100));
}
}
///////////////////


void intelArt(){


if(me[0].ins.x+me[0].ins.w-zombie[0].ins.x+10<=0){
	//zombie go left

	zombie[0].oriantation=2;
	zombie[0].ins.x-=zombie[0].step/4;
	}
if(me[0].ins.x-(zombie[0].ins.x+zombie[0].ins.w)+10>=0){//go right
	zombie[0].oriantation=4;
	zombie[0].ins.x+=zombie[0].step/4;
	}
if(me[0].ins.y+me[0].ins.h-zombie[0].ins.y-30<=0){
	//go up
	zombie[0].oriantation=1;
	zombie[0].ins.y-=zombie[0].step/4;
	}
	if(me[0].ins.y-(zombie[0].ins.y+zombie[0].ins.h-30)>=0){
	zombie[0].oriantation=3;
	zombie[0].ins.y+=zombie[0].step/4;
	//go down
	}}
#endif
