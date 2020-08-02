#include <bits/stdc++.h>

using namespace std;

int v[300][300];
int count_grid(vector<int> &h,int r) {
    stack<int> mono;
    int ans = 0;
    mono.push(h[0]);
    for (int i = 1; i < r; i++) {
        if (h[i] >= mono.top()) {
            mono.push(h[i]);
        }
        else {
            int cnt = 1;
            while (!mono.empty() && h[i] < mono.top()) {
                ans = max(ans, mono.top() * cnt);
                mono.pop();
                cnt++;
            }
            while (cnt--) {
                mono.push(h[i]);
            }
        }
    }
    int cnt = 1;
    while (!mono.empty()) {
        ans = max(ans, mono.top() * cnt);
        cnt++;
        mono.pop();
    }
    return ans;
}
int solve(int r, int c, int k) {
    int ans = 0;
    vector<int> height(r);
    int min1, max1;
    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            min1 = max1 = v[i][j];
            int m = j + 1;
            for (; m < c; m++) {
                if (v[i][m] < min1) min1 = v[i][m];
                if (v[i][m] > max1) max1 = v[i][m];
                if (max1 - min1 > k) {
                    break;
                }
            }
            height[i] = m - j;
        }
        ans = max(ans, count_grid(height,r));
    }
    return ans;
}
int main() {
    int T;
    int iCase = 0;
    cin >> T;
    while (T--) {
        iCase++;
        int R, C, K;
        cin >> R >> C >> K;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> v[i][j];
            }
        }
        int ans = 0;
        ans=solve(R, C, K);
        printf("Case #%d: %d\n", iCase,ans);
    }
    return 0;
}
