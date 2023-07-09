#include <stdio.h>
#include <stdlib.h>

int swap(int *firstIndex, int *secondIndex){
    int temp = *firstIndex;
    *firstIndex = *secondIndex;
    *secondIndex = temp; 
}

int *CopyIntArray(int *originalArray, int arraysize){
    int *copiedArray = (int *) malloc(sizeof(int)*arraysize);
    for(int i = 0; i < arraysize; i++) copiedArray[i] = originalArray[i];
    return copiedArray;
}

void PrintArray(int *myArray, int arraySize){
    printf("My array: ");
    for(int i = 0; i < arraySize; i++){
        printf("%i ", myArray[i]);
    }
    printf("\n");
}

int correctIndex(int *myArray, int arraySize, int left, int right){

    int i = left+1;
    int j = right;
    int correctIDX;

    while(i < j){
        while((myArray[j] > myArray[left]) && (i < j)){
            j--;
        }
        while((myArray[i] < myArray[left]) && (i < j)){
            i++;
        }
        swap(&myArray[i], &myArray[j]);
    }


    if(i == left+1 && myArray[left+1] > myArray[left]) correctIDX = left;
    else correctIDX = i;

    swap(&myArray[left], &myArray[correctIDX]);
    PrintArray(myArray, 7);
    return correctIDX;

}

void QuickSort(int *myArray, int arraySize, int left, int right){
    if(arraySize > 1){
        int pivot = correctIndex(myArray, arraySize, left, right);
        QuickSort(myArray, pivot-left, left, pivot-1);
        QuickSort(myArray, right-pivot, pivot+1, right);
    }
}

void main(){
    int myArray[] = {25, 79, 3, 6, 858, 24, 6};
    PrintArray(myArray, 7);
    printf("\n");
    QuickSort(myArray, 7, 0, 6);
    printf("\n");
    PrintArray(myArray, 7);
}