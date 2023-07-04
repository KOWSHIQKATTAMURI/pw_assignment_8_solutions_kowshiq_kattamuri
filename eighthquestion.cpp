#include<bits/stdc++.h>
using namespace std;

bool buddyStrings(string s, string goal){
    if(s.length() != goal.length()){
            return false;
        }
        if(s == goal){
            set<char> temp(s.begin(), s.end());
            return temp.size() < goal.size();
        }
        vector<int> check;
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != goal[i]){
                check.push_back(i);
                count++;
            }
        }
        if(count == 2){
            swap(s[check[0]], s[check[1]]);
            return s == goal;
        }
        return false;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    cout << buddyStrings(s1, s2);
}
