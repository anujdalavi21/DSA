 #include<iostream>
using namespace std;

void BinarySearch(int arr[],int size,int search)
{
    int l=0;
    int r=size-1;
    int m=0;
    int flag=0;

    while(l<=r)
    {
        m=(l+r)/2;
        if(arr[m]==search)
        {
            flag=1;
            break;
        }
       else if(arr[m] > search)
      {
        r=m-1;
      }

      else                                                                                                                         
      {
        l=m+1;
      }
    
    }
if(flag==1)
{
    cout<<"Found"<<endl;
}
else{
    cout<<"Not found"<<endl;
}

}

int main()
{
    int *ptr=NULL;
    int n=0;
    cout<<"Enter the size of array:";
    cin>>n;

    int arr[n];
    ptr=new int[n];

    cout<<"Enter the elements of array:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    int no=0;
    cout<<"Enter the element to search:";
    cin>>no;

    BinarySearch(arr,n,no);

    delete []ptr;

    return 0;
}