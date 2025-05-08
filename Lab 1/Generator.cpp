#include <iostream>
#include <random>
#include <chrono>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    int n;
    cin >> n;

    cout << n << "\n";
    for(int i=0; i<n; i++){
        cout << 1+rng()%998244353 << " ";
    }
    cout << "\n";
}