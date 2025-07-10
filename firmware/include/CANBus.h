#ifndef CAN_BUS_H
#define CAN_BUS_H

#include <cstdint>
#include <array>
#include <string>

struct CANFrame {
    uint32_t id;
    std::array<uint8_t, 8> data{};
    uint8_t length = 8;

    std::string toString() const;
};

CANFrame encodeBatteryStatus(float voltage, float current, float temperature);

#endif
