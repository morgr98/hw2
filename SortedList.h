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

    class out_of_range{};


};
template<class T>
class SortedList<T>::const_iterator{
private:
    const SortedList* sortedList;
    int index;
    const_iterator(const SortedList* sortedList,int index);
    friend class SortedList;

public:
    SortedList::const_iterator& operator=(const SortedList::const_iterator& iterator);
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
SortedList<T>::const_iterator::const_iterator(const SortedList<T> *sortedList, int index) {
    this->sortedList=sortedList;
    this->index=index;
}

template<class T>
typename SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator=(const SortedList<T>::const_iterator &iterator) {
    this->index=iterator.index;
    this->sortedList=iterator.sortedList;
    return *this;
}

template<class T>
typename SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator++() {
    if(index==this->sortedList->size){
        throw  out_of_range();
    }
    ++index;
    return *this;
}

template<class T>
const T& SortedList<T> ::const_iterator::operator*() const {
     if(index==this->sortedList->size || index<0){
}      throw  out_of_range();
          }




#endif //EXAMDETAILS_CPP_SORTEDLIST_H
