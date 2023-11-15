#include <iostream>
#include <cmath>
#include <thread>
#include <vector>
#include "Plante.h"
#include "function.h"


using namespace std;

//-----------------Plantes----------------------------------------------
/**
* @brief importation des images de plantes mures pour l'affichage temporelle.
*/
CImg<unsigned char> rose5("Plante/Fleur/rose/rose5.pnm");
CImg<unsigned char> tulip5("Plante/Fleur/tulip/tulip5.pnm");
CImg<unsigned char> pineapple5("Plante/Legume/pineapple/pineapple5.pnm");
CImg<unsigned char> cucumber5("Plante/Legume/cucumber/cucumber5.pnm");
CImg<unsigned char> melon5("Plante/Legume/melon/melon5.pnm");
CImg<unsigned char> turnip5("Plante/Legume/turnip/turnip5.pnm");
CImg<unsigned char> sunflower5("Plante/Legume/sunflower/sunflower5.pnm");
CImg<unsigned char> strawberry5("Plante/Legume/strawberry/strawberry5.pnm");
CImg<unsigned char> grapes5("Plante/Legume/grapes/grapes5.pnm");
CImg<unsigned char> eggplant5("Plante/Legume/eggplant/eggplant5.pnm");
CImg<unsigned char> corn5("Plante/Legume/corn/corn5.pnm");
CImg<unsigned char> potato5("Plante/Legume/potato/potato5.pnm");
CImg<unsigned char> avocado5("Plante/Legume/avocado/avocado5.pnm");
CImg<unsigned char> orange5("Plante/Legume/orange/orange5.pnm");
CImg<unsigned char> tomato5("Plante/Legume/tomato/tomato5.pnm");
CImg<unsigned char> lemon5("Plante/Legume/lemon/lemon5.pnm");

//------------Jardinier---------------------------------------------------
/**
* @brief importation d'une image de gardinier pour l'affichage temporelle.
*/
extern CImg<unsigned char> WaitTop_g;


//============================Graphique===============
// 
// Initialisation des images de l'interface et couleur
CImg<unsigned char> Jardin_(772, 512, 1, 3, 255); //taille 512+260
unsigned char vert[] = { 0,255,0 };
unsigned char marron[] = { 165, 42, 42 };
int w_bg = Jardin_.width();
int h_bg = Jardin_.height();
CImg<unsigned char> Champs_("image/map_.pnm"); //taille 512/512
CImg<unsigned char> menu("image/menu3.pnm"); //taille 260/441
CImg<unsigned char> ground("image/ground.pnm"); //taille 32/32
CImg<unsigned char> GameOver("image/GameOver.pnm"); //taille 510/360

CImg<unsigned char> copy_jardin(Jardin_);
CImg<unsigned char> copy_champs(Champs_);

/*
		CImg<float> champs(640, 400, 1, 3, 0);
		CImgDisplay affiche(640, 400, "Garden Simulator", 0);
		affiche.display(champs);
		CImg<unsigned char> copy_champs(champs);

		Plante P;
		Fleur rose(1);
		//rose.pousse(2);
		while (!affiche.is_closed())
		{
			int xm = affiche.mouse_x();
			int ym = affiche.mouse_y();

			copy_champs = champs;
			Fleur rose(1);
			time_t t0 = time(0);
			rose.pousse(t0);
			if (affiche.is_keyF())
			{

				copy_champs.draw_image(xm, ym, 0, 0, rose5, NO_opacite(rose5));

				if (affiche.button() & 1)
				{

					champs.draw_image(xm, ym, 0, 0, rose.get_etat_plante(), NO_opacite(rose.get_etat_plante()));
					time_t ttime = time(0);
					rose.set_date_plantation(ttime);
				}


			}

			cout << t0 - rose.get_date_plantation() << endl;
			affiche.display(copy_champs);

			affiche.wait();

		}

		*/
int main()
{

	// Dessin de la fenêtre et de l'image Jardin_
	CImgDisplay disp(Jardin_, "Garden Simulator");

	/**
	* @brief Vecteur de pointeurs de plantes
	* Chaque element du vecteur contient l'adresse d'un objet
	* de type Plante ou de l'une de ses classes derivees
	*/
	vector<Plante*> Plantes;	

	/**
	* @brief Vecteur de jardiniers
	* Chaque element du vecteur contient un objet de type Jardinier
	* Les vecteurs sont utilises pour stocker et gerer les plantes et les jardiniers dans le jeu
	*/
	vector<Jardinier> Jardiniers;

	/// taille des plantes en pixel
	int taille = 32;

	// declaration et initialisation du variable graines
	int graines = 15;

	/// Declarer et initialiser la variable "start"
	time_t start = time(0);

	/**
	* @brief cette variable permet de s'assurer que l'image GameOver est affichee.
	*/
	bool game_over_displayed = false;

	///  affichage du jardin_
	disp.display(Jardin_);

	/// <summary>
	/// tant que la fenetre n'est pas fermer, on remplit des vecteurs Jardiniers et Plantes 
	/// en fonctions des touches et de la valeur de graines. 
	/// On fait appel a la fonction pousse qui assurer le changement d etat des plantes
	/// et la fonction draw_jardinier, qui assure la meme chose pour les jardiniers.
	/// la fonction trajet_jardinier perment quant a elle, le deplacement du jardinier 
	/// le plus proche vers la plantes la plus proches, sous conditions.
	/// </summary>
	/// <returns> nothing </returns>
	while (!disp.is_closed())
	{

//<<<<<<<<<<<<<<<<<<<<<<< Affichage >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		disp.wait(10);
		disp.display(copy_jardin);
		copy_jardin = Jardin_;
		Jardin_.draw_rectangle(512, 0, 779, h_bg - 443, vert);
		Jardin_.draw_image(0, 0, 0, 0, Champs_, 1);
		Jardin_.draw_image(512, h_bg - 441, menu, 1);
		copy_champs = Champs_;
		
		/// Calculer et afficher le temps ecoule en secondes
		time_t current = time(0);
		int duree = current - start;
		string text2 = "temps: " + to_string(duree) + "s";
		string text3 = "score: " + to_string(duree) + "s";

		/// Afficher le temps sur le rectangle vert
		Jardin_.draw_text(555, 33, text2.c_str(), marron, 1, 1, 30);

		/// Afficher la valeur de "graines" sur le rectangle vert
		string text = "Graines: " + to_string(graines);
		Jardin_.draw_text(555, 5, text.c_str(), marron, 1, 1, 30);


		if (game_over_displayed==true)
		{
			// Mettre le programme en pause pendant 5 seconde
			disp.wait(5000);
			// Fermer la fenêtre d'affichage
			disp.close();
		}
		if (graines == 0 )
		{
			// Afficher le message "Game Over" et du score au milieu du champ
			copy_jardin.draw_image(5, 80, 0, 0, GameOver, NO_opacite(GameOver));
			copy_jardin.draw_text(150,120, text3.c_str(), marron, 1, 1, 50);
			// Indiquer que le message "Game Over" a ete affiche
			game_over_displayed = true;
		}

		// les coordonnees de la souris
		int xm = disp.mouse_x();
		int ym = disp.mouse_y();

		bool can_plant = true;// rectangle de securite pour planter
		bool mettre_Jard = true; //  rectangle de securite pour mettre un Jardinier



//<<<<<<<<<<<<<<<<<<<<<<< PLANTATION >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		//faire pousser chaque plante du vecteur Plantes
		for (Plante* plante : Plantes)
		{
			if (!plante->get_ramassage()) {
				time_t t0 = time(0);
				plante->pousse(t0);
			}
		}

		//Affichage de la plante ajoutée dans "Plantes"
		for (Plante* plante : Plantes)
		{
			int x = plante->get_position_x();
			int y = plante->get_position_y();

			// zone de securité pour chaque plante.
			// dans chaque zone, il y'a qu'une seule plante
			if (xm > x - taille && xm < x + taille && ym > y - taille && ym < y + 32)
			{
				can_plant = false;
			}
			Champs_.draw_image(x, y, 0, 0, plante->get_etat_plante(), NO_opacite(plante->get_etat_plante()));
		}

		//----------------------Fleur---------------------
		//Remplissage du vector Plantes en fonction du keyboard et du nombre de clic.
		if (disp.is_keyR())
		{	//Affichage temporelle de la plante choisie
			copy_jardin.draw_image(xm, ym, 0, 0, rose5, NO_opacite(rose5));
			copy_jardin.draw_text(xm, ym - taille, "Fleur", marron, 1, 1, 20);

			if (disp.button() & 1 && can_plant && graines >= 1)
			{
				
				Plante* rose = new Fleur(1); 
				//Appel de la fonction Planter
				rose->Planter(xm, ym);
				//remplissage du vecteur Plantes Pour chque clic.
				Plantes.push_back(rose);
				//diminuer le nbre de graines apres ajout.
				graines -= 1;
			}
		}
		if (disp.is_keyT())
		{
			copy_jardin.draw_image(xm, ym, 0, 0, tulip5, NO_opacite(tulip5));
			copy_jardin.draw_text(xm, ym - taille, "Fleur", marron, 1, 1, 20);

			if (disp.button() & 1 && can_plant && graines>=1)
			{
				Plante* tulip = new Fleur(3);  

				tulip->Planter(xm, ym);
				Plantes.push_back(tulip);
				// Diminuer la valeur de "graines" de 1
				graines -= 1;
			}
		}
		if (disp.is_keyN())
		{
			copy_jardin.draw_image(xm, ym, 0, 0, sunflower5, NO_opacite(sunflower5));
			copy_jardin.draw_text(xm, ym - taille, "Fleur", marron, 1, 1, 20);

			if (disp.button() & 1 && can_plant && graines >= 1)
			{
				Plante* sunflower = new Fleur(7);  //(3)

				sunflower->Planter(xm, ym);
				Plantes.push_back(sunflower);
				graines -= 1;
			}
		}
		//----------------------Legume---------------------
		if (disp.is_keyX())
		{
			copy_jardin.draw_image(xm, ym, 0, 0, tomato5, NO_opacite(tomato5));
			copy_jardin.draw_text(xm - taille / 2, ym - taille, "Legume", marron, 1, 1, 20);

			if (disp.button() & 1 && can_plant && graines >= 2)
			{
				Plante* tomato = new Legume(15);
				tomato->Planter(xm, ym);
				Plantes.push_back(tomato);
				graines -= 2;
			}
		}
		if (disp.is_keyE())
		{
			copy_jardin.draw_image(xm, ym, 0, 0, eggplant5, NO_opacite(eggplant5));
			copy_jardin.draw_text(xm - taille / 2, ym - taille, "Legume", marron, 1, 1, 20);

			if (disp.button() & 1 && can_plant && graines >= 2)
			{
				Plante* eggplant = new Legume(10);
				eggplant->Planter(xm, ym);
				Plantes.push_back(eggplant);
				graines -= 2;
			}
		}
		if (disp.is_keyQ())
		{
			copy_jardin.draw_image(xm, ym, 0, 0, potato5, NO_opacite(potato5));
			copy_jardin.draw_text(xm - taille / 2, ym - taille, "Legume", marron, 1, 1, 20);

			if (disp.button() & 1 && can_plant && graines >= 2)
			{
				Plante* potato = new Legume(12);
				potato->Planter(xm, ym);
				Plantes.push_back(potato);
				graines -= 2;
			}
		}
		if (disp.is_keyI())
		{
			copy_jardin.draw_image(xm, ym, 0, 0, turnip5, NO_opacite(turnip5));
			copy_jardin.draw_text(xm - taille/2, ym -taille, "Legume", marron, 1, 1, 20);

			if (disp.button() & 1 && can_plant && graines >= 2)
			{
				Plante* turnip = new Legume(6); 
				turnip->Planter(xm, ym);
				Plantes.push_back(turnip);
				graines -= 2;
			}
		}
		if (disp.is_keyU())
		{
			copy_jardin.draw_image(xm, ym, 0, 0, cucumber5, NO_opacite(cucumber5));
			copy_jardin.draw_text(xm - taille / 2, ym - taille, "Legume", marron, 1, 1, 20);

			if (disp.button() & 1 && can_plant && graines >= 2)
			{
				Plante* cucumber = new Legume(4);  
				cucumber->Planter(xm, ym);
				Plantes.push_back(cucumber);
				graines -= 2;
			}
		}
		//----------------Plantes a graines----------------
		if (disp.is_keyL())
		{
			copy_jardin.draw_image(xm, ym, 0, 0, lemon5, NO_opacite(lemon5));
			copy_jardin.draw_text(xm - taille / 2, ym - taille, "à graines", marron, 1, 1, 20);

			if (disp.button() & 1 && can_plant && graines >= 3)
			{
				Plante* lemon = new Plante_Grain(16);
				lemon->Planter(xm, ym);
				Plantes.push_back(lemon);
				graines -= 3;
			}
		}
		if (disp.is_keyO())
		{
			copy_jardin.draw_image(xm, ym, 0, 0, orange5, NO_opacite(orange5));
			copy_jardin.draw_text(xm - taille / 2, ym - taille, "à graines", marron, 1, 1, 20);

			if (disp.button() & 1 && can_plant && graines >= 3)
			{
				Plante* orange = new Plante_Grain(14);
				orange->Planter(xm, ym);
				Plantes.push_back(orange);
				graines -= 3;
			}
		}
		if (disp.is_keyA())
		{
			copy_jardin.draw_image(xm, ym, 0, 0, avocado5, NO_opacite(avocado5));
			copy_jardin.draw_text(xm - taille / 2, ym - taille, "à graines", marron, 1, 1, 20);

			if (disp.button() & 1 && can_plant && graines >= 3)
			{
				Plante* avocado = new Plante_Grain(13);
				avocado->Planter(xm, ym);
				Plantes.push_back(avocado);
				graines -= 3;
			}
		}
		if (disp.is_keyS())
		{
			copy_jardin.draw_image(xm, ym, 0, 0, strawberry5, NO_opacite(strawberry5));
			copy_jardin.draw_text(xm - taille / 2, ym - taille, "à graines", marron, 1, 1, 20);

			if (disp.button() & 1 && can_plant && graines >= 3)
			{
				Plante* strawberry = new Plante_Grain(8);
				strawberry->Planter(xm, ym);
				Plantes.push_back(strawberry);
				graines -= 3;
			}
		}
		if (disp.is_keyC())
		{
			copy_jardin.draw_image(xm, ym, 0, 0, corn5, NO_opacite(corn5));
			copy_jardin.draw_text(xm - taille / 2, ym - taille, "à graines", marron, 1, 1, 20);

			if (disp.button() & 1 && can_plant && graines >= 3)
			{
				Plante* corn = new Plante_Grain(11);
				corn->Planter(xm, ym);
				Plantes.push_back(corn);
				graines -= 3;
			}
		}
		if (disp.is_keyG())
		{
			copy_jardin.draw_image(xm, ym, 0, 0, grapes5, NO_opacite(grapes5));
			copy_jardin.draw_text(xm - taille / 2, ym - taille, "a graines", marron, 1, 1, 20);

			if (disp.button() & 1 && can_plant && graines >= 3)
			{
				Plante* grapes = new Plante_Grain(9);
				grapes->Planter(xm, ym);
				Plantes.push_back(grapes);
				graines -= 3;
			}
		}
		if (disp.is_keyM())
		{
			copy_jardin.draw_image(xm, ym, 0, 0, melon5, NO_opacite(melon5));
			copy_jardin.draw_text(xm - taille / 2, ym - taille, "à graines", marron, 1, 1, 20);

			if (disp.button() & 1 && can_plant && graines >= 3)
			{
				Plante* melon = new Plante_Grain(5);  
				melon->Planter(xm, ym);
				Plantes.push_back(melon);
				graines -= 3;
			}
		}
		if (disp.is_keyP())
		{
			copy_jardin.draw_image(xm, ym, 0, 0, pineapple5, NO_opacite(pineapple5));
			copy_jardin.draw_text(xm - taille/2, ym - taille, "a graines", marron, 1, 1, 20);

			if (disp.button() & 1 && can_plant && graines >= 3)
			{
				Plante* pineapple = new Plante_Grain(2);  
				pineapple->Planter(xm, ym);
				Plantes.push_back(pineapple);
				graines -= 3;
			}
		}

//<<<<<<<<<<<<<<<<<<<<<<< JARDINIERS >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		//faire évoluer le Jardinier 
		for (int i = 0; i < Jardiniers.size(); i++)
		{
			time_t t0 = time(0);
			Jardiniers[i].draw_Jardinier(t0);
		}

		for (int i = 0; i < Jardiniers.size(); i++)
		{
			// Appel de fonction
			trajet_jardinier_(Plantes, Jardiniers);

			int x = Jardiniers[i].get_position_x();
			int y = Jardiniers[i].get_position_y();

			// zone de sécurité de chaque jardinier
			//on ne peut pas mettre qu'un seul jardinier dans chaque zone
			if (xm > x - 2*taille && xm < x + 2*taille && ym > y - 2*taille && ym < y + 2*taille)
			{
				mettre_Jard = false;
				can_plant = false;
			}
			// Affichage du Jardinier
			copy_jardin.draw_image(x, y, 0, 0, Jardiniers[i].get_etat_jardinier(), NO_opacite(Jardiniers[i].get_etat_jardinier()));

			for (int j = 0; j < Plantes.size(); j++)
			{
				int x_p = Plantes[j]->get_position_x();
				int y_p = Plantes[j]->get_position_y();
				// si le jardinier est dans le carré(1) de la plante// (des fois (x_p==x && y_p==y) n'est pas verifie)
				if (x > x_p-1 && x < x_p+1 && y > y_p - 1 && y < y_p + 1)
				{
					Champs_.draw_image(x_p, y_p, 0, 0, ground, 255);
					if (Plantes[j]->get_type() == 3) {
						// la recolte de plante a graine, augmente le stocke de graines.
						graines += 5;
					}
					if (Plantes[j]->get_type() == 2) {
						// manger un legume restaure le moral du jardinier.
						Jardiniers[i].set_moral(3);
					}
				}
			}
		}

		if (disp.is_keySPACE())
		{
			copy_jardin.draw_image(xm, ym, 0, 0, WaitTop_g, NO_opacite(WaitTop_g));
			if (disp.button() & 1 && mettre_Jard == true && can_plant == true && graines >= 4)
			{
				Jardinier J;
				// initialisation du time pour le chgmt de moral
				time_t ttime = time(0);

				J.set_date_chgmt_moral(ttime);
				J.set_position_x(xm);
				J.set_position_y(ym);

				//remplir le vecteur Jardinier
				Jardiniers.push_back(J);
				graines -= 4;
			}
		}

		disp._update_window_pos();
	}


}
