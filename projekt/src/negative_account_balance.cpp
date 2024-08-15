#include "negative_account_balance.h"
#include <string>

NegativeAccountBalance::NegativeAccountBalance(int wrong_account_balance):
std::invalid_argument("Negative value of the account" + std::to_string(wrong_account_balance)){}

