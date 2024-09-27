#include <stdio.h>

#define SIZE 10

void print_array(int *arr, int size);
int search(int *arr, int size, int x);

int main() {
  int data[SIZE] = {2, 8, 10, 15, 21, 28, 33, 36, 40, 48};
  int value;

  print_array(data, SIZE);

  while (1) {
    printf("Enter a value to search (-1 to quit): ");
    scanf("%d", &value);

    if (value == -1) {
      break;
    }

    int index = search(data, SIZE, value);
    if (index != -1) {
      printf("%d is found at index %d.\n", value, index);
    } else {
      printf("%d is not in the array.\n", value);
    }
  }

  return 0;
}

void print_array(int *arr, int size) {
  printf("Array contents:\n");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int search(int *arr, int size, int x) {
  int low = 0;
  int high = size - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == x) {
      return mid;
    } else if (arr[mid] < x) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}
