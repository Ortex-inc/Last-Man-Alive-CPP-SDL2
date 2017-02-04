

#ifndef MSMANAGER_H
#define MSMANAGER_H
#include <iostream>
#include <vector>
#include <fstream>



	std::vector<std::string> value;
	std::vector<std::string> menu;


bool getParam(const char* str){

 int d=20;
 int i=0;
 int r=0;
 int inc=0;
 int in=0;



  std::ifstream is(str);
  int  x=sizeof(is);
    
	char arr[x];
	unsigned int c=0;
	char t;
 while (is.get(t)) {
    arr[c]=t;
    c++;t++;
}
 is.close();

std::string word="";


  // char ar[]=":DARK _none :TIMER_3 :BACKGROUND _exemple.bmp :MUSIC_scary.mp3 :MSG1 _msg1 :MSG2 _msg2   ";
	//
	
for(i=0;i<=x;i++){
///////////////////////////////:START COND
if(arr[i]=='_'){
value.push_back(" ");
for(r=i;r<=i+d;r++){
if(arr[r+1]==' ' || arr[r+1]==':'){break;}
word+=arr[r+1];}
std::string txt(word);
	value[inc]=txt;
txt="";word="";inc++;
}
//////////////////////////////////END COND



///////////////////////////////:START COND
else if(arr[i]==':'){
	
menu.push_back(" ");
for(r=i;r<=i+d;r++){
if(arr[r+1]==' ' || arr[r+1]=='_'){break;}
word+=arr[r+1];}
std::string txt(word);
	menu[in]=txt;
txt="";word="";in++;
}
//////////////////////////////////END COND
}
return true;
}




bool syncParam(const char* str,bool option1,bool option2){


  std::ofstream is(str);
 
 
 is<<":"<<"SOUND"<<" _";
 if(option1){is<<1;}else{is<<0;}
is <<":"<<"FX"<<" _";
 if(option2){is<<1;}else{is<<0;}
 return 0;
}



  
#endif

