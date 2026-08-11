class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        using pp = pair<int, ListNode*>;

        priority_queue<
            pp,
            vector<pp>,
            greater<pp>
        > pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        if (pq.empty())
            return nullptr;

        pp topEl = pq.top();
        pq.pop();

        ListNode* ans = topEl.second;
        ListNode* prev = topEl.second;

        if (topEl.second->next) {
            pq.push({
                topEl.second->next->val,
                topEl.second->next
            });
        }

        while (!pq.empty()) {

            topEl = pq.top();
            pq.pop();

            prev->next = topEl.second;
            prev = topEl.second;

            if (topEl.second->next) {
                pq.push({
                    topEl.second->next->val,
                    topEl.second->next
                });
            }
        }

        return ans;
    }
};