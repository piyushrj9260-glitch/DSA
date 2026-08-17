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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }
        int cnt = 1;
        ListNode* temp = head;
        ListNode* l = NULL;
        ListNode* r = NULL;

        while(temp != NULL){
            if(cnt == left){
                l = temp;
            }
            if(cnt == right){
                r = temp;
            }
            temp = temp->next;
            cnt++;
        }
        stack<int>st;
        temp = l;
        while(temp != r){
            st.push(temp->val);
            temp = temp->next;
        }
        st.push(temp->val);
        temp = l;
        while(!st.empty()){
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
    }
};