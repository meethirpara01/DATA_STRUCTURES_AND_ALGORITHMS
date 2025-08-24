#include<iostream>
using namespace std; 

void merge(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;

    int lenleft = mid - s + 1;
    int lenright = e - mid;

    // CREATE LEFT AND RIGHT ARRAY
    int *left = new int[lenleft];
    int *right = new int[lenright];


    // COPY VALUE FROM ORIGINAL ARRAY TO LEFT ARRAY
    int k = s;
    // K --> STARTING INDEX OF LEFT ARRAY VALUES IN ORIGINAL ARRAY
    for (int i = 0; i < lenleft; i++)
    {
        left[i] = arr[k];
        k++;
    }

    k = mid + 1;
    for (int i = 0; i < lenright; i++)
    {
        right[i] = arr[k];
        k++;
    }  
    
    // NOW ACTUALE MERGE LOGIC HERE
    // LEFT ARRAY IS ALREDY SORTED
    // RIGHT ARRAY IS ALREDY SORTED

    int leftIndex = 0;
    int rightIndex = 0;

    // CATCH
    int mainArrayIndex = s;
    while (leftIndex < lenleft && rightIndex < lenright)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else
        {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }  
    }

    // NOW WE HAVE 2 CASE OF CATCH
    // CASE 1 - LEFT ARRAY EXHAUST BUT RIGHT ARRAY STILE HAVE ELEMENT
    while (rightIndex < lenright)
    {
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }
    
    // CASE 2 - RIGHT ARRAY EXHAUST BUT LEFT ARRAY STILE HAVE ELEMENT
    while (leftIndex < lenleft)
    {
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }


    // USE BEST PRECTICESS
    delete[] left;
    delete[] right;
}
void mergeSort(int arr[], int start, int end)
{
    // BASE CASE
    if (start > end)
    {
        // INVALID ARRAY
        return;
    }
    if (start == end)
    {
        // SINGLE ELEMENT
        return;
    }

    // BREAK THE ARRAY
    int mid = start + (end - start) / 2;
    // START TO MID IS LEFT PART
    // MID + 1 TO END IS RIGHT PART

    // RECURSION BHAIYA KO BULAO AND
    // LEFT AND RIGHT ARRAY KO SORT KARWAO
    // RECUSIVE CALL FOR LEFT ARRAY 
    mergeSort(arr, start, mid);
    // RECUSIVE CALL FOR RIGHT ARRAY 
    mergeSort(arr, mid + 1, end);

    // MERGE TWO SORTED\ ARRAY
    merge(arr, start, end);    
}

int main() 
{ 
    int size;
    cout << "Enter Size Of Array : "; 
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << "th Element Of Array: ";
        cin >> arr[i]; 
    }

    cout << "YOUR ARRAY BEFORE SORTING: " << endl;
    for(auto num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    int start = 0;
    int end = size - 1;
    mergeSort(arr, start, end);

    cout << "YOUR SORTED ARRAY USING MERGE SORT: " << endl;
    for(auto num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    
    return 0; 
}