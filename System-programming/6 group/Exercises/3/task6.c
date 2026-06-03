#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void terminate(char* err)
{
    perror(err);
    exit(EXIT_FAILURE);
}

int main(void)
{
    int status = mkdir("new_dir", 0777);
    if (stat < 0) terminate("Could not create new directory\n");

/*  Longer version:
    status = chdir("new_dir");
    if (status < 0) terminate("Could not change directory\n");

    status = symlink("not_existing", "still_not_existing");
    if (status < 0) terminate("Could not create symbolic link\n");

    status = chdir("..");
    if (status < 0) terminate("Could not change directory\n");

    status = rmdir("new_dir");
    if (status < 0) terminate("Could not remove directory\n");
*/
    
    status = symlink("not_existing", "new_dir/still_not_existing");
    if (status < 0) terminate("Could not create symbolic link\n");

    // unlink, otherwise folder wont be deleted

    status = rmdir("new_dir");
    if (status < 0) terminate("Could not remove directory\n");

    return 0;
}