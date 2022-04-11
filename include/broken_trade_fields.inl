#if !defined(FIELD) || !defined(SKIP) || !defined(CHAR_FIELD)
#error You need to define FIELD and SKIP and CHAR_FIELD macro
#else

SKIP(9)
FIELD(cl_ord_id, 14)
FIELD(match_number, 4)
CHAR_FIELD(reason);

#endif
