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
    int sizeofLL(ListNode* head){
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int size = sizeofLL(head);
        if(head == NULL){
            return NULL;
        }
        
        if(n == size){
            head = head->next;
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }

        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* rem = slow->next;
        slow->next = rem->next;
        delete rem;
        return head;
    }
};