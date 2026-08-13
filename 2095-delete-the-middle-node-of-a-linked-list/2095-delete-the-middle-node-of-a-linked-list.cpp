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
    int sizeOfLL(ListNode* head){
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    ListNode* deleteMid(ListNode* head,int n){
        if(head == NULL){
            return head;
        }
        if(n == 1){
            return NULL;
        }
        int cnt = 1;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL && cnt<n){
            cnt++;
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
        return head;
    }

    ListNode* deleteMiddle(ListNode* head) {
        int size = sizeOfLL(head);
        int n = (size/2) + 1;
        return deleteMid(head,n);
    }
};