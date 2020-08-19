#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> h, int n) {
    if (n < 3) return 0;
    int l = 0, r = 2;
    int res = 0;
    while (r < n) {
        if (h[l] < h[l + 1] && h[r] < h[l + 1]) {
            res++;
            l++; r++;
        }
        l++; r++;
    }
    return res;
}
int main() {
    int t;
    int icase = 0;
    cin >> t;
    while (t--) {
        icase++;
        int n;
        cin >> n;
        vector<int> h(n);
        
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
      
        int res = solve(h,n);
        printf("Case #%d: %d\n", icase, res);

    }
    

     return 0;
}



