#pragma once
#include <exception>

#define DEFAULT_HEAP_CAP   100

template<typename T>
class MinHeap
{
private:
    T* m_data;
    int m_size;
    int m_capacity;

public:
    MinHeap(int cap = DEFAULT_HEAP_CAP) :
        m_size(0), m_capacity(cap)
    {
        m_data = new T[cap];
    }

    ~MinHeap()
    {
        delete[] m_data;
    }

public:
    void push(T elem)
    {
        if (m_size == m_capacity)
        {
            __resize();
        }
        
        m_data[m_size++] = elem;
        __upAdjust();
    }

    T pop()
    {
        if (m_size == 0)
        {
            throw std::exception();
        }

        T t = m_data[0];
        m_data[0] = m_data[m_size-1];
        m_size--;
        __downAdjust();

        return t;
    }

    int size()
    {
        return m_size;
    }

    int capacity()
    {
        return m_capacity;
    }

private:
    void __resize()
    {
        T* temp = new T[m_capacity*2];
        for (int i = 0; i < m_size; i++)
        {
            temp[i] = m_data[i];
        }
        delete[] m_data;

        m_capacity = m_capacity*2;
        m_data = temp;
    }

    void __upAdjust()
    {
        int cur = m_size - 1;
        if (cur == 0)
            return;

        int parent = 0;
        while (cur > 0)
        {
            parent = (cur - 1) / 2;
            
            if (m_data[cur] >= m_data[parent])
                break;
            
            T t = m_data[parent];
            m_data[parent] = m_data[cur];
            m_data[cur] = t;
            cur = parent;
        }    

#ifdef DEBUG
        printf("__upAdjust: ");
        __printData();
#endif
    }

    void __downAdjust()
    {
        int lchild = 0;
        int rchild = 0;
        int little = 0;
        int cur = 0;

        while (true)
        {
            lchild = cur * 2 + 1;
            rchild = cur * 2 + 2;

            if (lchild >= m_size)
                break;
            
            if (rchild >= m_size)
            {
                little = lchild;
            }
            else
            {
                little = m_data[lchild] <= m_data[rchild] ? lchild : rchild;
            }

            if (m_data[cur] <= m_data[little])
                break;

            T t = m_data[cur];
            m_data[cur] = m_data[little];
            m_data[little] = t;
            
            cur = little;
        }

#ifdef DEBUG
        printf("__downAdjust: ");
        __printData();
#endif
    }

#ifdef DEBUG

    void __printData()
    {
        for (int i = 0; i < m_size; i++)
        {
            printf("%4d ", m_data[i]);
        }
        printf("\n");
    }

#endif
};

template<typename T>
class MaxHeap
{
private:
    T* m_data;
    int m_size;
    int m_capacity;

public:
    MaxHeap(int cap = DEFAULT_HEAP_CAP) :
        m_size(0), m_capacity(cap)
    {
        m_data = new T[cap];
    }

    ~MaxHeap()
    {
        delete[] m_data;
    }

public:
    void push(T elem)
    {
        if (m_size == m_capacity)
        {
            __resize();
        }
        
        m_data[m_size++] = elem;
        __upAdjust();
    }

    T pop()
    {
        if (m_size == 0)
        {
            throw std::exception();
        }

        T t = m_data[0];
        m_data[0] = m_data[m_size-1];
        m_size--;
        __downAdjust();

        return t;
    }

    int size()
    {
        return m_size;
    }

    int capacity()
    {
        return m_capacity;
    }

private:
    void __resize()
    {
        T* temp = new T[m_capacity*2];
        for (int i = 0; i < m_size; i++)
        {
            temp[i] = m_data[i];
        }
        delete[] m_data;

        m_capacity = m_capacity*2;
        m_data = temp;
    }

    void __upAdjust()
    {
        int cur = m_size - 1;
        if (cur == 0)
            return;

        int parent = 0;
        while (cur > 0)
        {
            parent = (cur - 1) / 2;
            
            if (m_data[cur] <= m_data[parent])
                break;
            
            T t = m_data[parent];
            m_data[parent] = m_data[cur];
            m_data[cur] = t;
            cur = parent;
        }    

#ifdef DEBUG
        printf("__upAdjust: ");
        __printData();
#endif
    }

    void __downAdjust()
    {
        int lchild = 0;
        int rchild = 0;
        int little = 0;
        int cur = 0;

        while (true)
        {
            lchild = cur * 2 + 1;
            rchild = cur * 2 + 2;

            if (lchild >= m_size)
                break;
            
            if (rchild >= m_size)
            {
                little = lchild;
            }
            else
            {
                little = m_data[lchild] >= m_data[rchild] ? lchild : rchild;
            }

            if (m_data[cur] >= m_data[little])
                break;

            T t = m_data[cur];
            m_data[cur] = m_data[little];
            m_data[little] = t;
            
            cur = little;
        }

#ifdef DEBUG
        printf("__downAdjust: ");
        __printData();
#endif
    }

#ifdef DEBUG

    void __printData()
    {
        for (int i = 0; i < m_size; i++)
        {
            printf("%4d ", m_data[i]);
        }
        printf("\n");
    }

#endif
};
