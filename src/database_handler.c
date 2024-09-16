#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "database_handler.h"

MYSQL *connect_to_mysql(void)
{
    MYSQL *conn = mysql_init(NULL);
    mysql_real_connect(conn, MYSQL_HOST, MYSQL_USER, MYSQL_PASSWORD, MYSQL_DB, 0, NULL, 0);
    if (conn == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(conn));
        exit(1);
    }
    return conn;
}

void save_fingerprint_data(MYSQL *db_conn, fp_print_data_t *print)
{
    char query[256];
    sprintf(query, "INSERT INTO users (fingerprints, photo_path) VALUES (?, ?)");
    mysql_query(db_conn, query);
    mysql_stmt_bind_param(stmt, &print->data);
    mysql_stmt_execute(stmt);
}
