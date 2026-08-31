class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) return {-1, -1};
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* nxt = curr->next;
        
        int first_crit = -1;
        int prev_crit = -1;
        int min_dist = INT_MAX;
        
        int curr_index = 1;
        
        while (nxt != nullptr) {
            if ((prev->val < curr->val && curr->val > nxt->val) || 
                (prev->val > curr->val && curr->val < nxt->val)) {
                
                if (first_crit == -1) {
                    first_crit = curr_index;
                } else {
                    min_dist = min(min_dist, curr_index - prev_crit);
                }
                prev_crit = curr_index;
            }
            
            curr_index++;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        
        if (min_dist == INT_MAX) return {-1, -1};
        
        int max_dist = prev_crit - first_crit;
        
        return {min_dist, max_dist};
    }
};