/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>
#include <string>
#include "mysqlx/xdevapi.h"

using namespace std;
using namespace mysqlx;
int main(void)
{
  cout << endl;
  // connecto to mysql using root user and password root
  std::string url = "mysqlx://root:root@localhost:33060";
  Session session = Session(url);
  // set the schema mytest
  Schema mytest = session.getSchema("mytest");
  // list databases
  cout << "List of databases:" << endl;
  for (auto db : session.getSchemas())
  {
    cout << db.getName() << endl;
    cout << "\tList of tables:" << endl;

    for (auto table : db.getTables())
    {
      cout << "\t  - " << table.getName() << endl;
    }
  }

  return 0;
}