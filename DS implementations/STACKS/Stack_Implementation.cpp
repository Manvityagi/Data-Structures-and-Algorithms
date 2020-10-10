/* C++ program to implement basic stack operations */
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

class Stack
{
    int top;

public:
    int a[MAX]; // Maximum size of Stack

    Stack()
    {
        top = -1;
    }

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x)
{
    // if top reaches the end of the stack then stack is full, we can't push more.
    if (top >= (MAX - 1))
    {
        cout << "Stack Overflow";
        return false;
    }
    // otherwise just push the value in the stack.
    else
    {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    // if top is less than 0 means our stack is empty, we can't pop more.
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}

int Stack::peek()
{
    // if top is less than 0 means stack is having no element.
    if (top < 0)
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        // return the element at top index.
        int x = a[top];
        return x;
    }
}

// if top is less than 0 means our stack is empty.
bool Stack::isEmpty()
{
    return (top < 0);
}

// Driver program
int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.peek();
    cout << s.pop() << " Popped from stack\n";

    return 0;
}
