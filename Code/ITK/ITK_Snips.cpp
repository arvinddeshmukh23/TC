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
//create item with item name =item id and attaches in new stuff folder
void create_item (char *item_id, tag_t *new_item, tag_t *new_rev)
{
    char  type_name[ITEM_type_size_c + 1] = {""}, rev_id[ITEM_id_size_c + 1] = "A";
       
    printf("Creating Item ID: %s\n", item_id);
    ITEM_create_item( item_id, item_id, type_name, rev_id, new_item, new_rev);

    printf("Saving Item ID: %s\n", item_id);
    ITEM_save_item(*new_item);

    printf("Attaching Item ID: %s to Newstuff Folder\n", item_id);
    FL_user_update_newstuff_folder(*new_item);
}

void createWorflowOnItemRev(){
	tag_t rev = NULLTAG, process_template = NULLTAG,process = NULLTAG;
	int attach_types[1] = {1}; 
	int status = 0;
	//find itemrev on which you want apply workflow 
	status=ITEM_find_rev("000206", "A", &rev);
	//find template
	status=EPM_find_process_template("oneStepWithStatus", &process_template);
	//create workflow with template
	status=EPM_create_process("oneStepWithStatus", "oneStepWithStatus", process_template, 1, &rev, attach_types, &process) 
}
