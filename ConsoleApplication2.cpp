#include <stdio.h>

// Функция для обмена элементов
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Функция разделения массива и возврата индекса опорного элемента
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Опорный элемент
    int i = (low - 1);      // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            i++;  // Увеличиваем индекс меньшего элемента
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Основная функция быстрой сортировки
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi - индекс разделения, arr[pi] теперь на правильном месте
        int pi = partition(arr, low, high);

        // Рекурсивно сортируем элементы перед разделением и после
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Функция для печати массива
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Пример использования
int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Исходный массив:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Отсортированный массив:\n");
    printArray(arr, n);
    return 0;
}