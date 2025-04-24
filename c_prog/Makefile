CC := gcc

temperature.exe: temperature_main.o temperature.o
	$(CC) -o temperature.exe temperature_main.o temperature.o

temperature_main.o: temperature_main.c temperature.h
	$(CC) -c temperature_main.c

temperature.o: temperature.c temperature.h
	$(CC) -c temperature.c

clean:
	rm -f *.o temperature.exe
