#include <iostream>
using namespace std;

class Heap{ //min heap
public:
    int *Harr;
    int size_a;
    int size_h;
    Heap(int max) {
        size_a = max;
        size_h = 0;
        Harr = new int[size_a];
    }
    int parent(int i) {
        return (i - 1) / 2;
    }
    int right(int i) {
        return i * 2 + 2;
    }
    int left(int i) {
        return 2 * i + 1;
    }
    void insert(int key) {
        if (size_a == size_h) {
            cout << "heap full";
            return;
        }
        size_h++;
        int i = size_h -1;
        Harr[i]  = key;
        while (i != 0 && Harr[i] < Harr[parent(i)]) {
            swap(Harr[i], Harr[parent(i)]);
            i = parent(i);
        }
    }
    void heapify(int i) {
        int small = i;
        int r = right(i);
        int l = left(i);
        if (l < size_h && Harr[l] < Harr[small]){
            small = l;
        }
        if (r < size_h && Harr[r] < Harr[small]){ // more important
            small = r;
        }
        if (small != i) {
            swap(Harr[i], Harr[small]);
            heapify(small);
        }
    }
    void buildHeap() {
        for (int i = size_h / 2 - 1; i >= 0 ; i--) {// why like that because here we find first parent 
            heapify(i);
        }
    }

    void HEapsort() {
        buildHeap();

        for (int i = size_h - 1; i >= 0; i--) {
            swap(Harr[0], Harr[i]);
            size_h--;
            heapify(0);
        }

        //что мы тут делаем когда унас есть куча через  buildHeap() после этого мы отправляем элимент вверх а самый маленький элемент вниз после этого мы 
        // производим процедуру обратно 
        // таким образом она сортируется 

        // а вот почему 0 ? отправляем под конец
    }
    int display() {
        for (int i = 0 ;i < size_a ; i++) {
            cout << Harr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int n;
    int arr[] = {4, 2, 5, 3 , 1 , 77 };
    Heap a(6);
    for (int i = 0 ; i < 6; i++) {
        a.insert(arr[i]);
    }
    a.HEapsort();
    a.display();

}