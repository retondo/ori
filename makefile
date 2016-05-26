CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=arquivo.h arquivo.c arvore.h binaria.c main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=proj

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

