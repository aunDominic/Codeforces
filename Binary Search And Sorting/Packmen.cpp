#include "bits/stdc++.h"
#include <iostream>
using namespace std;

typedef long long ll;

pair<ll,ll> operator+(const pair<ll,ll> &f, const pair<ll,ll> &s){
    return {f.first + s.first, f.second + s.second};
}
pair<ll,ll> operator*(const pair<ll,ll> &f, const ll &s){
    return {f.first * s, f.second * s};
}

int main (){
    int n; cin >> n;
    vector<int> a; // asterisk positions
    vector<int> p; // packmen positions
    for (int i = 0; i < n; i++){
        char c; cin >> c;
        if (c == '*') a.push_back(i);
        if (c == 'P') p.push_back(i);
    }
    

    auto f = [a, p](int t) -> bool{
        // For each packmen
        // i need to know where the previous packmen position was. 
        // INV, the previous packmen ate all asterisks to its left.
        // now i need to know the first asterisk to the right of the previous packmen 
        // I need an array of asterisk positions
        // Then i binary search for the first asterisk position that is bigger than the previous packmen position 
        
        
        int last = -1;
        // cout << "using t:" << t << "\n";
        for (int i = 0; i < p.size(); i++){
            auto it = upper_bound(a.begin(), a.end(), last);
            if (it == a.end()) return true;
            int j =  it - a.begin();
            int left_asterisk = a[j];
            int dist = 0; 
            // cout << "asterisk:" <<  left_asterisk << "\n";
            // cout << "packmen:" << p[i] << '\n';
            // cout << "last:" << last << '\n';
            if (left_asterisk < p[i]) { // asterisk to the left of packmen
                // I can either go right then change direction
                // go left then change direction
                // in both cases, i need to eat the leftmost asterisk
                int remaining_dist_left = t - (p[i] - left_asterisk);// go left first
                int go_left_end = left_asterisk + remaining_dist_left;
                int remaining_dist_right = t - (p[i] - left_asterisk);  // use up p[i] - left_asterisk moves once
                int go_right_end = remaining_dist_right / 2 + p[i];
                // cout << "left:" << go_left_end << " ";
                // cout << "right:" << go_right_end << "\n";
                if (remaining_dist_left < 0 && remaining_dist_right < 0) return false;
                last = max(go_left_end, go_right_end);
            } else { // asterisk to the right of packmen
                // use up all t moves to move to the right
                last = p[i] + t;
            }   
        }
        cout << "\n";
        if (last >= a[a.size() - 1]) return true;
        return false;
    };

    int lo = 0;
    int hi = 2e5;
    while (lo < hi){
        int mid = lo + (hi - lo) / 2;
        if (f(mid)){
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo;
}
