//
// Created by morgr on 05/06/2021.
//

#ifndef EXAMDETAILS_CPP_SORTEDLIST_H
#define EXAMDETAILS_CPP_SORTEDLIST_H

#include <ostream>
#include "Node.h"

typedef int T;

template<class T>
class SortedList {
private:
    Node *head, *tail;
    int size;

public:
    SortedList();
    SortedList(const SortedList&);
    ~SortedList();


    class const_iterator;
    const_iterator begin() const;
    const_iterator end() const;

    bool insert(const T& element);
    bool remove(const_iterator it);
    int length() const;


};
template<class T>
class SortedList<T>::const_iterator{
private:
    const SortedList* sortedList;
    int index;
    const_iterator(const SortedList* sortedList,int index);
    friend class SortedList;

public:
    SortedList::const_iterator& operator=(SortedList::const_iterator& iterator);
    SortedList::const_iterator& operator++();
    bool operator==(const SortedList::const_iterator iterator) const;
    const int& operator*()const;
};

template<class T>
SortedList<T>::SortedList() : head(nullptr), tail(nullptr), size(0) {}

template<class T>
SortedList<T>::~SortedList() {
    while(!head)
    {
        Node tmp = nodeGetNext(head);
        //or do we use delete here?
        nodeDestroy(head);
        head = tmp;
    }
}

template<class T>
SortedList<T>::SortedList(const SortedList& list):head(NULL), tail(NULL), size(list.length())
{
    //need to implement
}

#endif //EXAMDETAILS_CPP_SORTEDLIST_H
