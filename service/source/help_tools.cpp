#include "help_tools.hpp"

#include "ws2tcpip.h"

static bool IsLittleEndianness() {
    static const int kValue = 1;

    return *reinterpret_cast<const char *>(&kValue) == kValue;
}

static const bool kLittleEndianness = IsLittleEndianness();

namespace cloud_storage::service {
    uint64_t htonll(uint64_t _value) {
        if (kLittleEndianness) {
            const uint32_t high_part = htonl(static_cast<uint32_t>(_value >> 32));
            const uint32_t low_part = htonl(static_cast<uint32_t>(_value & 0xFFFFFFFFLL));

            return static_cast<uint64_t>(low_part) << 32 | high_part;
        }
        else {
            return _value;
        }
    }

    uint64_t ntohll(uint64_t _value) {
        if (kLittleEndianness) {
            const uint32_t high_part = ntohl(static_cast<uint32_t>(_value >> 32));
            const uint32_t low_part = ntohl(static_cast<uint32_t>(_value & 0xFFFFFFFFLL));

            return static_cast<uint64_t>(low_part) << 32 | high_part;
        }
        else {
            return _value;
        }
    }
} // namespace cloud_storage::service