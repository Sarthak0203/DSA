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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int prefix=0;
        unordered_map<int, ListNode*> mp;
        mp[0] = dummy;

        while(head){
            prefix+=head->val;
            if(mp.find(prefix) != mp.end()){
                ListNode* start = mp[prefix];
                ListNode* temp = start;
                int psum = prefix;
                while(temp!=head){
                    temp=temp->next;
                    psum+=temp->val;
                    if(temp!=head)
                        mp.erase(psum);
                }
                start->next=head->next;
            }
            else
                mp[prefix]= head;
            head=head->next;
        }
        return dummy->next;
    }
};