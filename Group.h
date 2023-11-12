#include "Expense.h"

#include <forward_list>

// delete later
#include <iostream>

using namespace std;

class Group : public People {
  forward_list<Expense> expenses;
  forward_list<Person> participants;
};
