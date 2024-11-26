#include "header.h"


void deletefirst(list& L, address& p) {
    p = L.first;
    if (L.first != nullptr) {
        L.first = p->next;
        p->next = nullptr;
        L.first->prev = nullptr;
    } else {
        L.first = nullptr;
        L.last = nullptr;
    }
}

void deletelast(list& L, address& p) {
    p = L.last;
    if (L.first != L.last) {
        L.last = p->prev;
        p->prev = nullptr;
        L.last->next = nullptr;
    } else {
        L.first = nullptr;
        L.last = nullptr;
    }
}

void deleteafter(list& L, address& prec, address p) {
    p = prec->next;
    prec->next = p->next;
    if (p->next != nullptr) {
        p->next->prev = prec;
    }
    p->next = nullptr;
    p->prev = nullptr;
}

/*zikra*/
void insertfirst(list &L, address p){
    if(L.first == nullptr){
        L.first = P;
        L.last = P;
    }else{
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}
void insertlast(list &L, address p){
    if(L.first == nullptr){
        L.first = p;
        L.last = p;
    }else{
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}
void insertafter(list &L, address prec, address p){
    if(L.first == nullptr){
        L.first = p;
        L.last = p;
    }else{
        p->prev = prec;
        p->next = prec->next;
        prec->next->prev = p;
        prec->next = p;
    }
}
void showall(list L){
    
}
