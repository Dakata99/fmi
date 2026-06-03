#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <utime.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   struct stat sb;
   struct utimbuf tb;

   if (stat(argv[1], &sb) == -1) {
     perror("stat");
     exit(EXIT_SUCCESS);
   }

   tb.actime = sb.st_atime - 3600;
   tb.modtime = sb.st_mtime + 60;

   if (utime(argv[1], &tb) == -1) {
     perror("chmod");
     exit(EXIT_SUCCESS);
   }

   exit(EXIT_SUCCESS);
}

