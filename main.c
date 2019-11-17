#include <stdio.h>
 
// function to sort the subsection a[i .. j] of the array a[]
void merge_sort(int i, int j, int a[], int aux[]) {
    if (j <= i) {
        return;     // the subsection is empty or a single element
    }
    int tengah = (i + j) / 2;

    // left sub-array is a[i .. mid]
    // right sub-array is a[mid + 1 .. j]
    
    merge_sort(i, tengah, a, aux);     // sort the left sub-array recursively
    merge_sort(tengah + 1, j, a, aux);     // sort the right sub-array recursively

    int pointer_left = i;       // pointer_left points to the beginning of the left sub-array
    int pointer_right = tengah + 1;        // pointer_right points to the beginning of the right sub-array
    int k;      // k is the loop counter

    // we loop from i to j to fill each element of the final merged array
    for (k = i; k <= j; k++) {
        if (pointer_left == tengah + 1) {      // left pointer has reached the limit
            aux[k] = a[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {        // right pointer has reached the limit
            aux[k] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right]) {        // pointer left points to smaller element
            aux[k] = a[pointer_left];
            pointer_left++;
        } else {        // pointer right points to smaller element
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }

    for (k = i; k <= j; k++) {      // copy the elements from aux[] to a[]
        a[k] = aux[k];
    }
}


int main() {
  int angka[100], aux[100], masukan, i, d, swap;
 
  printf("Masukkan banyak elemen angka :\n");
  scanf("%d", &masukan);
 
  printf("Masukan %d angka\n", masukan);
 
  for (i = 0; i < masukan; i++)
    scanf("%d", &angka[i]);
 
  merge_sort(0, masukan - 1, angka, aux);
 
  printf("Printing the sorted array:\n");
 
  for (i = 0; i < masukan; i++)
     printf("%d\n", angka[i]);
 
  return 0;
}