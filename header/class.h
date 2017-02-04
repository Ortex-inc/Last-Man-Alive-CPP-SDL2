#ifndef CLASS_H
#define CLASS_H


#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>
#include <sstream>
#include "MSmanager.h"



class Source {
	public:
	SDL_Surface *surface;

	Source(const char*src){
	surface=NULL;
	//surface=SDL_LoadBMP(src);
		surface=IMG_Load(src);
}
}prof("src/professor.bmp"),enemy("src/zombie.bmp"),bunny("src/bunny.bmp"),background("src/background.bmp"),
	heart("src/heart.bmp"),blood("src/blood.bmp"),flame("src/flame.bmp"),toxic("src/gas.bmp"),
	splash("menu.png"),boom("src/explosion.bmp"),potionimg("src/potion.png"),
	extra("src/extra.png"),touchs("src/buttons.bmp"),dark("src/dark.png"),cursor("src/cursor.png");


class Text{
	public:
Uint8 r,b,g;
const char * fontPath;
SDL_Color color;
char c;
const char* label;

		SDL_Surface*surface=NULL;
		TTF_Font *font=NULL;

		Text(const char * label,const char * fontPath,int size ,char c){
				TTF_Init();
				TTF_Font *font=NULL;
				switch(c)
				{
					case'w':
					r=255;g=255;b=255;
					break;
					case 'r':
					r=255;g=0;b=0;
					break;
					case 't':
					r=64;g=153;b=255;
					break;
					default:
					r=255;g=255;b=255;
					break;
				}
				this->fontPath=fontPath;
				this->label=label;
				font = TTF_OpenFont(fontPath, size);
				surface=TTF_RenderText_Solid(font,label,color);


		}
		void clean(const char*,int size);
	}msg(" ","font/font.ttf",36,'w'),timer("3:00","font/font.ttf",36,'t'),status("aaaaa","font/font.ttf",36,'r');
void Text::clean(const char* pt,int size){

	SDL_Color color={r,g,b};
SDL_FreeSurface(this->surface);
TTF_CloseFont(this->font);
		this->font=NULL;
				this->font = TTF_OpenFont(this->fontPath, size);
				surface=TTF_RenderText_Solid(this->font,pt,color);

	}



class Map{
	public:
	SDL_Rect dim,ins;
	SDL_Texture * texture;
	Map(){
		texture=SDL_CreateTextureFromSurface(screen,background.surface);
		}
void setMap();
	void position(int,int);
		void size(int,int,int,int);
		void print();
	};

	void Map::position(int x,int y){
	this->ins.x=x;
	this->ins.y=y;
		}

void Map::setMap(){texture=SDL_CreateTextureFromSurface(screen,background.surface);}
	void Map::size(int x,int y,int w,int h){

		this->ins.h=this->dim.h=h;
		this->ins.w=this->dim.w=w;
		this->dim.x=x;
		this->dim.y=y;


		}

	void Map::print(){

	SDL_RenderCopy(screen,texture,&dim,&ins);
}



//class
class Hero {
	public:
		bool limit;
	bool stand;
	int life;
	int step;
	int maxWidth,maxHeight;
	const char * name;

	SDL_Rect dim,ins;
	SDL_Texture *texture;
	int oriantation;


	int margX;
int margY;

	Hero(const char * name,int life){

		limit=false;
		this->stand=true;
		this->step=6;
		margY=10;
		margX=15;
		this->name=name;
		this->life=life;
		texture=NULL;
		texture=SDL_CreateTextureFromSurface(screen,prof.surface);


			maxWidth=prof.surface->w-margX;
			maxHeight=prof.surface->h-margY;

		}

		void position(int,int,int);
		void size(int,int);
		void move(void);
		void print();

	};

void Hero::position(int x,int y,int oriantation){
	this->dim.x=margX;
	this->dim.y=margY;
	this->ins.x=x;
	this->ins.y=y;
	this->oriantation=oriantation;
	}
	void Hero::size(int w,int h){

		this->ins.h=this->dim.h=h;
		this->ins.w=this->dim.w=w;
		}
		void Hero::move(){



			if(stand){
				switch(oriantation){
					case 1:dim.y=0+margY;break;
					case 2:dim.y=210+margY;break;
					case 3:dim.y=140+margY;break;
					case 4:dim.y=70+margY;break;
					}
				}

			if(up_pressed){
					stand=false;
					oriantation=1;
						dim.y=0+margY;
					if(dim.x>=maxWidth-dim.w)
					{ dim.x=margX;}
					else {dim.x+=dim.w+margX*2;}
					ins.y-=step;
					}

					if(left_pressed){
						stand=false;
					oriantation=4;
						dim.y=70+margY;
					if(dim.x>=maxWidth-dim.w)
					{ dim.x=margX;}
					else {dim.x+=dim.w+margX*2;}
						ins.x-=step;
					}

					if(down_pressed){
						stand=false;
					oriantation=3;
						dim.y=140+margY;
					if(dim.x>=maxWidth-dim.w)
					{ dim.x=margX;}
					else {dim.x+=dim.w+margX*2;}
						ins.y+=step;
					}

					if(right_pressed){
						stand=false;
					oriantation=2;
						dim.y=210+margY;
					if(dim.x>=maxWidth-dim.w)
					{ dim.x=margX;}
					else {dim.x+=dim.w+margX*2;}
						ins.x+=step;
					}

		}

void Hero::print(){

	SDL_RenderCopy(screen,texture,&dim,&ins);
  SDL_SetRenderDrawColor(screen,255,0,0,25);
      SDL_RenderFillRect(screen, &ins);
	}



	class Enemy {
	public:
	int life;
	int step;
int maxWidth,maxHeight;
	const char * name;

	SDL_Rect dim,ins;
	SDL_Texture *texture;
	int oriantation;
	bool wlk;
	bool init;
	bool finish;
	int old_oriantation;
		int margX;
int margY;
int s;
	Enemy(const char * name,int life){
		s=0;
		finish=true;
		this->step=5;
			 margX=15;
			 margY=4;
		init=true;
		wlk=true;
		this->name=name;
		this->life=life;
	old_oriantation=oriantation;
		texture=SDL_CreateTextureFromSurface(screen,enemy.surface);
		maxWidth=enemy.surface->w;
		maxHeight=enemy.surface->h;

		}

		void position(int,int,int);
		void size(int,int);
		void move();
		void attack();
		void print();

	};

void Enemy::position(int x,int y,int oriantation){
dim.x=margX;
dim.y=margY;

	this->ins.x=x;
	this->ins.y=y;

	this->oriantation=oriantation;
	}
	void Enemy::size(int w,int h){

		this->ins.h=this->dim.h=h;
		this->ins.w=this->dim.w=w;
		}





void Enemy::move(){
if(wlk){
	switch(oriantation){
case 1:dim.y=(maxHeight/8)*3+margY;break;
case 2:dim.y=(maxHeight/8)*2+margY;break;
case 3:dim.y=0+margY;break;
case 4:dim.y=(maxHeight/8)*1+margY;break;
}
if(dim.x>=dim.w*6){dim.x=margX;}
else {dim.x+=dim.w+margX*2;}

}
}

void Enemy::attack(){

if(!wlk && !finish){
if(s==0){
switch(oriantation){
case 1:dim.y=(maxHeight/8)*6+margY;break;
case 2:dim.y=(maxHeight/8)*5+margY;break;
case 3:dim.y=(maxHeight/8)*4+margY;break;
case 4:dim.y=(maxHeight/8)*7+margY;break;
}
s=1;
dim.x=margX;
}

//CONSOL POURSUIT
//std::cout<<"init"<<init<<std::endl;
std::cout<<dim.x;
//std::cout<<"bool "<<wlk<<finish<<s<<std::endl;

//attach down zombie

if(dim.x>=dim.w*4+margX){dim.x=margX;
wlk=true;finish=true;s=0;}
else if (dim.x<dim.w*4+margX && s>1){dim.x+=dim.w+margX*2;}
if(s){s++;}
}
}



void Enemy::print(){

	SDL_RenderCopy(screen,texture,&dim,&ins);
	  SDL_SetRenderDrawColor(screen,0,255,0,25);
      SDL_RenderFillRect(screen, &ins);
         //~ dang = SDL_CreateTextureFromSurface(screen,a);
         //~ // SDL_RenderCopy(screen, dang,NULL, NULL);

	}




//class
class Homy {
	public:
			int maxWidth,maxHeight;
	int step;
	const char * name;
	SDL_Rect dim,ins;
	SDL_Texture *texture;
	int oriantation;
	Homy(const char * name,int step){
		this->step=step;
		this->name=name;
		texture=NULL;
		texture=SDL_CreateTextureFromSurface(screen,bunny.surface);
		maxWidth=bunny.surface->w;
		maxHeight=bunny.surface->h;

		}

		void position(int,int,int);
		void size(int,int);

		void stance();
		void move(int);
		void print();

	};

void Homy::position(int x,int y,int oriantation){

	this->ins.x=x;
	this->ins.y=y;
	this->oriantation=oriantation;
	}
	void Homy::size(int w,int h){

		this->ins.h=this->dim.h=h;
		this->ins.w=this->dim.w=w;
		}
void Homy::stance(){
		if(oriantation==1){

			dim.y=(maxHeight/8)*3;
		if(dim.x>=maxWidth-dim.w)
		{ dim.x=0;}
		else {dim.x+=dim.w;}
		}
		if(oriantation==2){

			dim.y=0;
		if(dim.x>=maxHeight-dim.w)
		{ dim.x=0;}
		else {dim.x+=dim.w;}
		}
		if(oriantation==3){

			dim.y=(maxHeight/8)*2;
		if(dim.x>=maxWidth-dim.w)
		{ dim.x=0;}
		else {dim.x+=dim.w;}
		}
		if(oriantation==4){

			dim.y=(maxHeight/8)*1;
		if(dim.x>=maxWidth-dim.w)
		{ dim.x=0;}
		else {dim.x+=dim.w;}
		}

}

void Homy::move(int x){
	oriantation=x;
	if(oriantation==1){

		dim.y=(maxHeight/8)*7;
		if(dim.x>=dim.w*2)
		{ dim.x=0;}
		else {dim.x+=dim.w;}
		}
		if(oriantation==2){

			dim.y=(maxHeight/8)*4;
		if(dim.x>=dim.w*2)
		{ dim.x=0;}
		else {dim.x+=dim.w;}
		}
		if(oriantation==3){

			dim.y=(maxHeight/8)*6;
		if(dim.x>=dim.w*2)
		{ dim.x=0;}
		else {dim.x+=dim.w;}
		}
		if(oriantation==4){

			dim.y=(maxHeight/8)*5;
		if(dim.x>=dim.w*2)
		{ dim.x=0;}
		else {dim.x+=dim.w;}
		}


	}

void Homy::print(){
	SDL_RenderCopy(screen,texture,&dim,&ins);

	}

class Panel{
	public:
	int div;
		int maxWidth,maxHeight;
	//img of hero in panel
SDL_Rect dim,ins;
SDL_Texture *texture;

	Panel(){
this->div=1;
texture=SDL_CreateTextureFromSurface(screen,heart.surface);
maxWidth=heart.surface->w;
maxHeight=heart.surface->h;

	}
	void position(int,int);
	void size(int,int,int,int);
	void print();
};
void Panel::position(int x,int y){
	this->ins.x=x;
	this->ins.y=y;
}
void Panel::size(int x,int y,int w,int h){
	this->dim.x=x;
	this->dim.y=y;
	this->dim.w=this->ins.w=maxWidth-div;
	this->dim.h=this->ins.h=h;


}
void Panel::print(){
	SDL_RenderCopy(screen,texture,&dim,&ins);
}
class Blood{
	public:
			int maxWidth,maxHeight;
	SDL_Rect dim,ins,overAll;
	SDL_Texture *texture;
	Blood(){
	texture=NULL;
	texture=SDL_CreateTextureFromSurface(screen,blood.surface);
	maxWidth=blood.surface->w;
	maxHeight=blood.surface->h;

	}
	void position(int,int);
	void size(int,int,int,int);
	void animate();
	void print(int);

};
void Blood::position(int x,int y){
	this->ins.x=x;
	this->ins.y=y;
}
void Blood::size(int x,int y,int w,int h){
	this->dim.x=x;
	this->dim.y=y;
	this->dim.w=this->ins.w=w;
	this->dim.h=this->ins.h=h;


	overAll.x=0;
	overAll.y=0;
	overAll.h=SCREEN_HEIGHT;
	overAll.w=SCREEN_WIDTH;
}
void Blood::animate(){

	if(dim.x>=maxWidth-dim.w){dim.x=0;}
	else{dim.x+=dim.w;}
}
void Blood::print(int x){
SDL_RenderCopyEx(screen, texture,&dim, &ins,0,0,SDL_FLIP_NONE);
 SDL_SetRenderDrawColor(screen,255,0,0,-120);
  SDL_RenderFillRect(screen, &overAll);

}
//

class Fire{
	public:
		int maxWidth,maxHeight;
	SDL_Rect dim,ins;
	SDL_Texture *texture;
	Fire(){
	texture=NULL;
	texture=SDL_CreateTextureFromSurface(screen,flame.surface);
	maxWidth=flame.surface->w;
	maxHeight=flame.surface->h;

	}
	void position(int,int);
	void size(int,int,int,int);
	void animate();
	void print();

};
void Fire::position(int x,int y){
	this->ins.x=x;
	this->ins.y=y;
}
void Fire::size(int x,int y,int w,int h){
	this->dim.x=x;
	this->dim.y=y;
	this->dim.w=w;
	this->dim.h=h;
	this->ins.h=h;
	this->ins.w=w;
}

void Fire::animate(){

	if(dim.y>=maxHeight-dim.h*2){dim.y=0;}
	else{dim.y+=dim.h;}
}
void Fire::print(){
SDL_RenderCopy(screen, texture,&dim, &ins);
  SDL_SetRenderDrawColor(screen,0,255,250,25);
      SDL_RenderFillRect(screen, &ins);

}
//
class Gas{
	public:
	int maxWidth,maxHeight;
	SDL_Rect dim,ins;
	SDL_Texture *texture;
	Gas(){
	texture=NULL;
	texture=SDL_CreateTextureFromSurface(screen,toxic.surface);
	maxWidth=toxic.surface->w;
	maxHeight=toxic.surface->h;

	}
	void position(int,int);
	void size(int,int,int,int);
	void animate();
	void print();

};
void Gas::position(int x,int y){
	this->ins.x=x;
	this->ins.y=y;
}
void Gas::size(int x,int y,int w,int h){
	this->dim.x=x;
	this->dim.y=y;
	this->dim.w=this->ins.w=w;
	this->dim.h=this->ins.h=h;
}

void Gas::animate(){

	if(dim.x>=maxWidth-dim.w*2){dim.x=5;dim.y=maxHeight/2;}
	else{dim.x+=dim.w;}
	if(dim.y==maxHeight/2 && dim.x>=maxWidth-dim.w*2){dim.y=0;dim.x=5;}
}
void Gas::print(){
SDL_RenderCopy(screen, texture,&dim, &ins);

}
//
class Explosion{
	public:
	bool end;
	int maxWidth,maxHeight;
	SDL_Rect dim,ins;
	SDL_Texture *texture;
	Explosion(){
		end=false;
	texture=NULL;
	texture=SDL_CreateTextureFromSurface(screen,boom.surface);
	maxWidth=boom.surface->w;
	maxHeight=boom.surface->h;

	}


	void position(int,int);
	void size(int,int,int,int);
	void animate();
	void print();

};
void Explosion::position(int x,int y){
	this->ins.x=x;
	this->ins.y=y;
}
void Explosion::size(int x,int y,int w,int h){
	this->dim.x=x;
	this->dim.y=y;
	this->dim.w=this->ins.w=w;
	this->dim.h=this->ins.h=h;


	this->ins.w=w*1.5;
	this->ins.h=h*1.5;
}

void Explosion::animate(){

if(!end){
	if(dim.x>=maxWidth){dim.x=0;end=true;}
	else{dim.x+=dim.w;}
}else{ins.x=-ins.w*2;
	ins.y=-1;
	ins.h=0;
	ins.w=0;
	dim.h=0;
	dim.w=0;
	}
}
void Explosion::print(){
	if(end){SDL_DestroyTexture(texture);}
else {
SDL_RenderCopy(screen, texture,&dim, &ins);
  SDL_SetRenderDrawColor(screen,255,0,0,25);
      SDL_RenderFillRect(screen, &ins);
}

}

class Potion{
	public:
	int qt;
	bool token;
		int maxWidth,maxHeight;
	// SDL THINGS
	SDL_Rect dim,ins;
	SDL_Texture *texture;

	Potion(){
		token=false;
		texture=NULL;
			texture=SDL_CreateTextureFromSurface(screen,potionimg.surface);
	maxWidth=potionimg.surface->w;
	maxHeight=potionimg.surface->h;
		qt=1;
		}
	void position(int,int);
	void size(int,int,int,int);
	void animate();
	bool collision();
	void taked();
	void print();

	};

void Potion::position(int x,int y){
	this->ins.x=x;
	this->ins.y=y;
}
void Potion::size(int x,int y,int w,int h){
	this->dim.x=x;
	this->dim.y=y;
	this->dim.w=this->ins.w=w;
	this->dim.h=this->ins.h=h;
}

void Potion::animate(){

	if(dim.x>=maxWidth-dim.w){dim.x=0;}
	else{dim.x+=dim.w;}
}
void Potion::print(){
SDL_RenderCopy(screen, texture,&dim, &ins);

}

class Box{
	public:
	bool opened;
	SDL_Rect dim,ins;
	SDL_Texture *texture;
	unsigned short x;



	Box(){
		x=0;

		opened=false;
		texture=NULL;
		texture=SDL_CreateTextureFromSurface(screen,extra.surface);
		}
		~Box(){};
	void position(int,int);
	void size(int,int,int,int);
	void open();
	bool collision();
	void generator();
	void print();
	};
	void Box::position(int x,int y){
	this->ins.x=x;
	this->ins.y=y;
}
void Box::size(int x,int y,int w,int h){
	this->dim.x=x;
	this->dim.y=y;
	this->dim.w=w;
	this->dim.h=h;


	this->ins.w=w/2;
	this->ins.h=h/2;
}



void Box::print(){
SDL_RenderCopy(screen, texture,&dim, &ins);
  SDL_SetRenderDrawColor(screen,0,0,255,25);
      SDL_RenderFillRect(screen, &ins);

}
//

class Label{
	public:

SDL_Rect ins;


	Label(){
	}
	void position(int,int);
	void print();
};
void Label::position(int x,int y){
	this->ins.x=x;
	this->ins.y=y;

	this->ins.w=msg.surface->w;
	this->ins.h=msg.surface->h;
}



void Label::print(){
	ins.w=msg.surface->w;
	ins.h=msg.surface->h;
	SDL_Texture *texture=SDL_CreateTextureFromSurface(screen,msg.surface);
	SDL_RenderCopy(screen,texture,NULL,&ins);
	SDL_DestroyTexture(texture);
}


//
class Dialog{

public:
  SDL_Rect dim,ins;

Dialog(const char* label,const char* fontPath,int size){}
  void position(int,int);
  void size(int,int);
  void animate(int);
  void print();
};
  void Dialog::position(int x,int y){

 this->ins.y=this->dim.y=y;
 this->ins.x=this->dim.x=x;
  }

void Dialog::size(int a, int b){
  this->dim.h=b;
  this->dim.w=a;
}

void Dialog::animate(int max){
	if(this->ins.h<max){
  this->ins.h+=10;
    this->dim.h+=10;

}
}

  void Dialog::print(){

          SDL_SetRenderDrawColor(screen,0,0,0,250);
          SDL_RenderFillRect(screen, &dim);
  }


class Button{
public:
	SDL_Texture *texture;
	SDL_Rect dim,ins;
	bool clicked;
	short oldY;
	Button(){
		texture=SDL_CreateTextureFromSurface(screen,touchs.surface);
		clicked=false;

	}

		void position(int,int);
		void size(int,int,int,int);
		void onClick(void);
		void print(void);
};

	void Button::position(int x,int y){
		this->ins.x=x;
		this->ins.y=y;
		this->oldY=this->ins.y+2;
	}
	void Button::size(int x,int y,int w,int h){
		this->dim.x=x;
		this->dim.y=y;

		this->dim.w=this->ins.w=w;
		this->dim.h=this->ins.h=h;

	}

	void Button::onClick(){
		if(ins.x<=btnX && ins.x+dim.w>=btnX && ins.y<=btnY && ins.y+dim.h>=btnY ){
				//onClick code
			clicked=true;
		this->ins.y=this->oldY;
			//MAKE ANIMATION OR SOUND WHEN BUTTON COCKED
				}
				else if (btnX==-1 && btnY==-1){
					clicked=false;
				this->ins.y=this->oldY-2;}
}

	void Button::print(){
		SDL_RenderCopy(screen,texture ,&dim,&ins);
	}




	class Torch{
	public:
	int maxWidth,maxHeight;
	SDL_Rect dim,ins;
	SDL_Texture *texture;
	Torch(){
	texture=NULL;
	texture=SDL_CreateTextureFromSurface(screen,dark.surface);
	maxWidth=dark.surface->w;
	maxHeight=dark.surface->h;

	}
	void position(int,int);
	void size(int,int,int,int);
	void poursuit();
	void print();

};
void Torch::position(int x,int y){
	this->ins.x=x;
	this->ins.y=y;
}
void Torch::size(int x,int y,int w,int h){
	this->dim.x=x;
	this->dim.y=y;
	this->dim.w=w;
	this->dim.h=h;

	this->ins.h=SCREEN_HEIGHT;
	this->ins.w=SCREEN_WIDTH;
}


void Torch::print(){
SDL_RenderCopy(screen, texture,&dim, &ins);
SDL_SetTextureAlphaMod(texture,250);


}


class T{
	public:
int second,minute,hour;
bool up;
std::string s;
SDL_Rect ins;


	T(){
		second=0; minute=0; hour=0;
	up=false;
	}

	void position(int,int);
	void toTime(int var);
	bool timeUp();
	void print();
};
void T::position(int x,int y){
	this->ins.x=x;
	this->ins.y=y;

	this->ins.w=timer.surface->w;
	this->ins.h=timer.surface->h;
}







void T::print(){
	ins.w=timer.surface->w;
	ins.h=timer.surface->h;
	SDL_Texture *texture=SDL_CreateTextureFromSurface(screen,timer.surface);
	SDL_RenderCopy(screen,texture,NULL,&ins);
	SDL_DestroyTexture(texture);
}






class Mission{
	public:
	const char* path;
	std::string dark;
	int time;
		std::string background;
		std::string music;

		std::string msg1;
		std::string msg2;


	Mission(){}

	int currMission();
	void loadMission(int);


};

	int Mission::currMission(){
		getParam("mission/ndx.lma");
		path=value[0].c_str();
		return atoi(path);
		}
	void Mission::loadMission(int i){

		std::ostringstream ss;
		ss.str("");
		ss<<"mission/ms"<<i<<".lma";
		getParam(ss.str().c_str());
		dark=value[0];
		time=atoi(value[1].c_str());

		background=value[2];
		music=value[3];

		msg1=value[4];

		msg2=value[5];
}






class Menu{

	public:
Uint8 r,b,g;
int oldY;
bool clicked;
const char * fontPath;
SDL_Color color;
char c;
const char* label;
SDL_Rect ins,dim;
		SDL_Surface*surface=NULL;
		SDL_Texture *texture=NULL;
		TTF_Font *font=NULL;

		Menu(const char * label,const char * fontPath,int size ,char c,bool bold){
				TTF_Init();
				TTF_Font *font=NULL;
				switch(c)
				{
					case'r':
					r=205;g=51;b=51;
					break;
					case't':
					r=135;g=206;b=235;
					break;
					default:
					r=124;g=205;b=124;
					break;
				}





				clicked=false;
					oldY=0;
					SDL_Color color={r,g,b};
				this->fontPath=fontPath;
				this->label=label;
				font = TTF_OpenFont(this->fontPath, size);
				if(bold){TTF_SetFontStyle(font,TTF_STYLE_BOLD);}
				surface=TTF_RenderText_Solid(font,this->label,color);
ins.w=dim.w=this->surface->w;
ins.h=dim.h=this->surface->h;


}
void position(int,int);
void onClick();
void print();
};
void Menu::position(int x,int y){
	this->ins.x=x;
	this->ins.y=y;
	this->dim.x=0;
	 this->dim.y=0;
	 this->oldY=this->ins.y+2;
}


	void Menu::onClick(){
		if(ins.x<=btnX && ins.x+dim.w>=btnX && ins.y<=btnY && ins.y+dim.h>=btnY ){
				//onClick code
			clicked=true;
		this->ins.y=this->oldY;
			//MAKE ANIMATION OR SOUND WHEN BUTTON COCKED
				}
				else if (btnX==-1 && btnY==-1){
					clicked=false;
				this->ins.y=this->oldY-2;}
}


void Menu::print(){
	SDL_Texture *texture=SDL_CreateTextureFromSurface(screen,surface);
	SDL_RenderCopy(screen,texture,&dim,&ins);
	SDL_DestroyTexture(texture);
}

	class Splash_screen{
	public:
	SDL_Rect dim,ins;
	SDL_Surface *surface;
	SDL_Texture *texture;

	Splash_screen(const char*src){
			surface=NULL;
	//surface=SDL_LoadBMP(src);
		surface=IMG_Load(src);
		texture=SDL_CreateTextureFromSurface(screen,surface);
		}

	void position(int,int);
		void size(int,int,int,int);
		void print();
	};

	void Splash_screen::position(int x,int y){
	this->ins.x=x;
	this->ins.y=y;
		}

	void Splash_screen::size(int x,int y,int w,int h){
		this->dim.w=surface->w;
		this->dim.h=surface->h;
		this->ins.h=h;
		this->ins.w=w;
		this->dim.x=x;
		this->dim.y=y;
		}

	void Splash_screen::print(){
	SDL_RenderCopy(screen,texture,&dim,&ins);
}


/////////////////////////////////////////////MAIN CORE INTENTION
class Game{
	public:
	bool charged;
	bool paused;
	bool playing;

	bool music;
	bool effect;
	Game(){
		music=true;
		effect=true;
		paused=charged=playing=false;
		}
		void pause();//pause and resume DONE
		void tryAgain();// if life 0 or time up -try again
		void newGame(); //from menu page
		void loadGame();
		void stat();//stat game assemble and hold all pause try again and new game
		void clean();// clean up DONE
		//beta
		void setting();
		void getSetting();
	};
	
	class Cursor{
		public:
		SDL_Texture *texture;
		SDL_Rect dim,ins;
		
		Cursor(){
			texture=SDL_CreateTextureFromSurface(screen,cursor.surface);
			}
			
			void position(int,int);
			void size(int,int,int,int);
			void animate();
			void print();
		};
			void Cursor::position(int x,int y){
	this->ins.x=x;
	this->ins.y=y;
		}

	void Cursor::size(int x,int y,int w,int h){
		this->dim.x=x;
		this->dim.y=y;
		this->dim.w=this->ins.w=w;
		this->dim.h=this->ins.h=h;
		}

	void Cursor::print(){
	SDL_RenderCopy(screen,texture,&dim,&ins);
}

//////////////////////////////////////////

	class Info{
		public:
		short version;
		const char* mail;
		const char* web;
		Info(){}
		};
#endif
