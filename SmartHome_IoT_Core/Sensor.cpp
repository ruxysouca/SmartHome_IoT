#include "Sensor.h"

Sensor::Sensor(const char* name, int id, const char* sensorUnit, float initialReading, float maxThreshold) : IoTDevice(name, id)
{
	unit = new char[strlen(sensorUnit) + 1];
	strcpy(unit, sensorUnit);

	lastReading = initialReading;
	threshold = maxThreshold;
}

Sensor::Sensor(const Sensor& other) : IoTDevice(other)
{
	unit = new char[strlen(other.unit) + 1];
	strcpy(unit, other.unit);

	lastReading = other.lastReading;
	threshold = other.threshold;
}

Sensor& Sensor::operator=(const Sensor& other)
{
	if (this == &other)
		return *this;

	IoTDevice::operator=(other);

	delete[] unit;
	unit = new char[strlen(other.unit) + 1];
	strcpy(unit, other.unit);

	lastReading = other.lastReading;
	threshold = other.threshold;

	return *this;

}

Sensor::~Sensor()
{
	delete[] unit;
}