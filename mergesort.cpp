//
///
//// Created By Yseeva
///  November 09
//   Merge Sort in a recursive algorithm

#include <iostream>
using namespace std;

void Merge(int arr[], int left[], int leftSize, int right[], int rightSize) { //this function connects 2 arrays 
    int i = 0;
    int j = 0;
    int k = 0;
    
    while (i < leftSize && j < rightSize) { //till there is still some objects in at least one of arrays
                                            // here we connect'em in the right order 
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    //these 2 whiles checks if one of arrays was over 
    //it connects the rest at the end
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int size) { //here we just divide arrays in 2 halfs till there 
                                      // is only 1 item left which is sorted by default
                                      // and there's no need to call merge function

    if (size <= 1 ) {
        return;
    }
    
    int mid = size / 2;
    int leftPart[mid];
    int rightPart[size - mid];
    
    for (int i = 0; i < mid; i++) {
        leftPart[i] = arr[i];
    }
    
    for (int i = mid; i < size; i++) {
        rightPart[i - mid] = arr[i];
    }
   
    mergeSort(leftPart, mid);
    mergeSort(rightPart, size - mid);
    Merge(arr, leftPart, mid, rightPart, size - mid);
}

int main() {
    cout<<"Welcome !"<<endl<<"Enter the size of desired array :";
    int size;
    cin>>size;
    int arr[size];
    for(int i=0 ; i<size ; i++){
        cout<<"Enter item ["<<i+1<<"]= ";
        cin>>arr[i];
    }
    
    cout <<endl<< "--> 0riginal array is : ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, size);
    
    cout << "--> sorted array is as below: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}