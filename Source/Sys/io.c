#include <stdint.h>
#include <stdarg.h>
#include "rh850f1l_rlin.h"
#define DEBUG_PRINT

void (*fputc)(char c);

#if defined DEBUG_PRINT
#define _fputc(c) fputc(c)
#else
#define _fputc(c)
#endif

void _dputc(char c)
{
    char ch = c;

	if (ch == '\n') {
		_dputc('\r');
	}
	_fputc(c);
}
