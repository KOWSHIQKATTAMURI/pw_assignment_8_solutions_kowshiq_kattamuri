#include<bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2){
    vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1));
        for(int i = dp.size() -  1; i >= 0; i--){
            for(int j = dp[i].size() - 1; j >= 0; j--){
                if(i == dp.size() - 1 and j == dp[i].size() - 1){
                    dp[i][j] = 0;
                }else if(i == dp.size() - 1){
                    dp[i][j] = 0;
                }else if(j == dp[i].size() - 1){
                    dp[i][j] = 0;
                }else{
                    if(word1[i] == word2[j]){
                        dp[i][j] = 1 + dp[i + 1][j + 1];
                    }else{
                        dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                    }
                }
            }
        }
        int min_length = min(word1.length(), word2.length());
        int max_length = max(word1.length(), word2.length());
        if(min_length == dp[0][0]){
            return max_length - dp[0][0];
        }
        return max_length + min_length - 2*dp[0][0];
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << minDistance(s1, s2);
}
