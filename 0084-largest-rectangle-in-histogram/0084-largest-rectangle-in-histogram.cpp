class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n);
        stack<int> st;
        st.push(n-1);
        nse[n-1] = n;
        for(int i = n-2;i>=0;--i)
        {
            if(heights[i] <= heights[st.top()])
            {
                while(!st.empty() && heights[st.top()] >= heights[i])
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    nse[i] = st.top();
                }
                else { nse[i] = n; }
                st.push(i);
            }
            else
            {
                nse[i] = st.top();
                st.push(i);
            }
        }
        st = stack<int>();
        vector<int> pse(n);
        pse[0] = -1;
        st.push(0);
        for(int i = 1;i<n;++i)
        {
            if(heights[st.top()] >= heights[i])
            {
                while(!st.empty() && heights[st.top()] >= heights[i])
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    pse[i] = st.top();
                }
                else { pse[i] = -1; }
                st.push(i);
            }
            else
            {
                pse[i] = st.top();
                st.push(i);
            }
        }

        int MAX = 0;
        for(int i = 0;i<n;i++)
        {
            int a = heights[i] * (nse[i]-pse[i]-1);
            MAX = max(a,MAX);
        }
        return MAX ;
        
    }
};