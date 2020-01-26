#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_LENGTH  100

char* changeToUpper(char* word);
char* changeToUpper(char* word)
{
    uint8_t i=0;
    char delta = 'A'-'a';
    while(word[i])
    {
        word[i] += delta;
        i++;
    }
    return word;
}
int main()
{
    uint8_t T;
    char **word;
    scanf("%hhu",&T);
    word = calloc(T,sizeof(char*));
    for(uint8_t i=0; i<T;i++)
    {
        word[i]=calloc(MAX_LENGTH, sizeof(char));
        scanf("%s",word[i]);
    }
    for(uint8_t i=0; i< T; i++)
    {
        printf("%s\n",changeToUpper(word[i]));
    }

    return 0;
} 
