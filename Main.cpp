#include "Color.h"
#include "Group.h"
#include "States.h"
#include <cctype>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

string format(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (i == 0) {
      s[i] = toupper(s[i]);
    } else {
      s[i] = tolower(s[i]);
    }
  }

  return s;
}

string lower(string s) {
  for (int i = 0; i < s.length(); i++) {
    s[i] = tolower(s[i]);
  }

  return s;
}

int main() {
  Color::Modifier red(Color::FG_RED);
  Color::Modifier def(Color::FG_DEFAULT);

  States states = States();
  while (true) {
    cout << red << format(states.state) << "> " << def;

    string input;
    cin >> input;
    input = lower(input);

    if (input == "help") {
      cout << "Currently in " << red << format(states.state) << def << " menue."
           << endl
           << endl;
      cout << "Option available: " << endl;
      for (string nextState : states.nextViableStates()) {
        cout << " - " << format(nextState) << endl;
      }

      if (!states.actionsAvailable().empty()) {
        cout << endl;
        cout << "Commands available: " << endl;
        for (string commands : states.actionsAvailable()) {
          cout << " - " << commands << endl;
        }
      }
      cout << endl;
    } else if (input == "exit") {
      cout << "Bye "
           << "\uf25b";
      exit(0);
    } else {
      if (states.changeStateTo(input)) {
        cout << "Moved to " << input << endl;
      } else if (states.doAction(input)) {
      } else {
        cout << red << "Wrong Command!!" << def << endl;
      }
    }
  }
}
