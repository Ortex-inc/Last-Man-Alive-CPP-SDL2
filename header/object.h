#ifndef OBJECT_H
#define OBJECT_H

#include "class.h"
//Game
 std::vector <Game> game;
//Chars
std::vector <Hero> me;
std::vector <Homy> homy;
std::vector <Enemy> zombie;
//Map
std::vector <Map> map;
//Panels
std::vector <Panel> panel;
//Effects
std::vector <Blood> bloodi;
std::vector <Fire> fire;
std::vector <Gas> gas;
std::vector <Explosion> explosion;
std::vector <Torch> torch;
std::vector <Potion> potion;
std::vector <Box> box;
//Texts
std::vector <Label> msgbox;

std::vector <T> chrono;

std::vector <Button> button;

std::vector <Mission> mission;

std::vector <Menu> option;

std::vector <Menu> under_option;

std::vector <Splash_screen> fond;

std::vector <Dialog> dialog;

std::vector <Cursor> cr;


void T::toTime(int var){

	std::ostringstream ss;


	//~ if(var%3600==0){
		//~ this->hour=0;
		 //~ this->second=var%60;
		//~ this->minute=var/60;
		//~ }
	//~ else if(var%3600>0){
		 //~ this->hour=var%3600;
		//~ }
		if(second>=60){second=0;minute++;}
		if(minute>=60){minute=0;hour++;}

		if(var<=minute){up=true;}


	second++;
		if(minute<10){ss<<"0";}
ss<<minute<<":";


if(second<10){ss<<"0";}

ss<<second;
s=ss.str();
ss.str(" ");

}








	void init_src(){
		if(me.empty()){
		me.push_back(Hero("Mr. Jhon",100));
 homy.push_back(Homy("Arnub",8));
 zombie.push_back(Enemy("Césaro",100));
 map.push_back(Map());
panel.push_back(Panel());
bloodi.push_back(Blood());
fire.push_back(Fire());
gas.push_back(Gas());
explosion.push_back(Explosion());
potion.push_back(Potion());
box.push_back(Box());
game.push_back(Game());
msgbox.push_back(Label());


dialog.push_back(Dialog("","",1));

cr.push_back(Cursor());


}
me[0].life=100;
//void init_game(){
map[0].position(0,0);
map[0].size(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);

me[0].position(SCREEN_WIDTH-340,SCREEN_HEIGHT/3,2);
me[0].size(40,60);

zombie[0].position(200,140,4);
zombie[0].size(34,60);
//~
//~ zombie[1].position(140,70,2);
//~ zombie[1].size(64,64);

homy[0].position(me[0].ins.x-10,me[0].ins.y-10,me[0].oriantation);
homy[0].size(32,32);
//~
panel[0].position(5,5);
panel[0].size(0,0,111,40);
panel[0].div=0;

bloodi[0].size(0,0,512,512);
bloodi[0].position(SCREEN_WIDTH/2-bloodi[0].dim.w/2,SCREEN_HEIGHT/2-bloodi[0].dim.h/2);
bloodi[0].dim.x=0;
bloodi[0].dim.y=0;
fire[0].position(15,90);
fire[0].size(5,0,60,125);

gas[0].position(zombie[0].ins.x,zombie[0].ins.y-40);
gas[0].size(0,0,90,gas[0].maxHeight/2);


explosion[0].position(50,40);
explosion[0].size(0,0,65,64);

potion[0].position(100,50);
potion[0].size(0,0,29,35);

box[0].position(400,100);
box[0].size(20,349,70,70);

cr[0].size(0,0,40,40);

if(!chrono.empty()){
	chrono[0].second=0;
chrono[0].minute=0;
chrono[0].up=false;
}
dialog[0].position(0,0);
dialog[0].size(SCREEN_WIDTH,0);

}


//////////////////////////////////
void Torch::poursuit(){
	dim.x= 865+me[0].ins.w*2-10-me[0].ins.x;
  dim.y= 490+me[0].ins.h-me[0].ins.y;
  }

bool Box::collision(){

if(ins.x+ins.w>=me[0].ins.x && ins.x+ins.w<=me[0].ins.x+me[0].ins.w){
if(ins.y+ins.h>=me[0].ins.y && ins.y+ins.h<=me[0].ins.y+me[0].ins.h){


	if(me[0].ins.x+me[0].ins.w-ins.x>=0){if(left_pressed){me[0].step=0;std::cout<<"Collission right"<<std::endl;}else{me[0].step=6;}}
	if(me[0].ins.x-ins.x+ins.w>=0){if(up_pressed){me[0].step=0;std::cout<<"Collission down"<<std::endl;}else{me[0].step=6;}}
//no
std::cout<<"1";
		return 1;
}
}
if(ins.x>=me[0].ins.x && ins.x<=me[0].ins.x+me[0].ins.w){
if(ins.y>=me[0].ins.y && ins.y<=me[0].ins.y+me[0].ins.h){

		if(me[0].ins.x-ins.x+ins.w<=0){if(down_pressed){me[0].step=0;std::cout<<"Collission up"<<std::endl;}else{me[0].step=6;}}
		if(me[0].ins.x-ins.x+ins.w<=0){if(right_pressed){me[0].step=0;std::cout<<"Collission left"<<std::endl;}else{me[0].step=6;}}
//no
std::cout<<"2";
		return 1;
}
}
if(ins.x+ins.w>=me[0].ins.x && ins.x+ins.w<=me[0].ins.x+me[0].ins.w){
if(ins.y>=me[0].ins.y && ins.y<=me[0].ins.y+me[0].ins.h){

				if(me[0].ins.x-ins.x+ins.w>=0){if(down_pressed){me[0].step=0;std::cout<<"Collission up"<<std::endl;}else{me[0].step=6;}}

				if(me[0].ins.x-ins.x+ins.w>=0){if(left_pressed){me[0].step=0;std::cout<<"Collission left"<<std::endl;}else{me[0].step=6;}}
//no
std::cout<<"3";
		return 1;
}
}
if(ins.x>=me[0].ins.x && ins.x<=me[0].ins.x+me[0].ins.w){
if(ins.y+ins.h>=me[0].ins.y && ins.y+ins.h<=me[0].ins.y+me[0].ins.h){


      if(me[0].ins.y-ins.y+ins.h>=0){if(up_pressed){me[0].step=0;std::cout<<"Collission down"<<std::endl;}else{me[0].step=6;}}
	if(me[0].ins.x-ins.x+ins.w<=0){if(right_pressed){me[0].step=0;std::cout<<"Collission right"<<std::endl;}else{me[0].step=6;}}
std::cout<<"4";
		return 1;
		//make function of effect
}
}
return false;
}

 void Box::generator(){
	 if(Box::opened){
	 srand(time(NULL));
	 x =rand() % 4 +1;
	 std::cout<<x<<std::endl;
	 //DEPLACE

 }
 //CONDITIONS ALEATOIRE OBJECT EMPTY ,POTION,EXPLOSION
 if(x==1){
	 		std::cout<<"explosion"<<std::endl;
	 if(explosion.empty()){
		  explosion.push_back(Explosion());
	 explosion[0].position(ins.x-ins.w/2,ins.y-ins.h/2);
explosion[0].size(0,0,65,64);}


collision();
	 }
	 else if(x==2){
		 		std::cout<<"potion"<<std::endl;
		 potion.push_back(Potion());
		 potion[0].token=false;
	 potion[0].position(ins.x+ins.w/2,ins.y+ins.h/2);
potion[0].size(0,0,29,35);


		 }
	 else if(x>=3){
		std::cout<<"empty"<<std::endl;
		msg.clean("EMPTY",50);
		msgbox[0].position(SCREEN_WIDTH/2-msg.surface->w/2,SCREEN_HEIGHT/2-msg.surface->h/2);
		msgbox[0].print();
		update();
		SDL_Delay(150);

		 }
	 }


void Box::open(){

	if(Box::collision() && a_pressed){
		std::cout<<"Box opened !"<<std::endl;
		opened= true;
		 a_pressed=false;
		Box::generator();
			//~ Box::texture=NULL;
	 //~ SDL_DestroyTexture(texture);
	 ins.x=-1;
	 ins.y=-1;
	// box.pop_back();
	 a_pressed=false;
		}
		 else{opened=false;}
 }


 void generate(){
	if(box.size()<2){
		box.push_back(Box());
			srand(time(NULL));
	int ranX=rand()% SCREEN_WIDTH-box[0].ins.w;
	int ranY=rand()% SCREEN_HEIGHT-box[0].ins.w;

		box[box.size()-1].size(20,349,70,70);
		box[box.size()-1].position(ranX,ranY);
		//std::cout<<"X box: "<<ranX<<"- Y box: "<<ranY<<std::endl;
		}
	}



	//POTION CHUCK CODE
	bool Potion::collision(){


if(Potion::ins.x+Potion::ins.w>=me[0].ins.x && Potion::ins.x+Potion::ins.w<=me[0].ins.x+me[0].ins.w){
if(Potion::ins.y+Potion::ins.h>=me[0].ins.y && Potion::ins.y+Potion::ins.h<=me[0].ins.y+me[0].ins.h){
return true;
}
}
 if(Potion::ins.x>=me[0].ins.x && Potion::ins.x<=me[0].ins.x+me[0].ins.w){
if(Potion::ins.y>=me[0].ins.y && Potion::ins.y<=me[0].ins.y+me[0].ins.h){
return true;
}
}
 if(Potion::ins.x+Potion::ins.w>=me[0].ins.x && Potion::ins.x+Potion::ins.w<=me[0].ins.x+me[0].ins.w){
if(Potion::ins.y>=me[0].ins.y && Potion::ins.y<=me[0].ins.y+me[0].ins.h){
return true;
}
}
 if(Potion::ins.x>=me[0].ins.x && Potion::ins.x<=me[0].ins.x+me[0].ins.w){
if(Potion::ins.y+Potion::ins.h>=me[0].ins.y && Potion::ins.y+Potion::ins.h<=me[0].ins.y+me[0].ins.h){

return true;
}
}
return false;
}
void Potion::taked(){
	if(Potion::collision() && a_pressed){std::cout<<"Potion taked"<<std::endl;
token=true;
			me[0].life+=100;
				panel[0].div=0;
					panel[0].size(0,0,111,40);

		SDL_DestroyTexture(texture);
		ins.x=-ins.w*2;
		ins.y=-1;
		a_pressed=false;
		}
}
#endif
