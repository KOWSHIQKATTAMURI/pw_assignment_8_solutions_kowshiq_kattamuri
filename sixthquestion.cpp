#include<bits/stdc++.h>
using namespace std;

vector<int> findanagrams(string s, string p){
    vector<int> kow;
    if(p.length() > s.length()){
        return kow;
    }
    vector<int> x(26, 0), y(26, 0);
    int n = s.length(), m = p.length(), left = 0, right = 0;
    while(right < m){
        x[p[right] - 'a']++;
        y[s[right] - 'a']++;
        right++;
    }
    right -= 1;
    while(right < n){
        if(x == y){
            kow.push_back(left);
        }
        right += 1;
        if(right != n){
            y[s[right] - 'a']++;
        }
        y[s[left] - 'a']--;
        left += 1;
    }
    return kow;
}

int main(){
    string a, b;
    cin >> a >> b;
    vector<int> ans = findanagrams(a, b);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}
