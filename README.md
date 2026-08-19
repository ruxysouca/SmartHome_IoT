#  SmartHome_IoT


## Project Goal

This is my first independent C++ project, created as a learning initiative to solidify OOP concepts. The project simulates a Smart Home IoT ecosystem to practice clean code organization across header (`.h`) and implementation (`.cpp`) files, dynamic memory management without external libraries, polymorphism, and structured error handling.

## Key OOP concepts applied

* **Encapsulation:** Private attributes accessed safely through getters, setters and dedicated methods.
* **Manual memory management:** Deep copying implemented with custom copy constructors, copy assignment operators, and destructors to prevent memory leaks and dangling pointers.
* **Inheritance & diamond problem solution:** `Sensor` and `Actuator` inherit virtually from `IoTDevice` to avoid duplication inside `SmartThermostat` (multiple inheritance).
* **Polymorphism & abstract classes:** Base class interface with pure virtual methods (`runDiagnostics()`) called dynamically with base pointers (`IoTDevice*`).
* **Operator overloading:** Custom `operator<<` for easy console display of device details.
* **Exception handling:** Custom exception classes (`DeviceNotFoundException` and `InvalidThresholdException`) inheriting from `std::exception` for clear error messages.
* **Dynamic container:** A custom container (`SmartHub`) managing a dynamically resizable array of devices.

## Project Structure

```text
SmartHome_IoT/
├── .gitignore
├── LICENSE
├── README.md
└── SmartHome_IoT_Core/
    ├── Actuator.cpp
    ├── Actuator.h
    ├── Exceptions.h
    ├── IoTDevice.cpp
    ├── IoTDevice.h
    ├── Sensor.cpp
    ├── Sensor.h
    ├── SmartHub.cpp
    ├── SmartHub.h
    ├── SmartThermostat.cpp
    ├── SmartThermostat.h
    └── main.cpp
```
