#include "header_solong/fonction.h"
#include "header_solong/player.h"

// int in_life_solong(t_player *player)
// {
// 	if (player->health > 0)
// 		return (1);
// 	return (0);
// }

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_exit_error(char* message)
{
	ft_printf("%s\n", message);
	exit(1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
