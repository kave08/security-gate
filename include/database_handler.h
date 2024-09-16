#ifndef DATABASE_HANDLER_H
#define DATABASE_HANDLER_H

MYSQL *connect_to_mysql(void);
void save_fingerprint_data(MYSQL *db_conn, fp_print_data_t *print);

#endif // DATABASE_HANDLER_H
