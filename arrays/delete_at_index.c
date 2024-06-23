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

int main()
{
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};

    // append(&arr, 2);

    // add(&arr, 10, 2);

    delete(&arr, 1);

    display(arr);

    return 0;
}