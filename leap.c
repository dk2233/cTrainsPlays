#include <stdio.h>
#define YES "Yes"
#define NO "No"

//Compiler version gcc  6.3.0
char *checkLeapYear(int year);
int main()
{
  int T;
  unsigned int year;
  //printf("How many years:");
  scanf("%d",&T);
  for(int i=0; i<T;i++)
  {
    scanf("%d",&year);
    printf("%s\n",checkLeapYear(year));
  }
  
  return 0;
} 

char *checkLeapYear(int year)
{
  char *retVal=NO;
  if ((year % 400==0))
  {
      retVal= YES;
  }
  else if ((year %4 ==0) &&(year % 100!=0))
  {
    retVal = YES;
  }
  return retVal;
}
