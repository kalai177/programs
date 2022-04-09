#include<iostream>
#include<array>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int arr[],int low,int high)
{
    int pivot = arr[low]; // pivot
    int i = (high+1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = high;j>=low+1;j--)
    {
        // If current element is smaller than the pivot
        if (arr[j]>pivot)
        {
            i--; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[i-1]);
    return (i-1);
}


void insertionsort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        insertionsort(arr,low,pi-1);
        insertionsort(arr,pi+1,high);
    }
}

//display
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        std::cout<<arr[i]<<" ";
    }
}

//main

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
    insertionsort(arr,0,n-1);
    display(arr,n);
}