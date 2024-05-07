#pragma once

#include <iostream>
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include <cstdint>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List() : m_head(new ListNode(static_cast<int>(0))), m_tail(new ListNode(0, m_head)), m_size(0) {}

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    //Протестировать это
    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    //Протестировать это
    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    //Протестировать это
    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    //Протестировать это
    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }


    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};

TEST_CASE("test class List", "[List]") {
    SECTION("PushBack") {
        List test_list;
        test_list.PushBack(1);
        CHECK(test_list.Size() == 1);
        CHECK(test_list.Empty() == false);
    }

    SECTION("Double PushBack") {
        List test_list;
        test_list.PushBack(1);
        test_list.PushBack(1);
        CHECK(test_list.Size() == 2);
        CHECK(test_list.Empty() == false);
    }

    SECTION("PushFront") {
        List test_list;
        test_list.PushFront(1);
        CHECK(test_list.Size() == 1);
        CHECK(test_list.Empty() == false);
    }

    SECTION("PushFront") {
        List test_list;
        test_list.PushFront(1);
        test_list.PushFront(1);
        CHECK(test_list.Size() == 2);
        CHECK(test_list.Empty() == false);
    }
    
    SECTION("PopFront") {
        List test_list;
        CHECK_THROWS(test_list.PopFront());
    }

    SECTION("PopBack") {
        List test_list;
        CHECK_THROWS(test_list.PopBack());
    }
}

int main() {
    return Catch::Session().run();
}