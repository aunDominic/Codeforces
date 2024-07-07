#include "bits/stdc++.h"

using namespace std;

int main(){ 
    int n;
    cin >> n;
    vector<long long> v(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i];

    // There are n books
    // Two people will read all books, each book has duration t_i 
    // No two people can read the same book at the same time.
    // Clearly it is optimal for the person A to read the longest duration book,
    // and person B must read as much books as possible 
}