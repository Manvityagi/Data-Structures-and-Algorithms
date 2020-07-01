#include <bits/stdc++.h>
using namespace std;

void swap(vector<int> pq, int a, int b)
{
    int temp = pq[a];
    pq[a] = pq[b];
    pq[b] = temp;
}

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

    int getMax()
    {
        if (isEmpty())
        {
            return 0; // Priority Queue is empty
        }
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;
        int parentIndex = (childIndex - 1) / 2;
        //Compare data we just inserted to parents data. If its greater than parents we swap
        //Continue to do this until we reach the root node
        while (childIndex > 0 && pq[parentIndex] < pq[childIndex])
        {
            swap(pq, parentIndex, childIndex);

            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
    }

    int removeMax()
    {
        if (pq.size() == 0)
            return 0;
        int todel = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parent = 0, c1 = 1, c2 = 2;

        while ((parent < pq.size() - 1) && (pq[parent] < pq[c1] || pq[parent] < pq[c2]))
        {
            int newparent = (pq[c1] > pq[c2]) ? c1 : c2;
            swap(pq, newparent, parent);
            parent = newparent;
            c1 = 2 * parent + 1, c2 = 2 * parent + 2;
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
        case 2: // getmax
            cout << pq.getMax() << endl;
            break;
        case 3: // removemax
            cout << pq.removeMax() << endl;
            break;
        case 4: // size
            cout << pq.getSize() << endl;
            break;
        case 5: // isEmpty
            if (pq.isEmpty())
            {
                cout << "true" << endl;
            }
            else
            {
                cout << "false" << endl;
            }
            break;
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
