#include <iostream>

using namespace std;

// idea is if a % b != 0 THEN a = b b = a % b etc

int GCD(int n, int m)
{
    int a = max(n,m);
    int b = min(n,m);
    int r = a% b;
    while (r>0)
    {
        a = b;
        b = r;
        r = a%b;
    }

    return b;
}

void insertion_sort(int* A, int n)
{
    for(int i=1; i<n; i++)
    {
        while (A[i] < A[i-1] && i > 0)
        {
            swap(A[i], A[i-1]);
            i--;

        }
    }

}

void selection_sort(int* A, int n)
{
    for(int i = 0; i<n-2; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(A[j] < A[min]) min = j;
        }
        swap(A[i],A[min]);
    }
}

int main ()
{
    cout << "Started...." << "\n";
    int A[5]= {5,4,1,7,2};

    selection_sort(&A[0], 5);


    for(int i=0; i<5; i++)
    {
        cout << A[i] << ", ";
    }

    return 0;
}