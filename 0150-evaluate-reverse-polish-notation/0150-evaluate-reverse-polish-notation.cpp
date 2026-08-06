class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        st.push(stoi(tokens[0]));
        int i = 1;
        while(i < n)
        {
            if(tokens[i] == "+")
            {
                int arg2 = (int)(st.top());st.pop();
                int arg1 = (int)(st.top());st.pop();
                st.push((int)(arg1+arg2));
            }
            else if(tokens[i] == "-")
            {
                int arg2 = (int)(st.top());st.pop();
                int arg1 = (int)(st.top());st.pop();
                st.push((int)(arg1-arg2));
            }
            else if(tokens[i] == "/")
            {
                int arg2 = (int)(st.top());st.pop();
                int arg1 = (int)(st.top());st.pop();
                st.push((int)(arg1/arg2));
            }
            else if(tokens[i] == "*")
            {
                int arg2 = (int)(st.top());st.pop();
                int arg1 = (int)(st.top());st.pop();
                st.push((int)(arg1*arg2));
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
            i++;
        }
        return st.top();
        
        
    }
};