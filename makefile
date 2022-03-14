#
# In order to execute this "Makefile" just type "make"
#	A. Delis (ad@di.uoa.gr)
#

OBJS	= main.o readingDir.o
SOURCE	= main.c readingDir.c
HEADER	= header.h
OUT	= a.out
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 
# -g option enables debugging mode 
# -c flag generates object code for separate files


all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)


# create/compile the individual files >>separately<<
main.o: main.c
	$(CC) $(FLAGS) main.c 

readingDir.o: readingDir.c
	$(CC) $(FLAGS) readingDir.c 


# clean house
clean:
	rm -f $(OBJS) $(OUT)