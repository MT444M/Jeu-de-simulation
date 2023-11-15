#include "Jardinier.h"


//=============Importation Image ===========

/**
* @brief importation des images necessaire pour l'affichage du jardinier.
*/
 //vert ====================================

CImg<unsigned char> WaitTop_g("Jardinier/green/WaitTop.pnm");

CImg<unsigned char> WalkTop_1_g("Jardinier/green/WalkTop_1.pnm");

CImg<unsigned char> WalkTop_2_g("Jardinier/green/WalkTop_2.pnm");
////
CImg<unsigned char> WaitDown_g("Jardinier/green/WaitDown.pnm");

CImg<unsigned char> WalkDown_1_g("Jardinier/green/WalkDown_1.pnm");

CImg<unsigned char> WalkDown_2_g("Jardinier/green/WalkDown_2.pnm");
////
CImg<unsigned char> WaitLeft_g("Jardinier/green/WaitLeft.pnm");

CImg<unsigned char> WalkLeft_1_g("Jardinier/green/WalkLeft_1.pnm");

CImg<unsigned char> WalkLeft_2_g("Jardinier/green/WalkLeft_2.pnm");
////
CImg<unsigned char> WaitRight_g("Jardinier/green/WaitRight.pnm");

CImg<unsigned char> WalkRight_1_g("Jardinier/green/WalkRight_1.pnm");

CImg<unsigned char> WalkRight_2_g("Jardinier/green/WalkRight_2.pnm");

// Jardinier : jaune
CImg<unsigned char> WaitTop_y("Jardinier/yellow/WaitTop.pnm");

CImg<unsigned char> WalkTop_1_y("Jardinier/yellow/WalkTop_1.pnm");

CImg<unsigned char> WalkTop_2_y("Jardinier/yellow/WalkTop_2.pnm");
////
CImg<unsigned char> WaitDown_y("Jardinier/yellow/WaitDown.pnm");

CImg<unsigned char> WalkDown_1_y("Jardinier/yellow/WalkDown_1.pnm");

CImg<unsigned char> WalkDown_2_y("Jardinier/yellow/WalkDown_2.pnm");
////
CImg<unsigned char> WaitLeft_y("Jardinier/yellow/WaitLeft.pnm");

CImg<unsigned char> WalkLeft_1_y("Jardinier/yellow/WalkLeft_1.pnm");

CImg<unsigned char> WalkLeft_2_y("Jardinier/yellow/WalkLeft_2.pnm");
////
CImg<unsigned char> WaitRight_y("Jardinier/yellow/WaitRight.pnm");

CImg<unsigned char> WalkRight_1_y("Jardinier/yellow/WalkRight_1.pnm");

CImg<unsigned char> WalkRight_2_y("Jardinier/yellow/WalkRight_2.pnm");

// Jardinier : rouge
CImg<unsigned char> WaitTop_r("Jardinier/red/WaitTop.pnm");

CImg<unsigned char> WalkTop_1_r("Jardinier/red/WalkTop_1.pnm");

CImg<unsigned char> WalkTop_2_r("Jardinier/red/WalkTop_2.pnm");
////
CImg<unsigned char> WaitDown_r("Jardinier/red/WaitDown.pnm");

CImg<unsigned char> WalkDown_1_r("Jardinier/red/WalkDown_1.pnm");

CImg<unsigned char> WalkDown_2_r("Jardinier/red/WalkDown_2.pnm");
////
CImg<unsigned char> WaitLeft_r("Jardinier/red/WaitLeft.pnm");

CImg<unsigned char> WalkLeft_1_r("Jardinier/red/WalkLeft_1.pnm");

CImg<unsigned char> WalkLeft_2_r("Jardinier/red/WalkLeft_2.pnm");
////
CImg<unsigned char> WaitRight_r("Jardinier/red/WaitRight.pnm");

CImg<unsigned char> WalkRight_1_r("Jardinier/red/WalkRight_1.pnm");

CImg<unsigned char> WalkRight_2_r("Jardinier/red/WalkRight_2.pnm");

 
//---------------------------Methode---------------------------------
/**
* @brief Cette methode permet de mettre à jour l'etat du jardinier en fonction de 
* son moral et de l'heure actuelle. Elle permet aussi de mettre à jouer l etat du jardinier
* et son orientation dans son trajet.
*/
void Jardinier::draw_Jardinier(int t0)
{
    //diminuer l'etat moral du jardnier dans le temps
    if (get_moral() >1 &&  t0-get_date_chgmt_moral()>get_duree_etape_moral())  // 
    {
        set_moral(get_moral() - 1);
        set_date_chgmt_moral(t0);
    }
    
    if (get_moral() == 3)
    {
        if (get_orient() == "top")
        {
            etat_jardinier =  WaitTop_g;
     
        }
        else if (get_orient() == "right")
        {
            etat_jardinier = WaitRight_g;
        }
        else if (get_orient() == "left")
        {
            etat_jardinier = WaitLeft_g;
        }
        else
        {
            etat_jardinier = WaitDown_g;
        }
    }

    else if (get_moral() == 2)
    {
        if (get_orient() == "top")
        {
            etat_jardinier = WaitTop_y;
        }
        else if (get_orient() == "right")
        {
            etat_jardinier = WaitRight_y;
        }
        else if (get_orient() == "left")
        {
            etat_jardinier = WaitLeft_y;
        }
        else
        {
            etat_jardinier = WaitDown_y;
        }
    }
    else if (get_moral() == 1)
    {
        if (get_orient() == "top")
        {
            etat_jardinier = WaitTop_r;
        }
        else if (get_orient() == "right")
        {
            etat_jardinier = WaitRight_r;
        }
        else if (get_orient() == "left")
        {
            etat_jardinier = WaitLeft_r;
        }
        else
        {
            etat_jardinier = WaitDown_r;
        }
    }   
}

