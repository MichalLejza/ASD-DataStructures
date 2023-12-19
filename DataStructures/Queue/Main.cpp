#include "/DataStructures/Queue/Queue.cpp"

void testPriorityQueue()
{
    auto *a = new Queue::PriorityQueue<int>(4,34);
    a -> insert(5,21);
    a -> insert(10,89);
    a -> insert(56, 63);
    a -> insert(8, 37);
    a -> insert(89, 12);
    a -> print();
    a -> decreaseKey(8, 2);
    a -> print();
    a -> decreaseKey(8, 1);
    a -> print();
    a -> decreaseKey(10, 65);
    a -> print();
    a -> decreaseKey(10, 18);
    a -> print();
    a ->increaseKey(10, 35);
    a -> print();
    a -> increaseKey(89,78);
    a -> print();
}

void testQueue()
{

}

int main()
{
    testPriorityQueue();
    return 0;
}
