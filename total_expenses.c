#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define YES "Yes"
#define NO "No"

char *checkLeapYear(int year);
int main()
{
  uint8_t T;
  uint32_t *expenses;
  scanf("%hhu",&T);
  expenses = calloc(T,sizeof(uint32_t));
  for(uint8_t i=0; i<T;i++)
  {
    scanf("%u",&expenses[i]);
  }
  for(uint8_t i=0; i< T; i++)
  {
      float result = (float)expenses[i];
      if (expenses[i]>1000)
          result=0.9*result;
      printf("%.2f\n",result);
  }
  
  return 0;
} 
