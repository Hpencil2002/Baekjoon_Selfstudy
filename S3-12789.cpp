#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;

    stack<int> st;
    int num = 1;
    int student;
    for (int i = 0; i < N; i++) {
        cin >> student;

        if (student == num) {
            num += 1;
        }
        else {
            st.push(student);
        }

        while (!st.empty() && st.top() == num) {
            st.pop();
            num += 1;
        }
    }

    if (st.empty()) {
        cout << "Nice";
    }
    else {
        cout << "Sad";
    }

    return 0;
}