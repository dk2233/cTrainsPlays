#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE_OF_NUMBER uint32_t
#define MIN_PLAYER_NUMBER 1
#define MAX_NUMBER (uint32_t)1e+9

SIZE_OF_NUMBER HowManyAdmirers(SIZE_OF_NUMBER idPlayer,SIZE_OF_NUMBER playerNumber);

SIZE_OF_NUMBER HowManyAdmirers(SIZE_OF_NUMBER idPlayer, SIZE_OF_NUMBER playerNumber)
{
    SIZE_OF_NUMBER admirersNumber=0;
    //    printf("******* id: %d \n",idPlayer);
    for(SIZE_OF_NUMBER i=MIN_PLAYER_NUMBER;i <= playerNumber; i++)
    {
        if (i==idPlayer) break;
        //printf("%d \n",idPlayer);

        if ((idPlayer % i)==0) 
        {

            admirersNumber++;
            //printf("%d is admirer of %d \n",i,idPlayer);
        }
    }
    if ((admirersNumber % 2)!=0)
        printf("%d -> odd number of admirers %d \n",idPlayer,admirersNumber);
    return admirersNumber;
}

int main()
{
    uint8_t N;
    SIZE_OF_NUMBER *table;

    scanf("%hhu",&N);
    if (N>100) N=100;
    if (N<1) N=1;
    table = calloc(N,sizeof(SIZE_OF_NUMBER));
    for(uint8_t iter=0; iter<N; iter++)
    {
        scanf("%u",&table[iter]);
        if (table[iter]>MAX_NUMBER)
            table[iter]=MAX_NUMBER;
        else if (table[iter]<2)
            table[iter]=2;
    }
    for(uint8_t iter=0; iter<N; iter++)
    {
        SIZE_OF_NUMBER oddNumber=0;
        for(SIZE_OF_NUMBER nr=MIN_PLAYER_NUMBER; nr<=table[iter]; nr++)
        {
            if ((HowManyAdmirers(nr,table[iter]) % 2) !=0) oddNumber++; 
        }
        printf("%d\n",oddNumber);
    }

    return 0;
}
