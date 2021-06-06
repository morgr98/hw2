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
    T* data;
    Node* next;

public:
    Node();
    Node(T data);
    Node(const Node&);
    ~Node();
};

template<class T>
Node<T>::Node() : data(NULL), next(NULL){}

template<class T>
//not sure about the new here
Node<T>::Node(T data) :data(new T), next(NULL){
    data =
}

template<class T>
Node<T>::Node(const Node& node) {
    data = new T(node.data);
}


#endif //HW2_NODE_H
