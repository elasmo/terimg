#gmake	makefile
EXECUTABLE=terimg


OBJS=edit.o \
	 file.o \
	 init.o \
	 screen_buffer.o \
	 window.o \
	 menu.o \
	 main.o

CFLAGS=-Wall
LFLAGS=-lncurses

CC?=gcc
COMPILE=$(CC) -c
	
build:  $(OBJS)
	@echo "[7mLinking.[0m"
	@$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJS) $(LFLAGS)
	@chmod u+s $(EXECUTABLE)
	@echo -n [32m
	@wc -c "$(EXECUTABLE)"
	@echo -n [0m

%.o:	%.c
	@echo "[7mCompiling [1m$<[0m"
	@$(COMPILE) $(CFLAGS) -o $@ $<

clean:
	-rm -f $(OBJS) $(EXECUTABLE) *.core
