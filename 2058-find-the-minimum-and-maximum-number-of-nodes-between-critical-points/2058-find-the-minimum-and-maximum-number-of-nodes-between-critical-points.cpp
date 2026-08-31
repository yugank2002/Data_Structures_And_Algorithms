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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* nextt = head->next->next;
        ListNode* curr = head->next;
        ListNode* prev = head;

        vector<int>ans;
        int i=2;
        while(nextt!=NULL){
            if( (curr->val<prev->val && curr->val<nextt->val) || (curr->val>prev->val && curr->val>nextt->val) ){
                ans.push_back(i);
            }
            prev = curr;
            curr = nextt;
            nextt = nextt->next;
            i++;
        }

        if(ans.size()<2)return {-1,-1};

        int mini = INT_MAX;
        for(int i=1; i<ans.size(); i++){
            mini = min(mini,ans[i]-ans[i-1]);
        }
        int maxi = ans[ans.size()-1]-ans[0];

        return {mini,maxi};
    }
};