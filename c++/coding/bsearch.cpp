#include<iostream>
#include<array>
int bsearch(int arr[],int first, int end,int s);
int main()
{
    int n;
    std::cout<<"enter array size:";
    std::cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        int value;
        std::cout<<"enter the element:";
        std::cin>>value;
        arr[i]=value;
    }

    std::cout<<"enter the element to be searched as binary search:";
    int s;
    std::cin>>s;
    int position=bsearch(arr,0,n-1,s);
    if(position==-1) std::cout<<"element not present";
    else std::cout<<"the element"<<s<<"is present at "<<position;

}

int  bsearch(int arr[],int first, int end,int s)
{   
   
    if(end>=first)  
    {
       int  mid=first+(end-1) /2;
    
      if(arr[mid]==s) return mid;
      if(mid>s)
      {
        return bsearch(arr,0,mid-1,s);
       }
    if(mid<s)
    {
        return bsearch(arr,mid+1,end,s);
    }
    }
    return -1;
}