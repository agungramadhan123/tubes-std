#include "header.h"
#include <iostream>
using namespace std;

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
