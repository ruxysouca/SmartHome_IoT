#pragma once
#include "IoTDevice.h"
#include "Exceptions.h"

class SmartHub
{
private:
	IoTDevice** devices;
	int capacity;
	int count;

	void resize();

public:
	SmartHub(int initialCapacity = 2);

	SmartHub(const SmartHub& other);
	
	SmartHub& operator=(const SmartHub& other);
	
	~SmartHub();

	void addDevice(IoTDevice* device);

	IoTDevice* getDeviceById(int id) const;

	void runAllDiagnostics() const;

	int getDeviceCount() const;
};