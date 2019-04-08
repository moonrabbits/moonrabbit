#include "command_handling.h"

int change_dir(char** p_cwd, char* dir_name)
{
/*
    strcat(*p_cwd, "/");
    strcat(*p_cwd, dir_name);
*/
	strcpy(*p_cwd,dir_name);
	/* return 0 if the specified dir is not valid*/
    return 1;
}

int make_dir(char* cwd, char* dir_name)
{
    return 1;
}

int delete_file(char *cwd, char *file_name)
{
    return 1;
}

int open_shell(char *cwd)
{
/*
	char command[6+1+strlen(cwd)];
	strcpy(command,"$SHELL");
	strcat(command, " ");
	strcat(command, cwd);
*/
	system("$SHELL -i -c urxvt");
	return 1;
}

int handle_cmd(char *input, char** p_cwd)
{
/* 
 * separate command and arguments
 * put args into vector
 * depending on the command call appropriate function from above
 */

	/* separate command and arguments*/
	int split_index = 0;
	for (int i = 0; i < strlen(input); i++) 
		if (input[i] == ' ')
			split_index = i;
	
	/*make command variable */
	char cmd[split_index];
	for (int i = 0; i < split_index; i++)
		cmd[i] = input[i];

	/* make args var */
	int arg_len = strlen(input) - split_index;
	char args[arg_len];
	for (int i = 0; i < arg_len; i++)
		args[i] = input[split_index+1+i];

	/* appropriate function call */
	if ( !strcmp(cmd, "cd") ) {
		change_dir(p_cwd,args);
	}
		
		

	return 1;
}


















