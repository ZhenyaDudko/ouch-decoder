#if !defined(FIELD) || !defined(BIT_FIELD) || !defined(ONEBIT_FIELD) || !defined(CHAR_FIELD)
#error You need to define FIELD and BIT_FIELD and ONEBIT_FIELD and CHAR_FIELD
#else

// field_name, protocol_type, c++ type, start_position in message, length
FIELD(cl_ord_id, text, std::string)
FIELD(match_number, integer, int)
FIELD(filled_volume, integer, int)
FIELD(price, price, double)
FIELD(counterpart, text, std::string)

ONEBIT_FIELD(internalized);
ONEBIT_FIELD(self_trade);

// field_name, length, ctype
BIT_FIELD(liquidity_indicator, 2, LiquidityIndicator);

CHAR_FIELD(reason, BreakReason);

#undef FIELD
#undef BIT_FIELD
#undef ONEBIT_FIELD
#undef CHAR_FIELD

#endif
