#include "/Users/michallejza/CLionProjects/Everything/ASD/8.StrukturyDanych/Functions.hpp"


void zadaniePierwsze()
{
    std::cout << "PODPUNKT A)" << std::endl << "STOS PIERWSZY" << std::endl;
    int e = 9;
    auto *stosPierwszy = new Stack::Stack<int>();
    stosPierwszy->insert(1, 2, 3);
    stosPierwszy -> print();
    stosPierwszy -> pop();
    stosPierwszy -> push(e);
    stosPierwszy -> print();
    delete stosPierwszy;

    std::cout << "STOS DRUGI" << std::endl;
    auto *stosDrugi = new Stack::Stack<int>();
    stosDrugi ->insert(1,2,3);
    stosDrugi -> print();
    stosDrugi -> push(e);
    stosDrugi -> pop();
    stosDrugi -> print();
    delete stosDrugi;
    std::cout << std::endl << "PODPUNKT B)" << std::endl << "STOS PIERWSZY" << std::endl;

    auto *stosTrzeci = new Stack::Stack<int>();
    stosTrzeci ->insert(1,2,3);
    stosTrzeci -> print();
    auto top = stosTrzeci -> getTop();
    stosTrzeci -> pop();
    stosTrzeci ->push(top);
    stosTrzeci -> print();
    delete stosTrzeci;

    std::cout << "STOS DRUGI" << std::endl;
    auto *stosCzwarty = new Stack::Stack<int>();
    stosCzwarty ->insert(1,2,3);
    stosCzwarty -> print();
    stosCzwarty -> push(stosCzwarty -> getTop());
    stosCzwarty -> pop();
    stosCzwarty -> print();
    delete stosCzwarty;

    std::cout << std::endl << "PODPUNKT C)" << std::endl << "STOS PIERWSZY" << std::endl;
    auto *stosPiaty = new Stack::Stack<int>();
    stosPiaty ->insert(1,2,3);
    stosPiaty -> print();
    stosPiaty ->push(e);
    stosPiaty -> pop();
    stosPiaty -> print();
    delete stosPiaty;

    std::cout << std::endl << "PODPUNKT A)" << std::endl << "KOLEJKA PIERWSZA" << std::endl;
    auto *kolejkaPierwsza = new Queue::Queue<int>();
    kolejkaPierwsza ->insert(1,2,3);
    kolejkaPierwsza -> printQueue();
    kolejkaPierwsza -> pop();
    kolejkaPierwsza -> push(e);
    kolejkaPierwsza -> printQueue();
    delete kolejkaPierwsza;

    std::cout << "KOLEJKA DRUGA" << std::endl;
    auto *kolejkaDruga = new Queue::Queue<int>();
    kolejkaDruga ->insert(1,2,3);
    kolejkaDruga -> printQueue();
    kolejkaDruga ->push(e);
    kolejkaDruga -> pop();
    kolejkaDruga -> printQueue();
    delete kolejkaDruga;

    std::cout << std::endl << "PODPUNKT B)" << std::endl << "KOLEJKA PIERWSZA" << std::endl;
    auto *kolejkaTrzecia = new Queue::Queue<int>();
    kolejkaTrzecia ->insert(1,2,3);
    kolejkaTrzecia -> printQueue();
    auto temp = kolejkaTrzecia -> getHead();
    kolejkaTrzecia -> pop();
    kolejkaTrzecia -> push(temp);
    kolejkaTrzecia -> printQueue();
    delete kolejkaTrzecia;

    std::cout << "KOLEJKA DRUGA" << std::endl;
    auto *kolejkaCzwarta = new Queue::Queue<int>();
    kolejkaCzwarta -> insert(1,2,3);
    kolejkaCzwarta -> printQueue();
    kolejkaCzwarta -> push(kolejkaCzwarta -> getHead());
    kolejkaCzwarta -> pop();
    kolejkaCzwarta -> printQueue();
    delete kolejkaCzwarta;

    std::cout << std::endl << "PODPUNKT C)" << std::endl << "KOLEJKA PIERWSZA" << std::endl;
    auto *kolejkaPiata = new Stack::Stack<int>();
    kolejkaPiata ->insert(1,2,3);
    kolejkaPiata -> print();
    kolejkaPiata ->push(e);
    kolejkaPiata -> pop();
    kolejkaPiata -> print();
    delete kolejkaPiata;
}

void ZadanieSzesnaste()
{
    auto *graph = new Graph::DirectedGraph<int>();
    graph ->addNode(0,1);
    graph ->addNode(0,2);
    graph ->addNode(0,3);
    graph ->addNode(0,4);
    graph ->addNode(0,6);
    graph ->addNode(0,7);
    graph ->addNode(1,2);
    graph ->addNode(1,0);
    graph ->addNode(1,3);
    graph ->addNode(1,6);
    graph ->addNode(2,0);
    graph ->addNode(2,1);
    graph ->addNode(2,4);
    graph ->addNode(3,0);
    graph ->addNode(3,1);
    graph ->addNode(3,4);
    graph ->addNode(3,5);
    graph ->addNode(3,6);
    graph ->addNode(4,0);
    graph ->addNode(4,2);
    graph ->addNode(4,2);
    graph ->addNode(5,3);
    graph ->addNode(5,7);
    graph ->addNode(6,0);
    graph ->addNode(6,1);
    graph ->addNode(6,3);
    graph ->addNode(6,7);
    graph ->addNode(7,0);
    graph ->addNode(7,1);
    graph ->addNode(7,5);
    graph ->addNode(7,6);
    graph -> printGraph();
    auto *list = DFS(graph, 0);
    list -> print();
    delete graph;
    delete list;
}

void ZadanieSiedemnaste()
{
    auto *graph = new Graph::DirectedGraph<int>();
    graph ->addNode(0,1);
    graph ->addNode(0,2);
    graph ->addNode(0,3);
    graph ->addNode(0,4);
    graph ->addNode(0,6);
    graph ->addNode(0,7);
    graph ->addNode(1,2);
    graph ->addNode(1,0);
    graph ->addNode(1,3);
    graph ->addNode(1,6);
    graph ->addNode(2,0);
    graph ->addNode(2,1);
    graph ->addNode(2,4);
    graph ->addNode(3,0);
    graph ->addNode(3,1);
    graph ->addNode(3,4);
    graph ->addNode(3,5);
    graph ->addNode(3,6);
    graph ->addNode(4,0);
    graph ->addNode(4,2);
    graph ->addNode(4,2);
    graph ->addNode(5,3);
    graph ->addNode(5,7);
    graph ->addNode(6,0);
    graph ->addNode(6,1);
    graph ->addNode(6,3);
    graph ->addNode(6,7);
    graph ->addNode(7,0);
    graph ->addNode(7,1);
    graph ->addNode(7,5);
    graph ->addNode(7,6);
    graph -> printGraph();
    auto *listTwo = BFS(graph, 0);
    listTwo -> print();
    delete graph;
    delete listTwo;
}

int main()
{

    return 0;
}
