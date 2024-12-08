#include <iostream>
using namespace std;

void Maxheapify(int Arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < n && Arr[l] > Arr[largest])
    {
        largest = l;
    }

    if (r < n && Arr[r] > Arr[largest])
    {
        largest = r;
    }

    if (largest != i) 
    {
        swap(Arr[i], Arr[largest]);
        Maxheapify(Arr, n, largest);
    }
}


void Maxheapsort(int Arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        Maxheapify(Arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) 
    {
        swap(Arr[0], Arr[i]);
        Maxheapify(Arr, i, 0);
    }
}


void Display(int Arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << Arr[i] << " ";
    }

    cout << "\n";
}
 
 
int main() 
{
    int n,Arr[n]; 
    cout<<"How many elements you want to sort?:  ";
    cin>>n;
    cout<<"Enter "<<n<<" Elements: \n";
    for(int i=0; i<n; i++)
    {
        cin>>Arr[i];
    }
    
    Maxheapsort(Arr, n);
 
    cout << "\nSorted array is: \n";
    Display(Arr, n);
    
    return 0;
}
