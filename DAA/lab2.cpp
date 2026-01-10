//Iterative Sorting algorithm (Bubble, Insertion and Selective sort)
#include<iostream>
using namespace std;

int main() 
{
    int a[50], n, choice;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    do {
        cout<<"\n--------MENU--------\n";
        cout<<"1. Bubble Sort\n";
        cout<<"2. Selection Sort\n";
        cout<<"3. Insertion Sort\n";
        cout<<"4. Display Array\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;   

        switch(choice){

            case 1: //Bubble Sort
            for(int i=0; i<n-1; i++){
                for(int j=0; j<n-i-1; j++){
                    if(a[j]>a[j+1]){
                        int temp = a[j];
                        a[j]= a[j+1];
                        a[j+1] = temp;
                    }
                }
            }
            cout<<"Bubble Sort applied Successfully.\n";
            break;

            case 2: //Selection Sort
            for(int i=0; i<n-1; i++){
                int min = i;
                for(int j=i+1; j<n; j++){
                    if(a[j]<a[min]){
                        min = j;
                    }
                }
                int temp = a[i];
                a[i] = a[min];
                a[min] = temp;
            }
            cout<<"Selection Sort applied successfully.\n";
            break;

            case 3: //Insertion Sort
            for(int i=1; i<n; i++){
                int key = a[i];
                int j = i-1;
                while(j >= 0 && a[j] > key){
                    a[j+1] = a[j];
                    j--;
                }
                a[j+1] = key;
            }
            cout<<"Insertion Sort applied successfully.\n";
            break;

            case 4: //Display
            cout<<"Array elements:\n";
            for(int i=0; i<n; i++){   
                cout<<a[i]<<" ";
            }
            cout<<endl;
            break;

            case 5:
            cout<<"Exiting program....\n";
            break;

            default:
            cout<<"Invalid choice! Try again.\n";
        }

    } while(choice != 5);   

    return 0;
}
