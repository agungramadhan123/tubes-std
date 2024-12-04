#ifndef header_h_included
#define header_h_included

#include <iostream>
#include <string>

using namespace std;

// DLL ADT
typedef string infotype;
typedef struct elmlist *address;

// Stack ADT
const int MAXSIZE = 100;
typedef int Index;
typedef struct elmstack *adr;

struct elmstack {
    infotype kata;
    adr next;
    adr prev;
};

struct listStack {
    adr head;
    adr tail;
};

struct stack {
    infotype info[MAXSIZE];
    Index top = -1;
};

struct elmlist {
    infotype info;
    address next;
    address prev ;
};

struct list {
    address first;
    address last;
};

// aril
void createlist(list &L);
address createNewElm(infotype p);
void deletefirst(list &L, address &p);
void deletelast(list &L, address &p);
void deleteafter(list &L, address &prec, address p);

// zikra
void insertfirst(list &L, address p);
void insertlast(list &L, address p);
void insertafter(list &L, address prec, address p);
void showall(list L);

// agung
bool isempty(stack s);
bool full(stack s);
void push(stack &s, infotype p);
void pop(stack &s, infotype &p);
void undo(stack &undo, stack &redo, list &L);
void redo(stack &undo, stack &redo, list &L);

#endif
