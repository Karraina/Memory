#include <iostream>

using namespace std;

void increase_temp(int* temperature, int amount) {
	if (temperature != nullptr) {
		*temperature += amount;
	}
}

void display_temp(const int* temperature) {
	if (temperature != nullptr) {
		cout << "Current Temperature: " << *temperature << endl;
	}
	else {
		cout << "No Temperature Sensor Availiable.\n";
	}
}

int main() {

	cout << "MEMORY EXPLORER\n";
	cout << "-------------------------\n\n";

	int cpuTemp = 62;
	int gpuTemp = 55;
	double ramUsage = 7.5;
	char systemStatus = 'N';

	cout << "PART 1: HARDWARE MEMORY ADDRESS\n\n";

	cout << "CPU Temperature: " << cpuTemp << " C\n";
	cout << "CPU Address: " << &cpuTemp << endl;
	cout << "CPU Size: " << sizeof(cpuTemp) << " bytes\n\n";

	cout << "GPU Temperature: " << gpuTemp << " C\n";
	cout << "GPU Address: " << &gpuTemp << endl;
        cout << "GPU Size: " << sizeof(gpuTemp) << " bytes\n\n";

	cout << "Ram Usage: " << ramUsage << " GB\n";
        cout << "Ram Address: " << &ramUsage << endl;
        cout << "Ram Size: " << sizeof(ramUsage) << " bytes\n\n";

	cout << "System Status: " << systemStatus << endl;
        cout << "Status Address: " << static_cast<const void*>(&systemStatus)  << endl;
        cout << "Status Size: " << sizeof(systemStatus) << " bytes\n\n";

        cout << "PART 2: HARDWARE POINTERS\n\n";

        int* cpuPtr = &cpuTemp;
        double* ramPtr = &ramUsage;

	cout << "CPU Temperature: " << cpuTemp << endl;
	cout << "CPU Address: " << &cpuTemp << endl;
	cout << "Pointer Stores: " << cpuPtr << endl;
	cout << "Pointer's Own Address: " << &cpuPtr << endl;

	cout << endl;

	cout << "RAM Usage: " << ramUsage << endl;
	cout << "RAM Address: " << &ramUsage << endl;
	cout << "Pointer Stores: " << ramPtr << endl;
	cout << "pointer's Own Address: " << &ramPtr << endl;

	cout << "\nPART 3: DEREFRENCING POINTER\n\n";

	cout << "CPU Temperature: " << cpuTemp << endl;
	cout << "CPU Pointer Address: " << cpuPtr << endl;
	cout << "CPU Derefrenced Value: " << *cpuPtr << endl;

	cout << endl;

	cout << "RAM Usage: " << ramUsage << endl;
	cout << "RAM Derefrenced Value: " << *ramPtr << endl;

	cout << "\nPART 4: UPDATING HARDWARE READINGS\n\n";

	cout << "Original CPU Temperature: " << cpuTemp << " C\n";

	*cpuPtr = 78;

	cout << "Updated CPU TemperatureL: " << cpuTemp << " C\n";
	cout << "Value Through Pointer: " << cpuPtr << " C\n";

	*ramPtr += 1.5;

	cout << "\nUpdated RAM Usage: " << ramUsage << " GB\n";

	cout << "PART 5: SENSOR AVALIABILITY\n\n";

	int* sensorPtr = nullptr;

	if (sensorPtr == nullptr) {
		cout << "No Temperature Sensor Selected\n";
	}

	sensorPtr = &cpuTemp;

	if (sensorPtr != nullptr) {
		cout << "CPU sensor Connected\n";
		cout << "Current Reading: " << *sensorPtr << endl;
	}

	cout << "\nPART 6: SWITCHING SENSORS\n\n";

	cout << "Active Sensor: CPU\n";
	cout << "Reading: " << *sensorPtr << endl;

	sensorPtr = &gpuTemp;

	cout << "\nActive Sensor: GPU\n";
	cout << "Reading: " << *sensorPtr << endl;

	*sensorPtr = 65;

	cout << "Updated GPU Temperature: " << gpuTemp << endl;

	cout << "CPU Temperature: " << cpuTemp << endl;

	cout << "\nPART 7: POINTERS VS REFERENCES\n\n";

	int& cpuRef = cpuTemp;

	int* currentPtr = &cpuTemp;

	cout << "CPU Tempeture: " << cpuTemp << endl;
	cout << "Reference Value: " << cpuRef << endl;
	cout << "Pointer Value: " << *currentPtr << endl;

	cpuRef = 82;

	cout << "After Using The Reference:\n";
	cout << "CPU Temperature: " << cpuTemp << endl;

	*currentPtr = 85;

	cout << "After Using The Pointer:\n";
	cout << "CPU Temperature: " << cpuTemp << endl;

	cout << "\nPART 8: POINTER FUNCTION PARAMERERS\n\n";

	cout << "Before CPU Update: ";
	display_temp(&cpuTemp);

	increase_temp(&cpuTemp, 5);

	cout << "After CPU Update: ";
	display_temp(&cpuTemp);

	increase_temp(&gpuTemp, 10);

	cout << "Update GPU: ";
        display_temp(&gpuTemp);

        cout << "Unavailable Sensor: ";
        display_temp(nullptr);

        cout << "\nPART 9: TEMPERATURE HISTORY\n\n";

	int temperatures[5] = { 62, 65, 68, 72, 74 };

	int* tempHistoryPtr = temperatures;

	cout << "Temperature Reading:\n";

	for(int i = 0; i < 5; i++) {
		cout << "Reading " << i + 1 << ": " << temperatures[i] << endl;
	}

	cout << "\nMemory Address:\n";

	for(int i = 0; i < 5; i++) {
                cout << "Reading " << i + 1 << " Address: " << temperatures[i] << endl;
        }

        cout << "\nPointer Arithmetic:\n";

        cout << "First Reading: " << *tempHistoryPtr << endl;

        cout << "Second Reading: " << *(tempHistoryPtr + 1) << endl;

        cout << "Third Reading: " << *(tempHistoryPtr + 2) << endl;

	return 0;
}
