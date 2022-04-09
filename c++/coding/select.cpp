#include<iostream>
#include<array>
#include<algorithm>
int index(int arr[],int i,int n,int a)
{
    for(int j=i;i<n;i++)
    {
        if(arr[j]==a)
        {
            return i;
        }
        else j++;

    }
   return n-1;
}
void insertionsort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int a=*std::min_element(arr+i,arr+n);
        int b=index(arr,i,n,a);
        int temp=arr[i];
        arr[i]=arr[b];
        arr[b]=temp;

    }

}
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        std::cout<<arr[i]<<" ";
    }
}

int main()
{
    int n;
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

    insertionsort(arr,n);
    display(arr,n);
}