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
    Node<T> *head, *tail;
    int size;

public:
    SortedList();
    SortedList(const SortedList&);
    ~SortedList();


    class const_iterator;
    const_iterator begin() const;
    const_iterator end() const;

    bool insert(T& element);
    bool remove(const_iterator it);
    int length() const;

    class out_of_range{};


};
template<class T>
class SortedList<T>::const_iterator{
private:
    const SortedList* sortedList;
    const_iterator(const SortedList* sortedList);
    friend class SortedList;

public:
    SortedList::const_iterator& operator=(const SortedList::const_iterator& iterator);
    SortedList::const_iterator& operator++();
    bool operator==(const SortedList::const_iterator iterator) const;
    const T& operator*()const;
};

template<class T>
SortedList<T>::SortedList() : head(nullptr), tail(nullptr), size(0) {}

template<class T>
SortedList<T>::~SortedList() {
    while(!head)
    {
        Node<T>* temp = getNext(head);
        delete *head;
        head = temp;
    }
}

template<class T>
SortedList<T>::SortedList(const SortedList& list):head(NULL), tail(NULL), size(list.length())
{
    Node<T>* node_to_copy = list.head;
    while(!node_to_copy)
    {
        insert(node_to_copy.getData());
        node_to_copy = *node_to_copy.getNext();
    }

}

template<class T>
bool SortedList<T>::remove(const_iterator it) {
    
}

template<class T>
typename SortedList<T>::const_iterator SortedList<T>::begin() const {
    return  const_iterator(this,0);
}


template<class T>
typename SortedList<T>::const_iterator SortedList<T>::end() const {
    return const_iterator(this,size);
}

template<class T>
SortedList<T>::const_iterator::const_iterator(const SortedList<T> *sortedList) {
    this->sortedList=sortedList;
}

template<class T>
typename SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator=(const SortedList<T>::const_iterator &iterator) {
    this->sortedList=iterator.sortedList;
    return *this;
}

template<class T>
typename SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator++() {
    if(this->sortedList->head->getNext()==NULL){
        throw  out_of_range();
    }
    this->sortedList=this->sortedList->head->getNext();
    return *this;
}

template<class T>
const T& SortedList<T> ::const_iterator::operator*() const {
    return this->sortedList->head->getData();
}

template<class T>
bool SortedList<T>::const_iterator::operator==(const SortedList<T>::const_iterator iterator) const {
    return iterator.sortedList==this->sortedList;
}



#endif //EXAMDETAILS_CPP_SORTEDLIST_H
