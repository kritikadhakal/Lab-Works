// Iterative algorithms (GCD,FIBONACCI,FACTORIAL,LINEAR SEARCH)
#include <stdio.h>

int GCD(int a, int b);
int factorial(int n);
void fibonacci(int n);          
int linearSearch(int arr[], int n, int key);

int main() {
    int choice;
    do {
        printf("\nMenu\n");
        printf("1. GCD\n");
        printf("2. Factorial\n");
        printf("3. Fibonacci Series\n");
        printf("4. Linear Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int a, b;
            printf("Enter two numbers: ");
            scanf("%d%d", &a, &b);
            printf("GCD = %d\n", GCD(a, b));
        }
        else if (choice == 2) {
            int n;
            printf("Enter a number: ");
            scanf("%d", &n);
            printf("Factorial = %d\n", factorial(n));
        }
        else if (choice == 3) {
            int n;
            printf("Enter number of terms: ");
            scanf("%d", &n);
            fibonacci(n);
        }
        else if (choice == 4) {
            int n, key, i;
            int arr[50];
            printf("Enter number of elements: ");
            scanf("%d", &n);
            printf("Enter elements:\n");
            for (i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }
            printf("Enter element to search: ");
            scanf("%d", &key);
            int position = linearSearch(arr, n, key);
            if (position == -1)
                printf("Element not found\n");
            else
                printf("Element found at position %d\n", position + 1);
        }
        else if (choice == 5) {
            printf("Exiting the program\n");
        }
        else {
            printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}

int GCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;   // fixed
        a = temp;
    }
    return a;
}

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

void fibonacci(int n) {       
    int a = 0, b = 1, c;
    printf("Fibonacci Series: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", a);      
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
