// Merge Sort, Heap sort, Quick Sort, Randomized quick sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ---------- MERGE SORT ---------- */
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; j = 0; k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/* ---------- HEAP SORT ---------- */
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

/* ---------- QUICK SORT ---------- */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* ---------- RANDOMIZED QUICK SORT ---------- */
int randomPartition(int arr[], int low, int high) {
    int random = low + rand() % (high - low + 1);

    int temp = arr[random];
    arr[random] = arr[high];
    arr[high] = temp;

    return partition(arr, low, high);
}

void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

/* ---------- PRINT ---------- */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* ---------- MAIN ---------- */
int main() {
    int arr[100];
    int n, choice;

    srand(time(NULL));

    do {
        printf("\n====== SORTING MENU ======\n");
        printf("1. Merge Sort\n");
        printf("2. Heap Sort\n");
        printf("3. Quick Sort\n");
        printf("4. Randomized Quick Sort\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) {
            printf("Program terminated.\n");
            break;
        }

        printf("Enter number of elements to sort: ");
        scanf("%d", &n);

        if (n <= 0 || n > 100) {
            printf("Invalid number of elements!\n");
            continue;
        }

        printf("Enter %d elements:\n", n);
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);

        printf("\nSorting using selected algorithm...\n");

        switch (choice) {
            case 1:
                mergeSort(arr, 0, n - 1);
                break;
            case 2:
                heapSort(arr, n);
                break;
            case 3:
                quickSort(arr, 0, n - 1);
                break;
            case 4:
                randomizedQuickSort(arr, 0, n - 1);
                break;
            default:
                printf("Invalid choice! Try again.\n");
                continue;
        }

        printf("Sorted array:\n");
        printArray(arr, n);

    } while (1);

    return 0;
}
 