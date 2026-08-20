#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class DeviceLog
{
private:
	T* logEntries;
	int capacity;
	int count;

	void resize()
	{
		capacity *= 2;
		T* newEntries = new T[capacity];
		for (int i = 0; i < count; i++)
			newEntries[i] = logEntries[i];

		delete[] logEntries;
		logEntries = newEntries;
	}

public:
	DeviceLog(int initialCapacity = 2)
	{
		capacity = (initialCapacity > 0) ? initialCapacity : 2;
		count = 0;
		logEntries = new T[capacity];
	}

	DeviceLog(const DeviceLog<T>& other)
	{
		capacity = other.capacity;
		count = other.count;
		logEntries = new T[capacity];

		for (int i = 0; i < count; i++)
			logEntries[i] = other.logEntries[i];
	}

	DeviceLog<T>& operator=(const DeviceLog<T>& other)
	{
		if (this == &other)
			return*this;

		delete[] logEntries;

		capacity = other.capacity;
		count = other.count;
		logEntries = new T[capacity];

		for (int i = 0; i < count; i++)
			logEntries[i] = other.logEntries[i];

		return *this;
	}

	~DeviceLog()
	{
		delete[] logEntries;
	}
};