CFLAGS=-c -Wall
SOURCES=main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=kurs
VPATH=src

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	gcc $(OBJECTS) -o $@	

.c.o:
	gcc $(CFLAGS) $< -o $@
