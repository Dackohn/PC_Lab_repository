#include <stdbool.h> 
#include<conio.h>
#include <stdio.h>
#include<time.h>
#include<math.h>

int swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
int printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
}


int Bubble_sort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
 

        if (swapped == false)
            break;
    }
    printf("Sorted array(Bubble sort): \n");
    printArray(arr, n);
}
int Selection_sort(int arr[], int n)
{
    int i, j, min_idx;
 

    for (i = 0; i < n-1; i++)
    {

        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
    printf("Sorted array(Selection sort): \n");
    printArray(arr, n);
}
int Insertion_sort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("Sorted array(Insertion Sort): \n");
    printArray(arr, n);
} 
void Quick_Sort(int arr[], int low, int high, int n)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        Quick_Sort(arr, low, pi - 1, n);
        Quick_Sort(arr, pi + 1, high, n);
    }
}
int main()
{
    int si;int h;
    printf("The number of elements in array: ");
    scanf("%d", &si);
    printf("The array itself : \n");
    int arr[si];
    for(h=0; h<si;h++)
    scanf("%d" ,&arr[h]);
    int arr1[si];
    for(h=0;h<si;h++)
    arr1[h]=arr[h];
    double cpu_time_used;
     
    clock_t Bubble_time1 = clock();
    int n = sizeof(arr) / sizeof(arr[0]);
    Bubble_sort(arr,n);
    clock_t Bubble_time0 = clock();
    cpu_time_used = ((double) (Bubble_time0 - Bubble_time1)) / CLOCKS_PER_SEC;
    printf("\n %f seconds \n",cpu_time_used);
   
    for(h=0;h<si;h++)
    arr[h]=arr1[h];
    clock_t select_time1 = clock();
    Selection_sort(arr,n);
    clock_t select_time0 = clock();
    cpu_time_used = ((double) (select_time0-select_time1)) / CLOCKS_PER_SEC;
    printf("\n %f seconds \n",cpu_time_used);
   
    for(h=0;h<si;h++)
    arr[h]=arr1[h];
    clock_t insert_time1 = clock();
    Insertion_sort(arr,n);
    clock_t insert_time0 = clock();
    cpu_time_used = ((double) (insert_time0-insert_time1)) / CLOCKS_PER_SEC;
    printf("\n %f seconds \n",cpu_time_used);
    
    for(h=0;h<si;h++)
    arr[h]=arr1[h];
    clock_t Quick_time1 = clock();
    Quick_Sort(arr,0, n-1, n);
    printf("Sorted array(Quick sort): \n");
    printArray(arr, n);
    clock_t Quick_time0 = clock();
    cpu_time_used = ((double) (Quick_time0-Quick_time1)) / CLOCKS_PER_SEC;
    printf("\n %f seconds \n",cpu_time_used);
    
    getch();
    return 0;
}
/*input data 59	72	91	81	32
            71	79	91	91	89
            77	66	51	14	83
            47	18	55	83	15
            67	70	30	95	39
            13	77	75	85	72 
            80	78	13	97	62
            42	81	44	28	3
            3	45	50	16	32
            36	31	88	32	86
            41	51	77	81	77
            2	86	3	50	28
            33	9	68	1	68
            20	43	52	74	34*/
