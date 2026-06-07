/*
Expectation: by the time the array is printed in the child process it will be sorted in a part 
or even not sorted at all, depends on how the both processes start
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <wait.h>
#include <sys/types.h>
#include <unistd.h>

#include "shm.h"

#define SIZE 10000

void print(int* arr, int size)
{
    printf("[ ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("]\n");
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
// A function to implement bubble sort
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)    
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int main(void)
{
    // Create SHM
    int shm_id = shmget(IPC_PRIVATE, SIZE * sizeof(int), IPC_CREAT | 0600);
    if (shm_id == -1) terminate(ERRSHMGET);

    // Attach SHM
    int* arr = (int*) shmat(shm_id, NULL, 0);
    if (arr == (void*) -1) terminate(ERRSHMAT);
    
    int lower = 0, upper = 99;

    // Write to SHM
    for (int i = 0; i < SIZE; i++) arr[i] = (rand() % (upper - lower + 1)) + lower;

    // Read from SHM
    printf("Before sorting: ");
    print(arr, SIZE);

    pid_t pid = fork();
    if (pid == -1) terminate("FORK ERROR!");
    else if (pid == 0) // child
    {
        printf("PRINTING IN CHILD: ");
        print(arr, SIZE);
    }
    else // parent
    {
        bubble_sort(arr, SIZE);
        
        int status;
        wait(&status);

        // Detach SHM
        if (shmdt(arr) == -1) terminate(ERRSHMDT);

        // Delete SHM
        if(shmctl(shm_id, IPC_RMID, NULL) == -1) terminate(ERRSHMCTL);
    }

    return 0;
}