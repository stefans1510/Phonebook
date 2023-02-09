#include "Phonebook.h"
class PhonebookManager : public Phonebook {
public:
    virtual void loadContacts(string fileName);
    virtual void saveContacts(string fileName);
};