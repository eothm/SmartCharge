#include "BatteryPack.h"
#include <cstdlib> 
#include <cmath>   

BatteryPack::BatteryPack()
    : voltage(3.7f), current(1.0f), temperature(25.0f), faultReason("") { }

float BatteryPack::getVoltage() const {
    return voltage;
}

float BatteryPack::getCurrent() const {
    return current;
}

float BatteryPack::getTemperature() const {
    return temperature;
}

void BatteryPack::update(float dt_seconds) {
    voltage += 0.005f * dt_seconds;
    temperature += 0.01f * dt_seconds;

    // Make values stop
    if (voltage > 4.3f) voltage = 4.3f;
    if (temperature > 80.0f) temperature = 80.0f;

    current = 0.8f + static_cast<float>(rand() % 40) / 100.0f; // added randomness

    faultReason.clear();
    if (isOverVoltage()) faultReason = "Overvoltage";
    else if (isUnderVoltage()) faultReason = "Undervoltage";
    else if (isOverTemperature()) faultReason = "Overtemperature";
}

bool BatteryPack::isOverVoltage() const {
    return voltage > MAX_VOLTAGE;
}

bool BatteryPack::isUnderVoltage() const {
    return voltage < MIN_VOLTAGE;
}

bool BatteryPack::isOverTemperature() const {
    return temperature > MAX_TEMP;
}

bool BatteryPack::isFaulted() const {
    return !faultReason.empty();
}

std::string BatteryPack::getFaultReason() const {
    return faultReason;
}
