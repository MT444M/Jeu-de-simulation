#include "Plante.h"

//=================Importation Plante=========================
//  
/**
* @brief  Chargement des images
*/

//rose code 1
   
CImg<unsigned char> rose0("Plante/Fleur/rose/rose0.pnm");

CImg<unsigned char> rose1("Plante/Fleur/rose/rose1.pnm");

CImg<unsigned char> rose2("Plante/Fleur/rose/rose2.pnm");

CImg<unsigned char> rose3("Plante/Fleur/rose/rose3.pnm");

CImg<unsigned char> rose4("Plante/Fleur/rose/rose4.pnm");

//CImg<unsigned char> rose5("Plante/Fleur/rose/rose5.pnm");


//pineapple code 2
CImg<unsigned char> pineapple0("Plante/Legume/pineapple/pineapple0.pnm");

CImg<unsigned char> pineapple1("Plante/Legume/pineapple/pineapple1.pnm");

CImg<unsigned char> pineapple2("Plante/Legume/pineapple/pineapple2.pnm");

CImg<unsigned char> pineapple3("Plante/Legume/pineapple/pineapple3.pnm");

CImg<unsigned char> pineapple4("Plante/Legume/pineapple/pineapple4.pnm");

//CImg<unsigned char> pineapple5("Plante/Legume/pineapple/pineapple5.pnm");

//tulip code 3
CImg<unsigned char> tulip0("Plante/Fleur/tulip/tulip0.pnm");

CImg<unsigned char> tulip1("Plante/Fleur/tulip/tulip1.pnm");

CImg<unsigned char> tulip2("Plante/Fleur/tulip/tulip2.pnm");

CImg<unsigned char> tulip3("Plante/Fleur/tulip/tulip3.pnm");

CImg<unsigned char> tulip4("Plante/Fleur/tulip/tulip4.pnm");

//CImg<unsigned char> tulip5("Plante/Fleur/tulip/tulip5.pnm");

//cucumber code 4
CImg<unsigned char> cucumber0("Plante/Legume/cucumber/cucumber0.pnm");

CImg<unsigned char> cucumber1("Plante/Legume/cucumber/cucumber1.pnm");

CImg<unsigned char> cucumber2("Plante/Legume/cucumber/cucumber2.pnm");

CImg<unsigned char> cucumber3("Plante/Legume/cucumber/cucumber3.pnm");

CImg<unsigned char> cucumber4("Plante/Legume/cucumber/cucumber4.pnm");

//CImg<unsigned char> cucumber5("Plante/Legume/cucumber/cucumber5.pnm");


//melon code 5
CImg<unsigned char> melon0("Plante/Legume/melon/melon0.pnm");

CImg<unsigned char> melon1("Plante/Legume/melon/melon1.pnm");

CImg<unsigned char> melon2("Plante/Legume/melon/melon2.pnm");

CImg<unsigned char> melon3("Plante/Legume/melon/melon3.pnm");

CImg<unsigned char> melon4("Plante/Legume/melon/melon4.pnm");

//CImg<unsigned char> melon5("Plante/Legume/melon/melon5.pnm");


//turnip code 6
CImg<unsigned char> turnip0("Plante/Legume/turnip/turnip0.pnm");

CImg<unsigned char> turnip1("Plante/Legume/turnip/turnip1.pnm");

CImg<unsigned char> turnip2("Plante/Legume/turnip/turnip2.pnm");

CImg<unsigned char> turnip3("Plante/Legume/turnip/turnip3.pnm");

CImg<unsigned char> turnip4("Plante/Legume/turnip/turnip4.pnm");

//CImg<unsigned char> turnip5("Plante/Legume/turnip/turnip5.pnm");

//sunflower code 7
CImg<unsigned char> sunflower0("Plante/Legume/sunflower/sunflower0.pnm");

CImg<unsigned char> sunflower1("Plante/Legume/sunflower/sunflower1.pnm");

CImg<unsigned char> sunflower2("Plante/Legume/sunflower/sunflower2.pnm");

CImg<unsigned char> sunflower3("Plante/Legume/sunflower/sunflower3.pnm");

CImg<unsigned char> sunflower4("Plante/Legume/sunflower/sunflower4.pnm");

//CImg<unsigned char> sunflower5("Plante/Legume/sunflower/sunflower5.pnm");

//strawberry code 8
CImg<unsigned char> strawberry0("Plante/Legume/strawberry/strawberry0.pnm");

CImg<unsigned char> strawberry1("Plante/Legume/strawberry/strawberry1.pnm");

CImg<unsigned char> strawberry2("Plante/Legume/strawberry/strawberry2.pnm");

CImg<unsigned char> strawberry3("Plante/Legume/strawberry/strawberry3.pnm");

CImg<unsigned char> strawberry4("Plante/Legume/strawberry/strawberry4.pnm");

//CImg<unsigned char> strawberry5("Plante/Legume/strawberry/strawberry5.pnm");

//grapes code 9
CImg<unsigned char> grapes0("Plante/Legume/grapes/grapes0.pnm");

CImg<unsigned char> grapes1("Plante/Legume/grapes/grapes1.pnm");

CImg<unsigned char> grapes2("Plante/Legume/grapes/grapes2.pnm");

CImg<unsigned char> grapes3("Plante/Legume/grapes/grapes3.pnm");

CImg<unsigned char> grapes4("Plante/Legume/grapes/grapes4.pnm");

//CImg<unsigned char> grapes5("Plante/Legume/grapes/grapes5.pnm");

//eggplant code 10
CImg<unsigned char> eggplant0("Plante/Legume/eggplant/eggplant0.pnm");

CImg<unsigned char> eggplant1("Plante/Legume/eggplant/eggplant1.pnm");

CImg<unsigned char> eggplant2("Plante/Legume/eggplant/eggplant2.pnm");

CImg<unsigned char> eggplant3("Plante/Legume/eggplant/eggplant3.pnm");

CImg<unsigned char> eggplant4("Plante/Legume/eggplant/eggplant4.pnm");

//CImg<unsigned char> eggplant5("Plante/Legume/eggplant/eggplant5.pnm");

//corn code 11
CImg<unsigned char> corn0("Plante/Legume/corn/corn0.pnm");

CImg<unsigned char> corn1("Plante/Legume/corn/corn1.pnm");

CImg<unsigned char> corn2("Plante/Legume/corn/corn2.pnm");

CImg<unsigned char> corn3("Plante/Legume/corn/corn3.pnm");

CImg<unsigned char> corn4("Plante/Legume/corn/corn4.pnm");

//CImg<unsigned char> corn5("Plante/Legume/corn/corn5.pnm");

//potato code 12
CImg<unsigned char> potato0("Plante/Legume/potato/potato0.pnm");

CImg<unsigned char> potato1("Plante/Legume/potato/potato1.pnm");

CImg<unsigned char> potato2("Plante/Legume/potato/potato2.pnm");

CImg<unsigned char> potato3("Plante/Legume/potato/potato3.pnm");

CImg<unsigned char> potato4("Plante/Legume/potato/potato4.pnm");

//CImg<unsigned char> potato5("Plante/Legume/potato/potato5.pnm");

//avocado code 13
CImg<unsigned char> avocado0("Plante/Legume/avocado/avocado0.pnm");

CImg<unsigned char> avocado1("Plante/Legume/avocado/avocado1.pnm");

CImg<unsigned char> avocado2("Plante/Legume/avocado/avocado2.pnm");

CImg<unsigned char> avocado3("Plante/Legume/avocado/avocado3.pnm");

CImg<unsigned char> avocado4("Plante/Legume/avocado/avocado4.pnm");

//CImg<unsigned char> avocado5("Plante/Legume/avocado/avocado5.pnm");

//orange code 14
CImg<unsigned char> orange0("Plante/Legume/orange/orange0.pnm");

CImg<unsigned char> orange1("Plante/Legume/orange/orange1.pnm");

CImg<unsigned char> orange2("Plante/Legume/orange/orange2.pnm");

CImg<unsigned char> orange3("Plante/Legume/orange/orange3.pnm");

CImg<unsigned char> orange4("Plante/Legume/orange/orange4.pnm");

//CImg<unsigned char> orange5("Plante/Legume/orange/orange5.pnm");

//tomato code 15
CImg<unsigned char> tomato0("Plante/Legume/tomato/tomato0.pnm");

CImg<unsigned char> tomato1("Plante/Legume/tomato/tomato1.pnm");

CImg<unsigned char> tomato2("Plante/Legume/tomato/tomato2.pnm");

CImg<unsigned char> tomato3("Plante/Legume/tomato/tomato3.pnm");

CImg<unsigned char> tomato4("Plante/Legume/tomato/tomato4.pnm");

//CImg<unsigned char> tomato5("Plante/Legume/tomato/tomato5.pnm");

//lemon code 16
CImg<unsigned char> lemon0("Plante/Legume/lemon/lemon0.pnm");

CImg<unsigned char> lemon1("Plante/Legume/lemon/lemon1.pnm");

CImg<unsigned char> lemon2("Plante/Legume/lemon/lemon2.pnm");

CImg<unsigned char> lemon3("Plante/Legume/lemon/lemon3.pnm");

CImg<unsigned char> lemon4("Plante/Legume/lemon/lemon4.pnm");

//CImg<unsigned char> lemon5("Plante/Legume/lemon/lemon5.pnm");


/**
* @brief  La fonction pousse est utilisee pour faire evoluer le stade de maturite d'une plante.
Elle prend en argument le temps actuel t0 et verifie que la plante n'est pas encore mûre et 
que la duree de pousse du stade de maturite actuel au stade de maturite suivant est atteinte. 
Si ces conditions sont remplies, la fonction incremente le stade de maturite de la plante et
met a jour sa date de plantation. Ensuite, elle met a jour l'etat de la plante en utilisant 
un switch en fonction du code de la plante et du stade de maturite.
*/
void Plante::pousse(int t0) //permet de faire evoluer le stade de maturite des plantes. Prend en argument le temps actuel.
{
    if ((get_etat_pousse() < 5 &&  t0 - get_date_plantation() > get_duree_pousse()) ) //On verifie que la plante n'est pas mûre + que la duree de pousse du stade de marurite n au stade de maturitee n+1 est atteinte.
    {

        etat_pousse = etat_pousse + 1;
        set_date_plantation(t0);

        if (code == 1) {
            switch (etat_pousse) {
            case 0: {
                //extern CImg<unsigned char> rose1;
                etat_plante = rose0;
                break;
            }
            case 1: {
                //extern CImg<unsigned char> rose1;
                etat_plante = rose1;
                break;
            }
            case 2: {
                //extern CImg<unsigned char> rose2;
                etat_plante = rose2;
                break;
            }
            case 3: {
                //extern CImg<unsigned char> rose3;
                etat_plante = rose3;
                break;
            }
            case 4: {
                //extern CImg<unsigned char> rose4;
                etat_plante = rose4;
                break;
            }
            case 5: {
                extern CImg<unsigned char> rose5;
                etat_plante = rose5;
                break;
            }

            }
        }
        else if (code == 2) {
            switch (etat_pousse) {
            case 1: {
                extern CImg<unsigned char> pineapple1;
                etat_plante = pineapple1;
                break;
            }
            case 2: {
                extern CImg<unsigned char> pineapple2;
                etat_plante = pineapple2;
                break;
            }
            case 3: {
                extern CImg<unsigned char> pineapple3;
                etat_plante = pineapple3;
                break;
            }
            case 4: {
                extern CImg<unsigned char> pineapple4;
                etat_plante = pineapple4;
                break;
            }
            case 5: {
                extern CImg<unsigned char> pineapple5;
                etat_plante = pineapple5;
                break;
            }
            }
        }
        else if (code == 3) {
            switch (etat_pousse) {
            case 1: {
                extern CImg<unsigned char> tulip1;
                etat_plante = tulip1;
                break;
            }
            case 2: {
                extern CImg<unsigned char> tulip2;
                etat_plante = tulip2;
                break;
            }
            case 3: {
                extern CImg<unsigned char> tulip3;
                etat_plante = tulip3;
                break;
            }
            case 4: {
                extern CImg<unsigned char> tulip4;
                etat_plante = tulip4;
                break;
            }
            case 5: {
                extern CImg<unsigned char> tulip5;
                etat_plante = tulip5;
                break;
            }
            }
        }
        else if (code == 4) {
            switch (etat_pousse) {
            case 1: {
                extern CImg<unsigned char> cucumber1;
                etat_plante = cucumber1;
                break;
            }
            case 2: {
                extern CImg<unsigned char> cucumber2;
                etat_plante = cucumber2;
                break;
            }
            case 3: {
                extern CImg<unsigned char> cucumber3;
                etat_plante = cucumber3;
                break;
            }
            case 4: {
                extern CImg<unsigned char> cucumber4;
                etat_plante = cucumber4;
                break;
            }
            case 5: {
                extern CImg<unsigned char> cucumber5;
                etat_plante = cucumber5;
                break;
            }
            }
        }
        else if (code == 5) {
            switch (etat_pousse) {
            case 1: {
                extern CImg<unsigned char> melon1;
                etat_plante = melon1;
                break;
            }
            case 2: {
                extern CImg<unsigned char> melon2;
                etat_plante = melon2;
                break;
            }
            case 3: {
                extern CImg<unsigned char> melon3;
                etat_plante = melon3;
                break;
            }
            case 4: {
                extern CImg<unsigned char> melon4;
                etat_plante = melon4;
                break;
            }
            case 5: {
                extern CImg<unsigned char> melon5;
                etat_plante = melon5;
                break;
            }
            }
        }
        else if (code == 6) {
            switch (etat_pousse) {
            case 1: {
                extern CImg<unsigned char> turnip1;
                etat_plante = turnip1;
                break;
            }
            case 2: {
                extern CImg<unsigned char> turnip2;
                etat_plante = turnip2;
                break;
            }
            case 3: {
                extern CImg<unsigned char> turnip3;
                etat_plante = turnip3;
                break;
            }
            case 4: {
                extern CImg<unsigned char> turnip4;
                etat_plante = turnip4;
                break;
            }
            case 5: {
                extern CImg<unsigned char> turnip5;
                etat_plante = turnip5;
                break;
            }
            }
        }
        else if (code == 7) {
            switch (etat_pousse) {
            case 1: {
                extern CImg<unsigned char> sunflower1;
                etat_plante = sunflower1;
                break;
            }
            case 2: {
                extern CImg<unsigned char> sunflower2;
                etat_plante = sunflower2;
                break;
            }
            case 3: {
                extern CImg<unsigned char> sunflower3;
                etat_plante = sunflower3;
                break;
            }
            case 4: {
                extern CImg<unsigned char> sunflower4;
                etat_plante = sunflower4;
                break;
            }
            case 5: {
                extern CImg<unsigned char> sunflower5;
                etat_plante = sunflower5;
                break;
            }
            }
        }
        else if (code == 8) {
            switch (etat_pousse) {
            case 1: {
                extern CImg<unsigned char> strawberry1;
                etat_plante = strawberry1;
                break;
            }
            case 2: {
                extern CImg<unsigned char> strawberry2;
                etat_plante = strawberry2;
                break;
            }
            case 3: {
                extern CImg<unsigned char> strawberry3;
                etat_plante = strawberry3;
                break;
            }
            case 4: {
                extern CImg<unsigned char> strawberry4;
                etat_plante = strawberry4;
                break;
            }
            case 5: {
                extern CImg<unsigned char> strawberry5;
                etat_plante = strawberry5;
                break;
            }
            }
        }
        else if (code == 9) {
            switch (etat_pousse) {
            case 1: {
                extern CImg<unsigned char> grapes1;
                etat_plante = grapes1;
                break;
            }
            case 2: {
                extern CImg<unsigned char> grapes2;
                etat_plante = grapes2;
                break;
            }
            case 3: {
                extern CImg<unsigned char> grapes3;
                etat_plante = grapes3;
                break;
            }
            case 4: {
                extern CImg<unsigned char> grapes4;
                etat_plante = grapes4;
                break;
            }
            case 5: {
                extern CImg<unsigned char> grapes5;
                etat_plante = grapes5;
                break;
            }
            }
        }
        else if (code == 10) {
            switch (etat_pousse) {
            case 1: {
                extern CImg<unsigned char> eggplant1;
                etat_plante = eggplant1;
                break;
            }
            case 2: {
                extern CImg<unsigned char> eggplant2;
                etat_plante = eggplant2;
                break;
            }
            case 3: {
                extern CImg<unsigned char> eggplant3;
                etat_plante = eggplant3;
                break;
            }
            case 4: {
                extern CImg<unsigned char> eggplant4;
                etat_plante = eggplant4;
                break;
            }
            case 5: {
                extern CImg<unsigned char> eggplant5;
                etat_plante = eggplant5;
                break;
            }
            }
        }
        else if (code == 11) {
            switch (etat_pousse) {
            case 1: {
                extern CImg<unsigned char> corn1;
                etat_plante = corn1;
                break;
            }
            case 2: {
                extern CImg<unsigned char> corn2;
                etat_plante = corn2;
                break;
            }
            case 3: {
                extern CImg<unsigned char> corn3;
                etat_plante = corn3;
                break;
            }
            case 4: {
                extern CImg<unsigned char> corn4;
                etat_plante = corn4;
                break;
            }
            case 5: {
                extern CImg<unsigned char> corn5;
                etat_plante = corn5;
                break;
            }
            }
        }
        else if (code == 12) {
            switch (etat_pousse) {
            case 1: {
                extern CImg<unsigned char> potato1;
                etat_plante = potato1;
                break;
            }
            case 2: {
                extern CImg<unsigned char> potato2;
                etat_plante = potato2;
                break;
            }
            case 3: {
                extern CImg<unsigned char> potato3;
                etat_plante = potato3;
                break;
            }
            case 4: {
                extern CImg<unsigned char> potato4;
                etat_plante = potato4;
                break;
            }
            case 5: {
                extern CImg<unsigned char> potato5;
                etat_plante = potato5;
                break;
            }
            }
        }
        else if (code == 13) {
            switch (etat_pousse) {
            case 1: {
                extern CImg<unsigned char> avocado1;
                etat_plante = avocado1;
                break;
            }
            case 2: {
                extern CImg<unsigned char> avocado2;
                etat_plante = avocado2;
                break;
            }
            case 3: {
                extern CImg<unsigned char> avocado3;
                etat_plante = avocado3;
                break;
            }
            case 4: {
                extern CImg<unsigned char> avocado4;
                etat_plante = avocado4;
                break;
            }
            case 5: {
                extern CImg<unsigned char> avocado5;
                etat_plante = avocado5;
                break;
            }
            }
        }
        else if (code == 14) {
            switch (etat_pousse) {
            case 1: {
                extern CImg<unsigned char> orange1;
                etat_plante = orange1;
                break;
            }
            case 2: {
                extern CImg<unsigned char> orange2;
                etat_plante = orange2;
                break;
            }
            case 3: {
                extern CImg<unsigned char> orange3;
                etat_plante = orange3;
                break;
            }
            case 4: {
                extern CImg<unsigned char> orange4;
                etat_plante = orange4;
                break;
            }
            case 5: {
                extern CImg<unsigned char> orange5;
                etat_plante = orange5;
                break;
            }
            }
        }
        else if (code == 15) {
            switch (etat_pousse) {
            case 1: {
                extern CImg<unsigned char> tomato1;
                etat_plante = tomato1;
                break;
            }
            case 2: {
                extern CImg<unsigned char> tomato2;
                etat_plante = tomato2;
                break;
            }
            case 3: {
                extern CImg<unsigned char> tomato3;
                etat_plante = tomato3;
                break;
            }
            case 4: {
                extern CImg<unsigned char> tomato4;
                etat_plante = tomato4;
                break;
            }
            case 5: {
                extern CImg<unsigned char> tomato5;
                extern CImg<unsigned char> tomato5o;
                etat_plante = tomato5;
                break;
            }
            }
        }
        else if (code == 16) {
            switch (etat_pousse) {
            case 1: {
                extern CImg<unsigned char> lemon1;
                etat_plante = lemon1;
                break;
            }
            case 2: {
                extern CImg<unsigned char> lemon2;
                etat_plante = lemon2;
                break;
            }
            case 3: {
                extern CImg<unsigned char> lemon3;
                etat_plante = lemon3;
                break;
            }
            case 4: {
                extern CImg<unsigned char> lemon4;
                etat_plante = lemon4;
                break;
            }
            case 5: {
                extern CImg<unsigned char> lemon5;
                etat_plante = lemon5;
                break;
            }
            }
        }
    }
}

/**
* @brief La fonction Plante::Plante(int code_plante) est un constructeur 
* de la classe Plante. Elle prend en argument un entier "code_plante" 
* et initialise le champ de donnees "type_" avec cet entier.
* Elle initialise egalement le champ de donnees "etat_pousse" a 0.
*/
Plante::Plante(int code_plante) 
    : type_(code_plante)
{
    set_etat_pousse(0);
}
//==================Fleur=============================
/**
* @brief Le constructeur de la classe Fleur prend un entier code_fleur en argument
* et appelle le constructeur de la classe Plante en lui passant ce même entier. 
* Ensuite, il definit la duree de pousse de la fleur a 1 et en fonction du code de la 
* fleur, il definit le code de la plante a 1, 3 ou 7 qui sont des fleurs.
* @see Legume(int code_legume): Plante(code_legume), Plante_Grain(int code_a_grain) : Plante(code_a_grain)
*/

Fleur::Fleur(int code_fleur) :Plante(code_fleur)
{
    set_duree_pousse(1); // DUREE POUSSE

    if (code_fleur == 1){ //rose{
        set_code(1);
    }
    else if (code_fleur == 3){  //tulip
        set_code(3);
    }
    else if (code_fleur == 7){  //sunflower
        set_code(7);
    }
}

/**
* @brief Cette methode permet de planter un legume dans le jardin virtuel.
* Elle prend en argument les coordonnees x et y de l'emplacement
* où le legume doit être plante. Elle initialise la date de plantation 
* du legume en utilisant l'horodatage courant, et definit les coordonnees x et y
* de l'emplacement de la plante dans le jardin. Cette methode est une 
* fonction virtuelle pure de la classe Plante, qui doit donc être implementee 
* dans toutes les classes qui heritent de Plante.
* 
* @see void Legume::Planter(int x, int y), void Plante_Grain::Planter(int x, int y)
*/
void Fleur::Planter(int x, int y)
{
    time_t ttime = time(0);
    set_date_plantation(ttime);
    set_position_x(x);
    set_position_y(y);
}

//================Legume==============================
Legume::Legume(int code_legume): Plante(code_legume)
{
    set_duree_pousse(2); // DUREE POUSSE

    if (code_legume == 4){ //---------cucumber
        set_code(4);
    }
    else if (code_legume == 6){ //----turnip
        set_code(6);
    }
    else if (code_legume == 10){ //---eggplant
        set_code(10);
    }
    else if (code_legume == 12){ //---potato
        set_code(12);
    }
    else if (code_legume == 15){ //---tomato
        set_code(15);
    }
}


void Legume::Planter(int x, int y)
{
    time_t ttime = time(0);
    set_date_plantation(ttime);
    set_position_x(x);
    set_position_y(y);
}

//==================Plante_Grain=======================
Plante_Grain::Plante_Grain(int code_a_grain) : Plante(code_a_grain)
{
    set_duree_pousse(3);     // DUREE POUSSE

    if (code_a_grain == 2){  //pineapple
        set_code(2);
    }
    else if (code_a_grain == 5){  //melon
        set_code(5);
    }
    else if (code_a_grain == 8){ //strawberry
        set_code(8);
    } 
    else if (code_a_grain == 9){  //grapes
        set_code(9);
    }
    else if (code_a_grain == 16){ //lemon
        set_code(16);
    } 
    else if (code_a_grain == 14){ //orange
        set_code(14);
    } 
    else if (code_a_grain == 11){ //corn
        set_code(11);
    }
    else if (code_a_grain == 13){ //avocado
        set_code(13);
    }
}

void Plante_Grain::Planter(int x, int y)
{
    time_t ttime = time(0);
    set_date_plantation(ttime);
    set_position_x(x);
    set_position_y(y);
}




