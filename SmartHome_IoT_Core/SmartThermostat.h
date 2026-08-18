#pragma once
#include "Actuator.h"
#include "Sensor.h"

class SmartThermostat : public Sensor, public Actuator
{
private:
	float targetTemperature;

public:
	SmartThermostat(const char* name, int id, const char* sensorUnit, const char* actType,
		float initialReading = 20.0f, float maxThreshold = 35.0f, bool initialActuatorState = false,
		float targetTemp = 22.0f);

	SmartThermostat(const SmartThermostat& other);

	SmartThermostat& operator=(const SmartThermostat& other);

	void setTargetTemperature(float newTarget);

	float getTargetTemperature() const;

	void evaluateState();

	void runDiagnostics() override;

	virtual ~SmartThermostat();
};