
#failai	
main: main.o functions.o
	g++ -std=c++17 -O3 main.o functions.o -o main

Strategija1: Strategija1.o functions.o
	g++ -std=c++17 -O3 Strategija1.o functions.o -o Strategija1

Strategija2: Strategija2.o functions.o
	g++ -std=c++17 -O3 Strategija2.o functions.o -o Strategija2

Strategija3: Strategija3.o functions.o
	g++ -std=c++17 Strategija3.o functions.o -o Strategija3

#objektiniaifailai
functions.o:functions.cpp
	g++ -std=c++17 -O3 -c functions.cpp 

main.o: main.cpp
	g++ -std=c++17 -O3 -c main.cpp 

Strategija1.o:Strategija1.cpp
	g++ -std=c++17 -O3 -c Strategija1.cpp 

Strategija2.o:Strategija2.cpp
	g++ -std=c++17 -O3 -c Strategija2.cpp 

Strategija3.o:Strategija3.cpp
	g++ -std=c++17 -O3 -c Strategija3.cpp

clean:
	del *.o *.exe

run_main: main
	./main.exe

run1: Strategija1
	./Strategija1.exe

run2: Strategija2
	./Strategija2.exe

run3: Strategija3
	./Strategija3.exe