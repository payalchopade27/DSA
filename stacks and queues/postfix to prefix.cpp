#include <bits/stdc++.h>
using namespace std;


string postfixtoprefix(string s){
    stack<string> st;
    int i=0;
    string t1;
    string t2;


    while(i<s.length()){
       if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')) {

            st.push(string(1, s[i]));
        } 
        else {
            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();

            st.push(string(1, s[i]) + t2 + t1);
        } 
        i++;
    }  
    return st.top();


}

int main(){
    string s = "ab+c*";

    cout << postfixtoprefix(s);

    return 0;

}