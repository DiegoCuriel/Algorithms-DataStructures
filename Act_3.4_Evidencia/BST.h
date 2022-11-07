#ifndef BST_H
#define BST_H

#include "Ip.h"
#include <vector>

using namespace std;

struct Node
{
    int frec;
    vector<Ip> ips;
    Node *left, *right;
    Node(int frec, Ip ip)
    {
        this->frec = frec;
        this->ips = {ip};
        this->left = this->right = nullptr;
    }
};

class BST
{
    public:
        BST(int k);
        void insert(int frec, Ip ip);
        vector<pair<int, Ip>> kMasFrec();
    private:
        Node* root;
        int k;
        void insert(int frec, Ip ip, Node *previous, Node *current, bool side);
        void kMasFrec(Node *current, int &cont, vector<pair<int, Ip>> &ans);
};

#endif // BST_H
