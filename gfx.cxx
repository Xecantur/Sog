#include "gfx.hxx"

/*
int gfx::entry_override()
{
	return 0;
} // does nothing Make it do something!!!
int gfx::pre_entry(){return 0;}
*/
SDL_Event& gfx::getEvent()
{
	return gfx::e; // hopefully this will return a reference to the current instances SDL_Event
}

int gfx::init()
{
	///create window and opengl context
	///and handle input and drawing this is where entry_override() shines	
	
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cout <<"SDL: Initialization error = " << SDL_GetError() << endl;
		return -1;
	}
	
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
	SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3 );
	SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1);
	gfx::win = SDL_CreateWindow("SDL/GLEW Demo", 500, 500, 1024, 768, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	if(gfx::win == NULL)
	{
		cout <<"SDL: Couldn't open window reason: " << SDL_GetError() << endl;
		return -1;
	}
	gfx::context = SDL_GL_CreateContext(gfx::win);
	if(gfx::context == NULL)
	{
		cout << "SDL_GL: Couldn't get a context reason: " << SDL_GetError() << endl;
		return -2;
	}
	SDL_GL_MakeCurrent(gfx::win, gfx::context);
	SDL_GL_SetSwapInterval(1);
	glewExperimental = true;
	GLenum err = glewInit();
	if(GLEW_OK != err)
	{
		cout <<"Glew: Couldn't initialize reason: " << SDL_GetError() << endl;
		return -3;
	}
	quit = false;
	GLuint VertexArrayID;
	if(glGenVertexArrays == 0)
	{
		cout << "glGenVertexArrays not found!!!" << SDL_GetError() << endl;
		return -4;
	}
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	gfx::pre_entry();
	while(!quit)
	{
		while(SDL_PollEvent(&(gfx::getEvent())) != 0)
		{
			if(gfx::e.type == SDL_QUIT)
			{
				quit = true;
			}
			if(gfx::e.type == SDL_KEYDOWN && gfx::e.key.repeat == 0)
			{
				switch(gfx::e.key.keysym.sym)
				{
					case SDLK_q:
						quit = true;
						break;
				}
			}
		}
		gfx::entry_override();
		SDL_GL_SwapWindow(gfx::win);
	}
	SDL_DestroyWindow(gfx::win);
	SDL_Quit();
	return 0;
}


