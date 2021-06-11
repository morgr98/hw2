
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
    Node();
    void setData(T data);
    ~Node()=default;
    bool operator==(const Node<T> & node);
};

template<class T>
Node<T>::Node( T data1){
    data= data1;
    this->next= nullptr;
}

template<class T>
Node<T>::Node() {
    this->data= NULL;
    this->next= nullptr;
}

template<class T>
void Node<T>::setData(T data) {
    this->data=data;
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
    int index;
    explicit const_iterator(const Node<T>* node, int index);
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
    size=0;
    for (SortedList<T>::const_iterator temp_it = sortedList.begin(); !(temp_it == sortedList.end()); ++temp_it) {
    this->insert(temp_it.node->data);
    }
}

template<class T>
SortedList<T>::~SortedList<T>() {
    Node<T>* temp= head;
    Node<T>* node=temp->next;
    while(!(node == nullptr))
    {
        delete temp;
        temp=node;
        node=node->next;
    }
    delete temp;
}



template<class T>
void SortedList<T>::insert(T data) {
    Node<T>* new_node= new Node<T>(data);
  //  new_node->setData(data);
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

    if(it.node == this->begin().node)
    {
        Node<T>* node=it.node->next;
        head=node;
        delete it.node;
        size--;
        return;
    }
    Node<T>* tmp_it=head;
    for (int i=0;i<size;i++)
    {
        if (it.node==tmp_it->next)
        {
            Node<T>* node=tmp_it->next->next;
            delete tmp_it->next;
            tmp_it->next=node;
            delete it.node;
            if(i+2 == size)
            {
                tail=tmp_it;
            }
            size--;
            return;
        }
        tmp_it=tmp_it->next;
    }
}


template<class T>
int SortedList<T>::length() const {
    return this->size;
}


template<class T>
typename SortedList<T>::const_iterator SortedList<T>::begin() const {
    return  const_iterator(this->head,0);
}


template<class T>
typename SortedList<T>::const_iterator SortedList<T>::end() const {
    return const_iterator(this->tail->next,size);
}


template<class T>
SortedList<T>::const_iterator::const_iterator(const Node<T>* node1, int index) {
    this->node=node1;
    this->index=index;
}

template<class T>
typename SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator=(const SortedList<T>::const_iterator &iterator) {
    this->node=iterator.node;
    this->index=iterator.index;
    return *this;
}

template<class T>
typename SortedList<T>::const_iterator& SortedList<T>::const_iterator::operator++() {
   // if(this->node->next== nullptr){
   //     throw  out_of_range();
  //  }
    this->node=this->node->next;
    this->index++;
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
