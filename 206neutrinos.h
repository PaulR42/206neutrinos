/*
** 206neutrinos.h for . in /home/rollan_e/Projet/206neutrinos
** 
** Made by Paul Rolland
** Login   <rollan_e@epitech.net>
** 
** Started on  Tue May  5 14:23:29 2015 Paul Rolland
** Last update Sun May 10 19:53:26 2015 Paul Rolland
*/

#ifndef _206NEUTRINOS_H_
# define _206NEUTRINOS_H_

typedef struct s_value
{
  double	nbMesure;
  double	Amoy;
  double	Hmoy;
  double	Qmoy;
  double	ecart;
}		t_value;

void	aff_value(t_value *);
double	a_moy(double, double, double);
double	h_moy(double, double, double);
double	q_moy(double, double, double, double);
double	calc_ecart(double, double, double, double, double);

#endif /* !_206NEUTRINOS_H_ */
