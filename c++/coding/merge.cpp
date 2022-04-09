#include<iostream>
#include<array>
#include<algorithm>
void mergearray(int arr[],int const low,int const mid,int const high)
{
    auto const firsize=mid-low+1;
    auto const secsize=high-mid;
    auto *firarray=new int[firsize];
    auto *secarray=new int[secsize];
    for(auto k=0;k<firsize;k++)
    {
        firarray[k]=arr[k+low];
    }
    for(auto n=0;n<secsize;n++)
  {
    secarray[n]=arr[mid+1+n];
  }
   auto firindex=0;
   auto secindex=0;
   int arrindex=low;
   while(firindex<firsize && secindex <secsize)
   {
       if(firarray[firindex]<=secarray[secindex])
       {
           arr[arrindex]=firarray[firindex];
           firindex++;
       } 
       else 
       {
           arr[arrindex]=secarray[secindex];
           secindex++;
       }
       arrindex++;
}
while(firindex<firsize)
{
    arr[arrindex]=firarray[firindex];
    firindex++;
    arrindex++;
}
while(secindex<secsize)
{
    arr[arrindex]=secarray[secindex];
    secindex++;
    arrindex++;
}
}
void mergesort(int arr[],int const low,int const high)
{
    if (low>=high) return;
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    mergearray(arr,low,mid,high);
}

void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        std::cout<<arr[i]<<" ";
    }
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
    mergesort(arr,0,n-1);
    printarray(arr,n);
}