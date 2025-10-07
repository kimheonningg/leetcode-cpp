// Implementing a queue using stacks
#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> main; // main stack that stores element in reverse order
    stack<int> sub; // temporary storage
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        int main_size = main.size();
        for(int i = 0; i < main_size-1; i++) {
            // temporarily move values of main to sub
            sub.push(main.top());
            main.pop();
        }

        int pop_value = main.top(); // the last value inside main
        main.pop();

        while (!sub.empty()) {
            // move values of sub back to main
            main.push(sub.top());
            sub.pop();
        }

        return pop_value;
    }
    
    int peek() { // = top()
        int main_size = main.size();
        for(int i = 0; i < main_size-1; i++) {
            // temporarily move values of main to sub
            sub.push(main.top());
            main.pop();
        }

        int top_value = main.top(); // the last value inside main
        // do not main.pop()

         while (!sub.empty()) {
            // move values of sub back to main
            main.push(sub.top());
            sub.pop();
        }

        return top_value;
    }
    
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */