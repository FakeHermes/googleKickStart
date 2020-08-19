#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(map<int,vector<int>> m, int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (m[i].front() == 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int tmp = q.front();
        q.pop();
        for (int i = 1; i < m[tmp].size(); i++) {
            m[m[tmp][i]].front()--;
            if (m[m[tmp][i]].front() == 1) {
                q.push(m[tmp][i]);
            }
        }
    }
    //拓扑排序find the circle
    queue<int> s;
    for (int i = 1; i <= n; i++) {
        if (m[i].front() == 2) {
            m[i].front() = 0;
            s.push(i);
        }
        else {
            m[i].front() = n;
        }
    }
    //compute distance,multi-source bfs
    while (!s.empty()) {
        int tmp = s.front();
        int dis = m[tmp].front();
        s.pop();
        for (int i = 1; i < m[tmp].size(); i++) {
            if (m[m[tmp][i]].front() == n) {
                m[m[tmp][i]].front() = m[tmp].front() + 1;
                s.push(m[tmp][i]);
            }
        }

    }
    for (int i = 1; i <= n; i++) {
        cout << " " << m[i].front();
    }
           
}
int main() {
    int t;
    int icase = 0;
    cin >> t;
    //cout << fixed << setprecision(9);
    while (t--) {
        icase++;
        int n;
        cin >> n;
        map<int,vector<int>> m;
       // m[0].push_back(1);
        //m.clear();
        for (int i = 1; i <= n; i++) {
            m[i].push_back(0);
        }
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            m[u].push_back(v);
            m[v].push_back(u);
            m[u].front()++;
            m[v].front()++;
        }
        
        //printf("Case #%d: %d\n", icase,m); 
        //cout << "Case #"<<icase<<": " << m << "\n";
        cout << "Case #"<<icase<<":" ;
        solve(m, n);
        cout << "\n";
    }
    

     return 0;
}



