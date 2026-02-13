#include <stack>
using namespace std;

class MinStack {
    stack<long long> s;
    long long mini;

public:
    MinStack() {}

    void push(int val) {
        long long value = val;

        if(s.empty()) {
            s.push(value);
            mini = value;
        }
        else if(value >= mini) {
            s.push(value);
        }
        else {
            s.push(2LL * value - mini);  // forced 64-bit
            mini = value;
        }
    }

    void pop() {
        long long curr = s.top();
        s.pop();

        if(curr < mini) {
            mini = 2LL * mini - curr;   // forced 64-bit
        }
    }

    int top() {
        long long curr = s.top();
        if(curr < mini)
            return (int)mini;
        else
            return (int)curr;
    }

    int getMin() {
        return (int)mini;
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */