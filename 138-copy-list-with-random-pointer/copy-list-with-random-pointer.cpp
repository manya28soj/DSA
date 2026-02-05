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
//approach:   step 1: create a clone lis(using next ptr of original list)
//step 2: cloneNode->random = mapping[originalNode->random] 
class Solution {
public:
void insertAtTail(Node * &head , Node* &tail , int val){
    Node* newNode= new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return ;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}


    Node* copyRandomList(Node* head) {
        //step1: create a clone
        Node*cloneHead = NULL;
        Node* cloneTail=NULL;
        Node*temp =head;
        while(temp != NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp = temp->next;
        }
        //step2: create a map
        unordered_map<Node*,Node*> oldToNewNode;
        Node* originalNode=head;
        Node* cloneNode =cloneHead;
        while(originalNode != NULL   && cloneNode != NULL){
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode=cloneNode->next;
        }

        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL){
            cloneNode -> random = oldToNewNode[originalNode -> random];
             originalNode = originalNode->next;
            cloneNode=cloneNode->next;
        }
        return cloneHead;
    }
};