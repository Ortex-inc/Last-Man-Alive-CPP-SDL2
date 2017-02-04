#ifndef ANIMATE_H
#define ANIMATE_H
#include "object.h"


void animate(){
if(!bloodi.empty()){
	if(collision()){
if(bloodi[0].ins.x<=SCREEN_WIDTH || bloodi[0].ins.y<=SCREEN_HEIGHT){
bloodi[0].animate();
bloodi[0].print(1);
}
}
}



if(!zombie.empty()){

//~ if(zombie[0].old_oriantation!=zombie[0].oriantation){
//~ zombie[0].old_oriantation=zombie[0].oriantation;
//~ std::cout<<"oriantation changed!!"<<std::endl;
//~ }

if(zombie[0].ins.x<=SCREEN_WIDTH || zombie[0].ins.y<=SCREEN_HEIGHT){
	SDL_Delay(60);
zombie[0].attack();
}
}
}

void cursor_handle(){
	if(!cr.empty()){
if(cr[0].ins.x<=SCREEN_WIDTH || cr[0].ins.y<=SCREEN_HEIGHT){
cr[0].position(hvX,hvY);

//cr[0].animate();

}
cr[0].print();
}

	
}
#endif
