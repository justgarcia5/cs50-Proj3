//
//  main.c
//  JustinGProj3
//
//  Created by Justin Garcia on 4/10/21.
//

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 18
#define UPPER_LIMIT 20
#define LOWER_LIMIT 12
#define DATA_UPPER_LIMIT 90
#define DATA_LOWER_LIMIT 10

void RandomPrint(int [], int);
void FindMinMax(int [], int);
void FindAverage(int [], int);
int SmallestNum(int [], int);
void SortArray(int [], int);
void swap(int *a, int *b);
void FindMedian(int [], int);

int main(int argc, const char * argv[])
{
    int array [ARRAY_SIZE + 1];

    int size;
        
    size = rand() % (UPPER_LIMIT - LOWER_LIMIT + 1) + LOWER_LIMIT;
    
    RandomPrint(array, size);
    FindMinMax(array, size);
    FindAverage(array, size);
    SortArray(array, size);
    FindMedian(array, size);

    return 0;
}

void RandomPrint(int array [], int size)
{
    int i;
    
    printf("Justin Garcia - Project 3\n\n");
    printf("Array Size: %d\n\n", size);
    printf("Array Elements: \n");
    
    for(i = 0; i < size; i++)
    {
        array [i] = rand() % (DATA_UPPER_LIMIT - DATA_LOWER_LIMIT) + DATA_LOWER_LIMIT;
        printf("%d ", array [i]);
    }
    printf("\n\n");
}

void FindMinMax(int array [], int size)
{
    int i;
    int min, max;

    max = 0;
    min = 100;
    
    for(i = 0; i < size; i++)
    {
        if(min > array [i])
            min = array [i];
        
        if(max < array [i])
            max = array [i];
    }
    printf("Maximum = %d, Minimum = %d\n\n", max, min);

}
void FindAverage(int array [], int size)
{
    int total, i, average;
    total = 0;
    average = 0;
    
    for(i = 0; i < size; i++)
    {
        total += array[i];
    }
    average = total / size;
    printf("Average = %d\n\n", average);
}

void SortArray(int array [], int size)
{
    int index, last = size - 1;
    printf("Sorted Array:\n");
    while(last > 0)
    {
        index = SmallestNum(array, last);
        swap(&array[last], &array[index]);
        printf("%d ", array[last]);
        last--;
    }
    printf("%d", array[0]);
    printf("\n\n");
    array = array[0] + array;
}

int SmallestNum(int array [], int size)
{
    int i, index = 0;
    
    for(i = 0; i <= size; i++)
    {
        if(array[index] > array[i])
        {
            index = i;
        }
    }
    return index;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void FindMedian(int array [], int size)
{
    int half, median;
    if(size % 2 != 0){
        printf("odd");
        half = (size + 1) / 2;
        median = half;
    }
    else
    {
        half = size / 2;
        median = (array[half] + array[half + 1]) / 2;
        printf("Median = %d\n\n", median);
    }
}
