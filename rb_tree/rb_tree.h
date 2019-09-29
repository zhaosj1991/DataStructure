#pragma once
     
#define BLACK   0
#define RED     1

template<typename T_Key, typename T_Value>
class RBTree
{
public:
    RBTree(T_Key _key, T_Value _value)
    {
        root_node = new Node(_key, _value);
    }
    ~RBTree() {};

    class Node
    {
    public:
        T_Key key;
        T_Value value;
        bool color;

        Node* parent;
        Node* left_child;
        Node* right_child;
        /* data */
    public:
        Node(T_Key _key, T_Value _value)
        {
            key = _key;
            value = _value;
            color = BLACK;

            parent = nullptr;
            left_child = nullptr;
            right_child = nullptr;
        }
        ~Node() {};
    };

public:
    T_Value Find(T_Key key)
    {
        Node* temp_node = root_node;
        while (temp_node != nullptr)
        {
            if (key == temp_node->key)
                return temp_node->value;
            else if (key < temp_node->key)
                temp_node = temp_node->left_child;
            else
                temp_node = temp_node->right_child;
        }
    }

    void Insert(T_Key key, T_Value value)
    {
        Node* temp_node = root_node;
        while (temp_node != nullptr)
        {
            if (key < temp_node->key)
            {
                if (temp_node->left_child == nullptr)
                {
                    temp_node->left_child = new Node(key, value);
                    break;
                }
                else
                {
                    temp_node = temp_node->left_child;
                } 
            }
            else
            {
                if (temp_node->right_child == nullptr)
                {
                    temp_node->right_child = new Node(key, value);
                    break;
                }
                else
                {
                    temp_node = temp_node->right_child;
                }
            }
        }
    }

private:
    Node *root_node;
};
