#ifndef BATTERY_PACK_H
#define BATTERY_PACK_H

#include <cstdint>
#include <string>

class BatteryPack {
public:
    BatteryPack();
    float getVoltage() const;
    float getCurrent() const;
    float getTemperature() const;
    void update(float dt_seconds);
    bool isOverVoltage() const;
    bool isUnderVoltage() const;
    bool isOverTemperature() const;
    bool isFaulted() const;

    std::string getFaultReason() const;

private:

    float voltage;
    float current;     
    float temperature; 

    const float MAX_VOLTAGE = 4.2f;
    const float MIN_VOLTAGE = 3.0f;
    const float MAX_TEMP    = 60.0f;

    std::string faultReason;
};

#endif
