class LRUCache {
public:

    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            next = NULL;
            prev = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int capacity;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        this->capacity = capacity;

        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node) {
        Node* temp = head->next;

        node->next = temp;
        node->prev = head;

        head->next = node;
        temp->prev = node;
    }

    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    int get(int key) {

        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // Remove from current position
        deleteNode(node);

        // Put at front = most recently used
        addNode(node);

        return node->value;
    }

    void put(int key, int value) {

        // Key already exists
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];

            deleteNode(node);
            mp.erase(key);
        }

        // Add new node at front
        Node* node = new Node(key, value);

        addNode(node);
        mp[key] = node;

        // Capacity exceeded
        if (mp.size() > capacity) {

            Node* lru = tail->prev;

            mp.erase(lru->key);
            deleteNode(lru);

            delete lru;
        }
    }
};