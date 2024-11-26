#ifndef header_h_included
#define header_h_included
#include <iostream> 
#include <algorithm>
using namespace std;
typedef int infotype;
typedef string infotype;
typedef struct elmlist *address;

const int MAXSIZE = 100; 
typedef int Index;

struct stack {
    infotype info[MAXSIZE];
    Index top;
};


struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct list {
    address first;
    address last;
};

void createlist(list &L);
address createNewElm(infotype p);

void deletefirst(list& L, address& p);
void deletelast(list& L, address& p);
void deleteafter(list& L, address& prec, address p);

/*zikra*/
void insertfirst(list &L, address p);
void insertlast(list &L, address p);
void insertafter(list &L, address prec, address p);
void showall(list L);

// agung
stack create();
bool isempty(stack s);
bool full(stack s);
void push(stack &s,infotype p);
void pop(stack &s,infotype &p);
void undo(stack &s, infotype x);
void redo(stack &s,infotype x);

#endif
