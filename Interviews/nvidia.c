#include <stdio.h>

int countleadingzeroes(int x){
    int count=0;
    int sawOne=0;
    int i=0;
    if (x<=0)return -1;
    while(!sawOne)
    {
        sawOne= 0x80000000 & (x << i++);
        count++;

    }
    return count-1;
}
void main()
{
    int x = 301989888;
    printf("In the number %i there are...",x);
    printf("%i leading zeroes",countleadingzeroes(x));
}