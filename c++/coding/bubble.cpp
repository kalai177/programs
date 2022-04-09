#include<iostream>
#include<array>

//swap

void swap(int *x , int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

//bubble sort//

void bubblesort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<n-1;j++)
        {
            int k=j+1;
            if(arr[j]>arr[k])
            {
                swap(&arr[j],&arr[k]);
            }
        }
    }
}

// print array//

void printarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        std::cout<<arr[i]<<" ";
    }
}

//driver code//



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

    bubblesort(arr,n);
    printarray(arr,n);
}
    