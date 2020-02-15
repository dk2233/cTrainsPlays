#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define SIZE_OF_NUMBER int16_t

void BubbleSort(SIZE_OF_NUMBER *tab, uint8_t length);
void ShowArray(SIZE_OF_NUMBER *tab, uint8_t length);

void ShowArray(SIZE_OF_NUMBER *tab, uint8_t length)
{
    for(uint8_t i=0; i<length; i++)
    {
        printf("%d ",tab[i]);
    }
    putchar('\n');
    putchar('\n');
}

void BubbleSort(SIZE_OF_NUMBER *tab, uint8_t length)
{
    SIZE_OF_NUMBER temp;
    char isChangeNeeded=1;
    while(0!=isChangeNeeded )
    {
        isChangeNeeded=0;
        for(uint8_t i=0; i<(length-1);i++ )
        {
            if (tab[i]>tab[i+1])
            {
                temp=tab[i];
                tab[i] = tab[i+1];
                tab[i+1]=temp;
                isChangeNeeded=1;
            }
        }
    }

}

int main(int argc, char **argv)
{
    uint8_t N;
    SIZE_OF_NUMBER *table;

    if (argc>1)
    {
        N=atoi(argv[1]);
    }
    else
    {
        scanf("%hhu",&N);
    }
    table = calloc(N,sizeof(SIZE_OF_NUMBER));
    srand((unsigned int)clock());
    
    for(uint8_t iter=0; iter<N; iter++)
    {
        //scanf("%hi",&table[iter]);
        //
        table[iter]=(SIZE_OF_NUMBER )rand();
    }
    ShowArray(table,N);

    BubbleSort(table,N);

    ShowArray(table,N);


    return 0;
}
