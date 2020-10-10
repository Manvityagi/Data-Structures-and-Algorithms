#include <iostream>
using namespace std;

int stack[100], n = 100, top = -1;

void push(int val)
{
    // if top reaches end means stack is full now, we can't push more.
    if (top >= n - 1)
        cout << "Stack Overflow" << endl;
    // otherwise just increment the top and push the value in the stack.
    else
    {
        stack[top++] = val;
    }
}

void pop()
{
    // if stack got empty then we can't pop more.
    if (top <= -1)
        cout << "Stack Underflow" << endl;
    else
    {
        cout << "The popped element is " << stack[top] << endl;
        top--;
    }
}

void display()
{
    // we can print only if we are at valid index of queue.
    if (top >= 0)
    {
        cout << "Stack elements are:";

        // printing all the elements of the queue starting from top and decrementing it we will reach next element.
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
    else
        cout << "Stack is empty"; // if top is -1 means it is empty.
}

int main()
{
    int ch, val;
    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Exit" << endl;
    do
    {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            push(val);
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            cout << "Exit" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (ch != 4);

    return 0;
}