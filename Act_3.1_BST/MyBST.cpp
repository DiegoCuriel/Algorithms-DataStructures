// Act 3.1 - Operaciones avanzadas en un BST
// Diego Curiel Castellanos - A01640372

#include <iostream> 
#include "MyBST.h"
#include <vector>
#include <queue>

using namespace std;

MyBST::MyBST() // O(1)
{
    this->root = nullptr;
    this->size = 0;
}

int MyBST::length() // O(1)
{
    return this->size;
}

bool MyBST::isEmpty() // O(1)
{
    return this->size == 0;
}

bool MyBST::search(int data) // O(log n)
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        Node *current;
        current = this->root;

        while (current != nullptr)
        {
            if (data == current->data)
            {
                return true;
            }
            else if(data < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
    }
    return false;
}

bool MyBST::insert(int data) // O(log n)
{
    if (isEmpty())
    {
        this->root = new Node(data);
        this->size++;
        return true;
    }
    else
    {
        Node *prev, *current;
        prev = this->root;
        current = this->root;

        while (current != nullptr)
        {
            prev = current;
            if (data == current->data)
            {
                return false;
            }
            else if(data < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
        
        if (data < prev->data)
        {
            prev->left = new Node(data);
            this->size++;
            return true;
        }
        else
        {
            prev->right = new Node(data);
            this->size++;
            return true;
        }
    }
    return true; // Insertó el valor
}

bool MyBST::remove(int data) // O(log n)
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        Node* prev;
        Node* current;
        prev = this->root;
        current = this->root;

        while (current != nullptr)
        {
            if (data != current->data)
            {
                prev = current;
                if (data < current->data)
                {
                    current = current->left;
                }
                else if (data > current->data)
                {
                    current = current->right;
                }
            }
            else
            {
                if (current->left == nullptr && current->right == nullptr)
                {
                    if (prev->left == current)
                    {
                        prev->left = nullptr;
                    }
                    else
                    {
                        prev->right = nullptr;
                    }
                    delete current;
                }
                else if (current->left == nullptr)
                {
                    if (prev->left == current)
                    {
                        prev->left = current->right;
                    }
                    else
                    {
                        prev->right = current->right;
                    }
                    delete current;
                }
                else if (current->right == nullptr)
                {
                    if (prev->left == current)
                    {
                        prev->left = current->left;
                    }
                    else
                    {
                        prev->right = current->left;
                    }
                    delete current;
                }
                else
                {
                    Node* temp = current->right;
                    while (temp->left != nullptr)
                    {
                        temp = temp->left;
                    }
                    current->data = temp->data;
                    if (temp->right != nullptr)
                    {
                        temp->data = temp->right->data;
                        temp->left = temp->right->left;
                        temp->right = temp->right->right;
                    }
                    else
                    {
                        delete temp;
                    }
                }
                this->size--;
                return true;
            }
        }
    }
    return false; //No encontró el valor
}

void MyBST::preorden(Node* current) // O(n)
{
    if (current != nullptr)
    {
        cout << current->data << ",";
        preorden(current->left);
        preorden(current->right);
    }
}

void MyBST::preorden() // O(1)
{
    preorden(this->root);
}

void MyBST::inorder(Node* current) // O(n)
{
    if (current != nullptr)
    {
        inorder(current->left);
        cout << current->data << ",";
        inorder(current->right);
    }
}

void MyBST::inorder() // O(1)
{
    inorder(this->root);
}

void MyBST::postorder(Node* current) // O(n)
{
    if (current != nullptr)
    {
        postorder(current->left);
        postorder(current->right);
        cout << current->data << ",";
    }
}

void MyBST::postorder() // O(1)
{
    postorder(this->root);
}

void MyBST::level() // O(n)
{
    queue<Node*> cola;
    cola.push(this->root);

    while (!cola.empty())
    {
        Node* temp = cola.front();
        cout << temp->data << ",";
        cola.pop();

        if (temp->left != nullptr)
        {
            cola.push(temp->left);
        }
        if (temp->right != nullptr)
        {
            cola.push(temp->right);
        }
    }
}

void MyBST::visit(int type) // O(1)
{
    if (type == 1)
    {
        preorden();
    }
    else if (type == 2)
    {
        inorder();
    }
    else if (type == 3)
    {
        postorder();
    }
    else if (type == 4)
    {
        level();
    }
}

int MyBST::height() // O(1)
{
    return height(this->root);
}

int MyBST::height(Node* current) // O(n)
{
    if (current == nullptr)
    {
        return 0;
    }
    else
    {
        int left = height(current->left);
        int right = height(current->right);

        if (left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
    }
}

void MyBST::ancestors(int data) // O(log n)
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        Node *current;
        current = this->root;
        vector<int> valores;

        while (current != nullptr)
        {
            if (data == current->data)
            {
                valores.push_back(current->data);
                for (int i = 0; i < valores.size(); i++)
                {
                    cout << valores[i] << ",";
                }
                return;
            }
            else if (data < current->data)
            {
                valores.push_back(current->data);
                current = current->left;
            }
            else
            {
                valores.push_back(current->data);
                current = current->right;
            }
        }
        return;
    }
}

int MyBST::whatLevelAmI(int data) // O(log n)
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {
        Node *current;
        current = this->root;
        int level = 0;

        while (current != nullptr)
        {
            if (data == current->data)
            {
                return level;
            }
            else if (data < current->data)
            {
                level++;
                current = current->left;
            }
            else
            {
                level++;
                current = current->right;
            }
        }
        return -1;
    }
}