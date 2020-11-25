#pragma once
#include <atoi/export.h>

// Convert a string to an integer.
// Zero is returned if a null pointer is passed in or a conversion can not be performed.
#ifdef __cplusplus
ATOI_EXPORT extern "C" int my_atoi(char const *c);
#else
ATOI_EXPORT int my_atoi(char const *c);
#endif
