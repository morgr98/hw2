//
// Created by morgr on 05/06/2021.
//

#ifndef EXAMDETAILS_CPP_SORTEDLIST_H
#define EXAMDETAILS_CPP_SORTEDLIST_H


class SortedList {
private:

public:
    class const_iterator;

};

class SortedList::const_iterator{
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


#endif //EXAMDETAILS_CPP_SORTEDLIST_H
