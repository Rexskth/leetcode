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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) return head;

        ListNode* temp1 = head;
        int n = 0;

        // Count the number of nodes
        while (temp1 != nullptr) {
            n++;
            temp1 = temp1->next;
        }

        // Adjust k to prevent unnecessary rotations
        k = k % n;
        if (k == 0) return head; // If no rotation needed, return original list

        temp1 = head;
        ListNode* temp2 = head;

        // Traverse to the breaking point
        int i = 1;
        while (i != n - k) {
            temp1 = temp1->next;
            i++;
        }

        // Update head and rearrange pointers
        head = temp1->next;
        temp1->next = nullptr;
        temp1 = head;

        while (temp1->next != nullptr) {
            temp1 = temp1->next;
        }

        // Connect the tail to the original head
        temp1->next = temp2;

        return head;
    }
};