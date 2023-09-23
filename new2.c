#include "main.h"

/**
 * displayCommandHistory - Displays the command history list with line numbers.
 * @commandInfo: Structure containing potential arguments.
 * Return: Always 0.
 */
int displayCommandHistory(CommandInfoStruct *commandInfo)
{
    print_text_list(commandInfo->command_history);
    return (0);
}

/**
 * unsetCommandAlias - Unsets an alias for a command.
 * @commandInfo: Parameter struct.
 * @str: The string alias.
 * Return: Always 0 on success, 1 on error.
 */
int unsetCommandAlias(CommandInfoStruct *commandInfo, char *text)
{
    char *equals_sign, temp_char;
    int ret;

    equals_sign = custom_strchr(text, '=');
    if (!equals_sign)
        return (1);
    temp_char = *equals_sign;
    *equals_sign = 0;
    ret = delete_n_by_index(&(commandInfo->command_aliases),
                               get_node_with_index(commandInfo->command_aliases, node_with(commandInfo->command_aliases, text, -1)));
    *equals_sign = temp_char;
    return (ret);
}

/**
 * setCommandAlias - Sets an alias for a command.
 * @commandInfo: Parameter struct.
 * @str: The string alias.
 * Return: Always 0 on success, 1 on error.
 */
int setCommandAlias(CommandInfoStruct *commandInfo, char *text)
{
    char *equals_sign;

    equals_sign = custom_strchr(text, '=');
    if (!equals_sign)
        return (1);
    if (!*++equals_sign)
        return (unsetCommandAlias(commandInfo, text));

    unsetCommandAlias(commandInfo, text);
    return (append_list_node(&(commandInfo->command_aliases), text, 0) == NULL);
}

/**
 * printCommandAlias - Prints an alias for a command.
 * @node: The alias node.
 * Return: Always 0 on success, 1 on error.
 */
int printCommandAlias(list_t *node)
{
    char *equals_sign = NULL, *alias = NULL;

    if (node)
    {
        equals_sign = custom_strchr(node->text, '=');
        for (alias = node->text; alias <= equals_sign; alias++)
            _print(*alias);
        _print('\'');
        _print(equals_sign + 1);
        _print("'\n");
        return (0);
    }
    return (1);
}

/**
 * myAlias - works like the alias builtin (man alias).
 * @commandInfo: Structure containing potential arguments.
 * Return: Always 0.
 */
int myAlias(CommandInfoStruct *commandInfo)
{
    int i = 0;
    char *equals_sign = NULL;
    list_t *node = NULL;

    if (commandInfo->argument_count == 1)
    {
        node = commandInfo->command_aliases;
        while (node)
        {
            printCommandAlias(node);
            node = node->next;
        }
        return (0);
    }
    for (i = 1; commandInfo->arguments_list[i]; i++)
    {
        equals_sign = custom_strchr(commandInfo->arguments_list[i], '=');
        if (equals_sign)
            setCommandAlias(commandInfo, commandInfo->arguments_list[i]);
        else
            printCommandAlias(node_starts_with(commandInfo->command_aliases, commandInfo->arguments_list[i], '='));
    }

    return (0);
}
