#define _CRT_SECURE_NO_WARNINGS
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

	int getDeviceID() const;

	static int getTotalDevices();

	virtual void runDiagnostics() = 0;

	bool operator==(const IoTDevice& other) const;

	bool operator!=(const IoTDevice& other) const;

	bool operator<(const IoTDevice& other) const;

	bool operator>(const IoTDevice& other) const;

	friend std::ostream& operator<<(std::ostream& out, const IoTDevice& device);

	virtual ~IoTDevice();
};