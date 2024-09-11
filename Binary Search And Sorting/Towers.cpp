#include "bits/stdc++.h"
#include <iostream>
using namespace std;

typedef long long ll;

int main(){
    int n; cin >> n;
    multiset<int> towers;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        // place 'a' on the largest tower the smallest tower such that it is possible
        auto it = towers.upper_bound(a);
        if (it == towers.end()) {
            towers.insert(a);
            // cout << "Added: " << a << "\n";
        }
        else { 
            // cout << "Removed: " << *it << " ";
            towers.erase(it);

            towers.insert(a);
            // cout << "Added: " << a << "\n";
        }
    }
    cout << towers.size();
}