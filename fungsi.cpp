#include "header.h"
#include <iostream>

void createlist(list &L) {
    l.first = nullptr;
    l.last = nullptr;
}

address createNewElm(infotype p) {
    address temp = new elmlist;
    temp->info = p;
    temp->next = nullptr;
    temp->prev = nullptr;
    return temp;
}

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
        L.first = p;
        L.last = p;
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


bool isempty(stack s) {
    return s.top == 0;
}

bool full(stack s) {
    return s.top == MAXSIZE ;
}

void push(stack &s, infotype p) {
    if (!full(s)) {
        s.top++;
        s.info[s.top] = p;
    } 
}

void pop(stack &s, infotype &p) {
    if (!isempty(s)) {
        p = s.info[s.top];
        s.top--;
    }
}
void undo(stack &undo, stack &redo, list &L) {
    if (!isempty(undo)) {
        infotype currentText;
        pop(undo, currentText);
        push(redo, currentText);

        if (!isempty(undo)) {
            L.first->info = undo.info[undo.top]; 
        } else {
            L.first->info = " "; 
        }
    } 
}

void redo(stack &undo, stack &redo, list &L) {
    if (!isempty(redo)) {
        infotype nextText;
        pop(redo, nextText);
        push(undo, nextText);

        L.first->info = nextText; 
    } 
}


void showall(list L) {
    address p = L.first;
    while (p != nullptr) {
        cout << p->info << " ";
        p = p->next;
    }
    cout << endl;
}
