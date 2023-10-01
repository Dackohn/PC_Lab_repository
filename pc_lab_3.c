#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
int random(int M,int N,int arr[M][N])
{
    int i;int j;
    srand(time(0));
    for(i=0;i<M;i++)
    {
        for (j=0;j<N;j++)
        {
        arr[i][j]=rand()%1000;
        printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
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
 
    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void Quick_Sort(int arr[], int low, int high, int n)
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        Quick_Sort(arr, low, pi - 1, n);
        Quick_Sort(arr, pi + 1, high, n);
    }
}
int main()
{
    int M;int N;
    printf("Number of lines: \n ");
    scanf("%d",&M);
    printf("Number of columns: \n");
    scanf("%d",&N);
    int i; int j;int o;int u;int k;
    o=N*M;
    int arr[M][N]; int arr_l[o];
    random(M,N,arr);
        for(i=0;i<M;i++)
    {
        for (j=0;j<N;j++)
        {

            arr_l[i*N+j]=arr[i][j];

        }
    
    }
        Quick_Sort(arr_l,0,o-1,o);
        printf("\n");
    printf("\n \n \n");
    k=0;
    int left=0;int right=N-1;int top=0;int bottom=M-1;
        while (left <= right && top <= bottom) 
        {
        for (i = left; i <= right; i++) 
        {
            arr[top][i] = arr_l[k++];
        }
        top++;

        for (i = top; i <= bottom; i++) 
        {
            arr[i][right] = arr_l[k++];
        }
        right--;

        if (top <= bottom) 
        {
            for (i = right; i >= left; i--) 
            {
                arr[bottom][i] = arr_l[k++];
            }
            bottom--;
        }

        if (left <= right) 
        {
            for (i = bottom; i >= top; i--) 
            {
                arr[i][left] = arr_l[k++];
            }
            left++;
        }
    }
    for (int i = 0; i < M; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}