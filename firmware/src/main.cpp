#include "BatteryPack.h"
#include "CANBus.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    BatteryPack battery;

    const float timestep = 1.0f; 
    const int totalIterations = 30;

    std::cout << "Starting SmartChargeHub simulation...\n";

    for (int i = 0; i < totalIterations; ++i) {
        battery.update(timestep);

        float voltage = battery.getVoltage();
        float current = battery.getCurrent();
        float temp    = battery.getTemperature();

        CANFrame frame = encodeBatteryStatus(voltage, current, temp);

        std::cout << "[Tick " << i << "] "
                  << "V=" << voltage << "V, "
                  << "I=" << current << "A, "
                  << "T=" << temp << "°C"
                  << (battery.isFaulted() ? "FAULT: " + battery.getFaultReason() : "")
                  << "\n";

        std::cout << "→ " << frame.toString() << "\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    std::cout << "Simulation ended.\n";
    return 0;
}
