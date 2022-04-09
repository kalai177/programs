#include<iostream>
#include<array>
int main()
{
    int n;
    std::cout<<"enter size of array:";
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        int value;
        std::cout<<"enter the element:";
        std::cin>>value;
        arr[i]=value;
    }
    
    std::cout<<"enter the element to be searched:";
    int ele;
    std::cin>>ele;
    for(int j=0;j<n;j++)
    {
        if(arr[j]==ele) 
        {
        std::cout<<"element is present at position:"<<j<<std::endl;
        break;
        }
        if(j==n-1 && arr[j]!= ele)  std::cout<< "element not present";
    }
}