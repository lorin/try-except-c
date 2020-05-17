#include <setjmp.h>

jmp_buf env;
const int N = 256;
char error[N] = {0};

#define try if(setjmp(env)==0)
#define catch else
