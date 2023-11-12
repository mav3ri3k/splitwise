#include "Expense.h"

#include <forward_list>

using namespace std;

class Group {
  forward_list<Expense> expenses;
  forward_list<Person> participants;
};
