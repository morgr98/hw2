//
// Created by morgr on 05/06/2021.
//

#ifndef EXAMDETAILS_CPP_SORTEDLIST_H
#define EXAMDETAILS_CPP_SORTEDLIST_H

#include <ostream>

typedef int T;

template<class T>
struct Node {
private:
    T data;
    Node<T> *next;
};

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

    void insert(T& data);
    void remove(const_iterator it);
    int length() const;

    class out_of_range{};
};
template<class T>
class SortedList<T>::const_iterator{
private:
    const Node<T> node ;
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
        Node<T>* temp = head->next;
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
        insert(node_to_copy->data);
        node_to_copy = *node_to_copy->next();
    }

}

template<class T>
void SortedList<T>::insert(T& new_data) {
    Node<T> node_to_compare = *head;
    Node<T> new_node = new Node<T>;
    new_node->data = new_data;
    if (node_to_compare == NULL)
    {
        head = new_node;
        head->next = NULL;
        tail = head;
        return;
    }
    while (node_to_compare!= NULL && node_to_compare->data<new_data)
    {
        node_to_compare=*(head->next);
    }
    if (node_to_compare == NULL)
    {
        new_node->next = NULL;
        tail = new_node;
        return;
    }
    else
    {
        new_node->next = node_to_compare->next;
        node_to_compare->next = new_node;
        return;
    }



}

template<class T>
void SortedList<T>::remove(const_iterator it) {
    if (it==NULL)
        return;
    for(SortedList<T>::const_iterator temp_it = begin(); temp_it!=end(); temp_it++)
    {
        if(it==temp_it->next)
        {
            Node<T> temp_node = temp_it->next;
            temp_it->next = temp_it->next->next;
            delete temp_node;
            return;
        }
    }
}

template<class T>
typename SortedList<T>::const_iterator SortedList<T>::begin() const {
    return  const_iterator(this->head);
}


template<class T>
typename SortedList<T>::const_iterator SortedList<T>::end() const {
    return const_iterator(this->tail);
}

template<class T>
SortedList<T>::const_iterator::const_iterator(const SortedList<T> *sortedList) {
    this->sortedList=sortedList;
}

template<class T>
typename SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator=(const SortedList<T>::const_iterator &iterator) {
    this->node=iterator.node;
    return *this;
}

template<class T>
typename SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator++() {
    if(this->node.getNext()== NULL){
        throw  out_of_range();
    }
    this->node=this->node.getNext();
    return *this;
}

template<class T>
const T& SortedList<T> ::const_iterator::operator*() const {
    return this->node.getData();
}

template<class T>
bool SortedList<T>::const_iterator::operator==(const SortedList<T>::const_iterator iterator) const {
    return iterator.node==this->node;
}



#endif //EXAMDETAILS_CPP_SORTEDLIST_H
