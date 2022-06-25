CFLAGS=-Wall -lm -lpthread
CC=gcc
EXE=messagerie
INCLUDE=Includes

SRC  := $(wildcard src/*/*.c) main.c
OBJS := $(patsubst src/%.c, obj/%.o, $(SRC))

.PHONY: all
help:

compil:$(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(CFLAGS) -I $(INCLUDE)

obj/%.o: src/%.c
	$(CC) -o $@ -c -g $^ $(CFLAGS)

clean:
	rm obj/*/*.o
	rm $(EXE)

exec:
	./$(EXE)

help:
	@echo "\nall -> Appel de l'help\ncompil -> Compilation du projet\nclean-> supprime les .o ainsi que l'executable\nexec -> execute le projet compilé"