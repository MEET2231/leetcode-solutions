class Solution {
public:
    int N,M;
    int solvebase(int r,vector<int> & base)
    {
        // base matrix 
        // get pse
        // get nse
        // get MAX area
        stack<int> st;
        vector<int> pse(N);
        pse[0] = -1;
        st.push(0);
        for(int i = 1;i<N;i++)
        {
            if(base[i] > base[st.top()])
            {
                pse[i] = st.top();
                st.push(i);
            }
            else
            {
                while(!st.empty() && base[st.top()] >= base[i])
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    pse[i] = st.top();
                }
                else
                {
                    pse[i] = -1;
                }
                st.push(i);
            }
        }
        vector<int> nse(N);
        st = stack<int>();
        st.push(N-1);
        nse[N-1] = N;
        for(int i = N-2;i>=0;--i)
        {
            if(base[i] > base[st.top()])
            {
                nse[i] = st.top();
                st.push(i);
            }
            else
            {
                while(!st.empty() && base[st.top()] >= base[i])
                {
                    st.pop();
                }
                if(!st.empty())
                {
                    nse[i] = st.top();
                }
                else
                {
                    nse[i] = N;
                }
                st.push(i);
            }
        }
        int MAX = 0;
        for(int i = 0;i<N;++i)
        {
            MAX = max(base[i]*(nse[i] - pse[i] - 1),MAX);
        }
        return MAX;


    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        M = matrix.size();
        N = matrix[0].size();
        vector<int> base(N,0);
        int MAX = 0;
        for(int i = 0;i<M;++i)
        {
            for(int j = 0;j<N;++j)
            {
                if(matrix[i][j] == '0')
                {
                    base[j] = 0;
                }
                else
                {
                    base[j]++;
                }
            }
            MAX = max(solvebase(i,base),MAX);

        }
        return MAX;
        
    }
};