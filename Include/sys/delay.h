#ifndef SLEEP_H_
#define SLEEP_H_

#include <stdint.h>
#include <io.h>
#ifdef __cplusplus
extern "C" {
#endif

typedef uint32_t msecond_t;
typedef uint32_t usecond_t;

#ifdef __tms_struct_required_
struct tms {
	clock_t	tms_utime;		/* user time */
	clock_t	tms_stime;		/* system time */
	clock_t	tms_cutime;		/* user time, children */
	clock_t	tms_cstime;		/* system time, children */
};
#endif

extern void mdelay(__IO msecond_t delay_ms);
extern void udelay(__IO usecond_t delay_us);

#ifdef __cplusplus
}
#endif

#endif /* SLEEP_H_ */
