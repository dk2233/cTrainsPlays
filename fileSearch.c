#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_CHAR  100 

int main(int argc, char** argv)
{
    if (argc<2)
    {
        printf(" give file name \n");
        return 1;

    }

    FILE *fileStruct;

    fileStruct = fopen(argv[1],"r");

    if (fileStruct == NULL)
    {
        printf(" wrong file name\n"); 
        return 1;
    }

    char* str1 = calloc(NUMBER_OF_CHAR,sizeof(char));
    while(1)
    {

        str1 = fgets(str1, NUMBER_OF_CHAR, fileStruct);
        if (str1==NULL)
            break;
        if ( strchr(str1,EOF) )
        {
            printf("%s\n",str1);
            break;
        }


        printf("%s\n",str1 );
    }


    return 0;
}
