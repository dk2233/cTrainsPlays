#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_BOOKS      1.0e+9
struct onePupilBooks
{
    uint32_t MinBooks;
    uint32_t MaxBooks;
} ;


static uint32_t howManyIsHappy(struct onePupilBooks *tab, unsigned int N, uint32_t booksNo);

static uint32_t howManyIsHappy(struct onePupilBooks *tab, unsigned int N, uint32_t booksNo)
{
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


void showAllPairs(struct onePupilBooks* tab,uint32_t N)
{
    for(unsigned int i=0; i < N ; i++)
    {
        printf("%d -> min:%d max:%d \n",i, tab[i].MinBooks, tab[i].MaxBooks);
    }
}   

int main(int argc, char** argv)
{
    unsigned int N;
    uint32_t minStudentBooksValue=(uint32_t)MAX_BOOKS;
    uint32_t maxBooksNumber=1U;
    uint32_t maxNumberOfHappy=0U;
    uint32_t minNumberOfBooks=0U;
    struct onePupilBooks *onePupilBooks_tab;  

    scanf("%u",&N);
    if (N>10000) N=10000;
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
//    printf("%u\n",UINT32_MAX);
//    printf("%u\n",(uint32_t)MAX_BOOKS);
    
    for(unsigned int iter=0; iter<N; iter++)
    {
        if (maxBooksNumber<onePupilBooks_tab[iter].MaxBooks)
            maxBooksNumber=onePupilBooks_tab[iter].MaxBooks;

        if (minStudentBooksValue>onePupilBooks_tab[iter].MinBooks)
            minStudentBooksValue=onePupilBooks_tab[iter].MinBooks;
    }
  
    //printf("min:%d max:%d\n",minStudentBooksValue, maxBooksNumber);
    minNumberOfBooks=minStudentBooksValue;
    maxNumberOfHappy=howManyIsHappy(onePupilBooks_tab,N,minNumberOfBooks);
    uint32_t actualNr; 
    for(unsigned int bookCheck = minStudentBooksValue; bookCheck<maxBooksNumber; bookCheck++)
    {
        actualNr = howManyIsHappy(onePupilBooks_tab, N, bookCheck);

        if (maxNumberOfHappy<actualNr)
        {
            maxNumberOfHappy=actualNr;
            minNumberOfBooks = bookCheck ;
        } 
    }
    printf("%d %d\n",minNumberOfBooks, maxNumberOfHappy);

    free(onePupilBooks_tab);
    
    return 0;
}




