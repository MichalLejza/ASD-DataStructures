#include "Node.cpp"
#include "iostream"

auto testWeightedGraphs() -> void
{
    auto *one = new Node::WeightedGraphNode<int64_t>(10);
    auto *two = new Node::WeightedGraphNode<int64_t>(20);
    auto *three = new Node::WeightedGraphNode<int64_t>(30);
    auto *four = new Node::WeightedGraphNode<int64_t>(40);

    std::pair<Node::WeightedGraphNode<int64_t> *, ssize_t> paraTwo{two, 10};
    std::pair<Node::WeightedGraphNode<int64_t> *, ssize_t> paraThree(three, 30);

    one -> addConnection(paraTwo);
    one ->addConnection(paraThree);
    one ->addConnection(four, 90);
    int64_t x = 50;
    one ->addConnection(x,100);

    one -> printNode();
    one -> printConnectedNodes();
    two -> printNode();
    two -> printConnectedNodes();
    three -> printNode();
    three -> printConnectedNodes();
    four -> printNode();
    four -> printConnectedNodes();

    auto *test = new Node::WeightedGraphNode<int64_t>(30);

    for (auto a : one -> connectedNodes)
    {
        if (a.first -> getData() == test -> getData())
        {
            std::cout << "YES: " << a.first -> getData() << " == " << test -> getData() << std::endl;
        }
        else
        {
            std::cout << "NO: " << a.first -> getData() << " == " << test -> getData() << std::endl;
        }
    }

    std::cout << one->getSetSize();
    delete one;
    delete two;
    delete three;
    delete four;
    delete test;
}

auto testBSTNode() -> void
{
    auto *one = new Node::BNode<int>(10);
    auto *two = new Node::BNode<int>(10);
    one -> printNode();

    one -> setLeft(10);
    one -> getLeft() -> printNode();

    one -> setRight(two);
    one -> getRight() -> printNode();
}


auto main() -> int
{
    testBSTNode();
    return 0;
}
