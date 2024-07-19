https://leetcode.com/problems/middle-of-the-linked-list/description/

class Solution {
public:
    ListNode* middleNodeHelper(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
            if(fast->next!=NULL){
                fast = fast->next;
            }
        }
        return slow;
    }

    ListNode* middleNode(ListNode* head) {
        return middleNodeHelper(head);
    }
};