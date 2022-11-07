#include "BST.h"
#include <algorithm>

BST::BST(int k)
{
    // Complejidad: O(1)

    this->root = nullptr;
    this->k = k;
}

void BST::insert(int frec, Ip ip)
{
    // Complejidad: O(sqrt(n))
    // Complejidad amortizada: O(1)

    if (this->root == nullptr)
    {
        this->root = new Node(frec, ip);
    }
    else if (frec < this->root->frec)
    {
        this->insert(frec, ip, this->root, this->root->left, true);
    }
    else if (frec > this->root->frec)
    {
        this->insert(frec, ip, this->root, this->root->right, false);
    }
    else
    {
        this->root->ips.push_back(ip);
    }
}

void BST::insert(int frec, Ip ip, Node *previous, Node *current, bool side)
{
    // Complejidad: O(sqrt(n))
    // Complejidad amortizada: O(1)

    if (current == nullptr)
    {
        if (side)
        {
            previous->left = new Node(frec, ip);
        }
        else
        {
            previous->right = new Node(frec, ip);
        }
    }
    else if (frec < current->frec)
    {
        return this->insert(frec,ip,  current, current->left, true);
    }
    else if (frec > current->frec)
    {
        return this->insert(frec, ip, current, current->right, false);
    }
    else
    {
        current->ips.push_back(ip);
    }
}

vector<pair<int, Ip>> BST::kMasFrec()
{
    // Complejidad: min(n, max(sqrt(n), k))

    int cont = this->k;
    vector<pair<int, Ip>> ans;
    this->kMasFrec(this->root, cont, ans);
    return ans;
}

void BST::kMasFrec(Node *current, int &cont, vector<pair<int, Ip>> &ans)
{
    // Complejidad: min(n, max(sqrt(n), k))

    if (!cont || current == nullptr)
    {
        return;
    }

    this->kMasFrec(current->right, cont, ans);
    
    for (int i = 0; i < min(cont, (int)current->ips.size()); ++i)
    {
        ans.push_back({current->frec, current->ips[i]});
    }
    cont -= min(cont, (int)current->ips.size());

    this->kMasFrec(current->left, cont, ans);
}
