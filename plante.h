#pragma once

#ifndef DEF_PLANTE
#define DEF_PLANTE
#include <iostream>
//#include <cstring>
#include "CImg.h"


using namespace std;
using namespace cimg_library;

/// <summary>
/// La classe Plante est une classe de base abstraite qui definit les caracteristiques communes
/// a toutes les plantes. Elle possede des champs de donnees comme la duree de pousse,
/// la date de plantation, l'etat de pousse, l'etat de la plante, le code de la plante,
/// sa position en x et en y, ainsi qu'un booleen indiquant si la plante a ete recoltee. 
/// Elle possede egalement plusieurs methodes pour acceder et modifier ces champs de donnees, 
/// ainsi qu'une methode virtuelle pure Planter qui sera implementee dans les classes filles. 
/// La classe Plante possede egalement un constructeur par defaut et un constructeur avec
/// un parametre entier qui initialise le champ de donnees type_.
/// 
/// 
/// Les classes Fleur, Legume et Plante_Grain sont des classes filles de la classe Plante, 
/// qui heritent de tous ses champs de donnees et methodes. Elles possedent egalement 
/// leur propre implementation de la methode Planter, ainsi qu'une methode get_type qui 
/// renvoie le type de la plante (fleur, legume ou plante a grains). Chacune de ces classes
///  possede un constructeur par defaut qui appelle le constructeur par defaut de
///  la classe Plante, ainsi qu'un constructeur qui prend un entier en parametre.
/// </summary>
class Plante {
private:
    int duree_pousse;      ///< Duree de pousse de la plante en secondes.
    int date_plantation;  ///< Date de plantation de la plante.
    int etat_pousse;      ///< etat de pousse de la plante.     

    CImg<unsigned char> etat_plante; ///< Image representant l'etat actuel de la plante.  

    int code;             ///< Code unique de chaque plante.                 
    int pos_y;            ///< Coordonnee y de la plante sur le champs.
    int pos_x;            ///< Coordonnee x de la plante sur le champs.

    int type_;            ///< Type de la plante (fleur, legume ou plante a grain).
    bool est_ramassee {false};       ///<  variable indiquant si la plante a ete recoltee
public:

    /**
     * @brief Methode pour Marquer la plante comme recoltee
     */
    void ramasser() { est_ramassee = true; }
    /**
     * @brief Methode indiquer si la plante a ete recoltee ou non.
     * @return Vrai si la plante a ete recoltee, faux sinon.
     */
    bool get_ramassage() { return est_ramassee; }

    /**
     * @brief Methode pour retourner le code unique de la plante.
     */
    int get_code() { return code; }

    /**
     * @brief Methode pour definiir le code unique de chaque plante.
     * @param c Code unique de la plante.
     */
    void set_code(int c) { code = c; }

    /**
     * @brief Retourne le type de la plante.
     * @return Type de la plante (fleur, legume ou plante a grain)
     */
    virtual int get_type() const = 0; 

    /**
     * @brief Methode pour mettre a jour l'image de la plante
     * @param img Nouvelle image de la plante
     */
    void set_etat_plante(CImg<unsigned char> img) { etat_plante = img; }

    /**
     * @brief Methode pour obtenir l'image actuelle de la plante
     * @return L'image actuelle de la plante
     */
    CImg<unsigned char> get_etat_plante() { return etat_plante; }

    /**
     * @brief Methode pour obtenir la duree de pousse de la plante
     * @return La duree de pousse de la plante
     */
    int get_duree_pousse() { return duree_pousse; }

    /**
     * @brief Methode pour mettre a jour la duree de pousse de la plante
     * @param d Nouvelle duree de pousse de la plante
     */
    void set_duree_pousse(int d) { duree_pousse = d; }

    /**
     * @brief Methode pour mettre a jour la date de plantation de la plante
     * @param d Nouvelle date de plantation de la plante
     */
    void set_date_plantation(int d) { date_plantation = d; }

    /**
     * @brief Methode pour obtenir la date de plantation de la plante
     * @return La date de plantation de la plante
     */
    int get_date_plantation() { return date_plantation; }

    /**
     * @brief Methode pour obtenir l'etat de pousse de la plante
     * @return L'etat de pousse de la plante
     */
    int get_etat_pousse() { return etat_pousse; }

    /**
     * @brief Methode pour mettre a jour l'etat de pousse de la plante
     * @param e Nouvel etat de pousse de la plante
     */
    void set_etat_pousse(int e) { etat_pousse = e; }

    /**
     * @brief Methode pour obtenir la position en x de la plante
     * @return La position en x de la plante
     */
    int get_position_x() { return pos_x; }

    /**
    * @brief Getter pour l'attribut pos_y (position en y de la plante)
    * @return int La position en y de la plante
    */
    int get_position_y() { return pos_y; }

    /**
    * @brief Setter pour l'attribut pos_x (position en x de la plante)
    * @param x La nouvelle position en x de la plante
    */
    void set_position_x(int x) { pos_x = x; }

    /**
    * @brief Setter pour l'attribut pos_y (position en y de la plante)
    * @param y La nouvelle position en y de la plante
    */
    void set_position_y(int y) { pos_y = y; }
    
    /**
     * @brief Methode pour faire pousser la plante
     * @param temps Temps ecoule depuis la derniere mise a jour de l'etat de pousse
     */
    void pousse(int);

    /**
    * @brief Methode virtuelle pure pour planter une plante.
    * Declaration de la fonction virtuelle pure.
    * @param x La position en x où planter la plante
    * @param y La position en y où planter la plante
    */
    virtual void Planter(int, int) = 0; 
    
    /**
    * @brief Constante statique indiquant que la plante est de type "Fleur", "Legume" ou "Plante a graines".
    */
    static const int TYPE_FLEUR = 1;
    static const int TYPE_LEGUME =2;
    static const int TYPE_PLANTE_GRAIN = 3;
   
    /**
    * @brief Constructeur par defaut de la classe "Plante"
    * Initialise le champ de donnees "type_" a 0 par defaut.
    */
    Plante() : type_(0) {}

    /**
    * @brief Constructeur de la classe "Plante"
    * @param type Le type de la plante
    */
    Plante(int);

    /**
    @brief Destructeur virtuel de la classe "Plante"
    */
    virtual ~Plante()
    {
    };
};


//===============CLass Fleur================
class Fleur : public Plante
{
public:

    /**
    * @brief Implementation de la fonction virtuelle pure "Planter" de la classe "Plante"
    * @param x Position en abscisse où planter la fleur
    * @param y Position en ordonnee où planter la fleur
    */
    virtual void Planter(int, int) override; 

    /**
    * @brief Retourne le type de la fleur
    * @return int Valeur correspondant au type de la fleur
    */
    int get_type() const override { return TYPE_FLEUR; }

    /**
    * @brief Constructeur par defaut de la classe "Fleur"
    * Ce constructeur appelle le constructeur par defaut de la classe "Plante"
    */
    Fleur() : Plante() {}  

    /**
    * @brief Constructeur de la classe "Fleur"
    * @param type Type de la fleur a creer
    */
    Fleur(int type) ;

    /**
    @brief Destructeur de la classe "Fleur"
    */
    virtual ~Fleur() {};
};

//===============Class Legume======================

class Legume : public Plante
{
public:
    /**
    * @brief Implementation de la fonction virtuelle pure "Planter" de la classe "Plante"
    * @param x Position en abscisse où planter la fleur
    * @param y Position en ordonnee où planter la fleur
    */
    virtual void Planter(int, int) override;  

    /**
    * @brief Retourne le type du legume
    * @return int Valeur correspondant au type du legume
    */
    int get_type() const override { return TYPE_LEGUME; }
    
    /**
    * @brief Constructeur par defaut de la classe "Legume"
    * Ce constructeur appelle le constructeur par defaut de la classe "Plante"
    */   
    Legume() : Plante() {}  

    /**
    * @brief Constructeur de la classe "Legume"
    * @param type Type de la legume a creer
    */
    Legume(int type) ;

    /**
    * @brief Destructeur de la classe "Legume"
    */
    virtual ~Legume(){};
};

//=============Class PlanteGrain=============

class Plante_Grain : public Plante 
{
public:

    /**
    * @brief Implementation de la fonction virtuelle pure "Planter" de la classe "Plante"
    * @param x Position en abscisse où planter la fleur
    * @param y Position en ordonnee où planter la fleur
    */
    virtual void Planter(int, int) override; 

    /**
    * @brief Retourne le type de la plange a graine
    * @return int Valeur correspondant au type de la plante a graine
    */
    int get_type() const override { return TYPE_PLANTE_GRAIN; }

    /**
    * @brief Constructeur par defaut de la classe "Plante_Grain"
    * Ce constructeur appelle le constructeur par defaut de la classe "Plante"
    */    
    Plante_Grain() : Plante() {} 

    /**
    * @brief Constructeur de la classe "Plante_Grain"
    * @param type Type de la legume a creer
    */
    Plante_Grain(int type);

    /**
    * @brief Destructeur de la classe "Plante_Grain"
    */
    virtual  ~Plante_Grain(){};
};


#endif