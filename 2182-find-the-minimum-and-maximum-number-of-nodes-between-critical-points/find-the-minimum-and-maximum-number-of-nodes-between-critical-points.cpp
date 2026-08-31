class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;
        int first = -1;
        int last = -1;
        int minDist = INT_MAX;

        while (curr->next) {
            bool isCritical =
                (curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val);

            if (isCritical) {
                if (first == -1) {
                    first = index;
                } else {
                    minDist = min(minDist, index - last);
                }

                last = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if (first == -1 || first == last)
            return {-1, -1};

        int maxDist = last - first;

        return {minDist, maxDist};
    }
};
