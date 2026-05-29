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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        for (ListNode* list : lists){
            if (list != nullptr){
                pq.push(list);
            }
        }

        ListNode* res = new ListNode();
        ListNode* cur = res;
        while (!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();
            cur->next = node;
            cur = cur->next;
            
            node = node->next;
            if (node != nullptr){
                pq.push(node);
            }
        }
        return res->next;
    }

    struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
};
