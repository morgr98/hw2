//
// Created by Gilad on 06/06/2021.
//

#ifndef HW2_NODE_H
#define HW2_NODE_H

typedef int T;
template<class T>
class Node
{
private:
    T data;
    Node<T>* next;

public:
    Node();
    Node(T data);
    Node(const Node&);
    ~Node();
    Node<T>* getNext() const;
    const T& getData() const;
    T& getData();


};

template<class T>
Node<T>::Node() : data(NULL), next(NULL){}

template<class T>
//not sure about the new here
Node<T>::Node(T new_data) : next(NULL){
    data = new T;
    data = new_data;
}

//same thing - new
template<class T>
Node<T>::Node(const Node& node) {
    data = new T;
    data = node.data;
}

template<class T>
Node<T>::~Node(){
    delete data;
    next = NULL;
}

template<class T>
Node<T>* Node<T>::getNext() const {
    return next;
}

template<class T>
T& Node<T>::getData() {
    return data;
}

template<class T>
const T& Node<T>::getData() const{
    return data;
}

#endif //HW2_NODE_H
