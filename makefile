AssignmentThreeFinal: driver.o
	g++ -o AssignmentThreeFinal driver.o 
driver.o: driver.cpp 
	g++ -c driver.cpp
clean:
	rm *.o AssignmentThreeFinal