#include<bits/stdc++.h>
using namespace std;

int minimumDeleteSum(string s1, string s2){
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1));
    for(int i = dp.size() - 1; i >= 0; i--){
        for(int j = dp[i].size() - 1; j >= 0; j--){
            if(i == dp.size() - 1 and j == dp[i].size() - 1){
                dp[i][j] = 0;
            }else if(i == dp.size() - 1){
                dp[i][j] += (s2[j] + dp[i][j + 1]);
            }else if(j == dp[i].size() - 1){
                dp[i][j] += (s1[i] + dp[i + 1][j]);
            }else{
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i + 1][j + 1];
                }else{
                    dp[i][j] = min(s1[i] + dp[i + 1][j], s2[j] + dp[i][j + 1]);
                }
            }
        }
    }
    return dp[0][0];
}

int main(){
    string s1, s2;
    cin >> s1 >>s2;
    cout << minimumDeleteSum(s1, s2) << endl;
}
