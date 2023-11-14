#include "Color.h"
#include "Contacts.h"
#include "Group.h"
#include "cli/cli.h"
#include <string>

using namespace std;

int main() {
  Color::Modifier red(Color::FG_RED);
  Color::Modifier def(Color::FG_DEFAULT);

  string states[3] = {"main", "contacts", "groups"};
  string state = states[0];

  while (true) {

    cout << red << state << "> " << def;
    string choice;
    cin >> choice;

    if (choice == "contacts") {
      state = states[1];
    } else if (choice == "Gropus") {
      state = states[2];
    } else {
      cout << "Wrong choice" << endl;
    }
  }
}
