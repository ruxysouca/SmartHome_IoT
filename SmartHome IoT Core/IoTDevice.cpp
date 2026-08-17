#include "IoTDevice.h"

int IoTDevice::totalDevices = 0;

IoTDevice::IoTDevice(const char* name, int id) : deviceID(id), status(OFFLINE)
{
	deviceName = new char[strlen(name) + 1];
	strcpy(deviceName, name);
	totalDevices++;
}

IoTDevice::IoTDevice(const IoTDevice& other)
{
	deviceName = new char[strlen(other.deviceName) + 1];
	strcpy(deviceName, other.deviceName);
	deviceID = other.deviceID;
	status = other.status;
	totalDevices++;
}

IoTDevice& IoTDevice::operator=(const IoTDevice& other)
{
	if (this == &other)
		return *this;

	delete[] deviceName;
	deviceName = new char[strlen(other.deviceName) + 1];
	strcpy(deviceName, other.deviceName);

	deviceID = other.deviceID;
	status = other.status;

	return *this;
}

IoTDevice::~IoTDevice()
{
	delete[] deviceName;
	totalDevices--;
}