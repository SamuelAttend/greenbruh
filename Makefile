SRCS = $(wildcard ./src/*.c)

CC = gcc

INCLUDE_PATHS = -I./include/

LIBRARY_PATHS = -L./lib/

COMPILER_FLAGS = -O2 -fstack-protector

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lm

OBJ_NAME = build/main.exe

all:
	$(CC) $(SRCS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) -o $(OBJ_NAME) $(LINKER_FLAGS)