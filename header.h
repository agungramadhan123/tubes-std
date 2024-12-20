#ifndef header_h_included
#define header_h_included
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

// DLL ADT
typedef char infotype;
typedef struct elmlist *address;

// Stack ADT
const int MAXSIZE = 100;
typedef string stackElement;

struct elmlist {
    infotype info;
    address next, prev;
};

struct list {
    address first, last;
};

struct stack {
    stackElement info[MAXSIZE];
    int top = -1;
};
address createNewElm(infotype nilai);
void insertAfter(list &L, address prec, address p);
void deleteAtCursor(list &L, address &cursor);
string getText(list &L);
void printlist( string &text, int cursorPos);
void insertNewline(list &L, address &cursor);
int countWords( string &text);
bool isempty(stack s);
bool full(stack s);
void push(stack &s, stackElement p);
void pop(stack &s, stackElement &p);
void undo(stack &undo, stack &redo, list &L);
void redo(stack &undo, stack &redo, list &L);
#endif
