#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

// Структура для узла связного списка
struct Node {
    int data;
    Node* next;
    Node (int data) {
        this->data = data;
        next = nullptr;
    }
};

// Функция для вставки узла в конец связного списка
// почему тут поинтер и амперсант? поинтер отвечает за указатель амперсант тут играть роль как использовать оригинал
void insert(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Функция для нахождения индекса ближайшего числа к цели
int findNearest(Node* head, int target) {
    int minDistance = INT_MAX; // Инициализация максимальным значением
    int index = 0;
    int nearestIndex = 0;
    Node* temp = head;

    // Проходим по всему списку
    while (temp != nullptr) {
        int distance = abs(temp->data - target);
        if (distance < minDistance) {
            minDistance = distance;
            nearestIndex = index;
        }
        index++;
        temp = temp->next;
    }
    return nearestIndex;
}

int main() {
    int n, target;

    // Ввод количества элементов в списке
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    // Ввод элементов списка и создание связного списка
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insert(head, tail, value);
    }

    // Ввод целевого числа
    cin >> target;

    // Поиск и вывод индекса ближайшего числа
    cout << findNearest(head, target) << endl;

    return 0;
}