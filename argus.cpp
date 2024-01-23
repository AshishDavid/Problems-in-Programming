//Problem Statement on 
//https://vjudge.net/problem/UVA-1203

#include <bits/stdc++.h>

using namespace std;

  
typedef pair<int, pair<int, int>> pi; 
int main()
{
    string st;
    int temp;
    cin >> st;
    vector<int> t;
    vector<int> num;
    while(st != "#") {
        int id;
        int tm;
        cin >> id;
        cin >> tm;
        num.push_back(id);
        t.push_back(tm);
        cin >> st;
    }
    int f;
    cin >> f;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for(int i = 0; i < num.size(); i ++) {
        pq.push(make_pair(t[i], make_pair(num[i], t[i])));
    }
    while(f != 0) {
        pi temp = pq.top();
        cout << temp.second.first << endl;
        pq.pop();
        temp.first += temp.second.second;
        pq.push(temp);
        f --;
    }
    return 0;
}
