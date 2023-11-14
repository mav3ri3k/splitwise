#include <string>
#include <vector>
using namespace std;

class States {
public:
  vector<string> states = {"main", "contacts", "groups", "exactGroup"};
  string state;

  vector<string> nextMain = {states[1], states[2]};
  vector<string> nextContacts = {states[0]};
  vector<string> nextGroups = {states[0], states[3]};
  vector<string> nextExactGroup = {states[2]};

  vector<string> actionMain = {};
  vector<string> actionContacts = {"Add Contact", "Delete Contact",
                                   "View Contacts"};
  vector<string> actionGroups = {"Add Group", "Delete Group", "View Groups"};
  vector<string> actionExactGroup = {"None"};

  States() { state = states[0]; }

  string currentState() { return state; }

  vector<string> &nextViableStates() {
    if (state == states[0]) {
      return nextMain;
    } else if (state == states[1]) {
      return nextContacts;
    } else if (state == states[2]) {
      return nextGroups;
    } else {
      return nextExactGroup;
    }
  }

  vector<string> &actionsAvailable() {
    if (state == states[0]) {
      return actionMain;
    } else if (state == states[1]) {
      return actionContacts;
    } else if (state == states[2]) {
      return actionGroups;
    } else {
      return actionExactGroup;
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
};
