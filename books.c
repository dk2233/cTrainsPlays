/* 
   Students of Dcoder school love Mathematics. They love to read a variety of Mathematics books.
   To make sure they remain happy,their Mathematics teacher decided to get more books for them. 
   A student would become happy if there are at least X Mathematics books in the class and 
   not more than Y books because they know "All work and no play makes Jack a dull boy".
   The teacher wants to buy a minimum number of books to make the maximum number of students happy.
   */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_BOOKS      1.0e+9

#define COMPILE_FOR_DCODER 1

struct onePupilBooks
{
    uint32_t MinBooks;
    uint32_t MaxBooks;
} ;

enum typesOf_show
{
    SHOW_MIN,
    SHOW_MAX,
} ;


void SimplestAlgorithm(struct onePupilBooks * arrayWithPupilBooks, uint32_t N );

void BetterAlgorithm(struct onePupilBooks * sortedMin, \
        struct onePupilBooks * sortedMax,\
        uint32_t N );

void showAllNumbersinLines(struct onePupilBooks * tab, uint32_t N , enum typesOf_show kindOf);

int compareToRaise(const void *a, const void *b);

static uint32_t howManyIsHappy(struct onePupilBooks *tab, unsigned int N, uint32_t booksNo);

static uint32_t howManyIsHappy(struct onePupilBooks *tab, unsigned int N, uint32_t booksNo)
{
    uint32_t happyNo=0;

    for(unsigned int iter=0; iter <N; iter++)
    {
        if ((booksNo <= tab[iter].MaxBooks ) && (booksNo >= tab[iter].MinBooks))
        {
            happyNo++;
        }
    }
    return happyNo;
}

int compareToRaise(const void *a, const void *b)
{
    return (*(uint32_t *)a) >(*(uint32_t *)b); 
}

int compareToRaiseMax(const void *a, const void *b)
{
    return (((struct onePupilBooks *)a)->MaxBooks) >(((struct onePupilBooks *)b)->MaxBooks ); 
}


void showAllPairs(struct onePupilBooks* tab,uint32_t N)
{
#ifndef COMPILE_FOR_DCODER
    for(unsigned int i=0; i < N ; i++)
    {
        printf("%d -> min:%d max:%d \n",i, tab[i].MinBooks, tab[i].MaxBooks);
    }
#endif
}   

void showAllNumbersinLines(struct onePupilBooks * tab, uint32_t N , enum typesOf_show kindOf)
{
#ifndef COMPILE_FOR_DCODER
    for (unsigned int i = 0U; i < N; i++)
    {
        uint32_t toBeShown = tab[i].MinBooks;
        switch(kindOf)
        {
            case(SHOW_MIN):
                toBeShown = tab[i].MinBooks;

                break;
            case(SHOW_MAX):
                toBeShown = tab[i].MaxBooks;
            default:
                break;
        }
        printf("%d ", toBeShown);
    }
    puts("\n");
#endif
}

void SimplestAlgorithm(struct onePupilBooks * arrayWithPupilBooks, uint32_t N )
{
    uint32_t maxBooksNumber=1U;
    uint32_t maxNumberOfHappy=0U;
    uint32_t minNumberOfBooks=0U;
    uint32_t minStudentBooksValue=(uint32_t)MAX_BOOKS;
    uint32_t numberOfHappy;

    /*  here is the main heart of the procedure
     *  assumption is it is enough to compare each students MIN with other students ranges */
    for(unsigned int iter=0; iter < N; iter++)
    {
        numberOfHappy = howManyIsHappy(arrayWithPupilBooks,N,arrayWithPupilBooks[iter].MinBooks);
#ifndef COMPILE_FOR_DCODER
        printf("for students nr %d its min books to be happy %d -> we have number of happy students %d \n",iter, arrayWithPupilBooks[iter].MinBooks,numberOfHappy);
#endif
    }
    /*     showAllPairs(tabCpyRiseMin,N);
     *     showAllPairs(tabCpyRiseMax,N);
     */
    minStudentBooksValue =  MAX_BOOKS;
    /*  fill min i max with starting values */
    for(unsigned int iter=0; iter < N; iter++)
    {
        if (maxBooksNumber < arrayWithPupilBooks[iter].MaxBooks)
            maxBooksNumber = arrayWithPupilBooks[iter].MaxBooks;

        if (minStudentBooksValue>arrayWithPupilBooks[iter].MinBooks)
            minStudentBooksValue = arrayWithPupilBooks[iter].MinBooks;
    }

#ifndef COMPILE_FOR_DCODER
    printf("min:%d max:%d\n",minStudentBooksValue, maxBooksNumber);
#endif
    minNumberOfBooks = minStudentBooksValue;
    maxNumberOfHappy = howManyIsHappy(arrayWithPupilBooks,N,minNumberOfBooks);

    uint32_t actualNr; 
    for(unsigned int bookCheck = minStudentBooksValue; bookCheck < maxBooksNumber; bookCheck++)
    {
        actualNr = howManyIsHappy(arrayWithPupilBooks, N, bookCheck);

        if (maxNumberOfHappy < actualNr)
        {
            maxNumberOfHappy = actualNr;
            minNumberOfBooks = bookCheck ;
        } 
    }
    printf("%d %d\n",minNumberOfBooks, maxNumberOfHappy);

}

void BetterAlgorithm(struct onePupilBooks * sortedMin, \
        struct onePupilBooks * sortedMax,\
        uint32_t N )
{
    uint32_t maxNumberOfHappy=0U;
    uint32_t minNumberOfBooks=0U;
    uint32_t numberOfHappy;

    minNumberOfBooks = sortedMin[0].MinBooks;
    maxNumberOfHappy = 0U;
    numberOfHappy = 0U;
    int j;


    for(int i = 0U, j = 0U; (i < N) && (j < N); )
    {
        if (sortedMin[i].MinBooks <= sortedMax[j].MaxBooks)
        {
            numberOfHappy += 1U;
            i+=1U;
        }
        else if (sortedMin[i].MinBooks > sortedMax[j].MaxBooks)
        {
            numberOfHappy -= 1U;
            j+=1U;
        }

        if (maxNumberOfHappy < numberOfHappy)
        {
            maxNumberOfHappy = numberOfHappy;
            minNumberOfBooks = sortedMin[i-1].MinBooks;
        }
    }
    printf("%d %d\n",minNumberOfBooks, maxNumberOfHappy);

}
int main(int argc, char** argv)
{
    unsigned int N;
    uint32_t minStudentBooksValue=(uint32_t)MAX_BOOKS;
    uint32_t maxBooksNumber=1U;
    uint32_t maxNumberOfHappy=0U;
    uint32_t minNumberOfBooks=0U;
    uint32_t numberOfHappy;
    struct onePupilBooks *onePupilBooks_tab;  
    /*  how many students N */
    scanf("%u",&N);
    if (N>10000) N=10000;
    onePupilBooks_tab = calloc(N, sizeof(struct onePupilBooks));
    if (NULL == onePupilBooks_tab)
    {
        printf("something wrong \n");
        return -1;
    }
    /*  now take min books and max books for each of the students */
    for(unsigned int iter=0; iter < N; iter++)
    { 
        scanf("%u %u",&(onePupilBooks_tab[iter].MinBooks),&(onePupilBooks_tab[iter].MaxBooks) );
    }  

    struct onePupilBooks *tabCpyRiseMin = calloc(N,sizeof(struct onePupilBooks) );
    struct onePupilBooks *tabCpyRiseMax = calloc(N,sizeof(struct onePupilBooks) );
    memcpy(tabCpyRiseMin, onePupilBooks_tab, sizeof(struct onePupilBooks)*N);
    memcpy(tabCpyRiseMax, onePupilBooks_tab, sizeof(struct onePupilBooks)*N);

    showAllPairs(tabCpyRiseMin,N);
    showAllPairs(tabCpyRiseMax,N);


    qsort((void*)&(tabCpyRiseMin[0].MinBooks), N, sizeof(struct onePupilBooks), &compareToRaise);
    qsort((void*)tabCpyRiseMax, N, sizeof(struct onePupilBooks), &compareToRaiseMax);

    showAllNumbersinLines(tabCpyRiseMin, N, SHOW_MIN); 
    showAllNumbersinLines(tabCpyRiseMax, N, SHOW_MAX); 


    //    SimplestAlgorithm(onePupilBooks_tab, N);
    BetterAlgorithm(tabCpyRiseMin, tabCpyRiseMax, N);
    free(onePupilBooks_tab);
    free(tabCpyRiseMin);
    free(tabCpyRiseMax);
    return 0;
}




