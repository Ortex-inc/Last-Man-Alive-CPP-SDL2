
#ifndef INPUTHANDLE_H
#define INPUTHANDLE_H
	SDL_Event event;

	int btnX,btnY;int hvX,hvY;
//Hundle bools
bool paused=false;
bool quit=false;
//sys keys
bool escape_pressed=false;
//orientation
bool right_pressed=false;
bool left_pressed=false;
bool up_pressed=false;
bool down_pressed=false;
//moves
bool a_pressed=false;
bool b_pressed=false;


void input(){
		 /* Check for new events */
        while(SDL_PollEvent(&event))
        {
			 switch( event.type ){

				 case SDL_QUIT:
				 quit=true;
				 break;
            //Key down
            case SDL_KEYDOWN:
                /* Check the SDLKey values and move change the coords */
                switch( event.key.keysym.sym ){
//REMOVABLE CODE WHEN  PORTED THIS GAME IN ANDROID OR FOR ANY TOUCH DEVICE
					case SDLK_ESCAPE:
                       escape_pressed=true;
                      if(!paused){paused=true;}
                      else if (paused){paused=false;}

                        break;

                    case SDLK_LEFT:

                      left_pressed=true;
                        break;
                    case SDLK_RIGHT:

                    right_pressed=true;

                        break;
                    case SDLK_UP:
                         up_pressed=true;
                        break;
                    case SDLK_DOWN:
                        down_pressed=true;
                        break;
                        //
                        case SDLK_a:
                       a_pressed=true;
                       paused=true;
                        break;
                        case SDLK_b:
                       b_pressed=true;
                        break;



                    default:
                        break;
            /* If a quit event has been sent */

        }
        break;
        //Key up
        case SDL_KEYUP:
         /* Check the SDLKey values and move change the coords */
                switch( event.key.keysym.sym ){
					case SDL_QUIT:
					quit=true;
					break;
case SDLK_ESCAPE:
                       escape_pressed=false;
					//
                    case SDLK_LEFT:
                       left_pressed=false;
							break;
                    case SDLK_RIGHT:
                        right_pressed=false;
                        break;
                    case SDLK_UP:
                        up_pressed=false;
                        break;
                    case SDLK_DOWN:
                    down_pressed=false;
                        break;
                          //
                        case SDLK_a:
                    //   a_pressed=false;
                        break;
                        case SDLK_b:
                       b_pressed=false;
                        break;

                    default:
                        break;

           }
           break;
					//click event
		case  SDL_MOUSEBUTTONUP:
	 btnX = -1 ;
	 btnY = -1 ;
					break;

					case  SDL_MOUSEBUTTONDOWN:
		 			btnX = event.button.x ;
	 				btnY = event.button.y ;
					break;
					
					case  SDL_MOUSEMOTION:
		 			hvX = event.motion.x ;
	 				hvY = event.motion.y ;
					break;

					default:
				   break;

		}
		}
		
		//zz
	//	bool paused=false;

	}
	

#endif
