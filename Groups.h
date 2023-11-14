#include "Group.h"
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Groups {

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

  static bool comparator(const Group &a, const Group &b) {
    return format(a.name) < format(b.name);
  }

public:
  vector<Group> groups;

  Group &refGroup(string name) {
    bool found = false;
    for (Group &group : groups) {
      if (group.name == name) {
        found = true;
        return group;
      }
    }
    return groups[0];
  }

  vector<string> groupsNames() {
    sortList();
    vector<string> names;
    for (Group group : groups) {
      names.push_back(group.name);
    }

    return names;
  }

  string addGroup() {
    string name;
    cout << "Name: ";
    cin >> name;

    if (name == "group") {
      throw 1;
    }
    name = formatName(name);

    groups.push_back(Group(name));

    cout << "New Group " << formatName(name) << " added" << endl;

    return name;
  }

  void viewGroups() {
    sortList();

    if (!groups.empty()) {
      cout << "Groups created: " << endl;
      for (Group group : groups) {
        cout << " - " << formatName(group.name);
        cout << endl;
      }
    } else {
      cout << "No Groups created yet" << endl;
    }
  }

  void sortList() { sort(groups.begin(), groups.end(), comparator); }
};
