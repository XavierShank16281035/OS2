#include <stdio.h>
#include <unistd.h>

int main()
{
    fork();
    printf("hello");
    return 0;
}