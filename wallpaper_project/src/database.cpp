#include "database.h"

#include <iostream>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

bool wal::DatabaseManager::open() {
  int rc;
  rc = sqlite3_open("/home/alexvanaxe/wal/test.db", &db);

  if (rc) {
    std::cout << "Error, could not open the database \n" << sqlite3_errmsg(db);
    return false;
  }

  return true;
}

void wal::DatabaseManager::insert(std::string query) {
  char *zErrMsg = 0;
  int rc;
  rc = sqlite3_exec(db, query.c_str(), callback, 0, &zErrMsg);
}
