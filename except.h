#include <setjmp.h>

#define try if(setjmp(env)==0)
#define catch else

#define throw(e) strncpy(error, e, N); longjmp(env, 1);

jmp_buf env;
const int N = 256;
char error[N] = {0};
