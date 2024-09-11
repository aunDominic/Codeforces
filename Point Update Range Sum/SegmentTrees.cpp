#include <bits/stdc++.h>

using namespace std;
template <class T> class GodTree{
    private:
        int len;
        vector<int> t; // SegTree

    public:
        GodTree(int len, int DEFAULT) : len(len), t(2 * len, DEFAULT){}
        // Elements with position i in the array 
        // are stored in nodes i + n
        void build() {  // build the tree by processing parent nodes in descending order. 
            for (int i = n - 1; i > 0; --i) t[i] = t[2 * i] + t[2 * i + 1];
        }

        void modify(int p, int value) {  // set value at position p, p is the position in the original array
            // The correspondin node is p + n 
            // Its parent is p / 2 or p >> 1
            // p is the child and p^1 represents the other child 
            // why? p^1 is either p-1 or p+1
            for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
            // p^1 represents 
        }

        int query(int l, int r) {  // sum on interval [l, r)
            int res = 0;
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if (l&1) res += t[l++]; // if l is odd, then it is the right child of its parent, so the parent is not included in the sum, so we add t[l] then increment it
                if (r&1) res += t[--r]; 
            }
            return res;
        }
};