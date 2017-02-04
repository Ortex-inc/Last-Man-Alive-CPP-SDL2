#ifndef LOGIC_H
#define LOGIC_H

int arr=0;
void logic(){
	//STAND BY
	//KEYBOARD VERIF
	if(!up_pressed&&!down_pressed&&!left_pressed&&!right_pressed)
	{	me[0].dim.x=me[0].margX;me[0].stand=true;}


//TOUCH PAD VERIF
if(!button.empty()){
	if(!button[0].clicked&&!button[1].clicked&&!button[2].clicked&&!button[3].clicked){
		up_pressed=down_pressed=right_pressed=left_pressed=false;
		me[0].stand=true;
		me[0].dim.x=me[0].margX;

}
}


//SCREEN RULES
if(me[0].ins.x+me[0].dim.w>=SCREEN_WIDTH){me[0].ins.x=SCREEN_WIDTH-me[0].dim.w;me[0].limit=true;}else{me[0].limit=false;}
if(me[0].ins.y+me[0].dim.h>=SCREEN_HEIGHT){me[0].ins.y=SCREEN_HEIGHT-me[0].dim.h;me[0].limit=true;}else{me[0].limit=false;}

if(me[0].ins.x<=0){me[0].ins.x=0;me[0].limit=true;}else{me[0].limit=false;}
if(me[0].ins.y<=0){me[0].ins.y=0;me[0].limit=true;}else{me[0].limit=false;}
//COMPORTEMENT HOMY
homy[0].position(me[0].ins.x-20,me[0].ins.y-15,me[0].oriantation);
if(me[0].stand){homy[0].stance();} else if(!me[0].stand) {homy[0].move(me[0].oriantation);}


if(panel[0].dim.w<=0){me[0].life=0;}
}


bool collision(){
//with zombie


if(zombie[arr].ins.x+zombie[arr].dim.w+10>=me[0].ins.x && zombie[arr].ins.x+zombie[arr].dim.w+10<=me[0].ins.x+me[0].dim.w){
if(zombie[arr].ins.y+zombie[arr].dim.h-30>=me[0].ins.y && zombie[arr].ins.y+zombie[arr].dim.h-30<=me[0].ins.y+me[0].dim.h){

			if(game[0].effect){effect("sounds/scream.wav");}
		panel[0].size(0,0,111,40);
		panel[0].div+=2;
			zombie[0].wlk=false;
		zombie[0].finish=false;


		return 1;
}
}
if(zombie[arr].ins.x>=me[0].ins.x && zombie[arr].ins.x+10<=me[0].ins.x+me[0].dim.w){
if(zombie[arr].ins.y>=me[0].ins.y && zombie[arr].ins.y<=me[0].ins.y+me[0].dim.h){


		if(game[0].effect){effect("sounds/scream.wav");}


	panel[0].size(0,0,111,40);
		panel[0].div+=2;
			zombie[0].wlk=false;
		zombie[0].finish=false;


		return 1;
}
}
if(zombie[arr].ins.x+zombie[arr].dim.w+10>=me[0].ins.x && zombie[arr].ins.x+zombie[arr].dim.w+10<=me[0].ins.x+me[0].dim.w){
if(zombie[arr].ins.y>=me[0].ins.y && zombie[arr].ins.y<=me[0].ins.y+me[0].dim.h){

	if(game[0].effect){effect("sounds/scream.wav");}
	panel[0].size(0,0,111,40);
		panel[0].div+=2;
		zombie[0].wlk=false;
		zombie[0].finish=false;


		return 1;
}
}
if(zombie[arr].ins.x>=me[0].ins.x && zombie[arr].ins.x<=me[0].ins.x+me[0].dim.w){
if(zombie[arr].ins.y+zombie[arr].dim.h-30>=me[0].ins.y && zombie[arr].ins.y+zombie[arr].dim.h-30<=me[0].ins.y+me[0].dim.h){

		if(game[0].effect){effect("sounds/scream.wav");}
		panel[0].size(0,0,111,40);
		panel[0].div+=2;
		zombie[0].wlk=false;
		zombie[0].finish=false;

		return 1;
}
}

//

//width explosion
if(me[0].ins.x>=explosion[arr].ins.x && me[0].ins.x<=explosion[arr].ins.x+(explosion[arr].dim.w*1.5)){
if(me[0].ins.y>=explosion[arr].ins.y && me[0].ins.y<=explosion[arr].ins.y+(explosion[arr].dim.h*1.5)){
	//CORRECT
//std::cout<<"BOOM!"<<std::endl;


		panel[0].size(0,0,111,40);
		panel[0].div+=5;
		return 1;


}
}
if(me[0].ins.x+me[0].dim.w>=explosion[arr].ins.x && me[0].ins.x+me[0].dim.w<=explosion[arr].ins.x+(explosion[arr].dim.w*1.5)){
if(me[0].ins.y+me[0].dim.h>=explosion[arr].ins.y && me[0].ins.y+me[0].dim.h<=explosion[arr].ins.y+(explosion[arr].dim.h*1.5)){
//CORRECT

		panel[0].size(0,0,111,40);
		panel[0].div+=5;
		bloodi[0].print(1);

		return 1;
}
}


//////////////////////:FIRE


if(fire[arr].ins.x+fire[arr].ins.w>=me[0].ins.x && fire[arr].ins.x+fire[arr].ins.w<=me[0].ins.x+me[0].ins.w){
if(fire[arr].ins.y+fire[arr].ins.h>=me[0].ins.y && fire[arr].ins.y+fire[arr].ins.h<=me[0].ins.y+me[0].ins.h){

panel[0].size(0,0,111,40);
		panel[0].div+=5;
		return true;
}
}
 if(fire[arr].ins.x>=me[0].ins.x && fire[arr].ins.x<=me[0].ins.x+me[0].ins.w){
if(fire[arr].ins.y>=me[0].ins.y && fire[arr].ins.y<=me[0].ins.y+me[0].ins.h){

panel[0].size(0,0,111,40);
		panel[0].div+=5;
		return true;
}
}
 if(fire[arr].ins.x+fire[arr].ins.w>=me[0].ins.x && fire[arr].ins.x+fire[arr].ins.w<=me[0].ins.x+me[0].ins.w){
if(fire[arr].ins.y>=me[0].ins.y && fire[arr].ins.y<=me[0].ins.y+me[0].ins.h){

panel[0].size(0,0,111,40);
		panel[0].div+=5;
		return true;
}
}
 if(fire[arr].ins.x>=me[0].ins.x && fire[arr].ins.x<=me[0].ins.x+me[0].ins.w){
if(fire[arr].ins.y+fire[arr].ins.h>=me[0].ins.y && fire[arr].ins.y+fire[arr].ins.h<=me[0].ins.y+me[0].ins.h){
panel[0].size(0,0,111,40);
		panel[0].div+=5;
return true;
}
}

zombie[0].wlk=true;
zombie[0].finish=true;
zombie[0].init=true;

return 0;
}
#endif
