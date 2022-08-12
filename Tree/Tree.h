#pragma once

#include<vector>

template<typename T>
class Tree
{
public:
  Tree() = default;
  ~Tree()
  {
    for (auto* t : d_children)
      delete t;
  }
  explicit Tree(const T& i_data) : d_data(i_data) {}

  void setParent(Tree& i_parent)
  {
    if (d_parent == &i_parent || isChildOf(i_parent))
      return;

    if (d_parent)
    {
      d_parent->removeChild(this);
    }

    d_parent = nullptr;
    if (i_parent.addChild(this))
    {
      d_parent = &i_parent;
    }
  }

  bool isChildOf(Tree& i_parent) const
  {
    return std::find(i_parent.d_children.cbegin(), i_parent.d_children.cend(), this) != i_parent.d_children.cend();
  }

  void setData(const T i_data)
  {
    d_data = i_data;
  }

  T getData() const
  {
    return d_data;
  }

  const std::vector<Tree*>& children() const
  {
    return d_children;
  }

private:
  bool addChild(Tree* i_child)
  {
    if (!i_child || i_child->isChildOf(*this))
      return false;

    d_children.push_back(i_child);
    return true;
  }

  bool removeChild(Tree* i_child)
  {
    auto it = std::remove(d_children.begin(), d_children.end(), i_child);
    if (it == d_children.end())
      return false;

    d_children.erase(it);
    return true;
  }

  T d_data;
  Tree* d_parent = nullptr;
  std::vector<Tree*> d_children;
};

template<typename T>
void printTree(std::ostream& os, const Tree<T>& i_tree)
{
  os << i_tree.getData() << "\n";
  for (auto* t : i_tree.children())
  {
    printTree(os, *t);
  }
}