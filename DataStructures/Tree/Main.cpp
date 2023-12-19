#include "Tree.cpp"

void testBSTTree()
{
    auto *tree = new Tree::BSTree<int>();
    tree -> insert(12,2,6,14,13,15,1);
    tree -> print();
}

auto main() -> int
{
    testBSTTree();
    return 0;
}
