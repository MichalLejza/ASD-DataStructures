#include "/Users/michallejza/CLionProjects/Everything/DataStructures/Tree/Tree.cpp"

void testBSTTree()
{
    auto *tree = new Tree::BSTree<int>();
    tree ->insert(8,5,2,6,10,9,11);
    tree -> print();
}

auto main() -> int
{
    testBSTTree();
    return 0;
}
