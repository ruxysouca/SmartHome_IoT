#include "SmartHub.h"

SmartHub::SmartHub(int initialCapacity)
{
	capacity = (initialCapacity > 0) ? initialCapacity : 2;
	count = 0;
	devices = new IoTDevice * [capacity];
}

SmartHub::SmartHub(const SmartHub& other)
{
	capacity = other.capacity;
	count = other.count;
	devices = new IoTDevice * [capacity];
	for (int i = 0; i < count; i++)
		devices[i] = other.devices[i];
}

SmartHub& SmartHub::operator=(const SmartHub& other)
{
	if (this == &other)
		return *this;

	delete[] devices;

	capacity = other.capacity;
	count = other.count;
	devices = new IoTDevice * [capacity];
	for (int i = 0; i < count; i++)
		devices[i] = other.devices[i];

	return *this;
}

SmartHub::~SmartHub()
{
	delete[] devices;
}