#include "bits/stdc++.h"
using namespace std;
class Robot {
   

    public:
        int id; 
        int pos;
        int health;
        char dir;
        Robot(int id, int pos, int health, char dir) : id(id), pos(pos), health(health), dir(dir){}


};

bool cmp1(const Robot& a, const Robot& b){
    return a.pos < b.pos;
}


class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        // Collisions can only occur when there is RL
        // RRRRRLLLLL
        // After every collision, either both are removed, or one is removed 
        // If one is removed, then it continues in the same direction 
        // Sort in order of position
        // LLLRRLLRRRL
        // Stack question again? 

        // RLRLRLR
        // so only consider RL pairs

        // Iterate array. If R, push to stack
        // If L, check stack, if R top of stack, then simulate collision, 
        // If L survives, pop stack again
        // If R survives then continue 
        // O(N^2) is this N^2 actually? 
        // cases: 
        // RRRR...L, then it is O(2N)
        // RRRR...LRRRRRR...L
        // The maximum amount of collisions is N, Our method 
        // Suppose we are on an L Robot
        // The L Robot (index l) may destroy all R Robots on the left 
        // Suppose robot l destroys j robots. Then the last R robot has health 
        // h[l] - j, can you binary search this? not sorted tho
        int n = positions.size();
        vector<Robot> v;
        for (int i = 0; i < n; i++){
            v.push_back(Robot(i, positions[i], healths[i], directions[i]));
        }

        sort(v.begin(), v.end(), cmp1);


        stack<Robot&> st;
        for (int i = 0; i < n; i++){
            if (v[i].dir == 'R') st.push(v[i]);
            else {
                while(!st.empty() && st.top().dir == 'R'){
                    Robot t = st.top(); st.pop();
                    // Same health, both die
                    if (v[i].health == t.health){
                        t.health = 0;
                        v[i].health = 0;
                        break;
                    } else if (v[i].health > t.health){
                        v[i].health--;
                        t.health = 0;
                    } else {
                        t.health--;
                        v[i].health = 0;
                        st.push(t);
                    }
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) if (v[i].health > 0) ans.push_back(v[i].health);

        return ans;


    }
};