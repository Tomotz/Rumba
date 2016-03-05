#pragma once
#include "AbstractSensor.h"


class BasicSensor : public AbstractSensor {
public:
	 struct SensorInformation sense() const;
};