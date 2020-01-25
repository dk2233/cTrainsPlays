#include  <stdio.h>
#include <stdint.h>
#include <math.h>
//Compiler version gcc  6.3.0
#define MAX_NUMBERS   100
#define MAX_VALUE     10000
#define MIN_VALUE     1
int main()
{
    uint16_t  numbers_a[MAX_NUMBERS];
    uint8_t T;
    scanf("%hhu",&T);
    if (T<1) T=1;
    if (T>MAX_NUMBERS) T=MAX_NUMBERS;
    for(uint8_t iter=0; iter<T; iter++)
    {
        scanf("%hu",&numbers_a[iter]);
        if (numbers_a[iter]>MAX_VALUE) numbers_a[iter]=MAX_VALUE;
        if (numbers_a[iter]<MIN_VALUE) numbers_a[iter]=MIN_VALUE;
    }
    for(uint8_t iter=0; iter<T; iter++)
    {
        uint16_t result = (uint16_t)sqrt(numbers_a[iter]);
        int16_t delta = (int16_t)(-numbers_a[iter]+(result+1)*(result+1));
//        printf(" delta between number and perfect square %d %i \n",result,(numbers_a[iter]-result*result));
//        printf(" delta between next perfect square %i \n",delta);
        if ((int16_t)(numbers_a[iter]-result*result)>delta)
            result++;
        printf("%d\n",result);
    }
    return 0;
}

