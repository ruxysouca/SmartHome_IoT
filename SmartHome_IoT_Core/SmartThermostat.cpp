#include "SmartThermostat.h"

SmartThermostat::SmartThermostat(const char* name, int id, const char* sensorUnit, const char* actType,
	float initialReading, float maxThreshold, bool initialActuatorState, float targetTemp) : 
	IoTDevice(name,id),  Sensor(name, id, sensorUnit, initialReading, maxThreshold), 
	Actuator(name, id, actType, initialActuatorState), targetTemperature(targetTemp) {}

SmartThermostat::SmartThermostat(const SmartThermostat& other) : IoTDevice(other) , 
Sensor(other), Actuator(other), targetTemperature(other.targetTemperature){}

SmartThermostat& SmartThermostat::operator=(const SmartThermostat& other)
{
	if (this == &other)
		return *this;

	IoTDevice::operator=(other);
	Sensor::operator=(other);
	Actuator::operator=(other);

	targetTemperature = other.targetTemperature;
	return *this;
}

SmartThermostat::~SmartThermostat() {}