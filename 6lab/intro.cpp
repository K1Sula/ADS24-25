#include <iostream>
using namespace std;
#include <stdlib.h>//note
#include <time.h>//note

using namespace std;

int partition(int* arr, int beg, int end){
    srand(time(NULL));

    int pivot = beg+rand()%(end-beg);//beg--end

    swap(arr[end], arr[pivot]);

    int i = beg - 1;

    for (int j = beg; j < end; j++)//note:end is a default pivot
    {
        if(arr[j]<=arr[end]){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[end],arr[i+1]);
    return i+1;
}

// divide and conquer
void quickSort(int* arr, int beg, int end){
    if(beg<end){
        int p = partition(arr, beg, end);
        quickSort(arr,beg, p-1);
        quickSort(arr,p+1,end);
    }
}

int main(){
    int arr[7] = {5,4,7,3,6,1,2};

    quickSort(arr,0,6);

    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}