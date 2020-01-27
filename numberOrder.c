#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define SIZE_OF_NUMBER  uint16_t
//Compiler version gcc  6.3.0

SIZE_OF_NUMBER ChangeNrOrder(SIZE_OF_NUMBER nr);

SIZE_OF_NUMBER ChangeNrOrder(SIZE_OF_NUMBER nr)
{
    SIZE_OF_NUMBER result=nr;
    char *tab;
    uint16_t size = 1;
    uint16_t position=1;
    uint16_t res_position;
    uint16_t iter=0;
    for( size=1; ; size++)
    {
        if ((nr/(position*10) ==0) && (nr/(position*100) == 0))
        {
            break;
        }
        position=position*10;
    }
    tab = calloc(size, sizeof(char));
    result = 0;
    res_position = 1;
    for( ; position>0;position/=10)
    {
        tab[iter] =(char)(nr/position);
        //printf("%d %d %d\n",tab[iter],position,nr);
        nr = nr % position;
        result +=res_position*tab[iter];
        res_position*=10;
        iter++;
    }


    return result;
}


int main()
{
    SIZE_OF_NUMBER nr;
    scanf("%hu",&nr);

    printf("%d\n",ChangeNrOrder(nr));
    return 0;
}
