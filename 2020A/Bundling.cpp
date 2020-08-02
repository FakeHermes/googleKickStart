#include <bits/stdc++.h>

using namespace std;
const int ALPHABET_SIZE = 26;

// trie node 
struct TrieNode{
    struct TrieNode* children[ALPHABET_SIZE];
    int num=0;
};

// Returns new trie node (initialized to NULLs) 
struct TrieNode* getNode(void){
    struct TrieNode* pNode = new TrieNode;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(struct TrieNode* root, string key){
    struct TrieNode* pCrawl = root;
    for (int i = 0; i < key.length(); i++){
        int index = key[i] - 'A';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();

        pCrawl = pCrawl->children[index];
        pCrawl->num++;
    }
}

int solve(struct TrieNode* root, long k) {
    list<struct TrieNode*> s;
    int n = 0;
    for (int i = 0; i < 26; i++) {
        if (root->children[i]) {
            s.push_back(root->children[i]);
            n++;
        }
    }
    int ans = 0;
    while (!s.empty()) {
        while (n--) {
            ans += (s.front()->num)/k;
            if (!((s.front()->num) / k)) {
                s.pop_front();
                break;
            }
            else {
                for (int i = 0; i < 26; i++) {
                    if (s.front()->children[i]) {
                        s.push_back(s.front()->children[i]);
                        n++;
                    }
                }
            }
            s.pop_front();
        }
    }
    return ans;
}

int main() {
    int T;
    int iCase = 0;
    cin >> T;
    while (T--) {
        iCase++;
        long N, Q;
        cin >> N >> Q;
        vector<string> s(N);
        struct TrieNode* root = getNode();
        for (int i = 0; i < N; i++) {
            cin >> s[i];
            insert(root, s[i]);
        }
        int ans = 0;
        ans=solve(root, Q);
        
        printf("Case #%d: %d\n", iCase,ans);
    }
    return 0;
}
