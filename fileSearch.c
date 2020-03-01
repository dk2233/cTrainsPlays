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
    char *strTmp;

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
        /*
         *found specific char 
         */
        strTmp=strchr(str1,'a');
        if (strTmp!=NULL)
        {
            printf("\'a\' in = \"%s\"\n",strTmp);
        }
        /*
         * found specific word
         */

        strTmp=strstr(str1,"Plugin");
        if (strTmp !=NULL)
        {
            printf("found %s\n in %s",strTmp,str1);
        }


        printf("%s\n",str1 );
    }


    return 0;
}
