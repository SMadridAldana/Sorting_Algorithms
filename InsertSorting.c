#include <stdio.h>
#include <stdlib.h>

int swap(int *firstIndex, int *secondIndex){
    int temp = *firstIndex;
    *firstIndex = *secondIndex;
    *secondIndex = temp; 
}

void PrintArray(int *myArray, int arraySize){
    printf("My array: ");
    for(int i = 0; i < arraySize; i++){
        printf("%i ", myArray[i]);
    }
    printf("\n");
}

void InsertSort(int * myArray, int arraySize){
    int low = myArray[0];

    for(int i = 1; i < arraySize; i++){
        if(myArray[i] < myArray[i-1]){
            for(int j = i; j > 0; j--){
                if(myArray[j-1] > myArray[j]){
                    swap(&myArray[j], &myArray[j-1]);
                }
                else break;
                PrintArray(myArray, 10);
            }
        }
    }
}

void main(){
    int myArray[] = {25, 9, 35, 6, 58, 14, 6, 15, 19, 21};
    PrintArray(myArray, 10);
    printf("\n");
    InsertSort(myArray, 10);
    printf("\n");
    PrintArray(myArray, 10);
}
