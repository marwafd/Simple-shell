#include "shell.h"

/**
 * history - displays the history list, one command by line, preceded
 * with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int history(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * alias_unset - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */
int alias_unset(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchar(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_id(&(info->alias),get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * alias_set - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */
int alias_set(info_t *info, char *str)
{
	char *p;

	p = _strchar(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (alias_unset(info, str));

	alias_unset(info, str);
	return (add_node_end_ls(&(info->alias), str, 0) == NULL);
}

/**
 * alias_print - prints an alias string
 * @node: the alias node
 * Return: Always 0 on success, 1 on error
 */
int alias_print(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchar(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * mimics_alias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *  constant function prototype.
 *  Return: Always 0
 */
int mimics_alias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			alias_print(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchar(info->argv[i], '=');
		if (p)
		alias_set(info, info->argv[i]);
		else
			alias_print(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

