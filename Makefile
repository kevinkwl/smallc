

CC=g++
CXXFLAGS= -g -Wall -std=c++11
LIB= -ll

SRC= main.cpp utils.cpp ast.cpp

FLEXGEN= lexer.cc
BISONGEN= parser.cc

FFLAGS= -olexer.cc
BFLAGS= -d -y --debug -oparser.cc

FLEX=flex ${FFLAGS}
BISON=bison ${BFLAGS}

lexer.cc: smallc.l
	${FLEX} smallc.l

parser.cc: smallc.y
	${BISON} smallc.y

parser: ${FLEXGEN} ${BISONGEN}
	${CC} ${CXXFLAGS} ${LIB} ${FLEXGEN} ${BISONGEN} ${SRC} -o parser

all: ${FLEXGEN} ${BISONGEN}

clean:
	rm -rf ${FLEXGEN} ${BISONGEN} *.o *.output parser