/************************************************************
 * 															*
 * 	Auteur 	:	Thomas legrand								*	
 * 	Date	:	11 mai 2015									* 
 *	Fichier	:	utils.cpp (Fichier source)					*
 *															*
 * 	Objectif:	diverses fonctions utiles					*
 * 															*	
 ************************************************************/

/*
 * \brief  abs calcul la valeur absolue d'une valeur
 *
 * \param valeur dont on souhaite la valeur absolue
 * \return retourne la valeur absolue de l'entier en paramètre
 */
int abs(int n)
{
    return n < 0 ? -n : n;
}


 /**
 * \brief Calcul la moyenne d'un tableau
 *
 * \param Tableau dont on souhaite connaitre la moyenne
 * \return retourne la moyenne du tableau
 */
int moyenne(int tab[],int _tailleMaxTab)
{
    int calcule = 0, i = 0;
    int taille = 0;
    for(i=0;i<_tailleMaxTab;i++)
    {
        if(tab[i] != 0) {
            calcule += tab[i];
            ++taille;		
        }
    }

    return (calcule/taille);
}

/** 
 * \brief  remplirTab permet d'ajouter un nouvel élément à la dernière position d'un tableau
 *
 * \param tab est le tableau dans lequel on souhaite mettre une nouvelle valeur
 * \param nvlElt est le nouvel élement qu'on veut mettre en début de tableau
 */
void remplirTab(int tab[], int nvlElt,int _tailleMaxTab)
{
    int i = 0;

    for(i=0;i<(_tailleMaxTab-1);i++)
    {
        tab[i+1] = tab[i];
    }

    tab[0] = nvlElt;
}
