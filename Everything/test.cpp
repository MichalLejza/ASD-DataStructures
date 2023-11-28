#include "iostream"
#include "cstdlib"

class Node {
public:
    int val;
    Node* next;
    Node* random;

    explicit Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        std::cout << "[ " << current -> val << ", ";
        if (current -> random == nullptr)
            std::cout << "NULL";
        else
            std::cout << current -> random -> val;
        std::cout << " ] -> ";
        current = current -> next;
    }
    std::cout << "NULL";
    std::cout << std::endl;
}

Node *copyRandomList(Node *head)
{
    if (!head)
        return nullptr;
    Node *original = head;
    Node *temp = nullptr;

    while (original)
    {
        temp = new Node(original -> val);
        temp -> next = original -> next;
        original -> next = temp;
        original = temp -> next;
    }

    printList(head);

    original = head;
    Node* newHead = head -> next;

    while (original)
    {
        if (original -> random)
            original -> next -> random = original -> random -> next;
        else
            original -> next -> random = nullptr;
        original = original -> next -> next;
    }

    printList(head);

    original = head;

    while (original)
    {
        temp = original -> next;
        original -> next = temp -> next;
        original = original -> next;

        if (original)
            temp -> next = original -> next;
        else
            temp -> next = nullptr;
    }
    return newHead;
}

int main()
{
    Node *one = new Node(7);
    Node *two = new Node(13);
    Node *three = new Node(11);
    Node *four = new Node(10);
    Node *five = new Node(1);
    one -> next = two;
    two -> next = three;
    three -> next = four;
    four -> next = five;
    two -> random = one;
    three -> random = five;
    four -> random = three;
    five -> random = one;
    printList(one);
    auto copy = copyRandomList(one);
    printList(copy);
    return 0;
}
