#ifndef __GFX_HXX_
#define __GFX_HXX_
#include <iostream>
#include <string>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <glm/glm.hpp>
using namespace std;

class gfx
{	private:
		SDL_Window * win;
		SDL_GLContext context;
		SDL_Event e;
		bool quit;
	public:
		virtual int entry_override(); // modify variable and events here MUST RETURN 0 on success or 1 on failure
		virtual int pre_entry(); // set your obj draws here
		int init(); ///use to start window; don't for get glewInit(); 
		SDL_Event& getEvent(); // getEvent to be used in entry_override()
		GLuint vertexbuffer;
		
};


#endif //__GFX_HXX__

