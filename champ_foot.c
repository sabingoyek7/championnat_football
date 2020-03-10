#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * type énuméré t_code permettant de représenter les noms des équipes, en
 *  utilisant le code unique associé à chacune d’elle dans la table
*/
typedef enum {
    akh,
    ant,
    bes,
    bur,
    riz,
    ela,
    esk,
    fen,
    gal,
    gaz,
    ank,
    kar,
    kas,
    erc,
    kay,
    kon,
    siv,
    tra
} t_code;

/**
 * type structure t_equipe permettant de stocker, pour chaque équipe : son
 * code ( code ), son nom court ( nom ) et sa ville ( ville ).
*/
typedef struct{
    t_code code;
    char *nom;
    char *ville;
} t_equipe;

/**
 * tableau equipes de type t_equipe , permettant de *stocker les données décrivant toutes les équipes de Süper Lig
*/

t_equipe equipes[18] = {
    {akh, "Akhisar", "Akhisar"},
    {ant, "Antalyaspor", "Antalya"},
    {bes, "Besiktas", "Istanbul"},
    {bur, "Bursaspor", "Bursa"},
    {riz, "Rizespor", "Rize"},
    {ela, "Elazigspor", "Elazig"},
    {esk, "Eskisehirspor", "Eskisehir"},
    {fen, "Fenerbahce", "Fenerbahce"},
    {gal, "Galatasaray", "Istanbul"},
    {gaz, "Gaziantepspor", "Gaziantep"},
    {ank, "Genclerbirligi", "Ankara"},
    {kar, "Karabukspor", "Karabuk"},
    {kas, "Kasimpasa", "Istanbul"},
    {erc, "Erciyesspor", "Kayseri"},
    {kay, "Kayserispor", "Kayseri"},
    {kon, "Konyaspor", "Konya"},
    {siv, "Sivasspor", "Sivas"},
    {tra, "Trabzonspor", "Trabzon"}
};

/**
 * fonction void affiche_nom(t_code code) qui reçoit le * code d’une équipe, et affiche le nom associé à ce code
*/
void affiche_nom(t_code code) {
    printf("%s",equipes[code].nom);
}

/**
 * structure t_rencontre: code de l’équipe jouant à domicile ( code_local ), code de l’équipe qui est reçue ( code_visiteur ), nombre de buts marqués par la première ( buts_local ) et par la seconde ( buts_visiteur )
*/
typedef struct {
    t_code code_local;
    t_code code_visiteur;
    int buts_local;
    int buts_visiteur;
} t_rencontre;

/**
 * fonction void affiche_rencontre(t_rencontre rencontre) qui
  affiche le résultat de la rencontre reçue en paramètre
*/
void affiche_rencontre(t_rencontre rencontre) {
    affiche_nom(rencontre.code_local);
    printf(" %d - %d ", rencontre.buts_local, rencontre.buts_visiteur);
    affiche_nom(rencontre.code_visiteur);
    printf("\n");
}

/**
 * fonction void initialise_score(t_rencontre* rencontre) qui
initialise aléatoirement le score de la rencontre passée en paramètre
*/
void initialise_score(t_rencontre* rencontre){
    srand(time(NULL));
    rencontre->buts_local = (rand() % 6);
    rencontre->buts_visiteur = (rand() % 6);
}

int main(int argc, char const *argv[])
{
    t_rencontre r = {ant,ank,2,0};
    initialise_score(&r);
    affiche_rencontre(r);
    //affiche_nom(ant);
    return EXIT_SUCCESS;
}
