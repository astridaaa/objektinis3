#failai	
main: main.o functions.o
	g++ -std=c++17 -O3 main.o functions.o -o main

Strategija1: Strategija1.o functions.o
	g++ -std=c++17 -O3 Strategija1.o functions.o -o Strategija1

Strategija2: Strategija2.o functions.o
	g++ -std=c++17 -O3 Strategija2.o functions.o -o Strategija2

Strategija3: Strategija3.o functions.o
	g++ -std=c++17 -O3 Strategija3.o functions.o -o Strategija3

unitTesting: unitTesting.o functions.o 
	g++ -std=c++17 -O3 unitTesting.o functions.o -o unitTesting.exe

vectorTest: vectorUnitTests.o
	g++ -std=c++17 -O3 vectorUnitTests.o -o vectorUnitTests.exe

#objektiniaifailai
functions.o: Strategijos/functions.cpp
	g++ -std=c++17 -O3 -c Strategijos/functions.cpp 

main.o: main.cpp
	g++ -std=c++17 -O3 -c main.cpp 

Strategija1.o: Strategijos/Strategija1.cpp
	g++ -std=c++17 -O3 -c Strategijos/Strategija1.cpp 

Strategija2.o: Strategijos/Strategija2.cpp
	g++ -std=c++17 -O3 -c Strategijos/Strategija2.cpp 

Strategija3.o: Strategijos/Strategija3.cpp
	g++ -std=c++17 -O3 -c Strategijos/Strategija3.cpp

unitTesting.o: unitTesting.cpp
	g++ -std=c++17 -O3 -c unitTesting.cpp

vectorUnitTests.o: vectorUnitTests.cpp
	g++ -std=c++17 -O3 -c vectorUnitTests.cpp

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

runtest: unitTesting
	./unitTesting.exe -s

vecTest: vectorTest
	./vectorUnitTests.exe -s
