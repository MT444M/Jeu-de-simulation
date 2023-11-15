#pragma once


#ifndef DEF_JARDINIER
#define DEF_JARDINIER
#include "CImg.h"
#include "plante.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <string>


using namespace std;
using namespace cimg_library;

/**
@brief Represents a Jardinier object in a gardening game.
@class Jardinier
*
* La classe Jardinier possede des variables privees pour stocker la position (pos_x, pos_y)
de l'objet Jardinier dans le jeu, l'orientation de l'objet Jardinier, le moral de 
l'objet Jardinier, la duree de chaque etape du moral, la date du dernier changement
de morale, et une chaîne representant l'orientation de l'objet Jardinier.
La classe Jardinier possede egalement un objet CImg public nomme "image" 
et un objet CImg public nomme "etat_jardinier" qui represente l'etat de l'objet Jardinier.
represente l'etat de l'objet Jardinier. La classe Jardinier possede des methodes 
publiques getter et setter pour chacune de ses variables privees. 
Elle possede egalement une methode nommee "draw_Jardinier" qui prend un argument entier et 
une methode nommee "set_etat_jardinier" qui prend un objet CImg comme argument et une methode 
nommee "get_etat_jardinier". un objet CImg comme argument et une methode nommee 
"get_etat_jardinier" qui renvoie un objet CImg. La classe Jardinier possede un
constructeur par defaut qui initialise le moral et la duree de chaque etape morale 
a 3 et 10,respectivement. Elle possede egalement un destructeur virtuel.
*
*
*@warning bug, la vitesse du jardinier fonction à chaque fois qu'on ajoute un nouveau jardinier, 
* A corriger 
*/
class Jardinier
{
private:

    int pos_x;             ///< Represente la position du jardinier sur l'axe des x.
    int pos_y;             ///< Represente la position du jardinier sur l'axe des y.
    int moral;             ///< Represente le moral du jardinier.
    int duree_etape_moral; ///< Represente la duree entre chaque etat de moral.
    int date_chgmt_moral;  ///< Represente la date du dernier changement de moral.
    string orient;         ///< Represente l'orientation du jardinier.
    CImg<unsigned char> etat_jardinier; ///< Represente l'etat actual du jardinier (image).
    int image_number;      // déclaration de la variable image_number en tant que membre de la classe

public:
    /**
    * 
    @brief Obtient la position x du jardinier
    @returns La position x du jardinier
    */
    int get_position_x() { return pos_x; }

    /**
    @brief Definit la position x du jardinier
    @param x La nouvelle position x du jardinier
    */
    void set_position_x(int x) { pos_x = x; }

    /**

    @brief Obtient la position y du jardinier
    @returns La position y du jardinier
    */
    int get_position_y() { return pos_y; }

    /**
    @brief Definit la position y du jardinier
    @param y La nouvelle position y du jardinier
    */
    void set_position_y(int y) { pos_y = y; }

    /**
    @brief Obtient le moral du jardinier
    @returns Le moral du jardinier
    */
    int get_moral() { return moral; }

    /**
    @brief Definit le moral du jardinier
    @param m Le nouveau moral du jardinier
    */
    void set_moral(int m) { moral = m; }

    /**
    @brief Definit la date de changement de moral du jardinier
    @param m La nouvelle date de changement de moral du jardinier
    */
    void set_date_chgmt_moral(int m) { date_chgmt_moral = m; }

    /**
    @brief Obtient la date de changement de moral du jardinier
    @returns La date de changement de moral du jardinier
    */
    int get_date_chgmt_moral() { return date_chgmt_moral; }

    /**
    @brief Obtient la duree de l'etape de moral du jardinier
    @returns La duree de l'etape de moral du jardinier
    */
    int get_duree_etape_moral() { return duree_etape_moral; }

    /**
    @brief Definit la duree de l'etape de moral du jardinier
    @param m La nouvelle duree de l'etape de moral du jardinier
    */
    void set_duree_etape_moral(int m) { duree_etape_moral = m; }

    /**
    @brief Obtient l'orientation du jardinier
    @returns L'orientation du jardinier
    */
    string get_orient() { return orient; }

    /**
    @brief Definit l'orientation du jardinier
    @param c La nouvelle orientation du jardinier
    */
    void set_orient(string c) {orient= c;}

    /**
    @brief choisir le jardinier en fonction de son moral, et definir son orientation 
    @param t0 Le temps actuel
    */
    void draw_Jardinier(int);

    /**
    @brief Definit l'etat du jardinier
    @param img
    */
    void set_etat_jardinier(CImg<unsigned char> img) { etat_jardinier = img; }

    /**
    @brief Getter pour l'etat du jardinier
    @return L'image du jardinier
    */
    CImg<unsigned char> get_etat_jardinier() { return etat_jardinier; }

    int get_image_number() const { return image_number; }  // méthode pour accéder à la variable image_number
    void set_image_number(int image_number) { this->image_number = image_number; }  // méthode pour modifier la variable image_number

    /**
    * @brief Constructeur par defaut de la classe "Jardinier"
    * Initialise la valeur du moral a 3 et la duree de chaque etape du moral a 10.
    */
    Jardinier()
    {
        moral = 3;            // chaque nouveau jardinier à un niveau de moral 3
        duree_etape_moral = 15; //initialisation en 15s
        image_number = 0;  // initialisation de la variable image_number
    }

    /**
    @brief Destructeur virtuel de la classe "Jardinier"
    */
    virtual ~Jardinier() {}

};
#endif // DEF_JARDINIER


