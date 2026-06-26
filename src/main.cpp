#include <iostream>
#include <cstdio>
using namespace std;

struct qcm
{
    std::string avantquestion;
    std::string question;
    std::string propositions;
    int rep;
};
void fonction (void);
void charger_fichier(qcm tab[]);
int finish = 0;

int main()
{
    std::cout << "***QUESTIONNAIRE A CHOIX MULTIPLES*** \n\n";
    std::cout<<"\n1.Vous choisirez un theme que vous pouvez changer a tout moment\n2.Pour chaque question, entrez la lettre correspondant a votre reponse\n3.En fonction de votre score final, un message personnalise s'affichera\n\n";
    while(finish<1)
    {
        fonction();
    }
}

void charger_fichier(qcm tab[])
{
    // Ici, On cree une variable fichier qui va prendre la valeur du fichier texte dans le programme.
    // D'ailleurs on pointe vers la variable pour avoir l'adresse du fichier.
    //"r" ici c'est pour dire qu'on va venir lire le fichier "qcm.txt"
    FILE *fichier = fopen("qcm.txt","r");


    // On vient décréter le nombre maximum de caractères que peut avoir une section. Par exemple on a mit 100 caract-res maximum à la variable avant question car se sera toujours moins de 100 caractères pour sure,
    // Par exemple on aura "Question X :" on voit qu'on est loin de dépasser les 100 caractères, à la différence de propositions ou là on se laisse une marge plus grande car c'est tout une phrase.
    char avantquestion[100];
    char question[300];
    char propositions[500];
    int rep; // ici c'est la variable qui contient la bonne réponse donc elle tient sur 1 seul caractère donc pas besoin de tableau


    for(int i=0;i<30;i++)
    {
// on vient lire dans le fichier texte une partie du texte que l'on a mit. Cette partie est définie comme ceci : 99 caractères maximum, ensuite on vient encadrer une règle dans [], et on vient dire avec "^" 
// que l'on va jusqu'au caractère "|", enfin on désigne cette chaine de caractère à la variable avantquestion
        fscanf(fichier," %99[^|]",avantquestion);

        fscanf(fichier,"|%299[^|]",question);

        fscanf(fichier,"|%499[^|]",propositions);

        fscanf(fichier,"|%d",&rep); // ici on vient lire l'entier qui suit le dernier | 

        // Dès qu'on a tout lu, on va ensuite mettre les questions dans les tableaux pour les garder en mémoire sans avoir besoin de repasser par un scan de fichier

        // Ici tab[i] represente la question numero i du questionnaire. (donc quand i = 0 on est à la question une par exemple)
        tab[i].avantquestion = avantquestion;
        tab[i].question = question;
        tab[i].propositions = propositions;
        tab[i].rep = rep;
    }

    // Une fois que les 30 questions sont lues dans la boucle, on ferme le fichier.
    fclose(fichier);
}
// cet fonction sert à afficher le thème choisit par l'utilisateur et garder en mémoire son choix.
// on utilise pour les variables thème, question et score "static" pour éviter qu'à chaque appel de fonction on perde la valeur du score par exemple ou bien du thème choisit.
void fonction (void)
{
    typedef enum { choix, histoire, sports, sciences } theme;
    static theme etat_courant=choix;
    static int question=1;
    static int score=0;
    int decision,reponse, action,choix_final;
    qcm tab[30];
    charger_fichier(tab);

    switch (etat_courant)
    {

    case choix :
    {
        std::cout<<"Choisissez votre theme : entrez 1 pour histoire-geo, 2 pour sports et 3 pour sciences : ";
        cin>>decision;
        system("cls");
        if (decision==1)etat_courant=histoire;

        if (decision==2)

        etat_courant=sports;

        if(decision==3)
            etat_courant=sciences;
        break;
    }


    case histoire:
    {
        decision=0;
        for ( int i=0;i<10;i++) // pour les questions d'histoire géo dans notre fichier texte, ça va de la première ligne à la dixième, d'ou la boucle qui va de 0 à 9
        {
            std::cout<<"\n\nTHEME : HISTOIRE-GEO\n\n";
            std::cout<<tab[i].avantquestion<<tab[i].question<<"\n"<<tab[i].propositions<<"Votre choix : "; // on affiche l'énoncé d'une question d'histoire géo 
            std::cin>>reponse; // on laisse l'utilisateur répondre
            if(i<10){ 
                if(reponse == tab[i].rep) // on compare la réponse de l'utilisateur avec la bonne réponse qu'on avait placé et scanné dans la fichier texte.
                {
                    std::cout<<"\nBonne reponse, +1 point\n"; 
                    score++;
                }
                else
                {
                    std::cout<<"\nMauvaise reponse, +0 point\n";
                }

                std::cout<<"Question suivante (1) ou changer de theme (2) : ";
                std::cin>>action;
                system("cls"); // après qu'on ait finit d'y répondre on supprime ce qu'il y avait dans la console, pour que se ne soit pas visuellement encombrant.
                if(action == 2) // l'utilisateur a chosiit de changer de thème
                {
                    etat_courant = choix;
                    question = 1;
                    return;
                }
            }
            if (i==9) // quand i = 9 dans la boucle qui précède on sait qu'on a finit les 10 questions du thèmes d'ou la comparaison avec 9
            {
                std::cout<<"C'est termine ! Entrez 1 pour voir votre score final, 2 pour changer de theme : ";
                std::cin>>action;
                system("cls");
                if(action==1)
                {
                    std::cout<<"\nScore final en histoire-geo : "<<score<<"\n";
                    finish=1;
                    return;
                }
                if(action == 2)
                {

                    etat_courant = choix;
                    question = 1;
                    return;
                }
            }
        }
        break;
    }


    case sports :

        {
            decision=0;
            for ( int i=10;i<20;i++)
            {
                std::cout<<"\n\nTHEME : SPORTS\n\n";
                std::cout<<tab[i].avantquestion<<tab[i].question<<"\n"<<tab[i].propositions<<"Votre choix : ";
                std::cin>>reponse;
                if(reponse == tab[i].rep)
                {
                    std::cout<<"\nBonne reponse, +1 point\n";
                    score++;
                }
                else
                {
                    std::cout<<"\nMauvaise reponse, +0 point\n";
                }
                std::cout<<"Question suivante (1) ou changer de theme (2) : ";
                std::cin>>action;
                system("cls");
                if(action == 2)
                {
                    etat_courant = choix;
                    question = 1;
                    return;
                }
                if (i==19)
                {
                    std::cout<<"C'est termine ! Entrez 1 pour voir votre score final, 2 pour changer de theme : ";
                    std::cin>>action;
                    system("cls");
                    if(action==1)
                    {
                        std::cout<<"\nScore final en sports : "<<score<<"\n";
                        finish=1;
                        return;
                    }
                    else if(action == 2)
                    {
                        etat_courant = choix;
                        question = 1;
                        return;
                    }
                }
            }
            break;
        }


    case sciences :
    {
        decision=0;
        for ( int i=20;i<30;i++)
        {
            std::cout<<"\n\nTHEME : SCIENCES\n\n";
            std::cout<<tab[i].avantquestion<<tab[i].question<<"\n"<<tab[i].propositions<<"Votre choix : ";
            std::cin>>reponse;
            if(reponse == tab[i].rep)
            {
                std::cout<<"\nBonne reponse, +1 point\n";
                score++;
            }
            else
            {
                std::cout<<"\nMauvaise reponse, +0 point\n";
            }

            std::cout<<"Question suivante (1) ou changer de theme (2) : ";
            std::cin>>action;
            system("cls");
            if(action == 2)
            {
                etat_courant = choix;
                question = 1;
                return;
            }

            if(i==29)
            {
                std::cout<<"C'est termine ! Entrez 1 pour voir votre score final, 2 pour changer de theme : ";
                std::cin>>action;
                system("cls");
                if(action==1)
                {
                    std::cout<<"\nScore final en sciences : "<<score<<"/10\n";
                    finish=1;
                    return;
                }
                else if(action == 2)
                {
                    etat_courant = choix;
                    question = 1;
                    return;
                }
            }
        }
    }
    break;
    }
}
