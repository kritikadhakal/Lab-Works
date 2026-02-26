//Selection problem with divide and conquer approach

#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    int j;
    for(j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

int randomPartition(int arr[], int low, int high){
    int random = low + rand()%(high - low + 1);
    int temp = arr[random];
    arr[random] = arr[high];
    arr[high] = arr[high];
    arr[high] = temp;
    return partition(arr,low,high);
}

int quickSelect(int arr[], int low, int high, int k){
    if(low <= high){
        int pivotindex = randomPartition(arr, low, high);
        if(pivotindex == k)
        return arr[pivotindex];
        else if (pivotindex > k)
        return quickSelect(arr, low, pivotindex - 1, k);
        else
        return quickSelect(arr, pivotindex + 1, high, k);
    }
    return -1;
}

int main(){
    int arr[] = {11, 9, 5, 18, 6, 1, 4, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    int result = quickSelect(arr,0,n-1,k-1);
    if(result != 1)
    printf("%d-th smallest element is %d\n",k,result);
    else
    printf("Invalid input!\n");
    return 0;
}


/* // Selection problem with divide and conquer approach (Quick Select)
// User input version

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    int j;
    for(j = low; j < high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

int randomPartition(int arr[], int low, int high){
    int random = low + rand() % (high - low + 1);
    swap(&arr[random], &arr[high]);   // correct swap
    return partition(arr, low, high);
}

int quickSelect(int arr[], int low, int high, int k){
    if(low <= high){
        int pivotindex = randomPartition(arr, low, high);

        if(pivotindex == k)
            return arr[pivotindex];
        else if(pivotindex > k)
            return quickSelect(arr, low, pivotindex - 1, k);
        else
            return quickSelect(arr, pivotindex + 1, high, k);
    }
    return -1;
}

int main(){
    int n, k, i;

    srand(time(NULL)); // seed random generator

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter value of k (to find k-th smallest element): ");
    scanf("%d", &k);

    if(k < 1 || k > n){
        printf("Invalid input!\n");
        return 0;
    }

    int result = quickSelect(arr, 0, n-1, k-1);

    printf("%d-th smallest element is %d\n", k, result);

    return 0;
}
 */