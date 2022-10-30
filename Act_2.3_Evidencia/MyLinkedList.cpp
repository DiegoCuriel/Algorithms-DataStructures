#include "MyLinkedList.h"

MyLinkedList::MyLinkedList() 
{
    /*
    Descripción: Constructor.

    Parámetros: Ninguno.

    Valor de retorno: Ninguno.

    Precondición: Ninguna.

    postcondición: Se crea el objeto.

    Complejidad: O(1)
    */

    this->size = 0;
    this->head = this->tail = nullptr;
}

MyLinkedList::~MyLinkedList()
{
    /*
    Descripción: Destructor.

    Parámetros: Ninguno.

    Valor de retorno: Ninguno.

    Precondición: Ninguna.

    postcondición: Se destruye el objeto.

    Complejidad: O(n) | n = longitud de la lista
    */

    while (!this->isEmpty())
    {
        this->removeFirst();
    }
}

int MyLinkedList::length()
{
    /*
    Descripción: Función que retorna la cantidad de elementos en la lista.

    Parámetros: Ninguno.

    Valor de retorno: Longitud de la lista.

    Precondición: Ninguna.

    postcondición: Ninguna.

    Complejidad: O(1)
    */

    return this->size;
}

bool MyLinkedList::isEmpty()
{
    /*
    Descripción: Función que indica si la lista está o no vacía.

    Parámetros: Ninguno.

    Valor de retorno: Boleano que indica si la lista está vacía.

    Precondición: Ninguna.

    postcondición: Ninguna.

    Complejidad: O(1)
    */

    return this->size == 0;
}

Registro MyLinkedList::first()
{
    /*
    Descripción: Función que retorna el primer valor de la lista.

    Parámetros: Ninguno.

    Valor de retorno: El primer valor en la lista.

    Precondición: size > 0

    postcondición: Ninguna.

    Complejidad: O(1)
    */

    return this->head->data;
}

Registro MyLinkedList::last()
{
    /*
    Descripción: Función que retorna el último valor de la lista.

    Parámetros: Ninguno.

    Valor de retorno: El último valor en la lista.

    Precondición: size > 0

    postcondición: Ninguna.

    Complejidad: O(1)
    */

    return this->tail->data;
}

Registro MyLinkedList::getAt(int pos)
{
    /*
    Descripción: Función que retorna el valor en cierta posición de la lista.

    Parámetros: La posición.

    Valor de retorno: El valor en la posición pos de la lista.

    Precondición: 0 <= pos < size

    postcondición: Ninguna.

    Complejidad: O(n) | n = pos + 1
    */

    Node *tmp = this->head;
    for (int i = 0; i < pos; ++i)
    {
        tmp = tmp->next;
    }
    return tmp->data;
}

void MyLinkedList::setAt(Registro data, int pos)
{
    /*
    Descripción: Función que cambia el valor de un dato en una posición de la
    lista.

    Parámetros: El dato y la posición.

    Valor de retorno: Ninguno.

    Precondición: 0 <= pos < size

    postcondición: Ninguna.

    Complejidad: O(n) | n = pos + 1
    */

    Node *tmp = this->head;
    for (int i = 0; i < pos; ++i)
    {
        tmp = tmp->next;
    }
    tmp->data = data;
}

void MyLinkedList::insertFirst(Registro data)
{
    /*
    Descripción: Función que inserta un dato al inicio de la lista.

    Parámetros: El dato a insertar.

    Valor de retorno: Ninguno.

    Precondición: Ninguna.

    postcondición: El dato está insertado.

    Complejidad: O(1)
    */

    this->head = new Node(data, this->head);
    if (this->isEmpty())
    {
        this->tail = head;
    }
    ++this->size;
}

void MyLinkedList::insertLast(Registro data)
{
    /*
    Descripción: Función que inserta un dato al final de la lista.

    Parámetros: El dato a insertar.

    Valor de retorno: Ninguno.

    Precondición: Ninguna.

    postcondición: El dato está insertado.

    Complejidad: O(1)
    */

    if (this->isEmpty())
    {
        this->insertFirst(data);
    }
    else
    {
        this->tail->next = new Node(data);
        this->tail = this->tail->next;
        this->size++;
    }
}

void MyLinkedList::insertAt(Registro data, int pos) // pos : [0, size] Exc invalid_argument
{
    /*
    Descripción: Función que inserta un dato en una posición del arreglo.

    Parámetros: El dato a insertar y la posición.

    Valor de retorno: Ninguno.

    Precondición: pos está en rango [0, size].

    postcondición: El dato está insertado.

    Complejidad: O(n)
    */

    if (0 <= pos && pos <= this->size)
    {
        if (pos == 0)
        {
            this->insertFirst(data);
        }
        else if (pos == this->size)
        {
            this->insertLast(data);
        }
        else
        {
            Node *tmp = this->head;
            for (int i = 0; i < pos - 1; ++i)
            {
                tmp = tmp->next;
            }
            tmp->next = new Node(data, tmp->next);
            ++this->size;
        }
    }
    else
    {
        throw std::invalid_argument("No se puede insertar un dato en una posición fuera del rango [0, size].");
    }
}

void MyLinkedList::removeFirst()
{
    /*
    Descripción: Función que elimina un dato al inicio de la lista.

    Parámetros: Ninguno.

    Valor de retorno: Ninguno.

    Precondición: Que no esté vacía la lista.

    postcondición: El dato es eliminado.

    Complejidad: O(1)
    */

    if (!this->isEmpty())
    {
        Node *tmp = this->head;
        this->head = this->head->next;
        delete tmp;
        if (size == 1)
        {
            this->tail = nullptr;
        }
        --this->size;
    }
    else
    {
        throw std::invalid_argument("No se puede borrar el primer elemento de una lista vacía.");
    }
}

void MyLinkedList::removeLast()
{
    /*
    Descripción: Función que elimina un dato al final de la lista.

    Parámetros: Ninguno.

    Valor de retorno: Ninguno.

    Precondición: Que no esté vacía la lista.

    postcondición: El dato es eliminado.

    Complejidad: O(n)
    */
    
    if (this->size <= 1)
    {
        removeFirst();
    }
    else
    {
        Node *tmp = this->head;
        for (int i = 0; i < this->size - 2; ++i)
        {
            tmp = tmp->next;
        }
        // tmp ya es una posición atrás de tail.
        tmp->next = nullptr;
        delete this->tail;
        this->tail = tmp;
        --this->size;
    }
}

void MyLinkedList::removeAt(int pos)
{
    /*
    Descripción: Función que elimina un dato en una posición de la lista.

    Parámetros: La posición.

    Valor de retorno: Ninguno.

    Precondición: Que no esté vacía la lista.

    postcondición: El dato es eliminado.

    Complejidad: O(n)
    */

    if (0 <= pos && pos < this->size)
    {
        if (pos == 0)
        {
            this->removeFirst();
        }
        else if (pos == this->size - 1)
        {
            this->removeLast();
        }
        else
        {
            Node *previo = this->head;
            for (int i = 0; i < pos - 1; ++i)
            {
                previo = previo->next;
            }
            Node *aEliminar = previo->next;
            Node *posterior = aEliminar->next;
            delete aEliminar;
            previo->next = posterior;
            --this->size;
        }
    }
    else
    {
         throw std::invalid_argument("No se puede borrar un dato en una posición que no existe.");
    }
}

std::ostream &operator<<(std::ostream &salida, const MyLinkedList &myLinkedList)
{
    /*
    Descripción: Función que imprime la lista.

    Parámetros: Salida y lista.

    Valor de retorno: La salida.

    Precondición: No.

    postcondición: Ninguna.

    Complejidad: O(n)
    */
    Node *tmp = myLinkedList.head;
    for (int i = 0; i < myLinkedList.size - 1; ++i)
    {
        salida << tmp->data << std::endl;
        tmp = tmp->next;
    }
    salida << tmp->data;
    return salida;
}

void MyLinkedList::consulta(std::ostream &salida, Registro l, Registro r)
{
    /*
    Descripción: Función que imprime los registros en el rango [l, r]

    Parámetros: salida por referencia, registros que lo encierran.

    Precondición: la lista debe estar ordenada de forma ascendente.

    postcondición: Ninguna.

    Valor de retorno: Ninguno.

    Complejidad: O(n) | n = posición de r en la lista ordenada
    */
    Node *tmp = this->head;
    while (tmp != nullptr && tmp->data < l)
    {
        tmp = tmp->next;
    }
    while (tmp != nullptr && tmp->data <= r)
    {
        salida << tmp->data;
        std::cout << tmp->data << std::endl;
        if (!(tmp->next == nullptr || !(tmp->next->data <= r)))
        {
            salida << std::endl;
        }
        tmp = tmp->next;
    }
}

Node* MyLinkedList::merge(Node *h1, Node *h2)
{
    /*
    Descripción: se unifican dos listas ordenadas en una sola también ordenada

    Parámetros: dos nodos de inicio

    Precondición: Las listas con cabeza en h1 y h2 deben estar ordenadas de forma
    ascendente.

    postcondición: La lista unificada quedará ordenada en forma ascendente.

    Valor de retorno: un nodo de inicio.

    Complejidad: O(n + m) | n = longitud de la lista con cabeza en h1 y 
    m = longitud de la lista con cabeza en h2.
    */
    if(h1 == nullptr)
    {
        return h2;
    }
    if(h2 == nullptr)
    {
        return h1;
    }
    Node *head;
    Node *tail;
    if(h1->data <= h2->data)
    {
        head = h1;
        tail = h1;
        h1 = h1->next;
    }
    else
    {
        head = h2;
        tail = h2;
        h2 = h2->next;
    }
    while(h1 != nullptr && h2 != nullptr)
    {
        if(h1->data <= h2->data)
        {
            tail->next = h1;
            tail = h1;
            h1 = h1->next; 
        }
        else
        {
            tail->next = h2;
            tail = h2;
            h2=h2->next;
        }  
    }
    if(h1 == nullptr)
    {
        tail->next = h2;
    }
    else
    {
       tail->next = h1; 
    }
    return head;
}

Node* MyLinkedList::mitad(Node *head)
{
    /*
    Descripción: obtiene el punto medio de la lista ligada

    Parámetros: el inicio de la lista

    Valor de retorno: nodo medio

    Complejidad: O(n) | n = longitud de la lista con cabeza en head
    */
    Node *tmp = head;
    int tam = 1;
    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
        ++tam;
    }
    tmp = head;
    for (int i = 0; i < tam / 2 - 1; ++i)
    {
        tmp = tmp->next;
    }
    return tmp;
}

Node* MyLinkedList::mergeSort(Node *head)
{
    /*
    Descripción: función auxiliar de mergeSort()

    Parámetros: cabeza de la lista a ordenar.

    Valor de retorno: la cabeza de la lista ya ordenada.

    Precondición: Ninguna.

    postcondición: La lista con cabeza en head está ordenada.

    Complejidad: O(n * log(n)) | n = longitud de la lista con cabeza en head
    */
    if(head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *h1 = head;
    Node *h1f = mitad(h1);
    Node *h2 = h1f->next;
    h1f->next = nullptr;    
    return merge(mergeSort(h1), mergeSort(h2)) ;
}

void MyLinkedList::mergeSort()
{
    /*
    Descripción: Función que ordena en forma ascendente los datos con el método 
    de Merge en listas ligadas.

    Parámetros: Ninguno.

    Valor de retorno: Ninguno.

    Precondición: Ninguna.

    postcondición: La lista con cabeza en head está ordenada.

    Complejidad: O(n * log(n)) | n = longitud de la lista con cabeza en head
    */
    this->head = this->mergeSort(this->head);
}
