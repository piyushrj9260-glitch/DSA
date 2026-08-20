/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* temp = head;
        unordered_map<ListNode*,int>mpp;
        int t = 0;
        while(temp != NULL){
            if(mpp.find(temp) != mpp.end()){
                return temp;
            }
            mpp[temp] = t++;
            temp = temp->next;
        }
        return NULL;
    }
};