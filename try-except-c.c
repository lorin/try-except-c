#include <setjmp.h>
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include <sys/stat.h>


jmp_buf env;
const int N = 256;
char error[N] = {0};

#define TRY if(setjmp(env)==0)
#define CATCH else

void print_stat_info(struct stat buf) {
  printf("device: %d\n", buf.st_dev);
  printf("inode: %llu\n", buf.st_ino);
  printf("inode protection mode: %d\n", buf.st_mode);
  printf("# of hard-links: %d\n", buf.st_nlink);
  printf("uid: %d\n", buf.st_uid);
  printf("gid: %d\n", buf.st_gid);
}

int main(int argc, char *argv[]) {

  TRY {

    if(argc!=2) {
      snprintf(error, N, "Invalid number of arguments: %d", argc);
      longjmp(env, 1);
    }

    char *path = argv[1];
    struct stat buf;
    if(stat(path, &buf)<0) {
      strerror_r(errno, error, N);
      longjmp(env, 1);
    }

    print_stat_info(buf);


  } CATCH {
    fprintf(stderr, "Error: %s\n", error);
    return -1;
  }

  return 0;
}
