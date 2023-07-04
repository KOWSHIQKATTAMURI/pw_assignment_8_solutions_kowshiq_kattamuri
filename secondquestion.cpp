#include<bits/stdc++.h>
using namespace std;

bool checkValidString(string s){
    stack<int> open, asterisk;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '*'){
            asterisk.push(i);
        }else if(s[i] == '('){
            open.push(i);
        }else{
            if(!open.empty()){
                open.pop();
            }else if(!asterisk.empty()){
                asterisk.pop();
            }else{
                return false;
            }
        }
    }
    while(!open.empty() and !asterisk.empty()){
        if(open.top() < asterisk.top()){
            open.pop();
            asterisk.pop();
        }else{
            return false;
        }
    }
    return open.empty();
}

int main(){
    string s;
    cin >> s;
    cout << checkValidString(s);
}
