#include "Actuator.h"
#include "Sensor.h"

int main()
{
	std::cout << "TESTING SENSOR\n";
	Sensor tempSensor("Bedroom Temp", 101, "Celsius", 21.5, 25.0f);
	tempSensor.runDiagnostics();

	std::cout << "\n Updating reading to 26.3 Celsius (over threshold)...\n";
	tempSensor.updateReading(26.3f);
	tempSensor.runDiagnostics();

	std::cout << "\nTesting sensor deep copy: \n";
	Sensor copiedSensor = tempSensor;
	copiedSensor.runDiagnostics();

	std::cout << "\n\nTESTING ACTUATOR\n";
	Actuator heater("Central heating valve", 201, "Thermal Relay", false);
	heater.runDiagnostics();

	std::cout << "\nToggling actuator state: \n";
	heater.toggleState();
	heater.runDiagnostics();

	std::cout << "\nTesting actuator assignment operator\n";
	Actuator assignedHeater("Dummy", 999, "None", false);
	assignedHeater = heater;
	assignedHeater.runDiagnostics();

	std::cout << "\n\nTESTING POLYMORPHISM";
	IoTDevice* devices[2];
	devices[0] = &tempSensor;
	devices[1] = &heater;

	for (int i = 0; i < 2; i++)
	{
		std::cout << "\nDevice " << i + 1 << " details:\n";
		std::cout << *devices[i] << '\n';
		devices[i]->runDiagnostics();
	}

	return 0;
}