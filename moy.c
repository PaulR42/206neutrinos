/*
** moy.c for . in /home/rollan_e/rendu/206neutrinos
** 
** Made by Paul Rolland
** Login   <rollan_e@epitech.net>
** 
** Started on  Sun May 10 19:51:20 2015 Paul Rolland
** Last update Sun May 10 19:54:02 2015 Paul Rolland
*/

#include <stdio.h>
#include <math.h>
#include "206neutrinos.h"

void	aff_value(t_value *value)
{
  printf("antal malinder :        %0.0f\n", value->nbMesure);
  printf("standardafvilgelse :    %0.2f\n", value->ecart);
  printf("aritmetisk gennemsnit : %0.2f\n", value->Amoy);
  printf("kvadratisk gennemsnit : %0.2f\n", value->Qmoy);
  printf("harmonisk gennemsnit :  %0.2f\n\n", value->Hmoy);
  return ;
}

double		a_moy(double nbMesure, double Amoy, double mesure)
{
  double	res;

  res = ((nbMesure * Amoy) + mesure) / (nbMesure + 1.0);
  return (res);
}

double		h_moy(double nbMesure, double Hmoy, double mesure)
{
  double	res;

  res = (nbMesure + 1) / ((1 / mesure) + (nbMesure / Hmoy));
  return (res);
}

double		q_moy(double nbMesure, double mesure, double Amoy, double ecart)
{
  double	res;

  res = (powf(ecart, 2) + powf(Amoy, 2)) * nbMesure;
  res = res + powf(mesure, 2);
  res = res / (nbMesure + 1);
  res = sqrt(res);
  return (res);
}

double		calc_ecart(double nbMesure, double ecart, double Amoy, double mesure, double newAmoy)
{
  double	res;

  res = (powf(ecart, 2) + powf(Amoy, 2)) * nbMesure;
  res = res + powf(mesure, 2);
  res = res / (nbMesure + 1);
  res = res - powf(newAmoy, 2);
  res = sqrt(res);
  return (res);
}
