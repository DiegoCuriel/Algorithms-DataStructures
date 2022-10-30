// Act 3.1 - Operaciones avanzadas en un BST
// Diego Curiel Castellanos - A01640372

#ifndef MYBST_H
#define MYBST_H

struct Node
{
    int data;
    Node *left, *right;
    
    Node(int data) //constructor
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class MyBST
{
    private:
        Node* root;
        int size;
        bool search(int data, Node* current);
        void preorden(Node* current);
        void inorder(Node* current);
        void postorder(Node* current);
        int height(Node* current);
    
    public:
        MyBST();
        int length();
        bool isEmpty();
        bool search(int data); //True si lo encontró
        bool insert(int data); //True si lo insertó
        bool remove(int data); //Falta, True si lo pudo borrar
        void preorden();
        void inorder();
        void postorder();
        void level();
        void visit(int type); // 1->preorder, 2->inorder, 3->postorder, 4->level
        int height(); //Falta, regresa la altura del BST
        void ancestors(int data); //no imprime nada si no lo encuentra
        int whatLevelAmI(int data); //regresa -1 si el dato no existe
};

#endif // MYBST_H