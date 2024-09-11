#include <bits/stdc++.h>
#include <iostream>
#include <map>
using namespace std;
long long MOD = 1e9 + 7;
template <class T> class GodTree{
    private:
        int n;
        vector<long long> t; // SegTree
    public:
        GodTree(int n, int DEFAULT) : n(n), t(2 * n, DEFAULT){}
        // Elements with position i in the array 
        // are stored in nodes starting from n
        void build() {  // build the tree by processing parent nodes in descending order. 
            for (int i = n - 1; i > 0; --i) t[i] = t[2 * i] + t[2 * i + 1];
        }

        void modify(int p, long long value) {  // set value at position p, p is the position in the original array
            // The correspondin node is p + n 
            // Its parent is p / 2 or p >> 1
            // p is the child and p^1 represents the other child 
            // why? p^1 is either p-1 or p+1
            for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = (t[p] + t[p^1]) % MOD;
            // p^1 represents 
        }

        int query(int l, int r) {  // sum on interval [l, r)
            int res = 0;
            if (l >= r) return 0;
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if (l&1) (res += t[l++]) %= MOD; // if l is odd, then it is the right child of its parent, so the parent is not included in the sum, so we add t[l] then increment it
                if (r&1) (res += t[--r]) %= MOD; 
            }
            return res;
        }
};

int main() {
    int n;
    cin >> n;
    GodTree<int> t(n, 0);
    vector<int> v(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> v[i]; a[i] = v[i];
    }

    sort(v.begin(), v.end());

    // let dp[i] be the number of increasing subsequences ending with value i 
    // the dp[i] = for all j < i , sum of dp[j]
    for (int i = 0; i < n; i++){
        int rank = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        long long cnt = t.query(0, rank + 1); // sum of all subsequences ending with less than rank 
        t.modify(rank, cnt + 1); // 1 represents ending the rank as its own subsequence
    }
    cout << t.query(0, n);

}