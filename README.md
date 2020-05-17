# Exceptions in C with setjmp/longjmp

A little experiment to play with setjmp/longjmp functions to emulate exception handling in C.

I implemented `try`, `catch`, and `throw` as macros in [except.h].

You can see them in action in [try-except-c.c]:

```c
  try {

    if(argc!=2) {
      throw("Wrong number of arguments\nUsage: try-except-c path");
    }

    char *path = argv[1];
    if(stat(path, &buf)<0) {
      throw(strerror(errno));
    }

    print_stat_info(buf);

  } catch {
    fprintf(stderr, "Error: %s\n", error);
    return -1;
  }
```
