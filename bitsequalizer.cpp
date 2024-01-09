//https://open.kattis.com/problems/bitsequalizer

// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    vector<int> ans(t);
    for(int i = 0; i < t; i ++) {
        int moves = 0;
        int total_diff = 0;
        int zero_to_one = 0;
        int one_to_zero = 0;
        string s, t;
        cin >> s >> t;
        for(int j = 0; j < s.length(); j ++) {
            if(s[j] != t[j]) {
                total_diff ++;
            }
            if(s[j] == '?' && t[j] == '1') {
                moves ++;
            }
            else if(s[j] == '0' && t[j] == '1') {
                zero_to_one ++;
            }
            else if(s[j] == '1' && t[j] == '0') {
                one_to_zero ++;
            }
        }
        if((zero_to_one+moves) - one_to_zero < 0) {
            ans[i] = -1;
            continue;
        }
        ans[i] = total_diff - min(zero_to_one, one_to_zero);
    }
    
    for(int i = 0; i < t; i ++) {
        cout << "Case " << i+1 << ": " << ans[i] << endl;
    }
    return 0;
}
