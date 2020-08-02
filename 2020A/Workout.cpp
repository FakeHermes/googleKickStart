#include <bits/stdc++.h>

using namespace std;
void heapify(vector<vector<long>>& arr, int n, int i)
{
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 

    // If left child is larger than root 
    if (l < n && arr[l][2] > arr[largest][2])
        largest = l;

    // If right child is larger than largest so far 
    if (r < n && arr[r][2] > arr[largest][2])
        largest = r;

    // If largest is not root 
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest);
    }
}

// Function to build a Max-Heap from the given array 
void buildHeap(vector<vector<long>>& arr, int n)
{
    // Index of last non-leaf node 
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal 
    // from last non-leaf node and heapify 
    // each node 
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void getInter(vector<vector<long>>& interv, vector<long> v, int n) {
    for (int i = 0; i < n - 1; i++) {
        interv[i].push_back(v[i + 1]-v[i]);
        interv[i].push_back(1);
        interv[i].push_back(v[i + 1] - v[i]);
    }

    buildHeap(interv, n - 1);
}
int solve(vector<long> v, long n, long k) {
    vector<vector<long>> interv(n-1);
    getInter(interv, v, n);
    for(long i = 0; i < k; i++){
        interv[0][1]++;
        if (interv[0][0] % interv[0][1] == 0) {
            interv[0][2] = interv[0][0] / interv[0][1];
            heapify(interv, n - 1, 0);
        }
        else {
            interv[0][2] = interv[0][0] / interv[0][1]+1;
            heapify(interv, n - 1, 0);
        }
    }
    int ans = interv[0][2];
    return ans;
}
int main() {
    int T;
    int iCase = 0;
    cin >> T;
    while (T--) {
        iCase++;
        long N, K;
        cin >> N >> K;
        vector<long> v(N);
        for (long i = 0; i < N; i++) {
            cin >> v[i];
        }
        int ans = 0;
        ans=solve(v, N, K);
        printf("Case #%d: %d\n", iCase,ans);
    }
    return 0;
}
