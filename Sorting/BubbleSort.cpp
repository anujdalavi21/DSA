#include<iostream>
using namespace std;

void Bubble_Sort(int arr[], int size)
{
   for(int i=0; i<size-1; i++)
   {
     for(int j=0; j<size-1;j++)
     {
        if(arr[j] > arr[j+1])
        {
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }

     }

   }  

}

void Print_Array(int arr[], int size)
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

    Bubble_Sort(arr, no);
    
    cout<<"Elemnt after array sorted:"<<endl;
    Print_Array(arr , no);

    return 0;
}