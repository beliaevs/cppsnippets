#pragma once
#include <memory>
//circular list
template<typename T>
class List
{
public: 
explicit List(T el) {}
List() = default;
List(const List& other)
{
    auto* head = other.d_head;
    if(!head)
        return;
    
    auto* next = head->d_next;
    while(next != other.d_head)
    {
        push_back(next->d_data);
    }
    push_front(head->d_data);
}

List& operator = (const List& rhs)
{
    List a(rhs);
    swap(a);
}

void swap(List& other)
{
    std::swap(d_head, other.d_head);
}

~List()
{
    if(!d_head)
        return;

    ListNode* cur = d_head->next;
    while(cur != d_head)
    {
        ListNode* next = cur->next;
        delete cur;
        cur = next;
    }
    delete d_head;
}

void push_back(T el)
{
    auto node = std::make_unique<ListNode>(el);
    if(!d_head)
    {
        d_head = node.release();
        return;
    }
    auto* nodeNext = d_head;
    auto* nodePrev = d_head->prev;
    node->next = nodeNext;
    nodeNext->prev = node.get();
    node->prev = nodePrev;
    nodePrev->next = node.release();
}

void push_front(T el)
{
    auto node = std::make_unique<ListNode>(el);
    if(!d_head)
    {
        d_head = node.release();
        return;
    }
    auto* nodePrev = d_head;
    auto* nodeNext = d_head->next;
    node->next = nodeNext;
    nodeNext->prev = node.get();
    node->prev = nodePrev;
    nodePrev->next = node.get();
    d_head = node.release();
}

class ListNode
{
    public:
    explicit ListNode(T data): d_data(std::move(data)) {}
    ListNode(const ListNode&) = delete;
    ~ListNode() = default;
    T d_data;
    ListNode* next = this;
    ListNode* prev = this;
};

private:

ListNode* d_head = nullptr;
};