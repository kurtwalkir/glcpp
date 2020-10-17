SHELL := /bin/sh

NAME := serverApp

MAKE    :=  /usr/bin/make
CC      :=  /usr/bin/g++

CFLAGS  := -g -Wall -Wextra -pedantic
LFLAGS  :=

ODIR    := obj
IDIR    := /inc
LIBS    := pthread
LIBPATH := 

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

print:
		echo "---->"$(SRCS)


.PHONY: clean
clean:
	rm -f $(ODIR)/*.o
	rm -f *.o
	rm -f *.txt	
	rm -f $(NAME)

