#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>

static int callback(void* data, int argc, char** argv, char** azColName) {
  int i;
  fprintf(stderr, "%s: \n", (const char*)data);

  for (i = 0; i < argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }

  printf("\n");
  return 0;
}

int main(int argc, char* argv[]) {
  sqlite3* db      = nullptr;
  char* z_err_msg  = nullptr;
  int rc           = 0;
  char* sql        = nullptr;
  const char* data = "Callback function called";

  /* Open database */
  rc = sqlite3_open("test.db", &db);

  if (rc) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    return (0);
  }
  fprintf(stderr, "Opened database successfully\n\n");

  /* Create SQL statement */
  // sql = "SELECT * from COMPANY WHERE ID >= 3";

  sql =
    "DELETE from COMPANY where ID = 2;"
    "SELECT * from COMPANY";

  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql, callback, (void*)data, &z_err_msg);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", z_err_msg);
    sqlite3_free(z_err_msg);
  } else {
    fprintf(stdout, "Operation done successfully\n");
  }
  sqlite3_close(db);
  return 0;
}