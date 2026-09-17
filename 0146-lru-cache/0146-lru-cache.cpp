class LRUCache {
private:
    class Node{
        public:
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k,int v){
            key = k;
            value = v;
            prev = next = NULL;
        }
    };

    int capacity;
    unordered_map<int,Node*>mp;
    Node* head;
    Node* tail;    

    void removeNode(Node* temp){
        Node* prevNode = temp->prev;
        Node* nextNode = temp->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAtFront(Node* temp){
        Node* nxt = head->next;

        head->next = temp;
        temp->next = nxt;

        nxt->prev = temp;
        temp->prev = head;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        Node* temp = mp[key];

        removeNode(temp);
        insertAtFront(temp);

        return temp->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* temp = mp[key];

            temp->value = value;

            removeNode(temp);
            insertAtFront(temp);
            
            return;
        }

        Node* temp = new Node(key,value);

        mp[key] = temp;

        insertAtFront(temp);

        if(mp.size() > capacity){
            Node* lru = tail->prev;

            mp.erase(lru->key);
            removeNode(lru);
            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */