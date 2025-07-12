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
    ListNode* reverseLinkedList(ListNode *head) {
        ListNode* temp = head;  
        ListNode* prev = nullptr;  
        while (temp != nullptr) {  
            ListNode* front = temp->next;  
            temp->next = prev;  
            prev = temp;  
            temp = front; 
        }
        return prev;  
    }

    ListNode* getKthNode(ListNode* temp, int k) {
        k -= 1; 
        while (temp != nullptr && k > 0) {
            k--; 
            temp = temp->next; 
        }
        return temp; 
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head; 
        ListNode* prevLast = nullptr; //taking the last pointer of previous segment
        
        while (temp != nullptr) {// we are doing this operation untill we did it for all k segments
            ListNode* kThNode = getKthNode(temp, k); /// it is to get he kth node
            if (kThNode == nullptr) { // that means there are no more segment that have k nodes
                if (prevLast) { // means we got the segment before
                    prevLast->next = temp; 
                }
                break; 
            }
            
            ListNode* nextNode = kThNode->next; // it is to take first node of non reversed current segment
            kThNode->next = nullptr;  // here we are braking the link between current and previous segment so that our reverse fumction can reverse the linked list of previous k segment 
            reverseLinkedList(temp); /// it is to reverse the segment
            
            if (temp == head) { // whether it is first segment or in the middle
                head = kThNode; // if it is first segment, it is not in between somewhere
            } else {
                prevLast->next = kThNode; // if it is in between somewhere
            }

            prevLast = temp; 
            temp = nextNode; 
        }
        
        return head; 
    }
};