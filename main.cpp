#include <iostream>

using namespace std;

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

	return 0;
}
