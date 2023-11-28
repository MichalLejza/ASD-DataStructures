#include <iostream>
#include <utility>
#include <vector>
#include "/Users/michallejza/CLionProjects/Everything/Sorts/Sorts.cpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Node/Node.cpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/LinkedList/LinkedList.cpp"
#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Queue/Queue.cpp"

struct Person {
    std::string name;
    int age;

    // Constructor
    Person(std::string n, int a) : name(std::move(n)), age(a) {}

    friend std::ostream& operator <<(std::ostream& os, const Person &p)
    {
        os << "Name: " << p.name << "  Age: " << p.age;
        return os;
    }
};

void testNode()
{
    Person person("Aga", 10);
    Person newPerson("Michal", 20);

    auto *n1 = new Node::Node<Person>(person);
    n1 -> printNode();
    std::cout << std::endl;

    n1 -> setData(newPerson);

    auto *n2 = new Node::Node<Person>(person);
    n1 ->setNext(n2);

    n1 -> printNode();
    n2 -> printNode();

    std::cout << std::endl;
    n1 -> printNode();
    n1 -> getNext() -> printNode();
}

void testLinkedList()
{
    auto *list = new LinkedList::LinkedList<int>();
    list -> pushBack(10);
    list -> pushBack(12);
    list -> pushFront(15);
    list -> printList();
    list -> sort();
    list -> printList();
    list -> pushBack(20);
    list -> printList();
}

int main()
{
    testLinkedList();
    return 0;
}