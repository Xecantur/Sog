OBJS = main.cxx gfx.cxx shader.cpp pgfx.cxx
LIBFLAGS = -lGLEW -lGL -lSDL2
CXXFLAGS = -Wall -Wextra -std=c++1y
OBJNAME = main
all :
	g++ ${OBJS} -o ${OBJNAME} ${CXXFLAGS} ${LIBFLAGS}
