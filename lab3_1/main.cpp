#include "UI.h"

int main() {

    int choice;

    do {

        cout << endl;
        cout << "===== MAIN MENU ====="
             << endl;

        cout << "1. Stack" << endl;
        cout << "2. Queue" << endl;
        cout << "3. Deque" << endl;
        cout << "4. Matrix" << endl;
        cout << "5. Run tests" << endl;
        cout << "0. Exit" << endl;

        cout << "Choose: ";
        cin >> choice;

        switch (choice) {

            case 1:
                StackMenu();
                break;

            case 2:
                QueueMenu();
                break;

            case 3:
                DequeMenu();
                break;

            case 4:
                MatrixMenu();
                break;

            case 5:
                RunTests();
                break;

            case 0:
                cout << "Program finished"
                     << endl;
                break;

            default:
                cout << "Wrong choice"
                     << endl;
        }

    } while (choice != 0);

    return 0;
}