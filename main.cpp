#include <SDL2/SDL.h>
#include <vector>
#include <math.h>
#include "header/screen.h"
#include "header/inputHandle.h"
#include "header/sound.h"
#include "header/move.h"
#include "header/logic.h"
#include "header/draw.h"
#include "header/animate.h"
#include "header/touchPad.h"
#include "header/menu.h"
#include "header/core.h"
#include "header/game.h"


//MAIN GAME
int main(int argc, char ** argv){
setScreen("Last man alive");
init_src();
game[0].getSetting();
SDL_ShowCursor(SDL_DISABLE);
while(!quit)
{
main_core();
cursor_handle();
update();
}

//game[0].setting();
game[0].clean();
return 0;
}
