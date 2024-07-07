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

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Cmp{
    public:
        bool operator() (pair<int,int>, pair<int,int> &b){
            return a.first < b.first;
        }
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head;
        int k = lists.size();
        priority_queue<pair<int,int>, vector<pair<int,int>, Cmp> pq;
        for (int i = 0; i < k ; i++){
            pq.push({lists[i].val, i});
        } 
        while(!pq.empty()){
            pair<int,int> t = pq.pop();
            
            ListNode* node;
            if (head.next == nullptr){
                head.val = t.first;
            } else {
                node.val = t.first;
                head.next = node;
            }
            if (lists[t.second].next != nullptr){
                lists[t.second] = lists[t.second].next;
                pq.push({lists[t.second].val, t.second});
            }  
        
        }
        return head;
    }
};