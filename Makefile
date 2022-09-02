CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb -I ../SFML-2.5.1/include/

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= -L ../SFML-2.5.1/lib/  -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
