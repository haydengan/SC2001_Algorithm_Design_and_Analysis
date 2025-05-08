#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

// sorting numbers in range [l, r]

int S, keyCompCount = 0;

void MergeSort(int arr[], int l, int r){
    int len = (r - l + 1);

    if(len <= S){
        for(int i = l + 1; i <= r; ++i){
            for(int j = i; j >= l + 1; --j){
                if((++keyCompCount) && arr[j] < arr[j - 1]) swap(arr[j], arr[j - 1]);
                else break;
            }
        }
        return;
    }
    int mid = (l + r) / 2;
    MergeSort(arr, l, mid);
    MergeSort(arr, mid + 1, r);
    int temp[len];
    fill(temp, temp + len, 0);
    int idx = 0, l_idx = l, r_idx = mid + 1;
    for(; l_idx <= mid; ++l_idx){
        while(r_idx <= r && (++keyCompCount) && arr[l_idx] > arr[r_idx]){
            temp[idx] = arr[r_idx];
            r_idx++;
            idx++;
        }
        temp[idx] = arr[l_idx];
        idx++;
    }
    while(r_idx <= r){
        temp[idx] = arr[r_idx];
        idx++, r_idx++;
    }
    for(int i = 0; i < len; ++i){
        arr[l + i] = temp[i]; 
    }
}


int main(int argc,char* argv[]){
    sscanf(argv[1], "%d", &S);

    int N; cin >> N;
    int arr[N];
    for(int i = 0; i < N; ++i) cin >> arr[i];
    
    clock_t startTime = clock();
    MergeSort(arr, 0, N - 1);
    clock_t endTime = clock();

    long long timeElapsedMs = ceil(1000000ll * (endTime - startTime) / CLOCKS_PER_SEC);
    cout << keyCompCount << " " << timeElapsedMs << endl; // Key Comparison Count and CPU runtime in ns
}