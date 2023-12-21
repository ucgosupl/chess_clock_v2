#ifndef TIME_H_
#define TIME_H_

#include <stdint.h>

#define MS_IN_S		1000
#define S_IN_MIN	60
#define MIN_IN_H	60

#define MS_IN_H		((MS_IN_S) * (S_IN_MIN) * (MIN_IN_H))
#define MS_IN_MIN	((MS_IN_S) * (S_IN_MIN))

#define MS2H(ms)	((ms) / MS_IN_H)
#define MS2MIN(ms)	((ms) / MS_IN_MIN)
#define MS2S(ms)	((ms) / MS_IN_S)

#define S2MS(s)					((s) * MS_IN_S)

#define TIME_TO_MS(h, m, s)		((h) * MS_IN_H + (m) * MS_IN_MIN + S2MS(s))



typedef uint32_t ms_t;

#endif /* TIME_H_ */
