#include "database.h"

int main() {
  wal::DatabaseManager manager;
  bool result = manager.open();

  if (result) {
    std::string sql = "insert into test(name, age) values ('Ericao', 23);";

    manager.insert(sql);
  }
}
