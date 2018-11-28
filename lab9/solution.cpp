#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

class Contact {
    private:
        string firstName, lastName, email, phoneNumber;

    public:
        Contact(string firstName, string lastName, string email, string phoneNumber) {
            this->firstName = firstName;
            this->lastName = lastName;
            this->email = email;
            this->phoneNumber = phoneNumber;
        }

        bool matches(string query) {
            return (query == firstName || query == lastName || query == phoneNumber);
        }

        string toString() { //no affiliation with any coffee-based languages
            return firstName + " " + lastName + " " + email + " " + phoneNumber;
        }
};

class ContactsBook {
    private:
        vector<Contact> contacts;
        string fileName;

        Contact _parseLine(string line) { //based off of the way we store on disk
            istringstream iss(line);
            string arr[4];
            for(int i = 0; i < 4; i++)
                iss >> arr[i];
            return Contact(arr[0], arr[1], arr[2], arr[3]); //firstName, lastName, email, phone
        }

        void _gatherContactInfoFromFile() {
            ifstream file(fileName.c_str());
            if(file) { //check to see if we have a file, if we do, pull info from it
                for(string line; getline(file, line);) {
                    contacts.push_back(_parseLine(line));
                }
            }
        }

    public:
        ContactsBook(string fileName) {
            this->contacts = vector<Contact>(); //start out by making our contacts empty
            this->fileName = fileName;
            _gatherContactInfoFromFile();
        }

        void addContact(Contact c) {
            contacts.push_back(c);
        }

        void showAllContacts() {
            for(int i = 0; i < contacts.size(); i++) { //for each only available in C++11 and up
                cout << contacts[i].toString() << endl;
            }
        }

        void writeToDisk() {
            ofstream f(fileName.c_str());
            for(int i = 0; i < contacts.size(); i++) {
                f << contacts[i].toString() << endl;
            }
        }

        string searchContacts(string query) {
            for(int i = 0; i < contacts.size(); i++) {
                if(contacts[i].matches(query))
                    return contacts[i].toString();
            }
            return "Sorry, no contact found";
        }
};

void printMenu() {
    cout << endl;
    cout << "Please select what you would like to do:" << endl;
    cout << "0: Add a contact" << endl;
    cout << "1: Search for a contact" << endl;
    cout << "2: Show all contacts" << endl;
    cout << "Anything else to save and quit" << endl;
    cout << endl;
}

int main() {
    ContactsBook book = ContactsBook("data.txt");

    cout << "Welcome to your contact list" << endl;
    char choice;

    while(true) {
        printMenu();
        cin >> choice;

        string firstName, lastName, email, phoneNumber, query;
        switch(choice) {
            case '0':
                cout << "First name of contact?" << endl;
                cin >> firstName;
                cout << "Last name of contact?" << endl;
                cin >> lastName;
                cout << "Email address of contact?" << endl;
                cin >> email;
                cout << "Phone number of contact?" << endl;
                cin >> phoneNumber;
                book.addContact(Contact(firstName, lastName, email, phoneNumber));
                break;
            case '1':
                cout << "Enter the first name, last name, or phone number you want to search for:" << endl;
                cin >> query;
                cout << book.searchContacts(query) << endl;
                break;
            case '2':
                book.showAllContacts();
                break;
            default:
                book.writeToDisk();
                return 0;
        }
    }
}