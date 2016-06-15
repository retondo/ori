CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=arquivo.h arquivo.c arvoreB.h arvoreB.c avl.h binaria.h binaria.c main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=proj

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

