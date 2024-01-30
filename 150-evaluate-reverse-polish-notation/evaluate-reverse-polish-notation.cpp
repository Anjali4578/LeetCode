class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& t: tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                long long op1 = st.top();
                st.pop();
                long long op2 = st.top();
                st.pop();

                if (t == "+") {
                    op1 = op2 + op1;
                }
                else if (t == "-") {
                    op1 = op2 - op1;
                }
                else if (t == "/") {
                    op1 = op2 / op1;
                }
                else if (t == "*") {
                    op1 = op2 * op1;
                }

                st.push(op1);
            }
            else {
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};