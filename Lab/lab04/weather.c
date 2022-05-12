#include <stdio.h>

int main(void){
    int temp;
    int difference;
    printf("Enter the temperature: ");
    scanf("%d",&temp);
    if( temp > 25 ){
        difference = temp - 25;
        printf("I wish it was %d degrees cooler.\n",difference);
        if(temp >= 40){
            printf("It is boiling!\n");
        }
    } else if ( temp < 25){
        difference = 25 - temp;
        printf("I wish it was %d degrees warmer.\n",difference);
        if(temp <= 10){
            printf("I am freezing!\n");
        }
    } else {
        printf("Nice weather we are having.\n");
   } 
    return 0;
}
