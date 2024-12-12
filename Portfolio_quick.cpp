#include<iostream>
using namespace std;

#define MAX 100

int partition(int A[MAX], int l, int r)
{
    int p = A[l];
    int i = l;
    int j = r + 1;

    do
    {
        do
        {
            i++;
        } while (i <= r && A[i] < p);

        do
        {
            j--;
        } while (A[j] > p);

        if (i < j)
            swap(A[i], A[j]);
    } while (i < j);

    swap(A[l], A[j]);

    return j;
}

void quicksort(int A[MAX], int l, int r)
{
    if (l < r)
    {
        int s = partition(A, l, r);
        quicksort(A, l, s - 1);
        quicksort(A, s + 1, r);
    }
}

int main()
{
    int n, A[MAX];
    cout << "Enter the number of sectors: ";
    cin >> n;
    cout << "Enter the energy demand for each sector (in kWh): " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    quicksort(A, 0, n - 1);

    cout << "Sorted energy demands (from low to high): ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
