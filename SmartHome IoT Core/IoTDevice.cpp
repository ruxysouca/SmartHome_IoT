#include "IoTDevice.h"

int IoTDevice::totalDevices = 0;

IoTDevice::IoTDevice(const char* name, int id) : deviceID(id), status(OFFLINE)
{
	deviceName = new char[strlen(name) + 1];
	strcpy(deviceName, name);
	totalDevices++;
}