#include "Actuator.h"
#include "Sensor.h"
#include "SmartThermostat.h"
#include "Exceptions.h"
#include "SmartHub.h"

int main()
{
/*	std::cout << "      TESTING SENSOR\n";
	Sensor tempSensor("Bedroom Temp", 101, "Celsius", 21.5, 25.0f);
	tempSensor.runDiagnostics();

	std::cout << "\n Updating reading to 26.3 Celsius (over threshold)...\n";
	tempSensor.updateReading(26.3f);
	tempSensor.runDiagnostics();

	std::cout << "\nTesting sensor deep copy: \n";
	Sensor copiedSensor = tempSensor;
	copiedSensor.runDiagnostics();

	std::cout << "\n\n      TESTING ACTUATOR\n";
	Actuator heater("Central heating valve", 201, "Thermal relay", false);
	heater.runDiagnostics();

	std::cout << "\nToggling actuator state: \n";
	heater.toggleState();
	heater.runDiagnostics();

	std::cout << "\nTesting actuator assignment operator\n";
	Actuator assignedHeater("Dummy", 999, "None", false);
	assignedHeater = heater;
	assignedHeater.runDiagnostics();

	std::cout << "\n\n      TESTING POLYMORPHISM";
	IoTDevice* devices[2];
	devices[0] = &tempSensor;
	devices[1] = &heater;

	for (int i = 0; i < 2; i++)
	{
		std::cout << "\nDevice " << i + 1 << " details:\n";
		std::cout << *devices[i] << '\n';
		devices[i]->runDiagnostics();
	}


	std::cout << "      TESTING SMART THERMOSTAT\n";
	SmartThermostat livingRoomThermostat("Living room thermostat", 301, "Celsius", "Heating relay", 19.5f, 35.0f, false, 22.0f);

	std::cout << "Initial state:\n";
	livingRoomThermostat.runDiagnostics();

	std::cout << "\n\nEvaluating state (temperature is below target):\n";
	livingRoomThermostat.evaluateState();
	livingRoomThermostat.runDiagnostics();

	std::cout << "\n\nUpdating temperature to 38.0 celsius (safety alert):\n";
	livingRoomThermostat.updateReading(38.0f);
	livingRoomThermostat.runDiagnostics();

	std::cout << "\n\nTesting deep copy:\n";
	SmartThermostat copiedThermostat = livingRoomThermostat;
	copiedThermostat.runDiagnostics();

	std::cout << "\n\nTesting assignment operator:\n";
	SmartThermostat assignedThermostat("Dummy thermostat", 999, "Celsius", "None");
	assignedThermostat = livingRoomThermostat;
	assignedThermostat.runDiagnostics();

	std::cout << "\n\n\n      TESTING POLYMORPHISM\n";
	IoTDevice* device = &livingRoomThermostat;
	std::cout << "Streaming via operator<<:\n" << *device;
	std::cout << "\n\nInvoking virtual runDiagnostics():\n";
	device->runDiagnostics();
	

	try
	{
		std::cout << "Attempting to create sensor with invalid threshold (-10.0):\n";
		Sensor faultySensor("Faulty sensor", 999, "Celsius", 20.0f, -10.0f);
	}
	catch (const InvalidThresholdException& ex)
	{
		std::cout << ex.what() << "\n";
	}
	*/

	std::cout << "1. TESTING EXCEPTION: INVALID THRESHOLD\n";
	try
	{
		std::cout << "Attempting to create sensor with invalid threshold (-5.0):\n";
		Sensor faultySensor("Faulty sensor", 99, "Celsius", 20.0f, -5.0f);
	}
	catch (const std::exception& ex)
	{
		std::cout << "Caught exception: " << ex.what() << "\n\n";
	}

	std::cout << "\n2. INITIALIZING DEVICES\n";
	Sensor bedroomSensor("Bedroom sensor", 101, "Celsius", 21.5f, 30.0f);
	Actuator livingRoomHeater("Living room valve", 201, "Thermal valve", false);
	SmartThermostat mainThermostat("Main thermostat", 301, "Celsius", "Heating relay", 19.0f, 35.0f, false, 22.5f);

	std::cout << "\n\n3. TESTING SMARTHUB (DYNAMIC ARRAY & RESIZE) ...\n";
	SmartHub hub(2);
	hub.addDevice(&bedroomSensor);
	hub.addDevice(&livingRoomHeater);
	hub.addDevice(&mainThermostat);

	hub.runAllDiagnostics();

	std::cout << "\n\n4. TESTING EXCEPTION: DEVICE LOOKUP\n";
	//Successful lookup
	try
	{
		std::cout << "Searching for device ID 201:\n";
		IoTDevice* foundDevice = hub.getDeviceById(201);
		std::cout << "Found device: " << *foundDevice << "\n\n";
	}
	catch (const std::exception& ex)
	{
		std::cout << "Caught exception! " << ex.what() << "\n\n";
	}

	//Failed lookup
	try
	{
		std::cout << "Searching for device ID 404:\n";
		IoTDevice* notFoundDevice = hub.getDeviceById(404);
		std::cout << "Found device: " << *notFoundDevice << "\n\n";
	}
	catch (const std::exception& ex)
	{
		std::cout << "Caught exception! " << ex.what() << "\n\n";
	}

	std::cout << "\n5. TESTING SMARTHUB RULE OF THREE \nTesting SmartHub copy constructor:\n";
	SmartHub copiedHub = hub;
	std::cout << "Copied hub device count: " << copiedHub.getDeviceCount();

	std::cout << "\n\nTesting SmartHub assignment operator:\n";
	SmartHub assignedHub(1);
	assignedHub = hub;
	std::cout << "Assigned hub device count: " << assignedHub.getDeviceCount();

	return 0;
}