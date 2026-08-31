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
        ListNode* left=nullptr;
        ListNode* right;

        ListNode* temp = head;
        vector<int> critical;
        int count = 0;
        while(temp){
            if(left && temp->next){
                if(left->val<temp->val && temp->val>temp->next->val){
                    critical.push_back(count);
                }
                if(left->val>temp->val && temp->val<temp->next->val){
                    critical.push_back(count);
                }
            }
            left = temp;
            temp = temp->next;
            count++;
        }
        if(critical.size()<2) return {-1, -1};
        int criSize = critical.size();
        int ma = critical[criSize-1]-critical[0];

        int mi = INT_MAX;
        for(int i=0; i<criSize-1; i++){
            mi = min(mi, critical[i+1] - critical[i]);
        }                

        return {mi, ma};
    }
};