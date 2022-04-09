#include<iostream>
void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void min_heaping(int arr[],int i,int n)
{
   int largest=i;
    int l= 2 *i +1;
    int r= 2 *i +2;
    if(l<n && arr[l]<arr[largest]) largest = l;
    if(r<n && arr[r]<arr[largest]) largest =r;
    if (largest != i) {
         swap(&arr[i], &arr[largest]);
         min_heaping(arr,largest,n);
     }

 }
void max_heaping(int arr[],int i, int n)
{
    int largest=i;
    int l= 2 *i +1;
    int r= 2 *i +2;
    if(l<n && arr[l]>arr[largest]) largest = l;
    if(r<n && arr[r]> arr[largest]) largest =r;
    if (largest != i) {
         swap(&arr[i], &arr[largest]);
         max_heaping(arr,largest,n);
     }
}

void buildheap(int arr[],int n)
{
        int which_heap;
        std::cout<<"enter the heap to be performed: 0 or 1:";
        std::cin>>which_heap;
        int last_parent=(n/2)-1;
        for(int i =last_parent;i>=0;i--)
        {
         if(which_heap==0) 
        {
            std::cout<<"performing max heaping:";
            max_heaping(arr,i,n);
        }
         else 
        {
            std::cout<<"performing min heaping:";
            min_heaping(arr,i,n);
        }
        }
}
bool ismin_heap(int arr[],int n)
{
    int last_parent=(n/2)-1;
    for(int i=0;i<last_parent;i++)
    {
        if(arr[i]>arr[2*i+1]) return false;
        if(arr[i]>arr[2*i+2] && 2*i+2 <n) return false;
    }
    return true;
}
bool ismax_heap(int arr[],int n)
{
    int last_parent=(n/2)-1;
    for(int i=0;i<=last_parent;i++)
    {
        if(arr[i]<arr[2*i+1]) return false;
        if(arr[i]<arr[2*i+2] && 2*i+2<n) return false;
    }
    return true;
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
    int choice;
    std::cout<<"u want max or min heap choose 0 for max and 1 for min:";
    std::cin>>choice;
    if(choice==0)
    {
    b1= ismax_heap(arr,n);
    if(b1==true)
    std::cout<<"the heap is maxheap:";
    else
    {
    printarray(arr,n);
    buildheap(arr,n);
    }
    }
    
    else 
    {
    b2=ismin_heap(arr,n);
    if(b2==true)
    {
        std::cout<<"its a min heap";
    }
    else 
    {
        printarray(arr,n);
    buildheap(arr,n);
    }
    }

    printarray(arr,n);



}