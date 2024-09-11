#include "bits/stdc++.h"

using namespace std;
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        // Maximum height of the shelves is 1e6   
        // every book, i either place it in the current shelf, or place it in a new shelf.
        // dp[i][j] = min height of shelf using the first i books and a total width of j 
        // For each i, i can choose to create a new shelf, or use the existing shelf (if the width fits)
        // so dp[i][j] = min(max(dp[i-1][j - width[i]], height[i]), dp[i][j]) // uses the current shelf
        // j - width[i] >= 0
        // dp[i][width[i]] = dp[i-1][j] + height[i] for all j // create a new shelf 
        int n = books.size();
        int m = shelfWidth;
        vector<vector<pair<int,int>>> dp(n+1, vector<pair<int,int>>(m+1, {2e6, 0}));
        dp[0][0] = {0,0};
        for (int i = 1; i <= n; i++){
            for (int j = 0; j <= m; j++){
                int new_total_height = dp[i-1][j].first + books[i-1][1];
                if (new_total_height < dp[i][books[i-1][0]].first){
                    dp[i][books[i-1][0]] = {new_total_height, books[i-1][1]};
                }
                if (j - books[i-1][0] >= 0) {
                    int max_height_in_shelf = max(dp[i-1][j-books[i-1][0]].second, books[i-1][1]);
                    int total_height_using_this_book = dp[i-1][j-books[i-1][0]].first - dp[i-1][j-books[i-1][0]].second + max_height_in_shelf;
                    if (total_height_using_this_book < dp[i][j].first){
                        dp[i][j] = {total_height_using_this_book, max_height_in_shelf};
                    }
                    
                }
            }
        }
        int ans = 2e6;
        for (int i = 1; i <= m; i++){
            ans = min(ans, dp[n][i].first);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> books = {{9,9},{5,4},{3,1},{1,5},{7,3}};
    int shelfWidth = 10;
    sol.minHeightShelves(books, shelfWidth);

}
