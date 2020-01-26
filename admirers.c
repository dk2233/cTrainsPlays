#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE_OF_NUMBER uint32_t
#define MIN_PLAYER_NUMBER 1

SIZE_OF_NUMBER HowManyAdmirers(SIZE_OF_NUMBER idPlayer,SIZE_OF_NUMBER playerNumber);

SIZE_OF_NUMBER HowManyAdmirers(SIZE_OF_NUMBER idPlayer, SIZE_OF_NUMBER playerNumber)
{
    SIZE_OF_NUMBER admirersNumber=0;
    //    printf("******* id: %d \n",idPlayer);
    for(SIZE_OF_NUMBER i=MIN_PLAYER_NUMBER;i <= playerNumber; i++)
    {
        if (i==idPlayer) continue;
        //printf("%d \n",i);

        if ((idPlayer % i)==0) 
        {

            admirersNumber++;
            //        printf("%d is admirer of %d \n",i,idPlayer);
        }
    }
    return admirersNumber;
}

int main()
{
    uint8_t N;
    SIZE_OF_NUMBER *table;

    scanf("%hhu",&N);
    table = calloc(N,sizeof(SIZE_OF_NUMBER));
    for(uint8_t iter=0; iter<N; iter++)
    {
        scanf("%u",&table[iter]);
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
