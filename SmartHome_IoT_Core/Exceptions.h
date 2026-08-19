#pragma once
#include <exception>
#include <string>

class DeviceNotFoundException : public std::exception
{
private:
	std::string errorMessage;

public:
	DeviceNotFoundException(int id)
	{
		errorMessage = "Error: device with ID " + std::to_string(id) + " was not found in the hub!";
	}

	const char* what() const noexcept override
	{
		return errorMessage.c_str();
	}
};

class InvalidThresholdException : public std::exception
{
private:
	std::string errorMessage;

public:
	InvalidThresholdException(float val)
	{
		errorMessage = "Error: invalid safety threshold " + std::to_string(val) + " (must be positive and realistic)!";
	}

	const char* what() const noexcept override
	{
		return errorMessage.c_str();
	}
};
