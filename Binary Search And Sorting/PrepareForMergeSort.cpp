#include "bits/stdc++.h"
#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v(n,0); 
    for (int i = 0; i < n; i++) cin >> v[i];

    // Initialise a 2 by 2 matrix
    // adj[i] represents the ith increasing sequence
    vector<int> adj[n];

    // a[i] represents the top number of the ith sequence (ie the max number)
    vector<int> a(n,0);

    // Loop thru the array
    // We will binary search the first ith sequence such that the top number is
    // less than the current number.

    
    for (int i = 0; i < n; i++){
        // Finds first number greater than 
        int j = upper_bound(a.begin(), a.end(), -v[i]) - a.begin();
        a[j] = -v[i];
        adj[j].push_back(v[i]);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }
        if (adj[i].size() > 0) cout << '\n';
    }

}