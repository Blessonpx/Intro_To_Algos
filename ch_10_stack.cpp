#include <iostream>
#include <boost/array.hpp>
#include <random>
#include <algorithm>
using namespace std;

#include <iostream>
#include <boost/array.hpp>

const int MAX_SIZE = 10; // Maximum size of the stack

class Stack {
private:
    boost::array<int, MAX_SIZE> arr;
    int top; // Index of the top element in the stack

public:
    Stack() {
        top = -1; // Initialize the top index to -1 (stack is initially empty)
    }

    void push(int value) {
        if (top == MAX_SIZE - 1) {
            std::cout << "Stack overflow" << std::endl;
        } else {
            top++;
            arr[top] = value;
            std::cout << value << " pushed to stack" << std::endl;
        }
    }

    void pop() {
        if (top == -1) {
            std::cout << "Stack underflow" << std::endl;
        } else {
            int value = arr[top];
            top--;
            std::cout << value << " popped from stack" << std::endl;
        }
    }

    bool empty() {
        return top == -1;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    while (!s.empty()) {
        s.pop();
    }
    s.pop(); // Stack underflow (stack is already empty)
    return 0;
}
