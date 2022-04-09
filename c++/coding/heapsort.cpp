#include<iostream>
void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void max_heaping(int arr[],int i, int n)
{
    int largest=i;
    int l= 2 *i +1;
    int r= 2 *i +2;
    if(l<n && arr[l]>arr[largest]) largest = l;
    if(r<n && arr[r]> arr[largest]) largest =r;
    if (largest != i) 
    {
         swap(&arr[i], &arr[largest]);
         max_heaping(arr,largest,n);
     }
}

void buildheap(int arr[],int n)
{
       int last_parent=(n/2)-1;
       for(int i =last_parent;i>=0;i--)
       {
           max_heaping(arr,i,n);
       }
       std::cout<<"done max heap";
       for(int j=n-1;j>0;j--)
       {
           swap(&arr[0],&arr[j]);
           max_heaping(arr,0,j);
       }
}

void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}


int main()
{
    int n;
    bool b1, b2;
    std::cout<<"enter no of elements in an arrray:";
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        int value;
        std::cout<<"enter the element:";
        std::cin>>value;
        arr[i]=value;
    }
    buildheap(arr,n);
    printarray(arr,n);
}