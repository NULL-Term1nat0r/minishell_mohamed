
#include "../minishell.h"

char  *ft_get_user_path(char *path)
{
	char *user_path1;
	char *user_path2;
	char *user_path3;
	char **cwd;

	cwd = ft_split(path, '/');
	user_path1 = ft_strjoin("/", cwd[0]);
	user_path2 = ft_strjoin(user_path1 , "/");
	user_path3 = ft_strjoin(user_path2, cwd[1]);
	free(user_path1);
	free(user_path2);
	ft_free_dstr(cwd);
	return (user_path3);
}

void ft_unset_env(t_env **head_ref, char *env_variable)
{
	t_env *search_node;
	t_env *previous_node;

	printf("check unset_env\n");

	search_node = get_env_node(*head_ref, env_variable);
	if (search_node == NULL)
		return;
	previous_node = find_previous_node(*head_ref, search_node);
	if (search_node == *head_ref)
		*head_ref = (*head_ref)->next;
	else
		previous_node->next = search_node->next;
	free(search_node->string);
	free(search_node);
}

void ft_unset_export(t_env **head_ref, char *env_variable)
{
	t_env *search_node;
	t_env *previous_node;

	printf("check unset_export\n");

	search_node = get_env_node(*head_ref, env_variable);
	if (search_node == NULL)
		return;
	previous_node = find_previous_node(*head_ref, search_node);
	if (search_node == *head_ref)
		*head_ref = (*head_ref)->next;
	else
		previous_node->next = search_node->next;
	free(search_node->string);
	free(search_node);
}

t_env *ft_get_env_node(t_env *head_ref, char *search)
{
	int n;
	t_env *current;

	if (!(head_ref))
		return NULL;
	while (current->next != NULL)
	{
		if (!ft_strcmp(current->var, search))
			return (current);
		current = current->next;
	}
	return (NULL);
}

void ft_change_string_at_envPath(t_ms *depot, char *search, char *new_string)
{
	t_env *node;
	char *new_path_string;

	node = ft_get_env_node(depot, search);
	node->value = ft_strdup(new_string);
}
char *ft_strncpy(char *source, char c)
{
	int 	i;
	int		j;
	int 	len;
	int n;
	char 	*new_string;

	len = ft_strlen(source);
	new_string = (char *)malloc(sizeof(char) * len);
	i = len;
	n = 0;
	j = 0;
	while (source[i - 1] != c)
	{
		n++;
		i--;
	}
	i = len - n - 1;
	while (i >= 0)
	{
		new_string[j] = source[j];
		i--;
		j++;
	}
	new_string[j] = '\0';
	return (new_string);
}

int ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2)) {
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

char *ft_get_new_path(t_env *head_ref)
{
	char *s;
	int i;
	int len;
	char *tmp;
	t_env *node;

	node = ft_get_env_node(head_ref, "PWD");
	len = ft_strlen(node->value);
	while (node->value)
	return (s);
}

//char	*get_folder_path(t_ms *depot)
//{
//	char	**path_folder;
//	char	*command;
//	char	*path_build;
//	char	*command_path;
//	int		i;
//
//	i = 0;
//	path_folder = get_env_path("PWD", 3, depot->ms_env);
//	free(command);
//	while (path_folder[i])
//	{
//		path_build= ft_strjoin("/", path_folder[i]);
//		command_path = ft_strjoin(path_folder[i++], command_built);
//		if (access(command_path, F_OK | X_OK) == 0)
//		{
//			ft_free_char_array(path_folder);
//			free(command_built);
//			return (command_path);
//		}
//		free(command_path);
//	}
//	ft_free_char_array(path_folder);
//	free(command_built);
//	return (NULL);
//}
//
//char	**get_command_arguments(char *arg)
//{
//	char	**arguments;
//
//	arguments = ft_split(arg, ' ');
//	return (arguments);
//}
