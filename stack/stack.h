#ifndef _STACK_H_
#define _STACK_H_

#include <cstddef>

template<typename Elem>
class Stack
{
public:
    Stack(){}
    ~Stack(){}

    void clear() {}
    virtual bool push(const Elem& it) = 0;
    virtual bool pop(Elem& it) = 0;
    virtual int length() const = 0;
};


// Array-based Stack implementation
template<typename Elem>
class AStack : public Stack<Elem>
{
private:
    Elem* m_pElem;
    int m_top;
    int m_size;

public:

#define ASTATCK_DEFAULT_SIZE 100

    AStack(int size = ASTATCK_DEFAULT_SIZE):
        m_size(size),
        m_top(0),
        m_pElem(new Elem[size])
    {

    }

    ~AStack()
    {
        if (NULL != m_pElem)
        {
            delete[] m_pElem;
            m_pElem = NULL;
        }
    }

    bool push(const Elem& it)
    {
        if (m_top >= m_size)
            return false;

        m_pElem[m_top++] = it;
        return true;
    }

    bool pop(Elem& it)
    {
        if (m_top == 0)
            return false;

        it = m_pElem[--m_top];
        return true;
    }
    
    int length() const {return m_top;}

};


#endif