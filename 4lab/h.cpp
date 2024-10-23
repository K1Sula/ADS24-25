#include <stdio.h>
#include <algorithm>
void solve(int arr[], int id, int coef)
{
    if (id < 1)
        return;

    printf("%i ", arr[id]);
    if (coef < 1)
        return;
    solve(arr, id - coef, coef / 2);
    solve(arr, id + coef, coef / 2);
}

int main(void)
{

    int n;
    scanf("%i", &n);
    int size = (1 << n);
    int arr[size];
    arr[0] = 0;
    for (int i = 1; i < size; i++)
        scanf("%i", &arr[i]);

    std::sort(arr, arr + size);

    solve(arr, (1 << (n - 1)), (n > 1 ? (1 << (n - 2)) : 0));
}