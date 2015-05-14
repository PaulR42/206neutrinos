/*
** main.c for . in /home/rollan_e/Projet/206neutrinos
** 
** Made by Paul Rolland
** Login   <rollan_e@epitech.net>
** 
** Started on  Tue Apr 28 18:21:32 2015 Paul Rolland
** Last update Sun May 10 20:02:31 2015 Paul Rolland
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "206neutrinos.h"

int	my_strlen(char *str)
{
  int	i;
  
  i = 0;
  if (str)
    while (str[i])
      i++;
  return (i);
}

char	*my_strcat(char *s1, char *s2)
{
  char	*new;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((new = malloc(sizeof(char) * 
		    (my_strlen(s1) + my_strlen(s2) + 1))) == NULL)
    return (NULL);
  if (s1)
    while (s1[i])
      {
	new[i] = s1[i];
	i++;
      }
  free(s1);
  if (s2)
    while (s2[j])
      new[i++] = s2[j++];
  new[i] = '\0';
  return (new);
}

char	*get_next_line(int fd)
{
  char	*str;
  char	*buf;
  int	ret;

  str = NULL;
  write(1, "Indtast din vaerdi : ", 21);
  if ((buf = malloc(sizeof(char) * 2)) == NULL)
    return (NULL);
  memset(buf, 0, 2);
  while ((ret = read(fd, buf, 1)) > 0)
    {
      buf[1] = '\0';
      if (buf[0] == '\0' || buf[0] == '\n')
	return (str);
      str = my_strcat(str, buf);
      memset(buf, 0, 2);
    }
  if (ret == -1)
    return (NULL);
  return (str);
}

t_value		*init_value(char **av)
{
  t_value	*value;

  if ((value = malloc(sizeof(t_value))) == NULL)
    return (NULL);
  value->nbMesure = atof(av[0]);
  value->Amoy = atof(av[1]);
  value->Hmoy = atof(av[2]);
  value->ecart = atof(av[3]);
  if (value->nbMesure < 1 || value->Amoy < 0 || value->Hmoy < 0 || value->ecart < 0)
    {
      printf("Bad parameters\n.");
      return (NULL);
    }
  return (value);
}

int	check_buf(char *buf)
{
  int	i;

  i = 0;
  if (buf)
    while (buf[i])
      {
	if (!(buf[i] == '.' || (buf[i] >= '0' && buf[i] <= '9')))
	  {
	    printf("%s\n", "Bad entry. Authorized char => '[0-9]' '.'");
	    return (-1);
	  }
	i++;
      }
  else
    return (-1);
  return (0);
}

int	edit_value(t_value *value, char *buf)
{
  double	mesure;
  double	tmp;
  int		ret;

  if ((ret = check_buf(buf)) == -1)
    return (0);
  mesure = atof(buf);
  tmp = value->Amoy;
  value->Amoy = a_moy(value->nbMesure, value->Amoy, mesure);
  value->Hmoy = h_moy(value->nbMesure, value->Hmoy, mesure);
  value->Qmoy = q_moy(value->nbMesure, mesure, tmp, value->ecart);
  value->ecart = calc_ecart(value->nbMesure, value->ecart, tmp, mesure, value->Amoy);
  value->nbMesure++;
  return (0);
}

int	main(int ac, char **av)
{
  char		*buf;
  t_value	*value;

  if (ac != 5)
    {
      printf("Usage: ./206neutrinos [NbMesure] [AMoy] [HMoy] [Ecart-Type]\n");
      return (-1);
    }
  if ((value = init_value(&av[1])) == NULL)
    return (-1);
  while ((buf = get_next_line(0)) != NULL)
    {
      if (!strcmp(buf, "ende"))
	return (0);
      if (edit_value(value, buf) == -1)
	return (-1);
      aff_value(value);
      free(buf);
    }
  return (0);
}
