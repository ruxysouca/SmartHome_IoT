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

void SmartHub::resize()
{
	capacity *= 2;

	IoTDevice** newDevices = new IoTDevice * [capacity];
	for (int i = 0; i < count; i++)
		newDevices[i] = devices[i];

	delete[] devices;
	devices = newDevices;
}

void SmartHub::addDevice(IoTDevice* device)
{
	if (count == capacity)
		resize();

	devices[count++] = device;
}

IoTDevice* SmartHub::getDeviceById(int id) const
{
	for (int i = 0; i < count; i++)
		if (devices[i]->getDeviceID() == id)
			return devices[i];

	throw DeviceNotFoundException(id);
}

void SmartHub::runAllDiagnostics() const
{
	std::cout << "-------------------------------------\nSMART HUB DIAGNOSTICS\n"
		<< "Connected devices count: " << count << '\n';

	for (int i = 0; i < count; i++)
	{
		devices[i]->runDiagnostics();
		std::cout << "\n";
	}

	std::cout << "-------------------------------------\n";
}

int SmartHub::getDeviceCount() const
{
	return count;
}

IoTDevice*& SmartHub::operator[](int index)
{
	if (index < 0 || index >= count)
		throw std::out_of_range("Index out of range in SmartHub!");

	return devices[index];
}

const IoTDevice* SmartHub::operator[](int index) const
{
	if (index < 0 || index >= count)
		throw std::out_of_range("Index out of range in SmartHub!");

	return devices[index];
}