#include "PhonebookManager.h"
#include <iostream>
using namespace std;

class UI {
public:
    void displayMenu();
    int getUserChoice();
    void executeChoice(int choice, PhonebookManager& phonebook);
};

void UI::displayMenu() {
    cout << "1. Add Contact" << endl;
    cout << "2. Remove Contact" << endl;
    cout << "3. Edit Contact" << endl;
    cout << "4. View Contacts" << endl;
    cout << "5. Exit" << endl;
}

int UI::getUserChoice() {
    int choice;
    cin >> choice;
    return choice;
}

void UI::executeChoice(int choice, PhonebookManager& phonebook) {
    string name;
    string phoneNumber;
    switch (choice) {
    case 1:
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter phone number: ";
        cin >> phoneNumber;
        phonebook.addContact(Contact(name, phoneNumber));
        break;
    case 2:
        cout << "Enter name: ";
        cin >> name;
        phonebook.removeContact(name);
        break;
    case 3:
        cout << "Enter name of contact you'd like to update: ";
        cin >> name;
        cout << "Enter new phone number: ";
        cin >> phoneNumber;
        phonebook.editContact(name, Contact(name, phoneNumber));
        break;
    case 4:
        for (Contact contact : phonebook.getContacts()) {
            cout << contact.getName() << ": " << contact.getPhoneNumber() << endl;
        }
        break;
    case 5:
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
}

int main() {
    PhonebookManager phonebook;
    UI ui;
    try {
        phonebook.loadContacts("contacts.txt");
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    int userChoice;
    do {
        ui.displayMenu();
        userChoice = ui.getUserChoice();
        ui.executeChoice(userChoice, phonebook);
    } while (userChoice != 5);
    try {
        phonebook.saveContacts("contacts.txt");
    }
    catch (const exception& e) {
        cerr << e.what() << endl;
    }
    return 0;
}


