#include <setjmp.h>

#define try if(setjmp(env)==0)
#define catch else

#define throw(e) strncpy(error, e, 256); longjmp(env, 1);

jmp_buf env;
char error[256] = {0};
