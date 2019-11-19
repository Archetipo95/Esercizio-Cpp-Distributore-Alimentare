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
        os << "DISTRIBUTORE #" << n << std::endl;
        os <<info;
        if(next){ os << std::endl; next->recPrint(os, ++n); }
        return os;
    }
  };
  nodo *last, *first; // lista vuota iff first==last==nullptr
  int size=0;
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
  dList():last(nullptr),first(nullptr){}

  ~dList() {delete first;}
  dList(const dList& d): first(copy(d.first,last)) {
    // first=copy(d.first,last);
  }

  dList& operator=(const dList& d) {
    if(this != &d) {
      delete first;
      first=copy(d.first,last);
    }
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

  dList(unsigned int k, const T& t): last(nullptr), first(nullptr) {
    for(unsigned int i=0; i<k; ++i)
      insertFront(t);
  }

  bool operator<(const dList& d) const {
    return isLess(first,d.first);
  }

 /* T operator[](int n){//senza troppi controlli
      nodo start= first;
      while(n){
          if(first->next) first=first->next;
          n--;
      }
      return aux.info;
  }*/

  class Iteratore {
      friend class dList<T>;
  private:
      nodo* punt;      //nodo puntato dall'iteratore
  public:
      bool operator==(Iteratore i) const {
          return punt==i.punt;
      }

      bool operator!=(Iteratore i) const {
          return punt!=i.punt;
      }

      //incremento prefisso
      Iteratore& operator++() {
          if(punt) punt=punt->next; //side-effect
          return *this;
      }//NB se punt==0 non fa nulla

      //incremento postfisso
      Iteratore operator++(int) {
          Iteratore aux = *this;
          if(punt) punt=punt->next;
          return aux;
      }
  };//end class Iteratore

  //metodi che usano iteratore
  Iteratore beginIT() const{
      Iteratore aux;
      aux.punt = first; //per amicizia
      return aux;
  }

  Iteratore endIT() const{
      Iteratore aux;
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

  class constiterator {
    friend class dList<T>;
  private:
    nodo* ptr;
    bool pastTheEnd; // true iff constiterator e' "past-the-end"
    // conversione nodo* => constiterator
    constiterator(nodo* p, bool pte=false): ptr(p), pastTheEnd(pte) {}
  public:
    constiterator(): ptr(nullptr), pastTheEnd(false) {}

    const T& operator*() const {
      return ptr->info;
    }

    const T* operator->() const {
      return &(ptr->info);
    }

    constiterator& operator++() {
      if(ptr!= nullptr) {
    if(!pastTheEnd) {
      if(ptr->next==nullptr) {++ptr; pastTheEnd=true;}
      else {ptr=ptr->next;}
    }
      }
      return *this;
    }

    constiterator& operator--() {
      if(ptr!=nullptr) {
    if(pastTheEnd) {--ptr; pastTheEnd=false;}
    else ptr=ptr->prev;
      }
      return *this;
    }

    bool operator==(const constiterator& x) const {
      return ptr==x.ptr;
    }

    bool operator!=(const constiterator& x) const {
      return ptr!=x.ptr;
    }
  };

  constiterator begin() const {
    return first;
  }

  constiterator end() const {
    if(last==nullptr) return nullptr;
    return constiterator(last+1,true);
  }

  int getSize(){
      return size;
  }


};

template <class T>
std::ostream& operator<<(std::ostream& os, const dList<T>& t){
    if(t.first!=nullptr) return t.first->recPrint(os, 0);
    return os;
}
#endif // DLIST_H
