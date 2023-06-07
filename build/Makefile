MAIN_SRC = ../main.c

SRCS = $(wildcard ../src/*.c)

CC = gcc

INCLUDE_PATHS = -I../include/

LIBRARY_PATHS = -L../lib/

COMPILER_FLAGS = -O2

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lm

OBJ_NAME = main.exe

all: $(SRCS)
	$(CC) $(MAIN_SRC) $(SRCS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) -o $(OBJ_NAME) $(LINKER_FLAGS)