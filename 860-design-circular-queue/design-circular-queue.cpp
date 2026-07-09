class MyCircularQueue {
public:
    vector<int> arr;
    int front;
    int back;
    int capacity;
    int curr_size;

    MyCircularQueue(int k) {
        arr.resize(k);
        capacity = k;
        curr_size = 0;
        front = -1;
        back = -1;
    }
    
    bool enQueue(int value) {
        if(curr_size==capacity) return false;
        if(curr_size==0){
            front = 0;
            back = 0;
        }else{
            back++;
        }
        arr[back%capacity] = value;
        curr_size++;
        return true;
    }
    
    bool deQueue() {
        if(curr_size==0) return false;
        front++;
        curr_size--;
        if(curr_size==0){
            front = -1;
            back = -1;
        }
        return true;
    }
    
    int Front() {
        if(curr_size==0) return -1;
        return arr[front%capacity];
    }
    
    int Rear() {
        if(curr_size==0) return -1;
        return arr[back%capacity];
    }
    
    bool isEmpty() {
        return curr_size==0;
    }
    
    bool isFull() {
        return curr_size==capacity;
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