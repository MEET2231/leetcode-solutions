class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(n-1);
        ans[n-1] = 0;
        for(int i = n-2;i>=0;i--)
        {
            if(temp[st.top()] > temp[i])
            {
                ans[i] = st.top() - i;
                st.push(i);
            }
            else{
                while(!st.empty() && temp[st.top()] <= temp[i] )
                {
                    st.pop();
                }
                if(st.empty())
                {
                    st.push(i);
                    ans[i] = 0;
                }
                else
                {
                    ans[i] = st.top() - i;
                    st.push(i);
                }
            }
        }
        return ans;
    }
};