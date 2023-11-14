#include "People.h"
#include <cctype>
#include <forward_list>
#include <iostream>
#include <string>

using namespace std;

class Contacts : public People {
private:
  static string format(string s) {
    for (int i = 0; i < s.length(); i++) {
      s[i] = tolower(s[i]);
    }

    return s;
  }

  string formatName(string s) {
    for (int i = 0; i < s.length(); i++) {
      s[i] = tolower(s[i]);
    }
    s[0] = toupper(s[0]);

    return s;
  }

  static bool comparator(const Person &a, const Person &b) {
    return format(a.name) < format(b.name);
  }

  bool add(Person person) {
    people.push_front(person);
    return true;
  }

  bool remove(Person person) {
    // people.remove(person);
    return true;
  }

public:
  forward_list<Person> people;
  bool isSorted;

  Person *retrieveName(string name) {
    forward_list<Person>::iterator itr = people.begin();

    while (itr != people.end()) {
      if (itr->name == name) {
        return &(*itr);
      }
    }

    return nullptr;
  }

  void addPerson() {
    string name;
    bool isFriend;

    cout << "Name: ";
    cin >> name;
    name = formatName(name);

    char c;
    cout << "Favourite(Y/n): ";
    cin >> c;

    if (c == 'y' || c == 'Y') {
      isFriend = true;
    } else {
      isFriend = false;
    }

    add(Person(name, isFriend, false));
  }

  void viewContacts() {
    sortList();

    if (!people.empty()) {
      cout << "People in Contacts: " << endl;
      for (Person person : people) {
        cout << " - " << person.name;

        if (person.isFriend) {
          cout << " \uf41e";
        }
        cout << endl;
      }
    } else {
      cout << "Oops!! Make few friends first!!" << endl;
    }
  }

  void sortList() { people.sort(comparator); }
};
