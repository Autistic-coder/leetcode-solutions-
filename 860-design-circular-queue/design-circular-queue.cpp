#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int head;
    int count;
    int capacity;

public:
    MyCircularQueue(int k) : data(k), head(0), count(0), capacity(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;

        data[(head + count) % capacity] = value;
        ++count;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        head = (head + 1) % capacity;
        --count;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return data[(head + count - 1) % capacity];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};