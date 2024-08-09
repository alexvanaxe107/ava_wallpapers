#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <sqlite3.h>

namespace wal {
  class DatabaseManager {
    public:
      bool open();
      void insert(std::string query);

    private:
      sqlite3 *db;
  };
}
#endif /* ifndef DATABASE_H */
