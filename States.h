#include <string>

using namespace std;

class States {
  string states[4] = {"main", "contacts", "groups", "exactGroup"};
  string state;

  string nextMain[2] = {states[1], states[2]};
  string nextContacts[1] = {states[0]};
  string nextGroups[2] = {states[0], states[3]};
  string nextExactGroup[1] = {states[2]};

  States() { state = states[0]; }

  string currentState() { return state; }

  string *nextViableStates() {
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
};
