#ifndef DLIST_H
#define DLIST_H

#include<iostream>

template<class T>
class dList;

template <class T>
std::ostream& operator<< (std::ostream&, const dList<T>&);

template<class T>
class dList {
    friend std::ostream& operator<< <T>(std::ostream&, const dList<T>&);
private:
    class nodo {
    public:
        T info;
        nodo *prev, *next;
        nodo(const T& t = T(), nodo* p=nullptr, nodo* n=nullptr):
            info(t), prev(p), next(n) {}
        ~nodo() {delete next;}

        std::ostream& recPrint(std::ostream& os, int n){
            os << n;
            os <<info;
            if(next){ next->recPrint(os, ++n);}
            return os;
        }

    };
    nodo *last, *first; // lista vuota iff first==last==nullptr
    unsigned int size=0;
    static nodo* copy(nodo* p, nodo*& l){
        if(p==nullptr) return l=nullptr;
        nodo* prec=new nodo(p->info,nullptr,nullptr);
        nodo* succ=prec;
        nodo* start=prec;
        while(p->next!=nullptr) {
            succ = new nodo(p->next->info,prec,nullptr);
            prec->next=succ;
            p=p->next;
            prec=prec->next;
        }
        l=succ;
        return start;
    }

    static bool isLess(nodo* d1, nodo* d2) {
        if(d2==nullptr) return false;
        // d2 NON e' vuota
        if(d1==nullptr) return true;
        // d1 e d2 NON vuote
        return d1->info < d2->info ||
                (d1->info==d2->info && isLess(d1->next,d2->next));
    }

public:
    dList():last(nullptr),first(nullptr),size(0){}
    dList(unsigned int k, const T& t): last(nullptr), first(nullptr) {
        for(unsigned int i=0; i<k; ++i)
            insertBack(t);

        size=k;
    }

    ~dList() {delete first;size=0;}
    dList(const dList& d): first(copy(d.first,last)), size(d.size) {}
    dList& operator=(const dList& d) {
        if(this != &d) {
            delete first;
            first=copy(d.first,last);
        }
        size=d.size;
        return *this;
    }

    void insertFront(const T& t) {
        first = new nodo(t,nullptr,first);
        if(first->next==nullptr) {
            // lista di invocazione era vuota
            last=first;
        }
        else {
            // lista di invocazione NON era vuota
            (first->next)->prev=first;
        }
        size++;
    }

    void insertBack(const T& t) {
        last = new nodo(t,last,nullptr);
        if(last->prev==nullptr) {
            // lista di invocazione era vuota
            first=last;
        }
        else {
            // lista di invocazione NON era vuota
            (last->prev)->next=last;
        }
        size++;
    }

    void removeFront(){
        nodo* aux = first->next;
        first->next=nullptr;
        delete first;
        first=aux;
        size--;
    }

    //toglie prima occorrenza di t
   /* void removeFirstOccurrence(T t) {
        nodo* p= first, *pr=nullptr;
        while(p && !(p->info==t)){
            pr=p; p=p->next;
        }
        if(p){
            if(!pr)
                first=p->next;
            else
                pr->next=p->next;
            //isolo il nodo
            p->next=nullptr;
            delete p;
            size++;
        }
    }*/

    void removeNth(int n){//se non ce nulla bug
        if(n<size){
            if(first->next==nullptr && first){//se ce un nodo
                delete first;
                first=last=nullptr;
            }else if(n==0)//se devo eliminare il primo
                removeFront();
            else if(first){
                nodo* aux=first;
                nodo* prec=nullptr;
                for(int i=0;i<n;i++){
                    prec=aux;
                    aux=aux->next;
                }//deve eliminare aux
                if(aux==last){
                    last=prec;
                }
                prec->next=aux->next;
                aux->next=nullptr;
                delete aux;
                size--;
            }
        }else {
            std::cout << "occhiooooooo!!!";
            return;//n outofbound
        }
    }

    bool operator<(const dList& d) const {
        return isLess(first,d.first);
    }

    bool isEmpty() const{
        return first==nullptr;
    }

    void Empty(){
        delete first;
        first=last=nullptr;
    }

    /* T operator[](int n){//senza troppi controlli
      nodo start= first;
      while(n){
          if(first->next) first=first->next;
          n--;
      }
      return aux.info;
  }*/

    class iterator {
        friend class dList<T>;
    private:
        nodo* punt;      //nodo puntato dall'iteratore
    public:
        bool operator==(iterator i) const {
            return punt==i.punt;
        }

        bool operator!=(iterator i) const {
            return punt!=i.punt;
        }

        //incremento prefisso
        iterator& operator++() {
            if(punt) punt=punt->next; //side-effect
            return *this;
        }//NB se punt==0 non fa nulla

        //incremento postfisso
        iterator operator++(int) {
            iterator aux = *this;
            if(punt) punt=punt->next;
            return aux;
        }
    };//end class iterator

    //metodi che usano iteratore
    iterator beginIT() const{
        iterator aux;
        aux.punt = first; //per amicizia
        return aux;
    }

    iterator endIT() const{
        iterator aux;
        aux.punt = nullptr; //per amicizia
        return aux;
    }

    T& operator[](int n) const {
        nodo* aux = first;

        while(aux && n){
            aux=aux->next;
            n--;
        }
        return aux->info; //per amicizia
        //NB nessun controllo se i.punt != 0
    }

    class constIterator {
        friend class dList<T>;
    private:
        nodo* ptr;
        bool pastTheEnd; // true iff constiterator e' "past-the-end"
        // conversione nodo* => constiterator
        constIterator(nodo* p, bool pte=false): ptr(p), pastTheEnd(pte) {}
    public:
        constIterator(): ptr(nullptr), pastTheEnd(false) {}

        const T& operator*() const {
            return ptr->info;
        }

        const T* operator->() const {
            return &(ptr->info);
        }

        constIterator& operator++() {
            if(ptr!= nullptr) {
                if(!pastTheEnd) {
                    if(ptr->next==nullptr) {++ptr; pastTheEnd=true;}
                    else {ptr=ptr->next;}
                }
            }
            return *this;
        }

        constIterator& operator--() {
            if(ptr!=nullptr) {
                if(pastTheEnd) {--ptr; pastTheEnd=false;}
                else ptr=ptr->prev;
            }
            return *this;
        }

        bool operator==(const constIterator& x) const {
            return ptr==x.ptr;
        }

        bool operator!=(const constIterator& x) const {
            return ptr!=x.ptr;
        }
    };

    constIterator begin() const {
        return first;
    }

    constIterator end() const {
        if(last==nullptr) return nullptr;
        return constIterator(last+1,true);
    }

    unsigned int getSize() const{
        return size;
    }


};

template <class T>
std::ostream& operator<<(std::ostream& os, const dList<T>& t){
    if(t.first!=nullptr) return t.first->recPrint(os,0);
    return os;
}

#endif // DLIST_H
