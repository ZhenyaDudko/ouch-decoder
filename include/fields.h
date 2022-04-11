#pragma once

#include <string>
#include <vector>

inline std::string extract_text(const std::vector<unsigned char> & message, std::size_t start_position, std::size_t length)
{
    while (length > 0 && message[start_position + length - 1] == ' ') {
        length--;
    }
    return std::string(message.begin() + start_position, message.begin() + start_position + length);
}

inline unsigned extract_integer(const std::vector<unsigned char> & message, std::size_t start_position, std::size_t length)
{
    unsigned value = 0;
    for (std::size_t i = 0; i < length; i++) {
        value = (value << 8) + message[start_position++];
    }
    return value;
}

inline double extract_price(const std::vector<unsigned char> & message, std::size_t start_position, std::size_t length)
{
    return extract_integer(message, start_position, length) / 10000.0;
}

inline int extract_bitfield(const std::vector<unsigned char> & message, std::size_t position, std::size_t offset, std::size_t length)
{
    return ((message[position] & (((1u << length) - 1) << (offset))) >> (offset));
}

inline char extract_char(const std::vector<unsigned char> & message, std::size_t position)
{
    return message[position];
}
