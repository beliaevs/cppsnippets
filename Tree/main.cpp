#include<iostream>

#include "Tree.h"

using TreeInt = Tree<int>;

int main()
{
  TreeInt root{0};

  auto* child1 = new TreeInt{1};
  auto* child2 = new TreeInt{2};
  child1->setParent(root);
  child2->setParent(root);
  auto* grandchild13 = new TreeInt{3};
  grandchild13->setParent(*child1);
  printTree(std::cout, root);
}