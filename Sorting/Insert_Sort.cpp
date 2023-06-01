#include<iostream>
using namespace std;
void Insert_Sort(int arr[], int size)
{
    for(int i=1; i<size; i++)
    {
        int temp=arr[i];
        int j=i-1;

        while(j >=0 && arr[j] >temp)
        {
            arr[j+1] =arr[j];
            j--;
        }
        arr[j+1]=temp;

    }    
}

void Print_Arry(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<endl;
    }
}

int main()
{
    int no=0;
    cout<<"Enter the size of array:";
    cin>>no;

    int arr[no];
    cout<<"Enter the elemnt of array:"<<endl;
    for(int i=0; i<no; i++)
    {
        cin>>arr[i];
    }

    Insert_Sort(arr, no);
    
    cout<<"Elemnt after array sorted:"<<endl;
    Print_Arry(arr , no);

    return 0;
}