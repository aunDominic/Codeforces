#include <bits/stdc++.h>
using namespace std;

int main (){
    long long n, m;
    cin >> n >> m;
    long long height = 0;
    int i = 0;
    // first pass
    int ans = 0;
    for (; i < n; i++){
        long long h; cin >> h;
        // we decrease h till h - height = m
        // so we jump up to h, h should equal height + m;
        if (h - height > m){
            ans++;
            height = height + m;
        } 
        // Otherwise we dont do anything
        else{
            i++;
            height = h;
            break;
        }
    }
    // second pass now we can choose to increase 
    for (; i < n; i++){
        long long h; cin >> h;
        // increase h to height 
        if (h - height > m){
            ans++; 
        }
        height = h;
    }
    cout << ans;
}