#include "Contacts.h"
#include "Groups.h"
#include <string>
#include <vector>
using namespace std;

class States {
  Groups groups;

  string format(string s) {
    for (int i = 0; i < s.length(); i++) {
      s[i] = tolower(s[i]);
    }

    return s;
  }

public:
  vector<string> states = {"groups", "group", "expense"};
  string state;
  string listItem;

  vector<string> nextGroups = {states[0], states[3]};
  vector<string> nextGroup = {states[2], states[4]};
  vector<string> nextExpense = {states[3]};

  vector<string> actionGroups = {"Add", "Delete", "View"};
  vector<string> actionGroup = {"Add", "Delete", "View"};
  vector<string> actionExpense = {"Add", "Delete", "View"};

  States() {
    state = states[0];
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
      return nextGroups;
    } else if (state == states[1]) {
      return nextGroup;
    } else {
      return nextExpense;
    }
  }

  vector<string> &actionsAvailable() {
    if (state == states[0]) {
      return actionGroups;
    } else if (state == states[1]) {
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

    if (state == states[0]) {
      if (action == format(actionGroup[0])) {
        Group &grp = groups.refGroup(action);
        grp.addExpense();
        return true;
      } else if (action == format(actionGroup[1])) {

        return true;
      } else if (action == format(actionGroup[2])) {
        Group &grp = groups.refGroup(action);
        grp.viewExpenses();
        return true;
      }
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
