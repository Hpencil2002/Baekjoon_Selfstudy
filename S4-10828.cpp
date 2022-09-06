#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int n;
    string func;
    stack<int> st;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> func;

        if (func == "push") {
            cin >> num;
            st.push(num);
        }
        else if (func == "pop") {
            if (st.empty()) {
                cout << "-1\n";
            }
            else {
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if (func == "size") {
            cout << st.size() << "\n";
        }
        else if (func == "empty") {
            if (st.empty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (func == "top") {
            if (st.empty()) {
                cout << "-1\n";
            }
            else {
                cout << st.top() << "\n";
            }
        }
    }

    return 0;
}