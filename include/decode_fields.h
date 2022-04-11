#pragma once

#include "fields.h"
#include "requests.h"

inline LiquidityIndicator convert_liquidity_indicator(int status)
{
    switch (status) {
    case 0: return LiquidityIndicator::Added;
    case 1: return LiquidityIndicator::Removed;
    default: return LiquidityIndicator::None;
    }
}

inline BreakReason convert_reason(char status)
{
    switch (status) {
    case 'E': return BreakReason::Erroneous;
    case 'C': return BreakReason::Consent;
    case 'S': return BreakReason::Supervisory;
    case 'X': return BreakReason::External;
    default: return BreakReason::Unknown;
    }
}

#define FIELD(name, protocol_type, ctype)                                                                                   \
    inline ctype extract_field_##name(const std::vector<unsigned char> & message, std::size_t position, std::size_t length) \
    {                                                                                                                       \
        return extract_##protocol_type(message, position, length);                                                          \
    }

#define BIT_FIELD(name, length, ctype)                                                                                      \
    inline ctype extract_field_##name(const std::vector<unsigned char> & message, std::size_t position, std::size_t offset) \
    {                                                                                                                       \
        return convert_##name(extract_bitfield(message, position, offset, length));                                         \
    }

#define CHAR_FIELD(name, ctype)                                                                         \
    inline ctype extract_field_##name(const std::vector<unsigned char> & message, std::size_t position) \
    {                                                                                                   \
        return convert_##name(extract_char(message, position));                                         \
    }

#define ONEBIT_FIELD(name)                                                                                                 \
    inline bool extract_field_##name(const std::vector<unsigned char> & message, std::size_t position, std::size_t offset) \
    {                                                                                                                      \
        return extract_bitfield(message, position, offset, 1) != 0;                                                        \
    }

#include "fields.inl"
