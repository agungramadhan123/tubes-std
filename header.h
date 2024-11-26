#ifndef header_h_included
#define header_h_included
#include <iostream> 
using namespace std;

typedef int infotype;
typedef elmlist* address;

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
address createNewElm(infotype data);

void deletefirst(list& L, address& p);
void deletelast(list& L, address& p);
void deleteafter(list& L, address& prec, address p);

/*zikra*/
void insertfirst(list &L, address p);
void insertlast(list &L, address p);
void insertafter(list &L, address prec, address p);
void showall(list L);

testest

#endif
