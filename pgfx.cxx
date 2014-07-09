#include "pgfx.hxx"
#include "shape.hxx"
int gfx::pre_entry()
{
	polygon * square = new polygon;
	square->square(10.5f, 10.5f);
	vector<float> poly = square->toArray(square->pvec);
	float * buffer = &poly[0];
	glGenBuffers(1, &(gfx::vertexbuffer));
	glBindBuffer(GL_ARRAY_BUFFER, gfx::vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(buffer), buffer, GL_STATIC_DRAW);
	GLuint ProgramID = LoadShaders("vertex.shader","fragment.shader");
	glUseProgram(ProgramID);
	return 0;
}

/*
void pgfx::manipulateBuffer(GLfloat x, GLfloat y, GLfloat z, int size, float buffer[])
{
		buffer[2] = z;
		buffer[5] = z;
		buffer[8] = z;

		buffer[0] += x;
		buffer[3] += x;
		buffer[6] += x;
		
		buffer[1] += y;
		buffer[4] += y;
		buffer[7] += y;
}
*/
/*
	float sub[] = {
		 1.0f, 1.0f, 0.0f,
		 -1.0f, 1.0f, 0.0f,
		 0.0f, -1.0f, 0.0f,
		};		
*/

int gfx::entry_override()
{
		//pgfx * proc = new pgfx;
	glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, gfx::vertexbuffer);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);
//		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(buffer), buffer);
		//proc->manipulateBuffer(10.0f,0.0f,0.0f,sizeof(buffer),buffer);
		glDrawArrays(GL_POLYGON, 0 , 4);
	glDisableVertexAttribArray(0);
		//delete proc;
	return 0;
}
