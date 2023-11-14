#include "People.h"
#include "Split.h"
#include <algorithm>
#include <cctype>
#include <forward_list>
#include <pstl/glue_execution_defs.h>
#include <string>
#include <vector>

using namespace std;

class Expense {
private:
  static bool comparator(const SplitPerson &a, const SplitPerson &b) {
    return a.name < b.name;
  }

  string format(string s) {
    for (int i = 0; i < s.length(); i++) {
      s[i] = tolower(s[i]);
    }

    s[0] = toupper(s[0]);

    return s;
  }

public:
  float myCost;
  float totalCost;
  string description;
  vector<SplitPerson> participants = {};

  Expense() {}

  void addExpense() {
    cout << "Add names of Participants and their cost: " << endl;
    cout << "Your split: Rs.";
    float myCost;
    cin >> myCost;
    this->myCost = myCost;
    totalCost += myCost;

    while (true) {
      string name;
      cout << "Name/n: ";
      cin >> name;

      if (name == "n" || name == "N") {
        break;
      } else {
        float split;
        cout << format(name) << "'s split: Rs.";
        cin >> split;
        totalCost += split;

        participants.push_back(SplitPerson(name, split));
      }
    }
    string des;
    cout << "Expense description: ";
    cin >> des;
    this->description = des;

    cout << "Expense Added" << endl;
  }
  void sortList() {
    sort(participants.begin(), participants.end(), comparator);
  }
};
