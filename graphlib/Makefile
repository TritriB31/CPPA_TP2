FLAGS=-c -Iinclude -I.

all: lib

lib: objects
	ar rcs libsimple.a *.o

objects: flex
	g++ ${FLAGS} -o parser.o parser.cpp
	g++ ${FLAGS} -o lexer.o lexer.cpp
	g++ ${FLAGS} -o ast.o src/ast.cpp
	g++ ${FLAGS} -o eval.o src/eval.cpp
	g++ ${FLAGS} -o is_numerical.o src/is_numerical.cpp
	g++ ${FLAGS} -o is_value.o src/is_value.cpp
	g++ ${FLAGS} -o parse.o src/parse.cpp
	g++ ${FLAGS} -o pretty_print.o src/pretty_print.cpp

flex: bison
	flex --outfile=lexer.cpp src/lexer.ll

bison:
	bison src/parser.yy --header=parser.hpp --output=parser.cpp

clean:
	${RM} parser.hpp parser.cpp lexer.cpp *.o libsimple.a

.PHONY: all clean lib bison flex