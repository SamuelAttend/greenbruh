SRCS = $(wildcard ./src/*.c)

CC = gcc

PKG = sdl2 libdecor-0 freetype2

INCLUDE_PATHS = -I./include/

ifeq ($(OS), Windows_NT)
	LIBRARY_PATHS = -L./lib/
endif

COMPILER_FLAGS = -m32 -std=c99 -O2 -fstack-protector

ifeq ($(OS), Windows_NT)
	LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
	COMPILER_FLAGS += -mwindows
else
	LINKER_FLAGS = `pkg-config --static --libs $(PKG)`
endif

OBJ_NAME = build/main

all:
	$(CC) $(SRCS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) -o $(OBJ_NAME) $(LINKER_FLAGS)