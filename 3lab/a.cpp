#include <iostream>
using namespace std;

bool BinarySearch(int arr[], int n, int l, int r)
{
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (arr[mid] == n)
            return true;
        else if (arr[mid] < n)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return false;
}

int main()
{
    // 1 part
    int R;
    cin >> R;
    int findA[R];
    for (int i = 0; i < R; i++)
    {
        cin >> findA[i];
    }

    // 2 part
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int mu = n * m;
    int arr1[mu];
    // give elements
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int index = 0;
    // colect element like snike in  arr1
    for (int i = n - 1; i >= 0; i--)
    {
        if (i % 2 == 0)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                
                arr1[index] = arr[i][j];
                index++;
            }
        }
        else
        {
            for (int j = 0; j < m; j++)
            {
                arr1[index] = arr[i][j];
                index++;
            }
        }
    }

    int l = 0, r = index - 1;
    for (int i = 0; i < R; i++)
    {
        bool result = BinarySearch(arr1, findA[i], l, r);
        if (result == true)
        {
            for (int g = 0; g < n; g++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (findA[i] == arr[g][j])
                    {
                        cout << g << " " << j << endl;
                    }
                }
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
}