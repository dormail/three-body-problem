all: main

main: MyWindow.cpp MyWindow.h
main: drawer.cpp drawer.h
main: ThreeBodyProblem.cpp ThreeBodyProblem.h

main: main.cpp
	g++ main.cpp \
		MyWindow.cpp \
		drawer.cpp \
		ThreeBodyProblem.cpp \
		-std=c++11 \
		$$(pkg-config gtkmm-3.0 --cflags --libs) -lpthread \
		-o main
