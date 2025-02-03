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
        if(head==NULL) return head; // no node
        if(head->next==NULL) return head; // only one node
        ListNode* cur = head;
        while(cur->next != NULL){ // becareful with this condition
            if(cur->val == cur->next->val){
                ListNode* temp = cur -> next;
                cur->next = temp->next;
                temp->next = NULL;
            }
            else cur = cur->next;
        }
        return head;
    }
};