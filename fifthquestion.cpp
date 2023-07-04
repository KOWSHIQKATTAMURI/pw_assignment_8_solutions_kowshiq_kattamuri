#include<bits/stdc++.h>
using namespace std;

int compress(vector<char>& kow){
    int n = chars.size(), i = 0, j = 0, count = 1;
    while(i < n){
        while(i < n - 1 and chars[i] == chars[i + 1]){
            i++;
            count++;
        }
        chars[j++] = chars[i++];
        if(count > 1){
            string num = to_string(count);
            for(auto k : num){
                chars[j++] = k;
            }
            count = 1;
        }
    }
    return j;
}

int main(){
    int n;
    cin >> n;
    vector<char> kow(n);
    for(int i = 0; i < n; i++){
        cin >> kow[i];
    }
    cout << compress(kow) << endl;
}
