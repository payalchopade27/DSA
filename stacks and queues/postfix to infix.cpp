#include <bits/stdc++.h>
using namespace std;

string postfixToInfix(string s) {
    stack<string> st;

    int i = 0;

    while (i < s.length()) {
                                                                           //TIME COMPLEXITY 
                                                                   //1.WHILE LOOP: O(N)
                                                                   // St.push("(" + t1 + s[i] + t2 + ")") THIS IS CAUSING TWO STRIMG TO ADD THEN STRING CAN BE OF N LENGTH (T1 AND T1)
                                                                   // SO TC : O(N1+N2)


                                                                   //AT LAST TC 0(N)
                                                                   //SC: IS O(N)THAT IS OF STACK WE CREATED 
        // Operand
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')) {

            st.push(string(1, s[i]));
        }

        // Operator
        else {
            string t1 = st.top();
            st.pop();

            string t2 = st.top();
            st.pop();

            st.push("(" + t2 + s[i] + t1 + ")");
        }

        i++;
    }

    return st.top();
}

int main() {
    string exp = "ab+c*";
    cout << postfixToInfix(exp);

    return 0;
}