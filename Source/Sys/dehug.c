#include <debug.h>
#include <printf.h>
//#include <string.h>
#include <ctype.h>

int _dputs(const char *str)
{
	while(*str != 0) {
		_dputc(*str++);
	}

	return 0;
}

int _dprintf(const char *fmt, ...)
{
	char buf[256];
	int err;

	va_list ap;
	va_start(ap, fmt);
	err = vsnprintf(buf, sizeof(buf), fmt, ap);
	va_end(ap);

	dputs(ALWAYS, buf);
    //_dputs(buf);

	return err;
}

int _dvprintf(const char *fmt, va_list ap)
{
	char buf[256] = {0};
	int err;

	err = vsnprintf(buf, sizeof(buf), fmt, ap);

	dputs(ALWAYS, buf);
    //_dputs(buf);

	return err;
}
