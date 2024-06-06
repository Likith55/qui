#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    while (1) {
        while (i <= high && a[i] <= pivot) {
            i++;
        }
        while (j >= low && a[j] > pivot) {
            j--;
        }
        if (i < j) {
            // Swap elements at i and j
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            break;
        }
    }

    // Swap pivot element with element at j
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quick_sort(int a[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(a, low, high);
        quick_sort(a, low, pivotIndex - 1);
        quick_sort(a, pivotIndex + 1, high);
    }
}

int main() {
    int n;
    int a[200000];
    double clk;
    clock_t starttime, endtime;

    printf("Enter the number of student records: \n");
    scanf("%d", &n);

    if (n > 200000) {
        printf("Number of records exceeds the maximum limit.\n");
        return 1;
    }

    printf("The roll numbers are:\n");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;  // Generating random roll numbers
        printf("%d\t", a[i]);
    }
    printf("\n");

    starttime = clock();
    quick_sort(a, 0, n - 1);
    endtime = clock();
    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("Sorted roll numbers are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}
