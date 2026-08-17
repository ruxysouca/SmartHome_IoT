#pragma once
#include "IoTDevice.h"

class Sensor : virtual public IoTDevice
{
protected:
	float lastReading;
	char* unit;
	float threshold;

public:
	Sensor(const char* name, int id, const char* sensorUnit, float initialReading = 0.0f, float maxThreshold = 50.0f);
	Sensor(const Sensor& other);
	Sensor& operator=(const Sensor& other);
	virtual ~Sensor();

};