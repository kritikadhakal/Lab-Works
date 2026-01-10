// Binary Search and min-max finding with Divide and conquer approach
#include<iostream>
using namespace std;

int arr[50], n;
//Recursive Binary Search
int binarySearch(int low, int high, int key)
{
    if(low > high)
    return -1;
    int mid = (low + high) / 2;
    if(arr[mid] == key)
    return mid;
    else if(key < arr[mid])
    return binarySearch(low, mid-1, key);
    else
    return binarySearch(mid+1, high, key);
}
//Recursive Min-Max
void findMinMax(int index, int &min, int &max)
{
    if(index==n)
    return;
    if(arr[index]<min)
    min = arr[index];
    if(arr[index]>max)
    max = arr[index];
    findMinMax(index + 1, min, max);
}
//Display Array
void display()
{
    cout<<"Array elements: ";
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int choice, key, result;
    int min, max;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements in sorted order:\n";
    for(int i=0; i<n; i++)
    cin>>arr[i];
    do{
        cout<<"\n-------MENU------\n";
        cout<<"1. Binary Search\n";
        cout<<"2. Min-Max\n";
        cout<<"3. Display\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            cout<<"Enter element to search: ";
            cin>>key;
            result = binarySearch(0, n-1, key);
            if(result!=-1)
            cout<<"Element found at position: "<<result + 1<<endl;
            else
            cout<<"Element not found\n";
            break;

            case 2:
            min=max=arr[0];
            findMinMax(1, min, max);
            cout<<"Minimum element: "<<min<<endl;
            cout<<"Maximum element: "<<max<<endl;
            break;

            case 3:
            display();
            break;

            case 4:
            cout<<"Exiting program....\n";
            break;

            default:
            cout<<"Invalid choice!\n";
        }
    }while(choice!=4);
    return 0;
}