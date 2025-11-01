class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(begin(nums), end(nums));

        
        while (head != nullptr && st.count(head->val)) {
            head = head->next;
        }

        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (st.count(curr->next->val)) {
                curr->next = curr->next->next; 
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};
