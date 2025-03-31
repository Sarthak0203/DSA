/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) break;
        }
        if(fast==nullptr || fast->next==nullptr) return nullptr;
        ListNode* temp=head;
        while(temp!=slow){
            temp=temp->next;
            slow=slow->next;
        }
        return temp;
    }
};