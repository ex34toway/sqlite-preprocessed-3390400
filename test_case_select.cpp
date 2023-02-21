#include "sqlite3.h"

#include <stdio.h>

int main(int argc, char** argv) {

	int  rc;
	sqlite3* pdb;

	const char* sql = "select mc.id,mc.name,mc.config->> 'type' as customer_type,mc.config,a.version as last_sync_version,a.create_time as last_sync_time from mapper_customer mc join (select mcv.version,mcv.customer_id,mcv.create_time from mapper_customer_version mcv where mcv.version in (select max(version) from mapper_customer_version where customer_id = mcv.customer_id)) a  on a.customer_id = mc.id order by mc.id asc";

	rc = sqlite3_open("test.db", &pdb);
	if (rc == SQLITE_OK) {
		sqlite3_stmt* stmt_handler;
		rc = sqlite3_prepare_v2(pdb, sql, -1, &stmt_handler, NULL);
		if (rc == SQLITE_OK) {
			while ((rc = sqlite3_step(stmt_handler)) == SQLITE_ROW)
			{
				int idType = sqlite3_column_type(stmt_handler, 1);
				const unsigned char* id = sqlite3_column_text(stmt_handler, 1);
				printf("%d %s\n", idType, id);
			}
			sqlite3_finalize(stmt_handler);
		}
		sqlite3_close(pdb);
	}
	return 0;
}
