#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    stack<char> st;
    string input;
    getline(cin, input);

    for (int i = 0; i < input.length(); i++) {
        if (input[i] != ' ' && input[i] != '<' && input[i] != '>') {
            st.push(input[i]);
        }

        if (input[i] == ' ') {
            while(!st.empty()) {
                cout << st.top();
                st.pop();
            }
            cout << input[i];
        }
        if (input[i] == '<') {
            if (st.empty()) {
                cout << input[i++];
                while(input[i] != '>') {
                    cout << input[i++];
                }
                cout << input[i];
            }
            else {
                while(!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
                cout << input[i++];
                while(input[i] != '>') {
                    cout << input[i++];
                }
                cout << input[i];
            }
        }
    }

    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }

    return 0;
}