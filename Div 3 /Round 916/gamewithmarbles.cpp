#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<long long> a;
        vector<long long> b;
        priority_queue<pair<long long,int>> pq;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            b.push_back(x);
        }
        for (int i = 0; i < n; i++){
            pq.push({a[i]+b[i] - 1, i});
        }
        bool turn = true; // true == alice
        while (!pq.empty()){
            auto [val, id] = pq.top();
            pq.pop();
            if (turn){
                a[id] -= 1;
                b[id] = 0;
            }
            else {
                b[id] -= 1;
                a[id] = 0;
            }
            turn = !turn;
        }
        long long score = 0;
        for (int i = 0 ; i < n; i++){
            score += a[i] - b[i];
        }
        cout << score << "\n";
    }
}