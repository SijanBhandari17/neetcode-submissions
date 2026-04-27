struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyCircularQueue {
private: 
    int size;
    int max_size;
    ListNode* front = nullptr;
    ListNode* rear = nullptr;
    
public:
    MyCircularQueue(int k) {
        size = 0;
        max_size = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            rear = new ListNode(value);
            front = rear;
        } 
        else{
            rear->next = new ListNode(value);
            rear = rear->next;
        }
        rear->next = front;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(front == rear) {
            front = rear = nullptr;
            size--;
            return true;
        }
        ListNode *temp = front->next;
        rear->next = temp;
        front->next = nullptr;
        front = temp;
        size--;
        return true;
    }
    
    int Front() {
                if(isEmpty()) return -1;

        return front->val;
        
    }
    
    int Rear() {
                if(isEmpty()) return -1;

        return rear->val;
        
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == max_size;
        
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