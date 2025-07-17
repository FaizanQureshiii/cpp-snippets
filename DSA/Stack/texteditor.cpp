#include<iostream>
#include<string>
using namespace std;

class TextEditor {
private:
    string* mainStack;
    string* undoStack;
    int size;
    int topMain;
    int topUndo;

public:
    TextEditor(int n) {
        size = n;
        topMain = -1;
        topUndo = -1;
        mainStack = new string[size];
        undoStack = new string[size];
        cout << "✨ Text editor ready! Stack size: " << size << " ✨" << endl;
    }

    ~TextEditor() {
        delete[] mainStack;
        delete[] undoStack;
    }

    void push(string val) {
        if (topMain == size - 1) {
            cout << "⚠️ Can't type more, editor full!" << endl;
            return;
        }

        if (val == "$") val = " "; // convert $ to space

        mainStack[++topMain] = val;
        cout << "✅ '" << val << "' added to text." << endl;
    }

    void pop() {
        if (topMain == -1) {
            cout << "⚠️ Nothing to delete!" << endl;
            return;
        }

        string removed = mainStack[topMain--];
        undoStack[++topUndo] = removed;
        cout << "❌ '" << removed << "' deleted." << endl;
    }

    void undo() {
        if (topUndo == -1) {
            cout << "⚠️ Nothing to undo!" << endl;
            return;
        }

        string restored = undoStack[topUndo--];
        mainStack[++topMain] = restored;
        cout << "↩️ Undo done! '" << restored << "' restored." << endl;
    }

    void display() {
        if (topMain == -1) {
            cout << "📝 Editor is empty." << endl;
            return;
        }

        cout << "📝 Current Text: ";
        for (int i = 0; i <= topMain; i++) {
            cout << mainStack[i];
        }
        cout << endl;
    }
};

int main() {
    TextEditor editor(100);
    int choice;
    string input;

    cout << "\n------ TEXT EDITOR MENU ------\n";
    cout << "1. Type\n";
    cout << "2. Delete Last Entry\n";
    cout << "3. Undo\n";
    cout << "4. Show Text\n";
    cout << "5. Exit\n";

    while (true) {
        cout << "\nChoose an option (1-5): ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter text (use '$' for space): ";
                getline(cin, input);
                for (char ch : input) {
                    string s(1, ch);
                    editor.push(s);
                }
                break;

            case 2:
                editor.pop();
                break;

            case 3:
                editor.undo();
                break;

            case 4:
                editor.display();
                break;

            case 5:
                cout << "👋 Exiting editor. Keep creating magic, Faizan!" << endl;
                return 0;

            default:
                cout << "⚠️ Invalid option. Try again!" << endl;
        }
    }
}
