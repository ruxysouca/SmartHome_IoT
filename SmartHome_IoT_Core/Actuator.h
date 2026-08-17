#pragma once
#include "IoTDevice.h"

class Actuator : virtual public IoTDevice
{
protected:
	bool state;
	char* actionType;

public:
	Actuator(const char* name, int id, const char* type, bool st = false);

	Actuator(const Actuator& other);

	Actuator& operator=(const Actuator& other);

	void toggleState();

	bool getState() const;

	void runDiagnostics() override;

	virtual ~Actuator();
};