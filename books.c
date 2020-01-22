#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct onePupilBooks
{
    uint32_t MinBooks;
    uint32_t MaxBooks;
} ;
//unsigned int
static uint32_t howManyHappy(struct onePupilBooks *tab, unsigned int N, uint32_t booksNo);

static uint32_t howManyHappy(struct onePupilBooks *tab, unsigned int N, uint32_t booksNo)
{
//    unsigned int retVal=tab[0].MinBooks;
    uint32_t happyNo=0;
    
    for(unsigned int iter=0; iter<N; iter++)
    {
        if ((booksNo<= tab[iter].MaxBooks ) && (booksNo >= tab[iter].MinBooks))
        {
            happyNo++;
        }
    }
    return happyNo;
}

int main(int argc, char** argv)
{
    unsigned int N;
    struct onePupilBooks *onePupilBooks_tab;  

  scanf("%u",&N);
  onePupilBooks_tab = calloc(N, sizeof(struct onePupilBooks));
  if (NULL == onePupilBooks_tab)
  {
      printf("something wrong \n");
      return -1;
  }
  for(unsigned int iter=0; iter<N; iter++)
  {
      scanf("%u %u",&(onePupilBooks_tab[iter].MinBooks),&(onePupilBooks_tab[iter].MaxBooks) );
  }  
  uint32_t minBooksNumber=0U;
  uint32_t numberOfHappy=0U;

  for(unsigned int iter=0; iter<N; iter++)
  {
      numberOfHappy=howManyHappy(onePupilBooks_tab,N,onePupilBooks_tab[iter].MinBooks);
     printf("for %d -> %d \n",onePupilBooks_tab[iter].MinBooks,numberOfHappy);
      //if (minBooksNumber
  }
  free(onePupilBooks_tab);
  return 0;
}
    
