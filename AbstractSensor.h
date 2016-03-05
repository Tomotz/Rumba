#pragma once
enum class Direction { East, West, South, North, Stay };
typedef struct SensorInformation SensorInformation;
class AbstractSensor {
public:
	// returns the sensor's information of the current location of the robot
	virtual SensorInformation sense() const = 0;
	virtual void move(Direction direction) = 0;
};