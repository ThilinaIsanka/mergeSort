#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace chrono;

void merge(vector<int>& arr, int l, int m, int r) {           //recursive
    int n1 = m - l + 1;  
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    int lengths[] = {1000,5000,10000,15000,20000,30000,40000,50000};
    for(int j=0; j<8; j++){
        const int n = lengths[j];
        //const int n = 2000;
        cout << "array size: " << n << endl;
        vector<int> arr(n);
        
        // seed the random number generator
        random_device rd;
        mt19937 gen(rd());    
        // generate random numbers between 1 and 100 and fill the vector
        uniform_int_distribution<int> dist(1, 100);
        for (int i = 0; i < n; i++) {
            arr[i] = dist(gen);
        }
        
        auto start = high_resolution_clock::now();
        mergeSort(arr, 0, arr.size() - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start)/1000000.0;
        cout << "Time taken: " << duration.count() << " miliseconds" << endl << endl;

        for (int i = 0; i < n;i++){
            //cout << arr[i] << " ";
        }
    }
    return 0;
}

//fuck
