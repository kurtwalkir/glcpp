SHELL := /bin/sh

NAME := serverApp

MAKE    :=  /usr/bin/make
CC      :=  /usr/bin/g++

CFLAGS  := -g -Wall -Wextra -pedantic

ODIR    := obj
IDIR    := /inc
LIBS    := pthread

DEPS    := $(wildcard $(IDIR)/*.h)
SRCS    := $(wildcard *.cpp)
SRCS    += $(wildcard src/*.cpp)
OBJS    := $(SRCS:.cpp=.o)

.PHONY: all
all: $(NAME) $(OBJS)

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(DEPS) 

$(NAME): $(OBJS)
	$(CC) $(LFLAGS) -o $@ $^ -L$(LIBPATH) -l$(LIBS) -pthread

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o
	rm -f src/*.o
	rm -f *.o
	rm -f *.txt	
	rm -f $(NAME)

