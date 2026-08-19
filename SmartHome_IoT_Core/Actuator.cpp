#include "Actuator.h"

Actuator::Actuator(const char* name, int id, const char* type, bool st) : IoTDevice(name, id)
{
	actionType = new char[strlen(type) + 1];
	strcpy(actionType, type);

	state = st;
}

Actuator::Actuator(const Actuator& other) : IoTDevice(other)
{
	actionType = new char[strlen(other.actionType) + 1];
	strcpy(actionType, other.actionType);

	state = other.state;
}

Actuator& Actuator::operator=(const Actuator& other)
{
	if (this == &other)
		return *this;

	IoTDevice::operator=(other);
	
	delete[] actionType;
	actionType = new char[strlen(other.actionType) + 1];
	strcpy(actionType, other.actionType);

	state = other.state;

	return *this;
}

Actuator::~Actuator()
{
	delete[] actionType;
}

void Actuator::toggleState()
{
	state = !state;
}

bool Actuator::getState() const
{
	return state;
}

void Actuator::runDiagnostics()
{
	std::cout << "-------------------------------------\n"
		<< "DIAGNOSTIC(actuator)\nName: " << deviceName << "\nID : " << deviceID
		<< "\nAction Type: " << actionType << "\nState: "
		<< (state ? "ON\n" : "OFF\n")
		<< "-------------------------------------\n";
}