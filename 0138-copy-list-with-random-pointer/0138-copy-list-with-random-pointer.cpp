/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return head;
        }
        Node* temp = head;
        while(temp != NULL){
            Node* cpy = new Node(temp->val);
            cpy->next = temp->next;
            temp->next = cpy;
            temp = cpy->next;
        }

        temp = head;
        while(temp != NULL){
            Node* cpy = temp->next;

            if(temp->random != NULL){
                cpy->random = temp->random->next;
            }else{
                cpy->random = NULL;
            }

            temp = cpy->next;
        }

        Node* dummy = new Node(-1);
        Node* res = dummy;
        temp = head;

        while(temp != NULL){
            Node* cpy = temp->next;
            temp->next = cpy->next;

            res->next = cpy;
            res = res->next;

            temp = temp->next;
        }

        return dummy->next;
    }
};