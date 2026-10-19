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
    ListNode* reverseLL(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* temp = head;
        ListNode* front = NULL;
        ListNode* prev = NULL;
        while(temp != NULL){
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        head = prev;

        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newl1 = reverseLL(l1);
        ListNode* newl2 = reverseLL(l2);

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        int carry = 0;
        while(newl1 != NULL || newl2 != NULL || carry){
            int sum = carry;

            if(newl1 != NULL){
                sum += newl1->val;
                newl1 = newl1->next;
            }
            if(newl2 != NULL){
                sum += newl2->val;
                newl2 = newl2->next;
            }

            carry = sum/10;

            temp->next = new ListNode(sum%10);
            temp = temp->next;
        }

        ListNode* ans = reverseLL(dummy->next);
        return ans;
    }
};