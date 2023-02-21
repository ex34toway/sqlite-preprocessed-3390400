#include "sqlite3.h"

#include <stdio.h>

int main(int argc, char** argv) {
	char** result;
	int  row, colum, rc;
	sqlite3* pdb;
	char* message;

	const char* sql = "select mc.id,mc.name,mc.config->> 'type' as customer_type,mc.config,a.version as last_sync_version,a.create_time as last_sync_time from mapper_customer mc join (select mcv.version,mcv.customer_id,mcv.create_time from mapper_customer_version mcv where mcv.version in (select max(version) from mapper_customer_version where customer_id = mcv.customer_id)) a  on a.customer_id = mc.id order by mc.id asc";

	rc = sqlite3_open("test.db", &pdb);
	if (rc == SQLITE_OK) {
		rc = sqlite3_get_table(pdb, sql,
			&result, &row, &colum, &message);
		if (rc == SQLITE_OK) {
			for (int i = 0; i <= row; i++) {
				for (int j = 0; j < colum; j++) {
					printf("%s|", *(result + colum * i + j));
				}
				printf("\n");
			}
		}
		sqlite3_close(pdb);
	}
	return 0;
}
