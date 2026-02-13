class MyCircularQueue {
    int *arr;
    int front;
    int rear;
    int size;

public:
    MyCircularQueue(int k) {
        size = k;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    
    bool enQueue(int value) {
        if (isFull())
            return false;

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
            return false;

        if (front == rear) {
            front = rear = -1;   // IMPORTANT LINE
        } else {
            front = (front + 1) % size;
        }

        return true;
    }
    
    int Front() {
        if (isEmpty())
            return -1;
        return arr[front];
    }
    
    int Rear() {
        if (isEmpty())
            return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear + 1) % size == front;
    }
};
