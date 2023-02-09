#include <string>
using namespace std;
class Contact {
public:
    string name;
    string phoneNumber;

    Contact(string name, string phoneNumber) {
        this->name = name;
        this->phoneNumber = phoneNumber;
    }

    void setName(string name) {
        this->name = name;
    }

    void setPhoneNumber(string phoneNumber) {
        this->phoneNumber = phoneNumber;
    }

    string getName() {
        return name;
    }

    string getPhoneNumber() {
        return phoneNumber;
    }
};