#include<iostream>
using namespace std;

void Sele_Sort(int arr[] , int size)
{
    for(int i=0; i<size-1; i++)
    {
        int min=i;
        for(int j=i+1; j<size; j++)
        {
            if(arr[j] < arr [min] )
            {
                min=j;
            }

        }
        if(min !=i)
        {
            int temp=arr[min];
            arr[min]=arr[i];
            arr[i]=temp;
        }

    }



}


void Print_Array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<<endl;
    }
}
int main()
{
    int n = 0;
    cout << ("Enter the size of array:");
    cin >> n;

    int arr[n];
    cout << "Enter the element of array:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Sele_Sort(arr, n);

    cout << "Elements after sort" << endl;

    Print_Array(arr, n);
}