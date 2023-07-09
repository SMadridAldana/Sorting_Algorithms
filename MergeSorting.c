#include <stdio.h>
#include <stdlib.h>

void PrintArray(int *myArray, int arraySize){
    printf("My array: ");
    for(int i = 0; i < arraySize; i++){
        printf("%i ", myArray[i]);
    }
    printf("\n");
}

void Merge(int * myArray, int left, int middle, int right){
    int lArraySize = ((middle-left)+1);
    int rArraySize = (right-middle);
    int *lTempArray = (int *) malloc(sizeof(int)*lArraySize);
    int *rTempArray = (int *) malloc(sizeof(int)*rArraySize);

    for(int i = 0; i < lArraySize; i++){
        lTempArray[i] = myArray[i+left]; 
    }

    for(int i = 0; i < rArraySize; i++){
        rTempArray[i] = myArray[i+middle+1]; 
    }

    int counterL = 0;
    int counterR = 0;

    while(counterL < lArraySize && counterR < rArraySize){
        if(lTempArray[counterL] < rTempArray[counterR]){
            myArray[left] = lTempArray[counterL];
            left ++;
            counterL ++;
        }
        else{
            myArray[left] = rTempArray[counterR];
            left ++;
            counterR ++;
        }
    }

    while(counterL < lArraySize){
        myArray[left] = lTempArray[counterL];
        left ++;
        counterL ++;
    }

    while(counterR < rArraySize){
        myArray[left] = rTempArray[counterR];
        left ++;
        counterR ++;
    }

    PrintArray(myArray, 8); /*Optional for debuging*/
    free(rTempArray);
    free(lTempArray);

}

void MergeSort(int *myArray, int arraySize, int left, int right){
    if(arraySize > 1){
        int middle = (left + right)/2;
        MergeSort(myArray, (middle-left)+1, left, middle);
        MergeSort(myArray, (right-middle), middle+1, right);
        Merge(myArray, left, middle, right);
    }
}

void main(){
    int myArray[] = {25, 9, 3, 600, 85, 24, 12, 36};
    PrintArray(myArray, 8);
    printf("\n");
    MergeSort(myArray, 8, 0, 7);
    printf("\n");
    PrintArray(myArray, 8);
}