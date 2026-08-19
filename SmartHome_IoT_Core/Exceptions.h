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

