class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

private:
    Node* head;
    Node* tail;
    int capacity;
    unordered_map<int, Node*> cache;

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);  // Dummy head
        tail = new Node(-1, -1);  // Dummy tail
        head->next = tail;
        tail->prev = head;
    }

    // Add a node right after the dummy head
    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    // Remove a node from the linked list
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* resNode = cache[key];
            int result = resNode->val;

            // Move the accessed node to the front
            deleteNode(resNode);
            addNode(resNode);
            cache[key] = head->next;

            return result;
        }
        return -1;
    }

    void put(int key, int value) {
    // If key already exists
    if (cache.find(key) != cache.end()) {
        Node* node = cache[key];
        node->val = value;     // Update value
        deleteNode(node);       // Remove from current position
        addNode(node);          // Insert at front (most recently used)
        return;
    }

    // If capacity is full, remove least recently used node
    if (cache.size() == capacity) {
        Node* lru = tail->prev;      // Least recently used node
        deleteNode(lru);
        cache.erase(lru->key);
    }

    // Create new node and insert at front
    Node* newNode = new Node(key, value);
    addNode(newNode);
    cache[key] = newNode;
}

};
