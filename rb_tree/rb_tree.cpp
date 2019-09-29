#include "rb_tree.h"

template<typename T_Key, typename T_Value>
void RBTree<T_Key, T_Value>::Insert(T_Key key, T_Value value)
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

template<typename T_Key, typename T_Value>
T_Value RBTree<T_Key, T_Value>::Find(T_Key key)
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