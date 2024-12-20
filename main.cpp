#include "header.h"

int main() {
    string bebas = " ";
    list L = {nullptr, nullptr};
    stack undoStack, redoStack;
    undoStack.top = -1;
    redoStack.top = -1;
    address cursor = nullptr;
    char input;
    int cursorPos = 0;

    push(undoStack, getText(L));
    printlist(bebas,cursorPos);

    while (true) {
        input = _getch();

        if (input == 27) {
            break;
        } else if (input == '\b') {
            if (cursor != nullptr) {
                deleteAtCursor(L, cursor);
                cursorPos--;
                push(undoStack, getText(L));
                redoStack.top = -1;
            }
        } else if (input == -32) {
            char arrow = _getch();
            if (arrow == 75 && cursor != nullptr && cursor->prev != nullptr) {
                cursor = cursor->prev;
                cursorPos--;
            } else if (arrow == 77 && cursor != nullptr && cursor->next != nullptr) {
                cursor = cursor->next;
                cursorPos++;
            }
        } else if (input == 26) {
            if (!isempty(undoStack)) {
                undo(undoStack, redoStack, L);
                cursor = L.last;
                cursorPos = getText(L).length();
            }
        } else if (input == 25) {
            if (!isempty(redoStack)) {
                redo(undoStack, redoStack, L);
                cursor = L.last;
                cursorPos = getText(L).length();
            }
        } else if (input == 13) {
            insertNewline(L, cursor);
            cursorPos++;
            push(undoStack, getText(L));
            redoStack.top = -1;
        } else { 
            address newElm = createNewElm(input);
            if (cursor == nullptr) {
                L.first = newElm;
                L.last = newElm;
                cursor = newElm;
                cursorPos = 0;
            } else {
                insertAfter(L, cursor, newElm);
                cursor = cursor->next;
                cursorPos++;
            }
            push(undoStack, getText(L));
            redoStack.top = -1;
        }

        string currentText = getText(L);
        printlist(currentText, cursorPos);
    }

    return 0;
}
