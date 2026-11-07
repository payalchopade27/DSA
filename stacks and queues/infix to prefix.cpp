#include <bits/stdc++.h>
using namespace std;

int priority(char c) {
    if (c == '^') return 3;
    else if (c == '*' || c == '/') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

string infixToPrefix(string s) {
    stack<char> st;
    int i = 0;
    string ans = "";

    // Reverse the infix expression
    reverse(s.begin(), s.end());

    // Swap opening and closing brackets
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        }
        else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    // Convert modified infix expression to postfix
    while (i < s.length()) {

        // Operand
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')) {

            ans += s[i];
        }

        // Opening bracket
        else if (s[i] == '(') {
            st.push(s[i]);
        }

        // Closing bracket
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        // Operator
        else {
            if (s[i] == '^') {
                while (!st.empty() &&
                       priority(s[i]) <= priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }
            else {
                while (!st.empty() &&
                       priority(s[i]) < priority(st.top())) {
                    ans += st.top();
                    st.pop();
                }
            }

            st.push(s[i]);
        }

        i++;
    }

    // Pop remaining operators
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    // Reverse postfix to get prefix
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    string exp = "(a+b)*c";
    cout << infixToPrefix(exp);
    return 0;
}