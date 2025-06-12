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
        if (cache.find(key) != cache.end()) {
            // Remove the old node
            Node* existingNode = cache[key];
            deleteNode(existingNode);
            cache.erase(key);
        }

        if (cache.size() == capacity) {
            // Remove least recently used node
            Node* lru = tail->prev;
            deleteNode(lru);
            cache.erase(lru->key);
        }

        // Insert new node at front
        Node* newNode = new Node(key, value);
        addNode(newNode);
        cache[key] = head->next;
    }
};
