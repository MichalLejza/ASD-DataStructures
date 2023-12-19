#include "/DataStructures/LinkedList/LinkedList.cpp"

void testLinkedList()
{
    auto *list = new LinkedList::LinkedList<int>();
    list -> insert(1,2,3,4,5,6,7);
    list -> print();
}

int main()
{
    testLinkedList();
    return 0;
}
