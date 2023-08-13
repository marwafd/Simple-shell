#include "shell.h"

/**
	 * exit_shell - exits the shell
	* @info: Structure containing potential arguments. Used to maintain
	* constant function prototype.
	* Return: exits with a given exit status
	* (0) if info.argv[0] != "exit"
*/
int _myexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		exitcheck = err_atoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			err_print(info, "Illegal number: ");
			_puts(info->argv[1]);
			_putchar('\n');
			return (1);
		}
		info->err_num = err_atoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
	* my_cd - changes the current directory of the process
	* @info: Structure containing potential arguments. Used to maintain
	* constant function prototype.
	* Return: Always 0
*/
int my_cd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenviron(info, "HOME=");
		if (!dir)
			chdir_ret = chdir((dir = _getenviron(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenviron(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenviron(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = chdir((dir = _getenviron(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		err_print(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenviron(info, "OLDPWD", _getenviron(info, "PWD="));
		_setenviron(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
	* my_help - changes the current directory of the process
	* @info: Structure containing potential arguments. Used to maintain
	* constant function prototype.
	* Return: Always 0
*/
int my_help(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); 
	return (0);
}

