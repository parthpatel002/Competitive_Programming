class Node {
public:
    
    int val;
    Node* next;
    Node* prev;
    
    Node(int value) : val(value), next(NULL), prev(NULL){ }
    
};

class MyLinkedList {
public:
    
    Node* head;
    Node* tail;
    int sz;
    
    /** Initialize your data structure here. */
    MyLinkedList() : head(NULL), tail(NULL), sz(0) { }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= sz)
            return -1;
        if(index < 0)
            return -1;
        Node* temp = head;
        int idx = 0;
        while(idx < index){
            temp = temp->next;
            idx++;
        }
        return temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        if(sz == 0){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        sz++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if(sz == 0){
            head = newNode;
            tail = newNode;
        }
        else{
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        sz++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0 || index > sz)
            return;
        else if(index == 0){
            this->addAtHead(val);
        }
        else if(index == sz){
            this->addAtTail(val);
        }
        else{
            Node* newNode = new Node(val);
            Node* n = head;
            Node* p = NULL;
            int idx = 0;
            while(idx < index){
                p = n;
                n = n->next;
                idx++;
            }
            p->next = newNode;
            n->prev = newNode;
            newNode->prev = p;
            newNode->next = n;
            sz++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= sz)
            return;
        else if(index == 0){
            if(sz == 1){
                delete head;
                head = NULL;
                tail = NULL;
            }
            else{
                Node* temp = head->next;
                delete head;
                temp->prev = NULL;
                head = temp;
            }
            sz--;
        }
        else if(index == sz-1){
            Node* temp = tail->prev;
            delete tail;
            temp->next = NULL;
            tail = temp;
            sz--;
        }
        else{
            Node* c = head;
            int idx = 0;
            while(idx < index){
                c = c->next;
                idx++;
            }
            Node* p = c->prev;
            Node* n = c->next;
            p->next = n;
            n->prev = p;
            delete c;
            sz--;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
