#ifndef DRAW_H
#define DRAW_H
#include "object.h"





void draw(){



if(!map.empty()){
for(unsigned int i=0;i<map.size();i++){
if(map[i].ins.x<=SCREEN_WIDTH || map[i].ins.y<=SCREEN_HEIGHT){
map[i].print();}
}}


if(!box.empty()){
for(unsigned int i=0;i<box.size();i++){
if(box[i].ins.x<=SCREEN_WIDTH || box[i].ins.y<=SCREEN_HEIGHT){
 box[i].collision();
 box[i].open();
box[i].print();
}
}}



//~ if(!gas.empty()){
//~ for(unsigned int i=0;i<gas.size();i++){
//~ if(gas[i].ins.x<=SCREEN_WIDTH || gas[i].ins.y<=SCREEN_HEIGHT){
//~ }
//~ }}



if(!fire.empty()){
for(unsigned int i=0;i<fire.size();i++){
if(fire[i].ins.x<=SCREEN_WIDTH || fire[i].ins.y<=SCREEN_HEIGHT){
fire[i].animate();
fire[i].print();}
}}

if(!explosion.empty()){
	std::cout<<explosion[0].ins.x<<std::endl;
for(unsigned int i=0;i<explosion.size();i++){
if(explosion[i].ins.x<=SCREEN_WIDTH || explosion[i].ins.y<=SCREEN_HEIGHT){
	std::cout<<"BOOM!";
if(!explosion[i].end){explosion[i].print();}}
explosion[i].animate();
if(explosion[0].end){explosion[0].animate();explosion.pop_back();}
}}






if(!zombie.empty()){
for(unsigned int i=0;i<zombie.size();i++){
if(zombie[i].ins.x<=SCREEN_WIDTH || zombie[i].ins.y<=SCREEN_HEIGHT){
if(zombie[0].wlk && zombie[0].finish ){zombie[i].move();}
zombie[i].print();}
}}



if(!homy.empty()){
for(unsigned int i=0;i<homy.size();i++){
if(homy[i].ins.x<=SCREEN_WIDTH || homy[i].ins.y<=SCREEN_HEIGHT){
homy[i].print();}
}}






if(!potion.empty()){
for(unsigned int i=0;i<potion.size();i++){
if(potion[i].ins.x<=SCREEN_WIDTH || potion[i].ins.y<=SCREEN_HEIGHT){
	if(!potion[i].token){
		potion[i].print();
		potion[i].taked();
	potion[i].animate();
}
}
}}

if(!torch.empty() && mission[0].dark!="none"){
torch[0].poursuit();
torch[0].print();
}
if(!panel.empty()){
for(unsigned int i=0;i<panel.size();i++){
if(panel[i].ins.x<=SCREEN_WIDTH || panel[i].ins.y<=SCREEN_HEIGHT){
panel[i].print();}
}}


if(!me.empty()){
for(unsigned int i=0;i<me.size();i++){
if(me[i].ins.x<=SCREEN_WIDTH || me[i].ins.y<=SCREEN_HEIGHT){
me[i].print();}
 me[i].move();
}}
}
#endif
