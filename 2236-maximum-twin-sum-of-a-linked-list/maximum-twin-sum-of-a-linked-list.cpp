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
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        int n;
        int maxi=INT_MIN;
        while(temp){
            n++;
            temp=temp->next;
        }
        vector<int> sum(n/2, 0);
        temp=head;
        for(int i=0;i<n/2;i++){
            sum[i]=temp->val;
            temp=temp->next;
        }
        for(int i=n/2-1;i>=0;i--){
            sum[i]+=temp->val;
            temp=temp->next;
            maxi=max(maxi, sum[i]);
        }
        return maxi;
    }
};