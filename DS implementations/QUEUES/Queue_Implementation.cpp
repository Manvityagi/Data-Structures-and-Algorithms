// C++ program for array implementation of q

#include <iostream>
#include <queue>
using namespace std;

// A class to represent a q
class Queue
{
public:
    int front, rear, size;
    unsigned capacity;
    int *array;
};

// function to create a queue of given capacity, it initializes size of queue as 0
Queue *createQueue(unsigned capacity)
{
    Queue *q = new Queue();
    q->capacity = capacity;
    q->front = q->size = 0;

    // assigning last index of the q to the rear.
    q->rear = capacity - 1;
    // dynamically allocating int array of capacity.
    q->array = new int[q->capacity];
    return q;
}

// Queue is full when size becomes equal to the capacity
int isFull(Queue *q)
{
    return (q->size == q->capacity);
}

// Queue is empty when size is 0
int isEmpty(Queue *q)
{
    return (q->size == 0);
}

// Function to add an item to the queue. It changes rear and size
void enqueue(Queue *q, int item)
{
    // if queue is full then we can't push more.
    if (isFull(q))
        return;
    // updating rear to next index.
    q->rear = (q->rear + 1) % q->capacity;
    // storing the item at the rear index of the queue.
    q->array[q->rear] = item;
    // as we added one more element so increment the size of the queue.
    q->size = q->size + 1;
    cout << item << " enqueued to q\n";
}

// Function to remove an item from queue. It changes front and size
int dequeue(Queue *q)
{
    // if queue is empty then we can't dequeue more, so for handling the underflow we will return INT_MIN.
    if (isEmpty(q))
        return INT_MIN;
    // as we dequeue from the front of the queue so we will store the front element in item variable.
    int item = q->array[q->front];
    // updating the front to the next index.
    q->front = (q->front + 1) % q->capacity;
    // as we have removed one element so we will decrement the size of the queue by 1.
    q->size = q->size - 1;
    return item;
}

// Function to get front of queue
int front(Queue *q)
{
    // in underflow condition we will return INT_MIN.
    if (isEmpty(q))
        return INT_MIN;
    // otherwise returning the element at the front index of the queue.
    return q->array[q->front];
}

// Function to get rear of queue
int rear(Queue *q)
{
    // in underflow condition we will return INT_MIN.
    if (isEmpty(q))
        return INT_MIN;
    // otherwise returning the element at the rear index of the queue.
    return q->array[q->rear];
}

// Driver code
int main()
{
    // creating a queue of maximum capacity 1000.
    Queue *q = createQueue(1000);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    cout << dequeue(q) << " dequeued from queue\n";

    cout << "Front item is " << front(q) << endl;
    cout << "Rear item is " << rear(q) << endl;

    return 0;
}