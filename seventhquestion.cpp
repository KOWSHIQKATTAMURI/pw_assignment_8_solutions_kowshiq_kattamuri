#include<bits/stdc++.h>
using namespace std;

string solve(string &s, int &index){
    string ans;
    while(index < s.size() and s[index] != ']'){
        if(!isdigit(s[index])){
            ans += s[index];
            index++;
        }else{
            int n = 0;
            while(index < s.size() and isdigit(s[index])){
                n = n*10 + s[index] - '0';
                index++;
            }
            index++;
            string temp = solve(s, index);
            index++;
            while(n--){
                ans += temp;
            }
        }
    }
    return ans;
}

string decodeString(string s){
    int index = 0;
    return solve(s, index);
}

int main(){
    string s;
    cin >> s;
    cout << decodeString(s);
}
