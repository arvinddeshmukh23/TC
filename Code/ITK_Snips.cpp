//Sample functions
//login
int ITK_user_main(int argc, char* argv[])
{
	int iFail = ITK_ok;

	char *users_id, *users_password, *users_group;
	
	users_id = ITK_ask_cli_argument("-u=");
	users_password = ITK_ask_cli_argument("-p=");
	users_group = ITK_ask_cli_argument("-g=");
	iFail = ITK_init_module(users_id, users_password, users_group);

	printf("Login Status : %d", iFail);
	TC_write_syslog("Login Status : %d", iFail);

	return iFail;
}
