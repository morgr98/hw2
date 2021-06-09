
#ifndef EXAMDETAILS_CPP_SORTEDLIST_H
#define EXAMDETAILS_CPP_SORTEDLIST_H

#include <ostream>
#include <string>

template<class T>
class Node {
public:
    T data;
    Node<T>* next;
    explicit Node(T data);
    ~Node()=default;
    bool operator==(const Node<T> & node);
};

template<class T>
Node<T>::Node(T data){
    this->data= data;
    this->next= nullptr;
}


template<class T>
bool Node<T>::operator==(const Node<T> &node) {
    if(this->data==node.data && this->next==node.next)
    {
        return true;
    }
    return false;
}


template<class T>
class SortedList {
private:
    Node<T> *head, *tail;
    int size;

public:
    SortedList();
    SortedList(const SortedList& sortedList);
    ~SortedList();


    class const_iterator;
    const_iterator begin() const;
    const_iterator end() const;

    void insert(T data);
    void remove(SortedList<T>::const_iterator it);
    int length() const;

    class out_of_range{};
};
template<class T>
class SortedList<T>::const_iterator{
private:
    const Node<T>* node ;
    explicit const_iterator(const Node<T>* node);
    friend class SortedList;

public:
    const_iterator& operator=(const SortedList::const_iterator& iterator);
    const_iterator& operator++();
    bool operator==(const SortedList::const_iterator& iterator);
    const T& operator*()const;
};

template<class T>
SortedList<T>::SortedList() {
    size=0;
    head= nullptr;
    tail= nullptr;
}

template<class T>
SortedList<T>::SortedList(const SortedList<T> & sortedList) {
    size=sortedList.size;
    for (SortedList<T>::const_iterator temp_it = begin(); !(temp_it == end()); ++temp_it) {
    this->insert(temp_it.node->data);
    }

}

template<class T>
SortedList<T>::~SortedList<T>() {
    Node<T>* temp= head;
    Node<T>* node=temp->next;
    while(!(temp == nullptr))
    {
        delete temp;
        temp=node;
        node=node->next;
    }
    delete temp;
}



template<class T>
void SortedList<T>::insert(T data) {
    Node<T>* new_node=new Node<T>(data);

    if(size==0)
    {
        head=new_node;
        size++;
        head->next= nullptr;
        tail=head;
        return;
    }
    Node<T> *tmp_node=head;
    while (!(tmp_node->next== nullptr) && tmp_node->next->data<data)
    {
        tmp_node=tmp_node->next;
    }
    if(tmp_node->next== nullptr)
    {
        size++;
        tail->next=new_node;
        new_node->next= nullptr;
        tail=tail->next;
        return;
    }
    size++;
    new_node->next=tmp_node->next;
    tmp_node->next=new_node;
}

template<class T>
void SortedList<T>::remove(SortedList<T>::const_iterator it) {

    for (SortedList<T>::const_iterator tmp_it= this->begin();!(tmp_it==this->end()); ++tmp_it)
    {
        if (it.node==tmp_it.node->next)
        {
            Node<T>* node=tmp_it.node->next->next;
            tmp_it.node=node;
            delete it.node->next;
            return;
        }
    }
}

/*
template<class T>
void SortedList<T>::insert(T new_data) {
    Node<T>* node_to_compare = head;
    Node<T>* new_node = new Node<T>();
    new_node->data = new_data;
    if (node_to_compare == nullptr)
    {
        size++;
        head = new_node;
        head->next = nullptr;
        tail = head;
        return;
    }
    while (node_to_compare!=nullptr && node_to_compare->data>new_data)
    {
        node_to_compare=(head->next);
    }
    if (node_to_compare == nullptr)
    {
        size++;
        new_node->next = nullptr;
        tail = new_node;
        return;
    }
    else
    {
        size++;
        new_node->next = node_to_compare->next;
        node_to_compare->next = new_node;
        return;
    }

}
*/

template<class T>
int SortedList<T>::length() const {
    return this->size;
}


template<class T>
typename SortedList<T>::const_iterator SortedList<T>::begin() const {
    return  const_iterator(this->head);
}


template<class T>
typename SortedList<T>::const_iterator SortedList<T>::end() const {
    return const_iterator(this->tail->next);
}
/*
template<class T>
void SortedList<T>::remove(SortedList::const_iterator it) {
    if (it.node == nullptr)
        return;
    for (SortedList<T>::const_iterator temp_it = begin(); !(temp_it == end()); ++temp_it) {
        if (it.node == temp_it.node->next) {
            Node<T>* temp_node = temp_it.node->next;
            temp_it.node->next = temp_it.node->next->next;
            delete temp_node;
            size--;
            return;
        }
    }

}
*/




template<class T>
SortedList<T>::const_iterator::const_iterator(const Node<T>* node1) {
    this->node=node1;
}

template<class T>
typename SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator=(const SortedList<T>::const_iterator &iterator) {
    this->node=iterator.node;
    return *this;
}

template<class T>
typename SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator++() {
    if(this->node->next== nullptr){
        throw  out_of_range();
    }
    this->node=this->node->next;
    return *this;
}

template<class T>
const T& SortedList<T> ::const_iterator::operator*() const {
    return this->node->data;
}

template<class T>
bool SortedList<T>::const_iterator::operator==(const SortedList<T>::const_iterator& iterator) {
    return iterator.node==this->node;
}



#endif //EXAMDETAILS_CPP_SORTEDLIST_H
