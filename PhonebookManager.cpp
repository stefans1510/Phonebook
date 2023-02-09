#include "PhonebookManager.h"
#include <fstream>
#include <iostream>

void PhonebookManager::loadContacts(string fileName) {
	ifstream file(fileName);
	if (!file.is_open()) {
		throw runtime_error("Unable to open file");
	}
	string line;
	while (getline(file, line)) {
		size_t pos = line.find(",");
		string name = line.substr(0, pos);
		string phoneNumber = line.substr(pos + 1);
		Contact contact(name, phoneNumber);
		contacts.push_back(contact);
	}
	file.close();
}

void PhonebookManager::saveContacts(string fileName) {
	ofstream file(fileName);
	if (!file.is_open()) {
		throw runtime_error("Unable to open file");
	}
	for (Contact contact : contacts) {
		file << contact.getName() << ", " << contact.getPhoneNumber() << endl;
	}
	file.close();
}