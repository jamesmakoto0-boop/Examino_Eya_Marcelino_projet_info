//  Copyright (c) 2020 Antoine Tran Tan
//

#include "my_header.h"
#include <iostream>
#include <string>

typedef struct
{
 std::string question;
 std::string a;
 std::string b;
 std::string c;
 std::string d;
 char reponse;
} Question;

int main(int argc, char *argv[])
{
 (void)argc;
 (void)argv;

 Question qcm[] = {
 {"RESISTANCE DE 140 kilo-ohms","BRUN JAUNE JAUNE","JAUNE VERT NOIR","ROUGE BLEU JAUNE","BRUN BLEU NOIRE",'A'},
 {"LES FORMULES EXACTES ?","1,2,3","3,4","1,2,4","2,3,4",'C'},
 {"Resistance equivalente ?","60 Ohms","5.45 Ohms","54.5 Ohms","6 kOhms",'B'},
 {"Tension aux bornes de R2 ?","0.22 V","2 V","220 mV","0.2 V",'B'},
 {"UN MELANGEUR EST ?","un additionneur et un soustracteur de frequences","un modulateur d'amplitude","un oscillateur a frequence variable","un modulateur en frequence",'A'},
 {"CAPACITE EQUIVALENTE ?","12 pF","1200 nF","29.8 pF","48 pF",'A'},
 {"On double le nombre de spires d'une bobine. Que devient son coefficient de self induction ?","il ne change pas","il double","il est divise par deux","il quadruple",'D'},
 {"LA PULSATION D'UN SIGNAL DE 100 Hz EST DE :","628 Rad/s","314 Rad/s","6.28 Rad/s","31.4 Rad/s",'A'},
 {"TENSION CRETE D'UN SIGNAL DE TENSION EFFICACE 100 V ?","70.7 V","220 V","36 V","141 V",'D'},
 {"BANDE DE FREQUENCE OCCUPEE PAR LE SIGNAL ?","10 kHz","20 kHz","650 kHz","ne peut etre determinee",'B'},
 {"IMPEDANCE VUE A L'ENTREE DU TRANSFORMATEUR ?","90 ohm","2700 ohm","90000 ohm","900 ohm",'C'},
 {"Valeur de R4 ?","450 Ohms","350 Ohms","87.5 Ohms","250 Ohms",'A'},
 {"APPAREIL A UTILISER POUR MESURER 6 VOLTS SUR 110 KILO-OHMS ?","un galvanometre","un voltmetre electronique 20 Mohms","un amperemetre","un controleur de 10 Kohms",'B'},
 {"FREQUENCE SUPERIEURE D'UN OCTAVE A 1000 Hz ?","10 000 Hz","20 000 Hz","2000 Hz","8000 Hz",'C'},
 {"Relations liant frequence f, periode T, pulsation w ?","f=1/T, w=2.PI.f","f=T/w, f=2.PI.w","f=1/T, f=2.PI.w.T","f=T/w, f=2.PI.T",'A'},
 {"Largeur de bande d'un signal de 7 MHz module en amplitude par 1000 Hz ?","1000 Hz","2 kHz","6999 kHz","7001 kHz",'B'},
 {"Largeur de bande du filtre avec Q=52 et Fc=3536 Hz ?","427 Hz","213 Hz","68 Hz","490 Hz",'C'},
 {"IMPEDANCE A LA RESONANCE ? L=10 uH, R=5 ohms, C=400 nF","7 ohms","5 ohms","infinie","1000 ohms",'B'},
 {"Gamme de l'oscillateur local avec MF de 462 kHz pour recevoir 24 a 40 m ?","12962 ... 7962 kHz","11538 ... 7038 kHz","12962 ... 7500 kHz","7500 ... 12500 kHz",'A'},
 {"UNE DIODE AU SILICIUM DEVIENT CONDUCTRICE A PARTIR DE ...","0.4 V","0.7 V","1.2 V","12 V",'B'}
 };

 int score = 0;
 int nbQuestions = 20;
 char choix;

 std::cout << "QCM examino - exercice 1" << std::endl;
 std::cout << "Repondre A, B, C, D ou E pour passer" << std::endl << std::endl;

 for(int i=0;i<nbQuestions;i++)
 {
  std::cout << "Question " << i+1 << std::endl;
  std::cout << qcm[i].question << std::endl;
  std::cout << "A: " << qcm[i].a << std::endl;
  std::cout << "B: " << qcm[i].b << std::endl;
  std::cout << "C: " << qcm[i].c << std::endl;
  std::cout << "D: " << qcm[i].d << std::endl;
  std::cout << "Votre reponse : ";
  std::cin >> choix;

  if(choix >= 'a' && choix <= 'z')
  {
   choix = choix - 32;
  }

  if(choix == 'E')
  {
   std::cout << "question passee, 0 point" << std::endl;
  }
  else if(choix == qcm[i].reponse)
  {
   score = score + 3;
   std::cout << "bonne reponse, +3 points" << std::endl;
  }
  else
  {
   score = score - 1;
   std::cout << "mauvaise reponse, -1 point" << std::endl;
  }

  std::cout << "score actuel : " << score << std::endl;
  std::cout << "--------------------------" << std::endl;
 }

 std::cout << "Score final : " << score << " / " << nbQuestions*3 << std::endl;

 return 0;
}
