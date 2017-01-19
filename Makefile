

CC=g++
CXXFLAGS= -g -Wall -std=c++11
LIB= -ll

SRC= main.cpp utils.cpp ast.cpp semant.cpp

FLEXGEN= lexer.cc
BISONGEN= parser.cc

FFLAGS= -olexer.cc
BFLAGS= -d -y --debug -oparser.cc

FLEX=flex ${FFLAGS}
BISON=bison ${BFLAGS}

CPPFILE= main.cpp utils.cpp ast.cpp semant.cpp ast_emit.cpp IRgen.cpp mips.cpp tac.cpp

scc: ${FLEXGEN} ${BISONGEN}
	${CC} ${CXXFLAGS} ${LIB} ${FLEXGEN} ${BISONGEN} ${CPPFILE} -o scc

lexer.cc: smallc.l
	${FLEX} smallc.l

parser.cc: smallc.y
	${BISON} smallc.y

parser: ${FLEXGEN} ${BISONGEN}
	${CC} ${CXXFLAGS} ${LIB} ${FLEXGEN} ${BISONGEN} ${SRC} -o parser

all: ${FLEXGEN} ${BISONGEN}



clean:
	rm -rf ${FLEXGEN} ${BISONGEN} *.o *.output parser