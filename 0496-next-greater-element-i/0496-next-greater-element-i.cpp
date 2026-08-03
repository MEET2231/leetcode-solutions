class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        unordered_map<int,int> mp;
        stack<int> st;
        st.push(nums2[n-1]);
        mp[nums2[n-1]] = -1;
        for(int i = n-2;i>=0;i--)
        {
            if(st.top() >= nums2[i])
            {
                mp[nums2[i]] = st.top();
                st.push(nums2[i]);
                
            }
            else
            {
                while(!st.empty() && st.top() < nums2[i])
                {
                    st.pop();
                }
                if(st.empty()) mp[nums2[i]] = -1,st.push(nums2[i]);
                else
                {
                    mp[nums2[i]] = st.top();
                    st.push(nums2[i]);
                }
            }
        }
        vector<int> ans;
        for(int i = 0;i<m;i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};