/*
 * =====================================================================================
 *
 *       Filename:  signed.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09.10.2020 22:19:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    /*  this is giving warning about overflow of type  */
    int16_t var_i16 = 0x8000;
    /*  this will show correct value - it does some cast to bigger type */
    printf(" var int16 0x8000 == %d %d\n ",var_i16,var_i16-1);
    /*  here we change - sign to + */
    var_i16 -=1;
    printf(" var int16 0x8000-1 == %d\n ",var_i16);
    
    return 0;
}


