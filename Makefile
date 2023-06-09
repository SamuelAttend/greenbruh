SRCS = $(wildcard ./src/*.c)

CC = gcc

PKG = sdl2 libdecor-0 freetype2 SDL2_ttf

INCLUDE_PATHS = -I./include/

ifeq ($(OS), Windows_NT)
	LIBRARY_PATHS = -L./lib/
endif

COMPILER_FLAGS = -std=c99 -O2 -fstack-protector

ifeq ($(OS), Windows_NT)
	LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf
	COMPILER_FLAGS += -mwindows -m32
else
	LINKER_FLAGS = Wl,-Bstatic `pkg-config --static --libs $(PKG)`
	COMPILER_FLAGS += `pkg-config --static --cflags $(PKG)`
endif

OBJ_NAME = build/main

all:
	$(CC) $(SRCS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) -o $(OBJ_NAME) $(LINKER_FLAGS)