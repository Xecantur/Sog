#ifndef __PGFX_HXX__
#define __PGFX_HXX__
#include "gfx.hxx"
#include "shader.hpp"
#include <unistd.h>
#include <sys/types.h>
static const GLfloat vertData[] = {
		-1.0f,-1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		};


class pgfx : public gfx
{
	private:
	
	public:
//		int pre_entry(); // graphics setup ie set draw buffers
//		int entry_override(); // actual drawing
//		GLuint vertexbuffer;
//		void manipulateBuffer(GLfloat x, GLfloat y, GLfloat z, int size, float buffer[]);
		pgfx(){}
		virtual ~pgfx(){}
};

#endif //__PGFX_HXX__
