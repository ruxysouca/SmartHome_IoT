#include "Sensor.h"
#include "Exceptions.h"

Sensor::Sensor(const char* name, int id, const char* sensorUnit, float initialReading, float maxThreshold) : IoTDevice(name, id)
{
	if (maxThreshold <= 0.0f)
		throw InvalidThresholdException(maxThreshold);

	unit = new char[strlen(sensorUnit) + 1];
	strcpy(unit, sensorUnit);

	lastReading = initialReading;
	threshold = maxThreshold;

	readingHistory.addEntry(initialReading);
}

Sensor::Sensor(const Sensor& other) : IoTDevice(other), readingHistory(other.readingHistory)
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
	readingHistory = other.readingHistory;

	return *this;

}

Sensor::~Sensor()
{
	delete[] unit;
}

void Sensor::updateReading(float newValue)
{
	lastReading = newValue;

	readingHistory.addEntry(newValue);

	if (isThresholdExceeded())
		status = ERROR;
	else
		status = ONLINE;
}

float Sensor::readValue() const
{
	return lastReading;
}

bool Sensor::isThresholdExceeded() const
{
	return lastReading > threshold;
}

void Sensor::printReadingHistory() const
{
	readingHistory.printLogs("SENSOR READING HISTORY");
}

void Sensor::runDiagnostics()
{
	std::cout << "-------------------------------------\n"
		<< "DIAGNOSTIC (sensor)\nName: " << deviceName << "\nID: " << deviceID
		<< "\nLast reading: " << lastReading << " " << unit << "\nStatus: "
		<< (isThresholdExceeded() ? "ALERT (Threshold exceeded)\n" : "NORMAL\n")
		<< "-------------------------------------\n";

	printReadingHistory();
}