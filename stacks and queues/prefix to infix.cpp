#include <bits/stdc++.h>
using namespace std;

string prefixtoInfix(string s) {
    stack<string> st;
    int i = s.length() - 1;

    string t1;
    string t2;
 
    while (i >= 0) {                                               //TIME COMPLEXITY 
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
            t1 = st.top();
            st.pop();

            t2 = st.top();
            st.pop();

            st.push("(" + t1 + s[i] + t2 + ")");
        }

        i--;
    }

    return st.top();
}

int main() {
    string s = "*+abc";

    cout << prefixtoInfix(s);

    return 0;
}