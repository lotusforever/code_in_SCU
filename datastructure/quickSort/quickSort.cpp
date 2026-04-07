#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    while (low<high) {
        while (low<high&&arr[high]>=arr[low]) {
            high--;
        }
        int temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;//交换arr[high]和arr[low]

        while (low<high&&arr[low]<=arr[high]) {
            low++;
        }
        temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;//交换arr[high]和arr[low]
    }
    return low;
}

void quickSortHelp(int arr[], int low, int high) {
    if (low<high) {
        int pivotloc=partition(arr, low, high);
        quickSortHelp(arr, low, pivotloc-1);
        quickSortHelp(arr, pivotloc+1, high);
    }
}

void quickSort(int arr[], int n) {
    quickSortHelp(arr, 0, n-1);
}

int main()
{
    int arr[]={8,3,9,4,7,5,6,2,1,10};
    int n=sizeof(arr)/sizeof(arr[0]);

    cout<<"初始顺序：";
    for (int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;

    quickSort(arr, n);

    cout<<"排序顺序：";
    for (int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;

    system("pause");
    return 0;
}