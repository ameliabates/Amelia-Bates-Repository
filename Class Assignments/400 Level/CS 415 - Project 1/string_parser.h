typedef struct {
	int int_commands;
	char *command_array[20];
} parseing;

parseing *parser_string(char *input);
void command_execution(parseing *commands);
void free_command(parseing *commands);
