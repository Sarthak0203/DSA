/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr){
            return;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* secondHead = slow->next;
        slow->next = nullptr;
        ListNode* cur = secondHead;
        ListNode* prev = nullptr;

        while(cur!=nullptr){
            ListNode* nextNode = cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextNode;
        }

        ListNode* t1 = head;
        ListNode* t2 = prev;
        while(t2!=nullptr){
            ListNode* m1 = t1->next;
            ListNode* m2 = t2->next;
            t1->next = t2;
            t2->next=m1;
            t1=m1;
            t2=m2;
        }

    }
};