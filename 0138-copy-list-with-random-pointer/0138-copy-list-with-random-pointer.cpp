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

        Node* temp = head;

        while(temp != nullptr)
        {
            Node* copynode = new Node(temp->val);
            copynode->next = temp->next;
            temp->next = copynode;
            temp = temp->next->next;
        }
        temp = head;
        while(temp != nullptr)
        {
            if (temp->random != nullptr) {
                temp->next->random = temp->random->next; 
            } else {
                temp->next->random = nullptr;
            }
            temp = temp->next->next;
        }
        Node dummy(0);
        Node* res = &dummy;
        temp = head;
        while(temp != nullptr)
        {
            res->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            res = res->next;
        }
        return dummy.next;
        
    }
};