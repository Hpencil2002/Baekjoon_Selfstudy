#include <iostream>
using namespace std;

int N, M;
int ans;
char str[510] = { 0, };

struct TRIE {
    TRIE* node[26];

    TRIE() {
        for (int i = 0; i < 26; i++) {
            node[i] = NULL;
        }
    }
    ~TRIE() {
        for (int i = 0; i < 26; i++) {
            delete node[i];
        }
    }
    void Insert(char* str) {
        if (*str == '\0') {
            return;
        }

        int cur = *str - 'a';
        if (node[cur] == NULL) {
            node[cur] = new TRIE();
        }

        node[cur]->Insert(str + 1);
    }
    bool Find(char* str) {
        if (*str == '\0') {
            return true;
        }

        int cur = *str - 'a';
        if (node[cur] == NULL) {
            return false;
        }

        return node[cur]->Find(str + 1);
    }
};

int main() {
    cin >> N >> M;

    TRIE* root = new TRIE();
    for (int i = 0; i < N; i++) {
        cin >> str;
        root->Insert(str);
    }

    for (int i = 0; i < M; i++) {
        cin >> str;

        if (root->Find(str)) {
            ans += 1;
        }
    }

    cout << ans;

    return 0;
}