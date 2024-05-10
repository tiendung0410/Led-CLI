#ifndef CLI_TYPES_H
#define CLI_TYPES_H
#include <stdint.h>

typedef void (*cli_comand_func_t)(char **argv,uint8_t arg_num);

typedef struct 
{
  cli_comand_func_t function;             
  char                   *help;        
}cli_command_info_t;

typedef struct 
{
  const char                  *name;     
  const cli_command_info_t *command_infor;    
}cli_command_entry_t;
#endif
