SRCS = $(wildcard ./src/*.c)

CC = gcc

PKG = sdl2 libdecor-0 freetype2

INCLUDE_PATHS = -I./include/ `pkg-config --static --cflags $(PKG)`

ifeq ($(OS), Windows_NT)
	LIBRARY_PATHS = -L/lib/windows/
endif

COMPILER_FLAGS = -std=c99 -O2 -fstack-protector

ifeq ($(OS), Windows_NT)
	LINKER_FLAGS = -mingw32 -lSDL2main -lSDL2
else
	LINKER_FLAGS = `pkg-config --static --libs $(PKG)`
endif

OBJ_NAME = build/main

all:
	$(CC) $(SRCS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) -o $(OBJ_NAME) $(LINKER_FLAGS)