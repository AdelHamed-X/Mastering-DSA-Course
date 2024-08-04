#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
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

int set(struct Array *arr, int index, int value)
{
    int i;

    if (index < 0 || index > arr->length)
        return -1;

    for (i = arr->length; i > index; i--)
        arr->A[i] = arr->A[i - 1];
    
    arr->length++;
    arr->A[i] = value;
    return i;
}

int sum(struct Array arr)
{
    if (!arr.A)
        return -1;
    
    int i, total = 0;

    for (i = 0; i < arr.length; i++)
    {
        total += arr.A[i];
    }

    return total;
}

int avg(struct Array arr)
{
    if (!arr.A)
        return -1;
    
    int i, total = 0;

    for (i = 0; i < arr.length; i++)
    {
        total += arr.A[i];
    }

    return total / arr.length;
}

void reverse(struct Array *arr)
{
    int i, j;

    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
}

int checkSorted(struct Array arr)
{
    int i;

    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
            return -1; // Unsorted
    }
    return 0; // sorted
}

struct Array *mergeArrays(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;

    struct Array *arr3;

    arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }

    for (;i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];
    for (;j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = arr1.length + arr2.length;
    arr3->size = arr1.size + arr2.size;
    
    return arr3;
}

struct Array *unionArrays(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;

    struct Array *arr3;

    arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] < arr2.A[j])
            arr3->A[k++] = arr1.A[i++];
        else if (arr2.A[j] < arr1.A[i])
            arr3->A[k++] = arr2.A[j++];
        else
        {
            arr3->A[k++] = arr2.A[j++];
            i++;
        }
    }

    for (;i < arr1.length; i++)
        arr3->A[k++] = arr1.A[i];
    for (;j < arr2.length; j++)
        arr3->A[k++] = arr2.A[j];

    arr3->length = k;
    arr3->size = arr1.size + arr2.size;
    
    return arr3;
}

struct Array *intersection(struct Array arr1, struct Array arr2)
{
    int i = 0, j = 0, k = 0;

    struct Array *arr3;

    arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i < arr1.length && j < arr2.length)
    {
        if (arr1.A[i] == arr2.A[j])
            arr3->A[k++] = arr1.A[i];
        i++;
        j++;
    }

    arr3->length = k;
    arr3->size = arr1.size + arr2.size;
    
    return arr3;
}

int findMissingElement(struct Array *arr)
{
    int low, high, diff, i;

    low = arr->A[0];
    high = arr->A[arr->length - 1];
    diff = arr->A[low] - low;

    for (i = low; i < high; i++)
    {
        if (diff != (arr->A[i] - i))
        {
            while(diff < (arr->A[i] - i))
            {
                printf("%d\n", (i + diff));
                diff++;
            }
        }
    }
    return 0;
}

int findMissingElementHash(struct Array *arr)
{
    int low, high, i;

    low = arr->A[0];
    high = arr->A[arr->length - 1];

    int h[high];

    for (i = low; i < high; i++)
        h[arr->A[i]] = 1;
    for (i = low + 1; i < high; i++)
        if (h[i] != 1) printf("%d\n", i);
    
    return 0;
}

void findDuplicates(struct Array *arr)
{
    int lastDuplicate = 0, i;

    for (i = 0; i < arr->length - 1; i++)
    {
        if (arr->A[i] == arr->A[i + 1] && arr->A[i] != lastDuplicate)
        {
            printf("%d\n", arr->A[i]);
            lastDuplicate = arr->A[i];
        }
    }
}

void findDuplicatesCount(struct Array *arr)
{
    int lastDuplicate = 0, i, j = 0;

    for (i = 0; i < arr->length - 1; i++)
    {
        if (arr->A[i] == arr->A[i + 1])
        {
            j = i + 1;
            while (arr->A[i] == arr->A[j]) j++;
            printf("%d is appearing %d times!\n", arr->A[i], j - i);
            i = j - 1;
        }
    }
}

int main()
{
    struct Array arr;

    arr.length = 9;
    arr.A = (int *)malloc(sizeof(int) * arr.length);

    int values[] = {1, 2, 2, 5, 6, 6, 6, 9, 10};
    for (int i = 0; i < arr.length; i++) {
        arr.A[i] = values[i];
    }

    findDuplicatesCount(&arr);

    return 0;
}