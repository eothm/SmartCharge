#include "CANBus.h"
#include <cstring>    
#include <sstream>
#include <iomanip>   

std::string CANFrame::toString() const {
    std::ostringstream oss;
    oss << "CAN ID: 0x" << std::hex << id << " Data: ";
    for (int i = 0; i < length; ++i) {
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)data[i] << " ";
    }
    return oss.str();
}

static void packFloat(std::array<uint8_t, 8>& buffer, float value, size_t offset) {
    if (offset + sizeof(float) > buffer.size()) return;
    std::memcpy(&buffer[offset], &value, sizeof(float));
}

CANFrame encodeBatteryStatus(float voltage, float current, float temperature) {
    CANFrame frame;
    frame.id = 0x101; 

    packFloat(frame.data, voltage, 0);    
    packFloat(frame.data, current, 4);      

    return frame;
}
