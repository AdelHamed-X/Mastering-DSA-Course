#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};


void display(struct Array arr)
{
    int i;

    for (i = 0; i < arr.length; i++)
    {
        printf("%d\n", arr.A[i]);
    }
}

void append(struct Array *arr, int value)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = value;
}

void add(struct Array *arr, int value, int index)
{
    if (arr->size < index < 0)
    {
        printf("Index is out of range!");
        return;
    }

    int i;

    for (i = arr->length; i > index; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->length++;
    arr->A[i] = value;
}

void delete(struct Array *arr, int index)
{
    if (arr->length < index < 0)
    {
        printf("Index is out of range!");
        return;
    }
    
    int i;

    for (i = index; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->length--;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int LinearSearch(struct Array *arr, int value)
{
    int i, temp;

    for (i = 0; i < arr->length; i++)
    {
        // ***** Normal linear search *****
        // if (arr->A[i] == value)
        //     return i;

        // ***** Improved linear search (Transposition) *****
        if (arr->A[i] == value)
        {
            swap(&arr->A[i], &arr->A[i - 1]);

            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array *arr, int value)
{
    int low = 0;
    int high = arr->length - 1;
    int mid;

    while(low <= high)
    {
        mid = (low + high) / 2;
        if(value == arr->A[mid])
            return mid;
        else if(value > arr->A[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int RecursiveBinarySearch(struct Array *arr, int low, int high, int value)
{
    int mid = (low + high) / 2;

    if(value == arr->A[mid])
        return mid;
    else if(value > arr->A[mid])
        return RecursiveBinarySearch(arr, mid + 1, high, value);
    else
        return RecursiveBinarySearch(arr, low, mid - 1, value); 
}

int get(struct Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    // append(&arr, 2);

    // add(&arr, 10, 2);

    // delete(&arr, 1);

    // printf("%d\n", LinearSearch(&arr, 5));

    // printf("%d\n", BinarySearch(&arr, 3));

    // int low = 0;
    // int high = arr.length - 1;
    // printf("%d\n", RecursiveBinarySearch(&arr, low, high, 5));

    printf("%d\n", get(arr, 3));

    display(arr);

    return 0;
}