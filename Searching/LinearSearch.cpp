#include<iostream>
using namespace std;

void LinearSearch(int arr[],int size,int search)
{
    int flag=0;
    for(int i=0; i<size; i++)
    {
        if(arr[i]==search)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }

}

int main()
{
    int n=0;
    cout<<"Enter the size of array:";
    cin>>n;
 
    int arr[n];
    cout<<"Enter the element:"<<endl;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int i=0;
    cout<<"Enter the element to search:";
    cin>>i;

    LinearSearch(arr,n,i);

    return 0;
}