struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int v = -1, ListNode *nxt = nullptr) :
        val(v),
        next(nxt)
    {}
};

class MyCircularQueue {
private:
    int size;
    int cap;
    ListNode *head;
    ListNode *tail;
public:
    MyCircularQueue(int k) {
        size = 0;
        cap = k;
        head = new ListNode();
        tail = new ListNode();
    }
    
    bool enQueue(int value) {
        if (size == cap)
            return false;

        ListNode *newNode = new ListNode(value);

        if (size > 0)
            tail->next->next = newNode;

        tail->next = newNode;

        if (size == 0)
            head->next = newNode;

        size++;
        return true;
    }
    
    bool deQueue() {
        if (size == 0)
            return false;

        head->next = head->next->next;
        size--;
        
        if (size == 0)
            tail->next = nullptr;

        return true;
    }
    
    int Front() {
        if (size == 0)
            return -1;

        return head->next->val;
    }
    
    int Rear() {
        if (size == 0)
            return -1;

        return tail->next->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */