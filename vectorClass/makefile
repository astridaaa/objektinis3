#failai	
main: main.o functions.o
	g++ -std=c++17 -O3 main.o functions.o -o main

unitTesting: unitTesting.o functions.o 
	g++ -std=c++17 -O3 unitTesting.o functions.o -o unitTesting.exe

vectorTest: vectorUnitTests.o
	g++ -std=c++17 -O3 vectorUnitTests.o -o vectorUnitTests.exe

#objektiniaifailai
functions.o: Strategijos/functions.cpp
	g++ -std=c++17 -O3 -c Strategijos/functions.cpp 

main.o: main.cpp
	g++ -std=c++17 -O3 -c main.cpp 

unitTesting.o: unitTesting.cpp
	g++ -std=c++17 -O3 -c unitTesting.cpp

vectorUnitTests.o: vectorUnitTests.cpp
	g++ -std=c++17 -O3 -c vectorUnitTests.cpp

clean:
	del *.o *.exe

run_main: main
	./main.exe

runtest: unitTesting
	./unitTesting.exe -s

vecTest: vectorTest
	./vectorUnitTests.exe -s
