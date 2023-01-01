//
// Created by Moshe Nahshon on 26/12/2022.
//
#include <stdio.h>

#include "header.h"


void shift_element(int* arr, int i){
    int tmp = *(arr);
    for(int j = 0;j < i;j++){
       int tmp2 = *(arr + j + 1);
        *(arr + j + 1) = tmp;
        tmp = tmp2;

    }
}
void insertion_sort(int* arr , int len){
    int val, prev;
    for (int i = 1;i < len; i++){
        val = *(arr + i);
        prev = i - 1;
        while(prev >= 0  && *(arr + prev) > val){
            prev--;
        }
        int diff = i - (prev + 1);
        shift_element(arr + prev + 1,diff);
        *(arr + prev +1) = val;
    }
}
int main(){
   int arr [50] ;
   for(int i = 0;i < 50;i++){
       scanf("%d",arr + i);
   }

   insertion_sort(arr,50);

   for (int i = 0;i < 49 ;i++) {
       printf("%d,",*(arr + i));
   }
   printf("%d\n",*(arr + 49));

    return 0;
}