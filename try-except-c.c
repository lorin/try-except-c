#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
#include <sys/stat.h>

#include "except.h"

void print_stat_info(struct stat buf);

int main(int argc, char *argv[]) {
  struct stat buf;

  try {

    if(argc!=2) {
      char err[128];
      snprintf(err, 128, "Invalid number of arguments: %d", argc);
      throw(err);
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

  return 0;
}


void print_stat_info(struct stat buf) {
  printf("device: %d\n", buf.st_dev);
  printf("inode: %llu\n", buf.st_ino);
  printf("inode protection mode: %d\n", buf.st_mode);
  printf("# of hard-links: %d\n", buf.st_nlink);
  printf("uid: %d\n", buf.st_uid);
  printf("gid: %d\n", buf.st_gid);
}
