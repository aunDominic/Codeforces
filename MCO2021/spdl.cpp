// #define NDBEUG
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <bitset>
#include <numeric>
#include <string.h>
#include <random>
#include <cassert>
#include <iomanip>
#include <ios>
#include <map>
#include <climits>
using namespace std;


struct Point{
    int x,y,i;
    Point (int x, int y, int i){
        this->x = x;
        this->y = y;
        this->i = i;
    };
};
struct Cart{
    long long d, i, j;
    Cart(long long d, long long i, long long j){
        this->d = d;
        this->i = i;
        this->j = j;
    }
    bool operator< (const Cart &other) const {
        if (this->d == other.d){

            if (this-> i == other.i){
                return this->j < other.j;
            }
            return this->i < other.i;
        }
        return this-> d < other.d;
    }
};
int main () {
    int n, q;
    cin >> n >> q;
    vector<Point> p;
    for (int i = 0 ; i < n; i++){
        int a,b;
        cin >> a >> b;
        Point point = Point(a,b,i);
        p.push_back(point);
    }

    multiset<long long> spdl[n];
    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            long long d = pow(p[i].x - p[j].x,2) + pow(p[i].y - p[j].y, 2);
            spdl[i].insert(d);
            spdl[j].insert(d);
        }
    }
    while (q--){
        int i, x ,y;
        cin >> i >> x >> y;
        multiset<long long> prev = spdl[i];
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            long long oldD = pow(p[i].x - p[j].x,2) + pow(p[i].y - p[j].y, 2); 
            long long newD = pow(x - p[j].x,2) + pow(y - p[j].y, 2); 
            auto itr = spdl[i].find(oldD);
            spdl[i].erase(itr);
            spdl[i].insert(newD);
            itr = spdl[j].find(oldD);
            spdl[j].erase(itr);
            spdl[j].insert(newD);
        }
        auto it1 = prev.begin();
        auto it2 = spdl[i].begin();
        bool equal = true;
        for (; it1 != prev.end() && it2 != spdl[i].end(); it1++, it2++){
            
            if (*it2 < *it1){
                cout << "smaller\n";
                equal = false;
                break;
            }
            else if (*it2 > * it1){
                cout << "larger\n";
                equal = false;
                break;
            }
        }
        if (equal) cout << "equal\n";
        p[i] = Point(x,y,i);
    }

}