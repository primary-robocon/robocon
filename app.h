#ifdef __cplusplus
extern "C" {
#endif

#include "ev3api.h"

#define MAIN_PRIORITY    (TMIN_APP_TPRI + 1)
#define TRACER_PRIORITY  (TMIN_APP_TPRI + 2)
#define CHANGE_PRIORITY  (TMIN_APP_TPRI + 3)

#ifndef STACK_SIZE
#define STACK_SIZE      (4096)
#endif /* STACK_SIZE */

#ifndef TOPPERS_MACRO_ONLY

extern void main_task(intptr_t exinf);
extern void tracer_task(intptr_t exinf);
extern void tracer_cyc(intptr_t exinf);
extern void tracer_line_change(intptr_t exinf);
void wait_start();
#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif
