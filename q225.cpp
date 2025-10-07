// Implementing a stack using queues
#include <iostream>
#include <queue>

using namespace std;

class MyStack {
    queue<int> main; // main queue
    queue<int> sub; // temporary storage
public:
    MyStack() {
        
    }
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        int main_size = main.size();
        for(int i = 0; i < main_size-1; i++) {
            // sub queue will store the elements in main,
            // but in reverse order- like a stack
            sub.push(main.front());
            main.pop();
        }

        int pop_value = main.front(); // the last value inside main
        main.pop();

        while(!sub.empty()) {
            // move values of sub back to main
            main.push(sub.front());
            sub.pop();

            // now main contains the elements in the original order
        }

        return pop_value;
    }
    
    int top() { // = front()
        int main_size = main.size();
        for(int i = 0; i < main_size-1; i++) {
            // sub queue will store the elements in main,
            // but in reverse order- like a stack
            sub.push(main.front());
            main.pop();
        }

        int top_value = main.front(); // the last value inside main
        // do not main.pop()

        while(!sub.empty()) {
            // move values of sub back to main
            main.push(sub.front());
            sub.pop();

            // now main contains the elements in the original order
        }

        // the top_value should be at the back of the queue
        main.push(main.front());
        main.pop();

        return top_value;
    }
    
    bool empty() {
        return main.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */