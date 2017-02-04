#ifndef GAME_H
#define  GAME_H

#include "object.h"


	

void Game::stat(){
	//INIT
if(mission.empty()){mission.push_back(Mission());}
	if(game.empty()){game.push_back(Game());}
//PAUSE
	else if(game[0].paused || paused ){
		if(playing){game[0].pause();}}
	//	//DEATH TRY AGAIN
if(me[0].life<=0 && playing){game[0].tryAgain();}
	}
	
	void Game::tryAgain(){

	while(playing && me[0].life<=0){

	msg.clean("Game Over",75); 
	msgbox[0].position(SCREEN_WIDTH/2-msg.surface->w/2,SCREEN_HEIGHT/2-msg.surface->h/2);

	input();
			msgbox[0].print();
			option[6].print();
			option[5].print();
			//or return home
			option[5].onClick();
			option[6].onClick();
				
	update();
	SDL_Delay(100);
			if(option[6].clicked){
				init_src();game[0].playing=false;game[0].paused=false;}
			if(option[5].clicked){
				game[0].playing=false;game[0].paused=false;msg.clean("`",1);init_src();main_core();
				}	
}
	}
	
	

void Game::newGame(){
//OBJECTS
init_src();
	std::string num;
	mission[0].loadMission(1);

	num=std::string("Mission: ")+std::string("1");
if(music){soundTrack(mission[0].music.c_str());}
if(mission[0].dark!="none"){
	torch.push_back(Torch());
	torch[0].position(0,0);
torch[0].size(dark.surface->w/3+(150/2),dark.surface->h/3,SCREEN_WIDTH,SCREEN_HEIGHT);
}
if(chrono.empty()){
chrono.push_back(T());
chrono[0].position(SCREEN_WIDTH/2-timer.surface->w,0);
}

	msg.clean(num.c_str(),70);

playing=true;
	}



void Game::loadGame(){
	init_src();
	std::string num;
	mission[0].currMission();
	num=std::string("Mission: ")+std::string(mission[0].path);
mission[0].loadMission(atoi(mission[0].path));
if(music){soundTrack(mission[0].music.c_str());}
if(mission[0].dark!="none"){
	torch.push_back(Torch());
	torch[0].position(0,0);
torch[0].size(dark.surface->w/3+(150/2),dark.surface->h/3,SCREEN_WIDTH,SCREEN_HEIGHT);
}
if(chrono.empty()){
chrono.push_back(T());
chrono[0].position(SCREEN_WIDTH/2-timer.surface->w,0);
}
	chrono[0].second=0;
	chrono[0].minute=0;
	playing=true;


	msg.clean(num.c_str(),70);

	}
	
	
	
	
	
	
	void Game::clean(){
	unsigned int i=0;
	if(!me.empty()){for(i=0;i<me.size();i++){SDL_DestroyTexture(me[i].texture);}}
	if(!zombie.empty()){for(i=0;i<zombie.size();i++){SDL_DestroyTexture(zombie[i].texture);}}
	if(!bloodi.empty()){	for(i=0;i<bloodi.size();i++){SDL_DestroyTexture(bloodi[i].texture);}}

	if(!panel.empty()){for(i=0;i<panel.size();i++){SDL_DestroyTexture(panel[i].texture);}}
	if(!gas.empty()){for(i=0;i<gas.size();i++){SDL_DestroyTexture(gas[i].texture);}}
	if(!fire.empty()){for(i=0;i<fire.size();i++){SDL_DestroyTexture(fire[i].texture);}}
	if(!explosion.empty()){for(i=0;i<explosion.size();i++){SDL_DestroyTexture(explosion[i].texture);}}
	if(!homy.empty()){for(i=0;i<homy.size();i++){SDL_DestroyTexture(homy[i].texture);}}
	if(!torch.empty()){	for(i=0;i<torch.size();i++){SDL_DestroyTexture(torch[i].texture);}}
	if(!map.empty()){for(i=0;i<map.size();i++){SDL_DestroyTexture(map[i].texture);}}
//
SDL_DestroyRenderer(screen);
SDL_DestroyWindow(window);
SDL_Quit();
	}





void Game::pause(){
	if(escape_pressed && playing){
	escape_pressed=false;
	paused=true;}

while(paused){
	//option menu must be added
	if(paused){button[5].size(320,140,100,100);}
  


	btnX=-1;btnY=-1;
		

	input();
	msg.clean("PAUSE",70);
	msgbox[0].position(SCREEN_WIDTH/2-msg.surface->w/2,SCREEN_HEIGHT/2-msg.surface->h/2);
	msgbox[0].print();
	button[5].print();
	option[5].print();

	option[5].onClick();
	button[5].onClick();
		btnX=-1;btnY=-1;
	if(button[5].clicked ){escape_pressed=false;paused=false;
		if(!paused){button[5].size(220,140,100,100);}else if(paused){button[5].size(320,140,100,100);}break;}
	if(option[5].clicked ){game[0].playing=false;game[0].paused=false;break;}
	update();}
	}
	
	
	void Game::getSetting(){
			getParam("option.lma");
		music=atoi(value[0].c_str());
		effect=atoi(value[1].c_str());
		}
		
void Game::setting(){
	bool edited=false;
	while(1){

	

if(under_option.empty()){
		under_option.push_back(Menu("Sound","font/font.ttf",30,'t',false));
		under_option.push_back(Menu("Fx","font/font.ttf",30,'t',false));
		}
		
		msg.clean("OPTION",70);
	msgbox[0].position(SCREEN_WIDTH/2-msg.surface->w/2,0);
	msgbox[0].print();

input();
under_option[0].position(SCREEN_WIDTH/2-under_option[0].surface->w/2,150);
under_option[1].position(SCREEN_WIDTH/2-under_option[1].surface->w/2,200);
under_option[0].onClick();
under_option[1].onClick();
option[5].onClick();  
btnX=-1;btnY=-1;               
//~ 
if(option[5].clicked){
game[0].playing=false;game[0].paused=false;msg.clean("`",1);
option[5].clicked=false;option[2].clicked=false;break;
}

if(under_option[0].clicked){edited=true;
	if(game[0].music){game[0].music=false;}
	else{game[0].music=true;}
	std::cout<<game[0].music<<std::endl;
	under_option[0].clicked=false;
}
if(under_option[1].clicked){edited=true;
	if(game[0].effect){game[0].effect=false;}
	else{game[0].effect=true;}
	std::cout<<game[0].effect<<std::endl;
under_option[1].clicked=false;
}		

under_option[0].print();
under_option[1].print();
option[5].print();


if(edited){syncParam("option.lma",music,effect);}
	update();
}
	}
	


#endif
