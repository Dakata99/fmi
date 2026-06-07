#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   struct stat sb;

   if (stat(argv[1], &sb) == -1) {
     perror("stat");
     exit(EXIT_SUCCESS);
   }

   mode_t mode = sb.st_mode;

   mode = mode | 0020;
   mode = mode & ~0001;
   
   if (chmod(argv[1], mode) == -1) {
     perror("chmod");
     exit(EXIT_SUCCESS);
   }

   exit(EXIT_SUCCESS);
}

