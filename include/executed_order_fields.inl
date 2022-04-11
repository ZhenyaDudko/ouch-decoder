#if !defined(FIELD) || !defined(SKIP) || !defined(BIT_FIELD)
#error You need to define FIELD and SKIP and BIT_FIELD
#else

SKIP(9)
FIELD(cl_ord_id, 14)
FIELD(filled_volume, 4)
FIELD(price, 4)
SKIP(1)
FIELD(match_number, 4)
FIELD(counterpart, 4)
SKIP(3)
BIT_FIELD(internalized, 5)
BIT_FIELD(self_trade, 7);
BIT_FIELD(liquidity_indicator, 3);

#endif
