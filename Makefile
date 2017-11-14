#gmake	makefile
EXECUTABLE=terimg


OBJS=src/edit.o \
	 src/file.o \
	 src/init.o \
	 src/screen_buffer.o \
	 src/window.o \
	 src/menu.o \
	 src/main.o

CFLAGS=-Wall -DDEV
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
