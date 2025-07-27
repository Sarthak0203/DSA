class Solution {

private:
    int f(ListNode* node){
        int x = 0;
        while (node && node->val != 0) {
            x += node->val;
            node = node->next;
        }
        return x;
    }

public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0); // dummy node for result list
        ListNode* curr = dummy;
        ListNode* temp = head->next; // skip first 0

        int sum = 0;
        while (temp) {
            if (temp->val == 0) {
                // end of one segment
                curr->next = new ListNode(sum);
                curr = curr->next;
                sum = 0;
            } else {
                sum += temp->val;
            }
            temp = temp->next;
        }

        return dummy->next;
    }
};
