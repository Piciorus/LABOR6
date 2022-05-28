#pragma once
#include <vector>
#include <string>
using namespace std;

template <class E>
class CrudRepository{

public:
    virtual void addToEnd(E elem) = 0;
    virtual bool remove(E elem) = 0;
    virtual int findId() = 0;
    virtual vector<E> &getStorage() = 0;
    virtual void setStorage(const vector<E> &elems) = 0;
    virtual ~CrudRepository(){};
};