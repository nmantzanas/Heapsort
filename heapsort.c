//
//  main.c
//  heap_sort
//
//  Created by Nico Mantzanas on 30.03.20.
//  Copyright © 2020 Nico Mantzanas. All rights reserved.
//

#include <stdio.h>
#include <math.h>


void Heapify(int A[], int s, int i)
{
    int m, temp;
    m = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if (l < s && A[l] > A[m]) {
        m = l;
    }
    if (r < s && A[r] > A[m]) {
        m = r;
    }
    if (m != i) {
        temp = A[i];
        A[i] = A[m];
        A[m] = temp;
        Heapify(A, s, m);
    }
}

void HeapSort(int A[], int n)
{
    int s, i, temp;
    s = n;
    
    for (i = n / 2 - 1; i >= 0; i--) {
        Heapify(A, s, i);
    }
    
    for (i = n-1; i >= 0; i--) {
        temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        Heapify(A, i, 0);
    }
}

void printArray(int A[], int n)
{
    int i;
    
    printf("[");

    for (i = 0; i < n-1; i++) {
        printf("%d, ", A[i]);
    }
    i = n;
    printf("%d", A[n-1]);
    printf("]\n");
}

int main()
{
    int A[] = {5, 13, 2, 25, 7, 17, 20, 8, 4};
    int n = sizeof(A) / sizeof(A[0]);
    HeapSort(A, n);
    printArray(A, n);
    
}

