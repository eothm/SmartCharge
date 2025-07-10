#include "CANBus.h"
#include <cstring>    
#include <sstream>
#include <iomanip>  
#include <cstdint>
#include <array>
#include <cstring> 

std::string CANFrame::toString() const {
    std::ostringstream oss;
    oss << "CAN ID: 0x" << std::hex << id << " Data: ";
    for (int i = 0; i < length; ++i) {
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)data[i] << " ";
    }
    return oss.str();
}

static void packUint16(std::array<uint8_t,8>& buffer, uint16_t value, size_t offset) {
    buffer[offset] = static_cast<uint8_t>(value & 0xFF);
    buffer[offset + 1] = static_cast<uint8_t>((value >> 8) & 0xFF);
}

CANFrame encodeBatteryStatus(float voltage, float current, float temperature) {
    CANFrame frame;
    frame.id = 0x101;
    frame.length = 6; 

    uint16_t v = static_cast<uint16_t>(voltage * 100);
    uint16_t i = static_cast<uint16_t>(current * 100);
    uint16_t t = static_cast<uint16_t>((temperature + 40) * 100);

    packUint16(frame.data, v, 0);
    packUint16(frame.data, i, 2);
    packUint16(frame.data, t, 4);

    return frame;
}


