#ifndef DLIST_H
#define DLIST_H
template <class T>
class dList
{
private:
    class Node {
    public:
        T info;
        Node* next;
        Node* prev;
        Node(const T&, Node* = 0, Node* = 0);
    };
    Node* first;
    Node* last;
    static void destroy(Node*);
    static void copy(Node*, dList<T>*);
    //static void copy(Node*, Node*, Node*);  Not working, for some reason
    static bool lex_compare(Node*, Node*);
public:
    dList();
    dList(const T&, unsigned int = 1);
    dList(const dList&);
    ~dList();
    dList& operator=(const dList&);
    void insertFront(const T&);
    void insertBack(const T&);
    void removeElement(const T&);
    bool operator<(const dList& d) const;
    class const_iterator {
        friend class dList<T>;
    private:
        const Node* ptr;
        bool pastTheEnd;
        const_iterator(const Node*, bool = false);
    public:
        const_iterator();
        const_iterator(const const_iterator& c);
        const_iterator& operator++();
        const_iterator operator++(int);
        const_iterator& operator--();
        const_iterator operator--(int);
        const T& operator*();
        const T* operator->();
        bool operator==(const const_iterator&) const;
        bool operator!=(const const_iterator&) const;
    };
    const_iterator c_begin() const;
    const_iterator c_end() const;
    class iterator {
        friend class dList<T>;
    private:
        Node* ptr;
        bool pastTheEnd;
        iterator(Node*, bool = false);
    public:
        iterator();
        iterator(const iterator& c);
        iterator& operator++();
        iterator operator++(int);
        iterator& operator--();
        iterator operator--(int);
        T& operator*();
        T* operator->();
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;
    };
    iterator begin() const;
    iterator end() const;
    T unstableRemoveElement(iterator&);
};

//////////////////////////////DE-CONSTRUCTORS////////////////////////////////

template <class T>
dList<T>::Node::Node(const T& item, Node* n, Node* p) : info(item), next(n), prev(p) { }

template <class T>
dList<T>::dList() : first(0), last(0){
}

template <class T>
dList<T>::dList(const T& t, unsigned int k) : first(0), last(0) {
    for (unsigned int i = 0; i < k; i++) {
        insertFront(t);
    }
}

template <class T>
dList<T>::dList(const dList& c) : first(0), last(0) {
    copy(c.first, this);
    //copy(c.first, first, last);
}

template <class T>
dList<T>& dList<T>::operator=(const dList& c) {
    if (this != &c) {
        destroy(first);
        copy(c.first, this);
        //copy(c.first, first, last);
    }
    return *this;
}

template <class T>
void dList<T>::copy(Node* c, dList<T>* t) {
    if (c == 0) { t->first = t->last = 0; return; }
    Node* p = c;
    t->first = t->last = new Node(c->info);
    while (p->next != 0) {
        p = p->next;
        t->last->next = new Node(p->info, 0, t->last);
        t->last = t->last->next;
    }
}

//template <class T>
//void dList<T>::copy(Node* c, Node* f, Node* l) {
//    if (c == 0) { f = l = 0; return; }
//    Node* p = c;
//    l = f = new Node(c->info);
//    while (p->next != 0) {
//        p = p->next;
//        l->next = new Node(p->info, 0, l);
//        l = l->next;
//    }
//}

template <class T>
void dList<T>::destroy(Node* n) {
    if (n != 0) {
        destroy(n->next);
        delete n;
    }
}

template <class T>
dList<T>::~dList() { destroy(first); }

//////////////////////////////OPERATIONS////////////////////////////////

template <class T>
void dList<T>::insertFront(const T& value) {
    first = new Node(value, first, 0);
    if (first->next == 0)
        last = first;
    else
        (first->next)->prev = first;
}

template <class T>
void dList<T>::insertBack(const T& value) {
    last = new Node(value, 0, last);
    if (last->prev == 0)
        first = last;
    else
        (last->prev)->next = last;
}

template <class T>
bool dList<T>::operator<(const dList& d) const {
    return lex_compare(first, d.first);
}

template <class T>
bool dList<T>::lex_compare(Node* f, Node* s) {
    if (!s) return false;
    if (!f) return true;
    if (f->info < s->info) return true;
    if (s->info < f->info) return false;
    return f->info == s->info && lex_compare(f->next, s->next);
}

template <class T>
void dList<T>::removeElement(const T& d){
    Node* p = first;
    while(p){
        if(p->info == d){
            Node* prv = p->prev;
            Node* nxt= p->next;
            if(prv)
                prv->next = nxt;
            else
                first = nxt;
            if(nxt)
                nxt->prev = prv;
            else
                last = prv;
            delete p;
            return;
        }
        p = p->next;
    }
}

/////////////////////////////////CONST ITERATOR//////////////////////////////////

        template <class T>
        dList<T>::const_iterator::const_iterator(const Node* p, bool pte) : ptr(p), pastTheEnd(pte) { }

        template <class T>
        dList<T>::const_iterator::const_iterator() : ptr(0), pastTheEnd(false) {}

        template <class T>
        dList<T>::const_iterator::const_iterator(const const_iterator& c){
            const_iterator(c.ptr, c.pastTheEnd);
        }

        template <class T>
        typename dList<T>::const_iterator& dList<T>::const_iterator::operator++() {
            if (ptr && !pastTheEnd) {
                if (ptr->next == nullptr) { ptr = ptr + 1; pastTheEnd = true; }
                else ptr = ptr->next;
            }
            return *this;
        }

        template <class T>
        typename dList<T>::const_iterator dList<T>::const_iterator::operator++(int) {
            dList<T>::const_iterator temp(*this);
            if (ptr && !pastTheEnd) {
                if (ptr->next == nullptr) { ptr = ptr + 1; pastTheEnd = true; }
                else ptr = ptr->next;
            }
            return temp;
        }

        template <class T>
        typename dList<T>::const_iterator& dList<T>::const_iterator::operator--() {
            if (ptr) {
                if (pastTheEnd) {
                    ptr -= 1;
                    pastTheEnd = false;
                }
                else
                    ptr = ptr->prev;
            }
            return *this;
        }

        template <class T>
        typename dList<T>::const_iterator dList<T>::const_iterator::operator--(int) {
            dList<T>::const_iterator temp(this);
            if (ptr) {
                if (pastTheEnd) {
                    ptr -= 1;
                    pastTheEnd = false;
                }
                else ptr = ptr->prev;
            }
            return temp;
        }

        template <class T>
        const T& dList<T>::const_iterator::operator*() {
            return ptr->info;
        }

        template <class T>
        const T* dList<T>::const_iterator::operator->() {
            return &(ptr->info);
        }

        template <class T>
        bool dList<T>::const_iterator::operator==(const const_iterator& CI) const {
            return this->ptr == CI.ptr; //ptr->info == CI.ptr->info;
        }

        template <class T>
        bool dList<T>::const_iterator::operator!=(const const_iterator& CI) const {
            return this->ptr != CI.ptr; //ptr->info != CI.ptr->info;
        }

        template <class T>
        typename dList<T>::const_iterator dList<T>::c_begin() const {
            if(first == 0)
                return const_iterator(last + 1, true);
            return const_iterator(first, false);
        }

        template <class T>
        typename dList<T>::const_iterator dList<T>::c_end() const {
            return const_iterator(last + 1, true);
        }

/////////////////////////////////NON CONST ITERATOR//////////////////////////////////

template <class T>
dList<T>::iterator::iterator(Node* p, bool pte) : ptr(p), pastTheEnd(pte) { }

template <class T>
dList<T>::iterator::iterator() : ptr(0), pastTheEnd(false) {}

template <class T>
dList<T>::iterator::iterator(const iterator& c){
    iterator(c.ptr, c.pastTheEnd);
}

template <class T>
typename dList<T>::iterator& dList<T>::iterator::operator++() {
    if (ptr && !pastTheEnd) {
        if (ptr->next == nullptr) { ptr = ptr + 1; pastTheEnd = true; }
        else ptr = ptr->next;
    }
    return *this;
}

template <class T>
typename dList<T>::iterator dList<T>::iterator::operator++(int) {
    dList<T>::iterator temp(*this);
    if (ptr && !pastTheEnd) {
        if (ptr->next == nullptr) { ptr = ptr + 1; pastTheEnd = true; }
        else ptr = ptr->next;
    }
    return temp;
}

template <class T>
typename dList<T>::iterator& dList<T>::iterator::operator--() {
    if (ptr) {
        if (pastTheEnd) {
            ptr -= 1;
            pastTheEnd = false;
        }
        else
            ptr = ptr->prev;
    }
    return *this;
}

template <class T>
typename dList<T>::iterator dList<T>::iterator::operator--(int) {
    dList<T>::iterator temp(this);
    if (ptr) {
        if (pastTheEnd) {
            ptr -= 1;
            pastTheEnd = false;
        }
        else ptr = ptr->prev;
    }
    return temp;
}

template <class T>
T& dList<T>::iterator::operator*() {
    return ptr->info;
}

template <class T>
T* dList<T>::iterator::operator->() {
    return &(ptr->info);
}

template <class T>
bool dList<T>::iterator::operator==(const iterator& CI) const {
    return this->ptr == CI.ptr; //ptr->info == CI.ptr->info;
}

template <class T>
bool dList<T>::iterator::operator!=(const iterator& CI) const {
    return this->ptr != CI.ptr; //ptr->info != CI.ptr->info;
}

template <class T>
typename dList<T>::iterator dList<T>::begin() const {
    if(first == 0)
        return iterator(last + 1, true);
    return iterator(first, false);
}

template <class T>
typename dList<T>::iterator dList<T>::end() const {
    return iterator(last + 1, true);
}


template <class T>
T dList<T>::unstableRemoveElement(iterator& it){   //WARNING! Unrefined function. Once the element is deleted, the iterator will put itself into the item after it.
    Node* prev = it.ptr->prev;                     //To prevent bugs, you have to manually decrease by 1 the iterator everytime it deletes an item or act as if you did ++.
    Node* next = it.ptr->next;                     //This is because I was not able to fix the bug where if you delete the first value you would point to a nullpointer
    T temp = it.ptr->info;                         //even though the list could be not empty.

    if(prev)
        prev->next = next;
    else                                           //POSSIBLE FIX 1: The node removed from the list is not deleted. This way the iterator does not move, but leaves garbage behind. X
        //Deleted first item                       //POSSIBLE FIX 2: Create an imaginary node which "next" ptr points to the first item. Also creates some garbage, although less heavy. X
        first = next;
    if(next)                                       //UPDATE: As I found out, this is how an erase normally behaves even in stdlib.
        next->prev = prev;
    else {
        //Deleted last item
        last = prev;
        it.pastTheEnd = true;
        delete it.ptr;
        it.ptr = last+1;
        return temp;
    }
    delete it.ptr;
    it.ptr = next;
    return temp;
}

#endif // DLIST_H
