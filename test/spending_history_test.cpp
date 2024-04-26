#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

#include "spending_history.h"

using namespace std;

TEST_CASE("Database is initialized correctly")
{
    SpendingHistory history;
    history.addReceipt(Company("Vinder",        "Livermore"),     Money(100));
    history.addReceipt(Company("Wikibox",       "San Jose"),      Money(200));
    history.addReceipt(Company("Tagcat",        "Cupertino"),     Money(300));
    history.addReceipt(Company("Thoughtbridge", "Milpitas"),      Money(400));
    history.addReceipt(Company("Wikibox",       "San Jose"),      Money(500));
    history.addReceipt(Company("Kazu",          "Pleasant Hill"), Money(600));
    history.addReceipt(Company("Thoughtbridge", "Milpitas"),      Money(700));

    vector<TotalSpent> totals = history.getTotals();
    REQUIRE(totals.size() == 5);
    REQUIRE(totals[0] == TotalSpent(Company("Thoughtbridge", "Milpitas"),      Money(1100)));
    REQUIRE(totals[1] == TotalSpent(Company("Wikibox",       "San Jose"),      Money(700)));
    REQUIRE(totals[2] == TotalSpent(Company("Kazu",          "Pleasant Hill"), Money(600)));
    REQUIRE(totals[3] == TotalSpent(Company("Tagcat",        "Cupertino"),     Money(300)));
    REQUIRE(totals[4] == TotalSpent(Company("Vinder",        "Livermore"),     Money(100)));
}
