#include "sqlite3.h"

#include <stdio.h>

int main(int argc, char** argv) {

	int  rc, nCol;
	sqlite3* pdb;

	const char* sql = "select * from Opcodes where Desc like 'ResultRow'";
	rc = sqlite3_open("test.db", &pdb);
	if (rc == SQLITE_OK) {
		sqlite3_stmt* stmt_handler;
		rc = sqlite3_prepare_v2(pdb, sql, -1, &stmt_handler, NULL);
		if (rc == SQLITE_OK) {
			nCol = sqlite3_column_count(stmt_handler);
			while ((rc = sqlite3_step(stmt_handler)) == SQLITE_ROW)
			{
				for (size_t i = 0; i < nCol; i++)
				{
					const unsigned char* val = sqlite3_column_text(stmt_handler, i);
					printf("%s\t", val);
				}
				printf("\n");
			}
			sqlite3_finalize(stmt_handler);
		}
		sqlite3_close(pdb);
	}
	return 0;
}
