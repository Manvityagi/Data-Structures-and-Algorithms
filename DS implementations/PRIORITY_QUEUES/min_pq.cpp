#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    // Return the size of priorityQueue - no of elements present
    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
            return 0; // Priority Queue is empty

        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        //Compare data we just inserted to parents data.If its less than parens we swap
        //Continue to do this until we reach the root node
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }
    int removeMin()
    {
        if (pq.size() == 0)
            return 0;
        int minindex;
        int todel = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentindex = 0;
        int childindex1 = 1;
        int childindex2 = 2;
        while (childindex1 < pq.size())
        {

            if (pq[childindex1] < pq[parentindex] || pq[childindex2] < pq[parentindex])
            {
                if (pq[childindex1] < pq[childindex2])
                    minindex = childindex1;
                else
                    minindex = childindex2;

                int temp = pq[parentindex];
                pq[parentindex] = pq[minindex];
                pq[minindex] = temp;

                parentindex = minindex;
                childindex1 = 2 * parentindex + 1;
                childindex2 = 2 * parentindex + 2;
            }
            else
                break;
        }
        return todel;
    }
    void display()
    {
        for (int i = 0; i < pq.size(); i++)
            cout << pq[i] << " ";
        cout << endl;
    }
};
int main()
{
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while (choice != -1)
    {
        switch (choice)
        {
        case 1: // insert
            int element;
            cin >> element;
            pq.insert(element);
            break;
        case 2: // getMin
            cout << pq.getMin() << endl;
            break;
        case 3: // removeMin
            cout << pq.removeMin() << endl;
            break;
        case 4: // size
            cout << pq.getSize() << endl;
            break;
        case 5: // isEmpty
            if (pq.isEmpty())
                cout << "true" << endl;
            else
                cout << "false" << endl;
        case 6: // show
            pq.display();
            break;
        default:
            return 0;
        }
        cin >> choice;
    }
    getchar();
    return 0;
}
