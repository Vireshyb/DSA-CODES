#include <stdio.h>
#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *fp, *fp2;
    fp = fopen("read.txt", "r");
    fp2 = fopen("output.txt", "w");

    if (fp == NULL || fp2 == NULL) {
        printf("File not found\n");
        return 1;
    }

    int n;
    fscanf(fp, "%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &arr[i]);
    }

    bubbleSort(arr, n);

    for (int i = 0; i < n; i++) {
        fprintf(fp2, "%d ", arr[i]);
    }

    fclose(fp);
    fclose(fp2);

    return 0;
}



