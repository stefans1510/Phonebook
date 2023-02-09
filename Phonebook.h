#include <iostream>
#include <vector>
#include "Contact.h"

class Phonebook {
protected:
    vector<Contact> contacts;

public:
    void addContact(Contact contact) {
        contacts.push_back(contact);
    }

    void removeContact(string name) {
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts[i].getName() == name) {
                contacts.erase(contacts.begin() + i);
                break;
            }
        }
    }

    void editContact(string name, Contact newContact) {
        bool contactExists = false;
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts[i].getName() == name) {
                contactExists = true;
                contacts[i] = newContact;
                break;
            }
        }
        if (!contactExists) {
            cout << "Error: Contact with name '" << name << "' does not exist" << endl;
        }
    }

    vector<Contact> getContacts() {
        return contacts;
    }
};