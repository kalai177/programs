#include<iostream>
#include<array>
#include<algorithm>
void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}
int main()
{
    int n;
    std::cout<<" Enter the number of elements:";
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        int value;
        std::cout<<" enter the element:";
        std::cin>>value;
        arr[i]=value;
    }
    printarray(arr,n);
    arr[0]=45;
    arr[4]=28;
    arr[7]=77;
    printarray(arr,n);
}