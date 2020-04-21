#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIZE_OF_NUMBER int16_t

void ShowArray(SIZE_OF_NUMBER *tab, uint8_t length);

//Compiler version gcc  6.3.0
void ShowArray(SIZE_OF_NUMBER *tab, uint8_t length)
{
    for(uint8_t i=0; i<length; i++)
    {
        printf("%d ",tab[i]);
    }
    putchar('\n');
}

int main()
{
    uint16_t N,k;
    SIZE_OF_NUMBER *tab;
    scanf("%hu %hu",&N,&k);
    tab=malloc(N*sizeof(SIZE_OF_NUMBER));

    if (tab==NULL)
    {
        printf("malloc error\n");
        return 1;
    }

    for(uint8_t i=0;i<N;i++)
    {
        scanf("%hd",(tab+i));
    }

    //ShowArray(tab,N);
    int32_t highest=tab[0];
    int32_t sum=highest;
    uint8_t count=1;

    //printf("%d\n",N);

    for(uint8_t i=1; i<N;i++)
    {
        if ((tab[i-1]<tab[i])&&(count<k))
        {
            sum+= tab[i];
            count++;
        }
        else if((tab[i-1]<tab[i])&&(count==k))
        {
            sum+=tab[i];
            sum-=tab[i-k];

        }
        else
        {
            if (highest<sum)
            {
                highest=sum;
            }
            sum=tab[i];
            count=1;
        }

    }
    if (highest<sum)
    {
        highest=sum;
    }

    printf("%d\n",highest);


    return 0;
}
