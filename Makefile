CLASS = Human
CPP = g++
TEST = checkInfection

mesg:
	@echo "Make targets are 'infection', and 'clean'"
	@echo "E.g., type 'make infection'"

infection: main.o Board.o Human.o conio.o
	g++ -Wall -o infection -g main.o Board.o Human.o conio.o
	@echo "Compiled. Executable is named 'infection'"


# *.dSYM are OS X debugging files
clean:
	rm -f infection *.o
	@rm -rf *.dSYM

Board.o: Human.cpp Board.h Board.cpp
	g++ -Wall -c -g Board.cpp


Human.o: Human.h Human.cpp
	g++ -Wall -c -g Human.cpp

main.o: Board.h
	g++ -Wall -c -g main.cpp

conio.o: conio.h conio.cpp
	g++ -Wall -c -g conio.cpp
