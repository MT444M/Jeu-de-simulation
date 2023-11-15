#pragma once
#ifndef DEF_FONCTION
#define DEF_FONCTION
#include "CImg.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <cmath>
#include <string>
#include "Jardinier.h"
#include "Plante.h"


using namespace std;

//=================Declaration des variables type plante===================
static const int TYPE_FLEUR = 1;
static const int TYPE_LEGUME = 2;
static const int TYPE_PLANTE_GRAIN = 3;


//========================affichage sans opacite=======================
/**
* @brief cette fonction permet de rendre transparent le background des images affichees 
* qui ont un font blanc.
* @param img image a rendre opaque.
* @return image, font transparent
*/
CImg<float> NO_opacite(CImg<unsigned char> img)
{

	CImg<float> opacite(img.width(), img.height(), 1, 1, 0);
	for (int x = 0; x < opacite.width(); ++x)
		for (int y = 0; y < opacite.height(); ++y)
			if (img(x, y, 0) == 255 and img(x, y, 1) == 255 and img(x, y, 2) == 255)
				opacite(x, y) = 0;
			else
				opacite(x, y) = 1;
	return opacite;
}


//========================calcul de distance euclidienne=======================

/**
* @brief Cette fonction calcule la distance euclidienne entre le jardinier 
* et la plante donnes en arguments.
* @return float distance
*/
double distance( Jardinier& j, Plante& p) 
{
    int dist_x = j.get_position_x() - p.get_position_x();
    int dist_y = j.get_position_y() - p.get_position_y();
    return sqrt(dist_x * dist_x + dist_y * dist_y);
}


//========================Mise a jour de la distance calcul=======================

/**
* @brief Cette fonction met a jour la matrice de distance entre les jardiniers et les 
* plantes selon le type de chaque jardinier et chaque plante.
* 
* @param vect_P Un vecteur de pointeurs de plantes.
* @param vect_J Un vecteur de jardiniers.
* @param M_dist Un tableau a deux dimensions contenant les distances entre les 
* jardiniers et les plantes.
* 
* 
* La fonction parcourt tous les jardiniers et met a jour la matrice de distance 
* en parcourant uniquement les plantes qui correspondent au type
* de jardinier (Graines pour les jardiniers de moral 3,
*  Legumes pour les jardiniers de moral 2 et Fleurs pour les jardiniers de moral 1).
* Si l'etat de pousse de la plante est 5, alors la distance entre la plante 
* et le jardinier est mise a jour dans la matrice.
*/
void UpdateDistance(vector<Plante*>& vect_P, vector<Jardinier>& vect_J, vector<vector<int>>& M_dist)
{
    // Pour chaque jardinier
    for (int i = 0; i < vect_J.size(); i++)
    {
        if (vect_J[i].get_moral() == 3) {
            // Parcours seulement les plantes de type "Plante_Grain"
            for (int j = 0; j < vect_P.size(); j++)
            {
                // Si la plante est en etat de recolte et si son type est "Plante_Grain"
                if (vect_P[j]->get_etat_pousse() == 5 && vect_P[j]->get_type() == TYPE_PLANTE_GRAIN)
                {
                    // Calcule la distance entre le jardinier et la plante
                    M_dist[i][j] = distance(vect_J[i], *vect_P[j]);
                }
            }
        }
        else if (vect_J[i].get_moral() == 2) {
            // Parcours seulement les plantes de type "Legume"
            for (int j = 0; j < vect_P.size(); j++)
            {
                if (vect_P[j]->get_etat_pousse() == 5 && vect_P[j]->get_type() == TYPE_LEGUME) 
                {
                    M_dist[i][j] = distance(vect_J[i], *vect_P[j]);
                }
            }
        }
        else if (vect_J[i].get_moral() == 1) {
            // Parcours seulement les plantes de type "Fleur"
            for (int j = 0; j < vect_P.size(); j++)
            {
                if (vect_P[j]->get_etat_pousse() == 5 && vect_P[j]->get_type() == TYPE_FLEUR)
                {
                    M_dist[i][j] = distance(vect_J[i], *vect_P[j]);
                }
            }
        }
    }
}


//======================== Mise a jour du cacul du trajet min=======================

/**
* @brief  Cette fonction met a jour la distance entre chaque plante et tous les 
* jardiniers et determine le jardinier et la plante associes a la distance minimale.
* 
* @param vect_P Un vecteur de pointeurs de plantes.
* @param vect_J Un vecteur de jardiniers.
* @param M_dist Une matrice de distances entre les jardiniers et les plantes.
*/
void trajet_jardinier_(vector<Plante*>& vect_P, vector<Jardinier>& vect_J)
{
    // Si le vecteur de plantes ou le vecteur de jardiniers est vide, on arrête la fonction
    if (vect_P.empty() || vect_J.empty()) return;

    // Initialisation de la matrice des distances
    vector<vector<int>> M_dist(vect_J.size(), vector<int>(vect_P.size(), INT_MAX));

    // Remplissage de la matrice des distances avec les distances 
    //entre chaque jardinier et chaque plante
    UpdateDistance(vect_P, vect_J, M_dist);

    // Variables pour stocker les positions de la plante et du jardinier
    int x_p = 0, y_p = 0, x_j = 0, y_j = 0;
    int p_m_p = 0, p_m_j = 0; // Position du jardinier associe a la distance minimale
    int min_d = INT_MAX; // Distance minimale initialisee a une valeur tres grande

    // Parcourt les plantes et trouve la distance minimale entre chaque plante et tous les jardiniers
    for (int i = 0; i < vect_J.size(); i++)
    {
        // Reinitialise la valeur de min_d a chaque iteration de la boucle externe
        int min_d = INT_MAX;
        // Parcours seulement les plantes de type "Plante_Grain" si le moral du jardinier est egal a 3
        if (vect_J[i].get_moral() == 3)
        {
            for (int j = 0; j < vect_P.size(); j++)
            {
                if (vect_P[j]->get_type() == TYPE_PLANTE_GRAIN && M_dist[i][j] < min_d)
                {
                    min_d = M_dist[i][j];
                    p_m_j = i;
                    p_m_p = j;
                }
            }
        }
        // Parcours seulement les plantes de type "Legume" si le moral du jardinier est egal a 2
        else if (vect_J[i].get_moral() == 2) 
        {
            for (int j = 0; j < vect_P.size(); j++)
            {
                if (vect_P[j]->get_type() == TYPE_LEGUME && M_dist[i][j] < min_d)
                {
                    min_d = M_dist[i][j];
                    p_m_j = i;
                    p_m_p = j;
                }
            }
        }
        // Parcours seulement les plantes de type "Fleur" si le moral du jardinier est egal a 1
        else if (vect_J[i].get_moral() == 1) {
            for (int j = 0; j < vect_P.size(); j++)
            {
                if (vect_P[j]->get_type() == TYPE_FLEUR && M_dist[i][j] < min_d)
                {
                    min_d = M_dist[i][j];
                    p_m_j = i;
                    p_m_p = j;
                }
            }
        }
    }

    x_p = vect_P[p_m_p]->get_position_x(); // Position en abscisse de la plante
    y_p = vect_P[p_m_p]->get_position_y(); // Position en ordonnee de la plante
    x_j = vect_J[p_m_j].get_position_x(); // Position en abscisse du jardinier
    y_j = vect_J[p_m_j].get_position_y(); // Position en ordonnee du jardinier
  
    int dist_x = x_p - x_j;  // La distance en abscisse entre la plante et le jardinier
    int dist_y = y_p - y_j; // La distance en ordonnee entre la plante et le jardinier

    // Si l'etat de croissance de la plante est egal a 5 (maturite) et 
    // que le type de la plante est egal au moral du jardinier
    // la 2ieme condition obliger le premier jardinier a respecter les conditions .
    if (vect_P[p_m_p]->get_etat_pousse() == 5 && vect_P[p_m_p]->get_type() == vect_J[p_m_j].get_moral())
    {
        if (dist_x == 0 && dist_y == 0)
        {
            if (vect_P[p_m_p]->get_type()==2){
                // manger un legume restaure le moral du jardinier.
                vect_J[p_m_j].set_moral(3);
            }
            if (p_m_p >= 0 && p_m_p < vect_P.size()){
                // Marque la plante comme ramassee
                vect_P[p_m_p]->ramasser();
                // retire la plante de la liste vect_P
                vect_P.erase(vect_P.begin() + p_m_p);
            }
        }
        // Si la distance en abscisse est positive, deplace le jardinier vers la droite
        if (dist_x > 0)
        {
            vect_J[p_m_j].set_position_x(vect_J[p_m_j].get_position_x() + 1);
            vect_J[p_m_j].set_orient("right");
        }
        else if (dist_x < 0)
        {
            vect_J[p_m_j].set_position_x(vect_J[p_m_j].get_position_x() - 1);
            vect_J[p_m_j].set_orient("left");
        }

        else if (dist_y > 0)
        {
            vect_J[p_m_j].set_position_y(vect_J[p_m_j].get_position_y() + 1);
            vect_J[p_m_j].set_orient("down");
        }
        else if (dist_y < 0)
        {
            vect_J[p_m_j].set_position_y(vect_J[p_m_j].get_position_y() - 1);
            vect_J[p_m_j].set_orient("top");
        }
    }

    // reinitialisation des varibles à chaque fin de parcours
    min_d = INT_MAX;
    p_m_j = 0;
    p_m_p = 0;
}

#endif




