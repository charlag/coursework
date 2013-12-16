CFLAGS=-c -Wall -std=c99
LDFLAGS=-L src
SOURCES=main.c file_io.c strio.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=kurs
VPATH=src

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	gcc $(OBJECTS) -o $@	

.c.o:
	gcc $(CFLAGS) $< -o $@
