CC = g++
CXX = $(CC)
DEBUG = -g -Wno-deprecated -fPIC

EXE = LorenzAttractor
C_SRCS = LorenzAttractor.C \
		 main.C

OBJS = ${C_SRCS:.C=.o}

# release settings
#CFLAGS = -O2 -I/usr/include
#LFLAGS = -s -L/usr/lib

# debug settings
DEFINES = #-DFAST
CFLAGS = $(DEBUG) $(DEFINES) -I/usr/include 
LFLAGS = -g -L/usr/lib -lfltk -lfltk_gl -lglut -lGL -lXi -lXmu  -lboost_program_options-mt -lboost_filesystem-mt


CXXFLAGS = $(CFLAGS)

all: ${EXE}

${EXE}: ${OBJS}
	${LINK.cpp} ${LFLAGS} -o $@ ${OBJS}

clean:
	-rm -f ${OBJS}

clobber: clean
	-rm -f ${EXE}

