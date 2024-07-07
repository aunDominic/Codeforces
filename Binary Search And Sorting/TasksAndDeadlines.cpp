#include "bits/stdc++.h"
#include <iostream>
using namespace std;

int main(){
    int n; // Number of tasks
    cin >> n;

    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    // All tasks must be processed
    // Some tasks will give a negative reward.
    // Since all tasks must be processed, we will end all tasks at time 
    // sum of all durations. 
    // Our reward is deadline - finish time.
    // We want to maximise our reward. By Finish at a earliest time as possible. 
    // In optimal ordering of tasks
    // Suppose we have a 
    // We first complete task 1, which takes duration d_i, and has deadline D_i
    // This gives reward D_i - d_i, and the next task we complete must have
    // reward D_i2 - d_i1 - d_i2
    // so the nth task has reward D_in - d_i1 - d_i2 - ... - d_in
    // So the total reward is 
    // D_i1 + Di2 + ... + D_in - d_i1 - d_i2 - ... - d_in 
    // Clearly the ordering of D_i does not matter
    // But we want the ordering of d_i to be such that the largest duration is at the back
    // So we sort by duration in ascending order

    sort(v.begin(), v.end());
    long long t = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++){
        t += v[i].first;
        ans += v[i].second - t; 
    }
    cout << ans;
}