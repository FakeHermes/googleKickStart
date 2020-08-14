//#include <bits/stdc++.h>
using namespace std;

map<int, int> m;
int dis[250][250] = { 0 };
bool visited[250][250];
int r, c;

void compute_dis(int x, int y, queue < pair<int, int>>& q,int pre_x,int pre_y,int &max_dis) {
    if (x >= 0 && x < r && y >= 0 && y < c && !visited[x][y]) {
        dis[x][y] = dis[pre_x][pre_y] + 1;
        max_dis = max(max_dis, dis[x][y]);
        visited[x][y] = true;
        q.push(make_pair(x, y));
    }
    return;
}
int BFS(queue < pair<int, int>> q) {
    int max_dis = 0;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        compute_dis(x - 1, y, q, x, y, max_dis);
        compute_dis(x + 1, y, q, x, y, max_dis);
        compute_dis(x, y - 1, q, x, y, max_dis);
        compute_dis(x, y + 1, q, x, y, max_dis);
    }
    return max_dis;
}

bool check(int mid, vector<vector<int>> location,pair<int,int> position) {
    for (int i = mid+1; i < location.size(); i++) {
        for (int j = 0; j < location[i].size(); j++) {
            int new_dis = abs(position.first - location[i][j] / c) + abs(position.second - location[i][j] % c);
            if (new_dis > mid) {
                return false;
            }
        }
    }
    return true;
}

int solve(vector<string>& v) {
    //find source
    queue < pair<int, int>> q;
    for (int i = 0; i < r;i++ ) {
        for (int j = 0; j < c; j++) {
            if (v[i][j] == '1') {
                q.push(make_pair(i, j));
                dis[i][j] = 0;
                visited[i][j] = true;
            }
        }
    }
 
  
    //initial dis,k=[0,max_dis]
    int k_max=BFS(q);
    int k_min = 0;

    vector<vector<int>> location(k_max+1);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            location[dis[i][j]].push_back(c * i + j);
        }
    }
    //binary search k
    int res = k_max;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (v[i][j] == '0') {
                k_min = 0;
                pair<int, int> p = make_pair(i, j);
                if (check(res-1, location, p)) {
                    res --;
                    while (k_min <= k_max) {
                        int mid = (k_max + k_min) / 2;

                        if (check(mid, location, p)) {
                            res = mid;
                            if (res == 0) return 0;
                            k_max = mid - 1;
                        }
                        else {
                            k_min = mid + 1;
                        }
                    }
                }
            }
        }
    }
  
    return res;
}
int main() {
    int t;
    int icase = 0;
    cin >> t;
    while (t--) {
        icase++;

        
        cin >> r >> c;
        vector<string> v(r);
        
        for (int i = 0; i < r; i++) {
            cin >> v[i];
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                visited[i][j] = false;
            }
        }
        int res = solve(v);
        printf("Case #%d: %d\n", icase, res);

    }
    
	

     return 0;
}



