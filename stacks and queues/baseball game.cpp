
#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    int baseball(vector<string>& operations) {
        stack<int> st;

        for (int i = 0; i < operations.size(); i++) {

            if (operations[i] == "+") {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int sum = a + b;

                st.push(b);
                st.push(a);
                st.push(sum);
            }

            else if (operations[i] == "D") {
                st.push(2 * st.top());
            }

            else if (operations[i] == "C") {
                st.pop();
            }

            else {
                st.push(stoi(operations[i]));
            }
        }

        int total = 0;

        while (!st.empty()) {
            total += st.top();
            st.pop();
        }

        return total;
    }
};

int main() {
    vector<string> operations = {"5", "2", "C", "D", "+"};

    solution obj;

    cout << obj.baseball(operations);

    return 0;
}
