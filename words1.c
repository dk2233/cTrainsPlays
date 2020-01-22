#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_LETTER 40


typedef struct 
{
    char word[MAX_LETTER];
    unsigned char StatusOfWord;
    unsigned char OrderOfGiven;
    unsigned char NumberOfSame;
} oneWord_t;
//unsigned int
enum 
{
    NOT_TESTED=0,
    ALREADY_FOUND=1,
    WORD_MORE_THAN_ONCE=2
};
void howManySame(oneWord_t *tab,unsigned char i,unsigned int n);
int comparision(const void * a, const void *b );
int comparisionOlder(const void * a, const void *b );


int comparisionOlder(const void * a, const void *b )
{
    return ((oneWord_t *)a)->OrderOfGiven > ((oneWord_t *)b)->OrderOfGiven;
}

int comparision(const void * a, const void *b )
{
    return ((oneWord_t *)a)->NumberOfSame < ((oneWord_t *)b)->NumberOfSame;

}

void howManySame(oneWord_t *tab,unsigned char i,unsigned int n)
{
    for(uint8_t iter=0; iter<n; iter++)
    {
        //if (iter==i) continue;
        if (tab[iter].StatusOfWord == NOT_TESTED)
        {
            if (strcmp(tab[i].word,tab[iter].word)==0)
            {
                tab[i].NumberOfSame++;
                tab[iter].StatusOfWord = ALREADY_FOUND;
                if (tab[i].NumberOfSame>1)
                {
                    tab[iter].StatusOfWord=WORD_MORE_THAN_ONCE;
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
    unsigned int N;

    scanf("%u",&N);
    oneWord_t *AllWord = calloc(N, sizeof(oneWord_t));
    if (NULL == AllWord)
    {
        printf("something wrong \n");
        return -1;
    }

    for(unsigned int iter=0; iter<N; iter++)
    {
        scanf("%s",AllWord[iter].word);
        AllWord[iter].OrderOfGiven=iter;
    }  

    //    oneWord_t *copyOfWord;
    for(unsigned int iter=0; iter<N; iter++)
    {
        howManySame(AllWord, iter, N);
        //        if (AllWord[iter].StatusOfWord!=WORD_MORE_THAN_ONCE)
        //            printf("%s -> %d\n",AllWord[iter].word,AllWord[iter].NumberOfSame);
    }
    qsort(AllWord, N, sizeof(oneWord_t), &comparision);
    for(unsigned int iter=0; iter<N; iter++)
    {
        char sameNumber=0;
        for(unsigned int iterToCheckRest=iter; iter<N; iter++)
        {
            if ((AllWord[iterToCheckRest].NumberOfSame == AllWord[iter].NumberOfSame) &&
                    (AllWord[iterToCheckRest].StatusOfWord!=WORD_MORE_THAN_ONCE))
            {
                sameNumber++;
            }
            else
                break;
        } 
        if (sameNumber>1)
        {
            qsort(&(AllWord[iter]),sameNumber,sizeof(oneWord_t),&comparisionOlder);
        }
    }

    for(unsigned int iter=0; iter<N; iter++)
    {
        if (AllWord[iter].StatusOfWord!=WORD_MORE_THAN_ONCE)
            printf("%s ",AllWord[iter].word);

    }
    puts("\n");
    free(AllWord);
    return 0;
}



