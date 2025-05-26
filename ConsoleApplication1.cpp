#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// Структура узла списка
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Инициализация пустого списка
Node* init_list() {
    return NULL;
}

// Добавление элемента в конец списка
Node* append(Node* head, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Ошибка выделения памяти\n");
        return head;
    }

    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    return head;
}

// Печать всех элементов списка
void print_list(Node* head) {
    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }

    Node* current = head;
    printf("Список: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Освобождение памяти
void free_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    Node* list = init_list();
    int choice, value;

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    printf("Реализация односвязного списка\n");

    while (1) {
        printf("\nМеню:\n");
        printf("1. Добавить элемент в конец списка\n");
        printf("2. Просмотреть список\n");
        printf("3. Выход\n");
        printf("Выберите действие: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("Введите значение для добавления: ");
            scanf_s("%d", &value);
            list = append(list, value);
            break;
        case 2:
            print_list(list);
            break;
        case 3:
            free_list(list);
            printf("Программа завершена\n");
            return 0;
        default:
            printf("Неверный выбор, попробуйте снова\n");
        }
    }
    return 0;
}