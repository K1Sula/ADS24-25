#include <iostream>
#include <string>
// Зачем нужен узел?
// Когда мы создаем связный список, мы хотим хранить не только данные, но и ссылки на другие узлы (элементы) списка.
//head -> (1, next) -> (2, next) ->  nullptr
using namespace std;
class Node {
public:
    int data; // integer it can be value 
    Node* next; // pointer for next node 
    // here we have question what`s happen here?
    /*
    Node rigth now is data type. So it`s mean we create Node pointer 
    */
    Node (int data) { // это конструктор
        this->data = data;
        next = nullptr;
    }
};


int main() {
    Node *head = new Node(1);// Создаем первый узел со значением 1 
    // это динамический память а не массив 
    Node *newelemnt = new Node(2);

    head -> next = newelemnt;// тут мы даем адрес нового элемента в head

    Node* current = head; // Указатель для обхода списка
    while (current != nullptr) {
        cout << current -> data << " ";
        current = current -> next;

    }

    current = head;
    while (current != nullptr) {
        Node *nextEle = current -> next;
        delete current;
        current = nextEle;
    }

    return 0;
}

/*
3. Создание узлов
Теперь давай посмотрим на строчку:

cpp
Копировать код
head->next = new Node(2);
new Node(2): Создается новый узел со значением 2.

Когда этот узел создается, его конструктор устанавливает:
data = 2
next = nullptr (поскольку на момент создания этот узел не связан с другим узлом)
head->next = ...: Здесь мы присваиваем указателю next в узле, на который указывает head, адрес нового узла, который мы только что создали.
*/