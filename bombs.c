/*
 * =====================================================================================
 *
 *       Filename:  bombs.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03.02.2020 20:28:33
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

#define TYPE_OF_CITY  uint32_t 

struct CityLayout
{
    TYPE_OF_CITY HowManyBuilding;
    TYPE_OF_CITY HowManyDestroy;
    TYPE_OF_CITY *LocationsOfBuildings; 
} ;

int main(int argc, char **argv)
{
    struct CityLayout layout;

    scanf("%u",&layout.HowManyBuilding);
    scanf("%u",&layout.HowManyDestroy);
    layout.LocationsOfBuildings=calloc(layout.HowManyBuilding, sizeof(TYPE_OF_CITY));

    for(TYPE_OF_CITY i=0; i<layout.HowManyBuilding; i++)
    {
        scanf("%u",&layout.LocationsOfBuildings[i]);
    }


    for(TYPE_OF_CITY i=0; i<layout.HowManyBuilding; i++)
    {
        printf("%d ",layout.LocationsOfBuildings[i]);
    }

    return 0;
}
