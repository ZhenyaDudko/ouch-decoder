#include "decode_fields.h"

namespace {

void set_mmt(char (&mmt)[15], char trading_mode, char transaction_category, char algorithm_indicator)
{
    char temp[] = "1  ------P ---";
    temp[1] = trading_mode;
    temp[2] = transaction_category;
    temp[10] = algorithm_indicator;
    std::copy(std::begin(temp), std::end(temp), mmt);
}

} // namespace

#define SKIP(length) \
    position += length;

#define FIELD(name, length)                                                 \
    request_details.name = extract_field_##name(message, position, length); \
    position += length;

#define BIT_FIELD(name, offset) \
    request_details.name = extract_field_##name(message, position, offset);

#define CHAR_FIELD(name)                                            \
    request_details.name = extract_field_##name(message, position); \
    position += 1;

ExecutionDetails decode_executed_order(const std::vector<unsigned char> & message)
{
    ExecutionDetails request_details;
    std::size_t position = 0;
#include "executed_order_fields.inl"
    set_mmt(request_details.mmt, message[40], message[41], message[42]);
    return request_details;
}

BrokenTradeDetails decode_broken_trade(const std::vector<unsigned char> & message)
{
    BrokenTradeDetails request_details;
    std::size_t position = 0;
#include "broken_trade_fields.inl"
    set_mmt(request_details.mmt, message[28], message[29], message[30]);
    return request_details;
}

#undef FIELD
#undef SKIP
#undef BIT_FIELD
#undef CHAR_FIELD
