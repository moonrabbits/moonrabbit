#include "input.h"

char* get_input(bool search_mode)
{
	char * command;
	command = malloc(sizeof(char) * 255);
	// clear info area and put your colon on display
	for (int i = 0; i < COLS-1; i++) {
		mvprintw(LINES-2,i, " ");
		mvprintw(LINES-1,i, " ");
	}
	if (search_mode) {
		mvprintw(LINES-1,0, "/");
	}
	else {
		mvprintw(LINES-1,0, ":");
	}

	// Turn terminal feedback on
	echo();
	nocbreak();

	// While char isn't ENTER, get char
	int c, read, cmd_index;
	read = 1;
	cmd_index = 0;
	
	while (read) {
		c = getch();
		switch (c) {
		case K_ENTER:
			read = 0;
			break;
		case K_BACKSPACE:
			command[cmd_index] = '\0';
			cmd_index--;
			break;
		default:
			command[cmd_index] = c;
			cmd_index++;
			command[cmd_index] = '\0';
			break;
		}
	}
	
	// Turn terminal feedback off again
	noecho();
	cbreak();
	return command;
}

// Print confirmation prompt for file deletion
bool confirm_deletion(int x_pos, int y_pos, int num_selected)
{
	mvprintw(x_pos, y_pos, "Delete selection? (y/N)", num_selected);
	char c = getch();
	if (c == 'y' || c == 'Y')
		return 1;
	else 
		return 0;
}