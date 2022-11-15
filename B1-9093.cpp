#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int N;
    string sent;
    stack<char> st;
    
    cin >> N;
    cin.ignore();
    for (int i = 0; i < N; i++) {
        getline(cin, sent);
        sent += ' ';

        for (int j = 0; j < sent.size(); j++) {
            if (sent[j] == ' ') {
                while (!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
                cout << ' ';
            }
            else {
                st.push(sent[j]);
            }
        }
        cout << "\n";
    }

    return 0;
}