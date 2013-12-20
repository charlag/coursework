CFLAGS=-c -Wall -g -std=c99
LDFLAGS=-lm -g
SOURCES=main.c file_io.c strio.c signal.c ui.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=kurs
VPATH=src

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	gcc $(LDFLAGS) $(OBJECTS) -o $@	

.c.o:
	gcc $(CFLAGS) $< -o $@

clean:
	@rm $(OBJECTS)
