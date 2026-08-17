#pragma once
#include <iostream>
#include <cstring>

enum DeviceStatus
{
	OFFLINE,
	ONLINE,
	ERROR
};

class IoTDevice
{
protected:
	char* deviceName;
	int deviceID;
	DeviceStatus status;
	static int totalDevices;

public:
	IoTDevice(const char* name, int id);

	IoTDevice(const IoTDevice& other);

	IoTDevice& operator=(const IoTDevice& other);

	virtual void runDiagnostics() = 0;

	friend std::ostream& operator<<(std::ostream& out, const IoTDevice& device);

	virtual ~IoTDevice();
};