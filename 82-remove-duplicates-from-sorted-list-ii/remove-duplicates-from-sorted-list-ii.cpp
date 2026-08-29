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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> mp;
        ListNode* temp = head;

        while(temp){
            mp[temp->val]++;
            temp = temp->next;
        }
        temp = head;
        for(auto &[a, b]: mp){
            if(b==1){
                temp->val = a;
                temp = temp->next;
            }
        }
        if(temp==head) return nullptr;
        if(temp && temp->next){
            temp->next = nullptr;
            temp = head;
            while(temp->next->next){
                temp = temp->next;
            }
            temp->next = nullptr;

        }
        temp = head;

        return head;
    }
};