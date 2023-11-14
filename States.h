#include "Contacts.h"
#include "Groups.h"
#include <string>
#include <vector>
using namespace std;

class States {
  Contacts contacts;
  Groups groups;

  string format(string s) {
    for (int i = 0; i < s.length(); i++) {
      s[i] = tolower(s[i]);
    }

    return s;
  }

public:
  vector<string> states = {"main", "contacts", "groups", "group", "expense"};
  string state;
  string listItem;

  vector<string> nextMain = {states[1], states[2]};
  vector<string> nextContacts = {states[0]};
  vector<string> nextGroups = {states[0], states[3]};
  vector<string> nextGroup = {states[2], states[4]};
  vector<string> nextExpense = {states[3]};

  vector<string> actionMain = {};
  vector<string> actionContacts = {"Add", "Delete", "View"};
  vector<string> actionGroups = {"Add", "Delete", "View"};
  vector<string> actionGroup = {"Add", "Delete", "View"};
  vector<string> actionExpense = {"Add", "Delete", "View"};

  States() {
    state = states[0];
    contacts = Contacts();
    groups = Groups();
  }

  string currentState() { return state; }

  string stateName() {
    if (state == states[3] || state == states[4]) {
      return listItem;
    } else {
      return state;
    }
  }

  vector<string> &nextViableStates() {
    if (state == states[0]) {
      return nextMain;
    } else if (state == states[1]) {
      return nextContacts;
    } else if (state == states[2]) {
      return nextGroups;
    } else if (state == states[3]) {
      return nextGroup;
    } else {
      return nextExpense;
    }
  }

  vector<string> &actionsAvailable() {
    if (state == states[0]) {
      return actionMain;
    } else if (state == states[1]) {
      return actionContacts;
    } else if (state == states[2]) {
      return actionGroups;
    } else if (state == states[3]) {
      return actionGroup;
    } else {
      return actionExpense;
    }
  }

  bool changeStateTo(string nextState) {
    bool allowed = false;
    for (string state : nextViableStates()) {
      if (state == nextState) {
        allowed = true;
      }
    }

    if (allowed) {
      state = nextState;
      return true;
    } else {
      return false;
    }
  }

  bool doAction(string action) {
    action = format(action);

    if (state == states[1]) {
      if (action == format(actionContacts[0])) {
        contacts.addPerson();
        return true;
      } else if (action == format(actionContacts[1])) {
        return true;
      } else if (action == format(actionContacts[2])) {
        contacts.viewContacts();
        return true;
      }
      return false;
    } else if (state == states[2]) {
      if (action == format(actionGroups[0])) {
        groups.addGroup();
        return true;
      } else if (action == format(actionGroups[1])) {
        return true;
      } else if (action == format(actionGroups[2])) {
        groups.viewGroups();
        return true;
      }
      return false;
    }

    return false;
  }

  bool moveToList(string item) {
    item = format(item);

    if (state == states[2]) {
      bool present = false;
      for (string name : groups.groupsNames()) {
        if (name == item) {
          present = true;
        }
      }

      if (!present) {
        return false;
      }
      if (changeStateTo(states[3])) {
        listItem = item;
        return true;
      } else {
        return false;
      }
      return false;
    } else if (state == states[3]) {
      bool present = false;
      return true;
    }

    return false;
  }
};
