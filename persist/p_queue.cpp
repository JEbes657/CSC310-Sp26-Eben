#include <iostream>
#include <memory>

using namespace std;

template <typename T>

struct Node
{
    T value;
    shared_ptr<Node<T>> next;

    Node(T val, shared_ptr<Node<T>> nxt = nullptr)
    {
        value = val;
        next = nxt;
    }
};

template <typename T>
shared_ptr<Node<T>> reverse(shared_ptr<Node<T>> head)
{
    shared_ptr<Node<T>> result = nullptr;
    
    while (head)
    {
        result = make_shared<Node<T>>(head->value, result);
        head = head->next;
    }

    return result;
}

template <typename T>
class persistentQueue
{
    private:
        shared_ptr<Node<T>> front;
        shared_ptr<Node<T>> back;
        int frontSzie;
        int backSize;

        persistentQueue balance()
        {
            if (backSize <= frontSize)
            {
                return *this;
            }
            // trigger expensive operation

            auto newFront = front;
            auto reverseRead = reverse(back);

            auto reversedRear = reverse(back);

            auto temp = reversedBack;
            while (temp)
            {
                newFront = make_shared<Node<T>>(temp->value, newFront);
                temp = temp->next;
            }

            return persistentQueue(newFront, nullptr, frontSize + backSize, 0);
        }
    public:
        persistentQueue()
        {
            front = nullptr;
            back = nullptr;
            frontSize = 0;
            backSize = 0;
        }

        persistentQueue(shared_ptr<Node<T>> f, shared_ptr<Node<T>> b, int fSize, int bSize)
        {
            front = f;
            back = b;
            frontSize = fSize;
            backSize = bSize;
        }

        bool isEmpty()
        {
            return frontSize == 0;
        }

        persistentQueue enqueue(T value)
        {
            auto newBack = make_shared<Node<T>>(value, back);
            return persistentQueue(front, newBack, frontSize, backSize + 1).balance();
        }

        persistentQueue dequeue()
        {
            if (isEmpty()) {
                throw runtime_error("Queue is empty");
            }
            
            return persistentQueue(front->next, back, frontSize - 1, backSize).balance();
        }

        T peek()
        {
            if (isEmpty()) {
                throw runtime_error("Queue is empty");
            }
            return front->value;
        }
};

int main()
{
    persistentQueue<int> q1;

    auto q2 = q1.enqueue(10);
    auto q3 = q2.enqueue(20);
    auto q4 = q3.enqueue(30);
    auto q5 = q4.dequeue();

    cout << q1.peek() << endl;
    cout << q5.peek() << endl;

    return 0;
}