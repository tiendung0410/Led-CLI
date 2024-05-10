#include "cli_command.h"
#include <string.h>
#include "response_ci.h"
#include "cli_types.h"

extern const cli_command_entry_t  command_entry_table[];



const cli_command_entry_t* find_command_entry(char *cmd)
{
	uint8_t index =0;
	while(command_entry_table[index].command_infor != NULL)
	{
	  if(strcmp(command_entry_table[index].name,cmd)==0)
		{
			return &command_entry_table[index];
		}	
		index++;
	}
	return NULL;
}
void cli_command_excute(char *uart_buff,uint8_t len)
{
  	char *argv[10];
		uint8_t arg_num =0;
		
		char * pch;
		pch = strtok (uart_buff," ");
		
		while (pch != NULL)
		{
			argv[arg_num] = pch;
			pch = strtok (NULL, " ");
			arg_num++;
		}

		
		const cli_command_entry_t* command_entry = find_command_entry(argv[0]);
		if(command_entry!=NULL)
		{
			command_entry->command_infor->function(argv,arg_num);
		}
		else
		{
			response_print("can no find command\n");
		}
}

