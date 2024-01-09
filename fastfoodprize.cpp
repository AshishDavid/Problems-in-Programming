//https://open.kattis.com/problems/fastfood
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<int> ans(t);
    for(int i = 0; i < t; i ++) {
        int n, m;
        cin >> n >> m;
        int total = 0;
        vector<vector<int>> req_sticker(n);
        vector<int> prize_money(n);
        map<int, int> stickers_collected;
        for(int j = 0; j < n; j ++) {
            int var_len;
            cin >> var_len;
            for(int k = 0; k < var_len; k ++) {
                int temp;
                cin >> temp;
                req_sticker[j].push_back(temp);
            }
            cin >> prize_money[j];
        }
        for(int j = 0; j < m; j ++) {
            int temp;
            cin >> temp;
            stickers_collected[j+1] = temp;
        }
        for(int j = 0; j < req_sticker.size(); j ++) {
            int minimum = INT_MAX;
            for(int k = 0; k < req_sticker[j].size(); k ++) {
                if(stickers_collected[req_sticker[j][k]] < minimum) {
                    minimum = stickers_collected[req_sticker[j][k]];
                }
            }
            total += prize_money[j]*minimum;
        }
        ans[i] = total;
    }
    for(int i = 0; i < t; i ++) {
        cout << ans[i] << endl;
    }
    return 0;
}
