#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  DIR * dir = opendir(".");
  struct dirent *direntry;
  printf("Statistics for directory: .\n");
  int size = 0;
  while (direntry = readdir(dir)) {
    if (direntry->d_type == DT_REG) {
      struct stat buf;
      stat(direntry->d_name, &buf);
      size += (int)(buf.st_size);
      printf("Regular file: %s\n", direntry->d_name);
    }
    else if(direntry->d_type != DT_REG){
      printf("Directory: %s\n", direntry->d_name);
    }
  }
  closedir(dir);
  printf("Total Directory Size: %d\n", size);
  return 0;
}