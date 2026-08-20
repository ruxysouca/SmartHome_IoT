#pragma once
#include "IoTDevice.h"
#include "DeviceLog.h"

class Sensor : virtual public IoTDevice
{
protected:
	float lastReading;
	char* unit;
	float threshold;
	DeviceLog<float> readingHistory;

public:
	Sensor(const char* name, int id, const char* sensorUnit, float initialReading = 0.0f, float maxThreshold = 50.0f);

	Sensor(const Sensor& other);

	Sensor& operator=(const Sensor& other);

	void updateReading(float newValue);

	float readValue() const;

	bool isThresholdExceeded() const;

	void runDiagnostics() override;

	void printReadingHistory() const;

	virtual ~Sensor();
};