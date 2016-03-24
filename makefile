all: make_me

make_me: Simulator.o Robot.o StupidAlgorithm.o BasicSensor.o
	g++ -std=c++11 -o simulator Robot.o StupidAlgorithm.o BasicSensor.o Simulator.o 
	
BasicSensor.o: BasicSensor.cpp AbstractAlgorithm.h StupidAlgorithm.h AbstractSensor.h BasicSensor.h House.h Robot.h Simulator.h SensorInformation.h Direction.h
	g++ -Wall -c BasicSensor.cpp -std=c++11
	
StupidAlgorithm.o: StupidAlgorithm.cpp AbstractAlgorithm.h StupidAlgorithm.h AbstractSensor.h BasicSensor.h House.h Robot.h Simulator.h SensorInformation.h Direction.h
	g++ -Wall -c StupidAlgorithm.cpp -std=c++11
	
Robot.o: Robot.cpp AbstractAlgorithm.h StupidAlgorithm.h AbstractSensor.h BasicSensor.h House.h Robot.h Simulator.h SensorInformation.h Direction.h
	g++ -Wall -c Robot.cpp -std=c++11
	
Simulator.o: Simulator.cpp AbstractAlgorithm.h StupidAlgorithm.h AbstractSensor.h BasicSensor.h House.h Robot.h Simulator.h SensorInformation.h Direction.h
	g++ -Wall -c Simulator.cpp -std=c++11
	
clean: 
	rm -f Simulator.o Robot.o StupidAlgorithm.o BasicSensor.o simulator
	