#include<iostream>
int main()
{
    int n;
    std::cout<<"enter no of elements in arrray:";
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
{
    int val;
    std::cout<<"enter the element:";
    std::cin>>val;
    arr[i]=val;
}
for(int i=1;i<n;i++)
{
   int j=i-1;
   while(j>=0 && arr[j]>arr[i])
   {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        int s=j-1;
        i=j;
        j=s;
        
   }
   
}

for(int k=0;k<n;k++)
{
    std::cout<<arr[k]<<" ";
}
}