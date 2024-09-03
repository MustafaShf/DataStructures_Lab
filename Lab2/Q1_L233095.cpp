#include <iostream>
using namespace std;

void rearrange(int arr[], int n) {
    
    int* pos = new int[n];
    int* neg = new int[n];
    int positiveCount = 0, negCount = 0;

    // Separate + &
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            pos[positiveCount++] = arr[i];
        } else {
            neg[negCount++] = arr[i];
        }
    }

    int i = 0, j = 0, k = 0;

    // Merge the two arrays back into arr[] alternating
    while (i < positiveCount && j < negCount) {
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }

    
    while (i < positiveCount) {
        arr[k++] = pos[i++];
    }

    
    while (j < negCount) {
        arr[k++] = neg[j++];
    }

    
    delete[] pos;
    delete[] neg;
}

int main() {
    int arr[] = {1, 2, 3, -4, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Old Array\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    rearrange(arr, n);
     cout<<"New Array\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
