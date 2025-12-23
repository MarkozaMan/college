#include <iostream>

// [1,6,42,7,2,7] 

using namespace std;

void heapify(char arr[], int n, int i)
{
    int largest = i;

    int left = i*2 + 1;
    int right = i*2 +2;

    if(left < n && arr[largest] < arr[left]) largest = left;
    
    if(right < n && arr[largest] < arr[right]) largest = right;

    if(largest != i)
    {
        swap(arr[largest], arr[i])
        heapify(arr, n, largest);
    }
}

void heapSort(char arr[], int n)
{
    for(int i = (n/2) - 1; i >= 0; i--) //
    {
        heapify(arr, n, i);
    }
    

    for(int i = n-1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }

}


int main()
{
    char arr[] = {'z', 'a', 't', 'p', 'c', 'm', 'e'};

    // int arr[] = {6,1,722,51,46,7,0,52};

    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    for(int i = 0; i < n; i++) cout << arr[i] << ' ';

    cout << endl;


}



