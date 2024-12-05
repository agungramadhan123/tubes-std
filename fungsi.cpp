#include "header.h"

address createNewElm(infotype nilai) {
    address p = new elmlist;
    p->info = nilai;
    p->next = nullptr;
    p->prev = nullptr;
    return p;
}
void insertAfter(list &L, address prec, address p) {
    if (prec != nullptr) {
        p->next = prec->next;
        p->prev = prec;
        if (prec->next != nullptr) {
            prec->next->prev = p;
        } else {
            L.last = p;
        }
        prec->next = p;
    } else {
        if (L.first == nullptr) {
            L.first = p;
            L.last = p;
        } else {
            p->next = L.first;
            L.first->prev = p;
            L.first = p;
        }
    }
}
void deleteAtCursor(list &L, address &cursor) {
    if (cursor != nullptr) {
        address temp = cursor;
        if (cursor->prev != nullptr) {
            cursor = cursor->prev;
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            } else {
                L.first = temp->next;
            }
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            } else {
                L.last = temp->prev;
            }
            delete temp;
        } else {
            L.first = cursor->next;
            if (L.first != nullptr) {
                L.first->prev = nullptr;
            }
            if (cursor == L.last) {
                L.last = nullptr;
            }
            delete cursor;
            cursor = L.first;
        }
    }
}
string getText(list &L) {
    string result;
    address temp = L.first;
    while (temp != nullptr) {
        result += temp->info;
        temp = temp->next;
    }
    return result;
}
int countWords(const string &text) {
    int count = 0;
    bool inWord = false;
    for (char c : text) {
        if (isalnum(c)) {
            if (!inWord) {
                inWord = true;
                count++;
            }
        } else {
            inWord = false;
        }
    }
    return count;
}
void printlist(const string &text, int cursorPos) {
    system("cls");
    cout << "Text Editor (Keyboard Simulation)" << endl;
    cout << "Commands: Backspace (delete), Left (←), Right (→), Undo (ctrl+z), Redo (ctrl+y), Exit (ESC)" << endl;
    cout << "-------------------------------------------------------" << endl;

    for (int i = 0; i <= text.length(); ++i) {
        if (i < text.length()) {
            cout << text[i];
        }

        if (i == cursorPos) {
            cout << '|';
        }
    }

    cout << endl << endl;
    cout << "Text right now: " << text << endl;
    int jumlahKata = countWords(text);
    cout << "Word count: " << countWords(text) << endl;
}


void insertNewline(list &L, address &cursor) {
    address newLine = createNewElm('\n');
    if (cursor != nullptr) {
        newLine->next = cursor->next;
        newLine->prev = cursor;
        if (cursor->next != nullptr) {
            cursor->next->prev = newLine;
        } else {
            L.last = newLine;
        }
        cursor->next = newLine;
        cursor = newLine;
    } else {
        L.first = newLine;
        L.last = newLine;
        cursor = newLine;
    }
}

bool isempty(stack s) {
    return s.top == -1;
}

bool full(stack s) {
    return s.top == MAXSIZE - 1;
}

void push(stack &s, stackElement p) {
    if (!full(s)) {
        s.info[++s.top] = p;
    }
}

void pop(stack &s, stackElement &p) {
    if (!isempty(s)) {
        p = s.info[s.top--];
    }
}

void undo(stack &undo, stack &redo, list &L) {
    if (!isempty(undo)) {
        string lastText;
        pop(undo, lastText);
        push(redo, getText(L));
        L.first = nullptr;
        L.last = nullptr;
        for (char c : lastText) {
            address newElm = createNewElm(c);
            if (L.last == nullptr) {
                L.first = newElm;
                L.last = newElm;
            } else {
                insertAfter(L, L.last, newElm);
            }
        }
    }
}
void redo(stack &undo, stack &redo, list &L) {
    if (!isempty(redo)) {
        string nextText;
        pop(redo, nextText);
        push(undo, getText(L));
        L.first = nullptr;
        L.last = nullptr;
        for (char c : nextText) {
            address newElm = createNewElm(c);
            if (L.last == nullptr) {
                L.first = newElm;
                L.last = newElm;
            } else {
                insertAfter(L, L.last, newElm);
            }
        }
    }
}
