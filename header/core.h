#ifndef CORE_H
#define CORE_H

#include "object.h"


void dlog(const char* disc){
	msg.clean(disc,15); 
msgbox[0].ins.x=dialog[0].ins.x;
msgbox[0].ins.y=dialog[0].ins.y;


dialog[0].animate(100);
dialog[0].print();
if(!a_pressed){msgbox[0].print();}
}


void main_core(){
start=SDL_GetTicks();
input();

game[0].stat();
if(!game[0].playing){menu_page();SDL_Delay(80);}
else{
game[0].pause();
//gas[0].position(zombie[0].ins.x-gas[0].ins.w/3,zombie[0].ins.y-30);




logic();
intelArt();
collision();
generate();
//if(left_pressed){ Mix_PauseMusic();} else if(right_pressed){Mix_ResumeMusic();}

draw();
animate();

touchPad();

///////////////CHRONO
if(!chrono[0].up){
chrono[0].toTime(mission[0].time);
timer.clean(chrono[0].s.c_str(),45);}
else {timer.clean("Time up",45);}
chrono[0].print();
}
if(!chrono.empty()){
if(chrono[0].minute<=0 && chrono[0].second<=2){
msgbox[0].position(SCREEN_WIDTH/2-msg.surface->w/2,SCREEN_HEIGHT/2-msg.surface->h/2);
msgbox[0].print();
}
}
//dlog("SALUT ! mes nounours! press ('A' to continue)");
if(collision()){zombie[0].init=true;zombie[0].wlk=false;zombie[0].attack();}


}


#endif
