# Sorting-Algorithms-performance-comparison
this small project is destined for comparing the performance and machine time for each sorting algorithm in C language


 ## Mini_Projets (Etude experimentale de la performmance des algorithme du Tri)
# Objectifs:
          1-Comprendre et implémenter différetes algorithmes de Tri.
          2-Maitriser les techniques de programmation en C.
            -> Gestion dynamique de mémoire
            ->Les Pointeurs(données,fonction)
          3-Utiliser le grapheur GNUPLOT.
            ->Utiliser un pipline (interface de Communication)
              entre l'application C et GNUPLOT.
# Travail a faire:
          1-Chercher les différentes méthodes de tri,les programmer et les mettre en bibliothéque/module:
            ->Tri Bulle.
            ->Tri par Selection.
            ->Tri Insertion.
            ->Tri Shell.
            ->Tri Rapide.
            ->Tri Fusion.
            ...
          2-Le comment?
            Tableau taille (pour plusieurs mesures) ->Methode Tri -> Tableau Trie
                                                Mesurer le temps machine.
            Le Systéme va fair appelle au différentes algorithme un par un et mesurer la durée de chaque methodes avec plusierus mesures,
            ensuite les mesures de temps donner par chaque methodes vont constituer une matrice dans la quelle chaque méthode presente une ligne,
            enfin on passe la matriche on GNUPLOT pour représenter chaque méthode en forme de courbe.
            on peut ajouter une analyse post-traitement
          3-Préparer les données de l'experience(des tableaux):
            -> Créer des listes (tableau) de données (entiers) aléatoires et chercher deux situations favorables/défavorables.
          4-Post-tratement des mesures:
            il faut trouver une méthode pour crée une courbe entre les différentes points qui est uniforme continue (les moyennes pondérées)la sommes des coefficients des pondérations égale a 1."Produit de Convolution"
            //pipopen pour communicer entre les applications. 

# Compétences:
    -->  Tableaux(Vecteurs/Matrice).
    --> Pointeurs(Tableaux dynamiques).
    --> Fonctions/Fonctions paramétre/pointeur sur fonction.
    --> Fonctions bibliotheque sur le temps systéme.CLOCKES CHECK pour calculer le temps
    --> Fonctions de la bibliiotheque pour generer des nombres aléatoires. / srand() et rand()

# Allures dans GNUPLOT après Lissage
![alt text](https://github.com/souhailOUARGUI/Sorting-Algorithms-performance-comparison.git/plot.jpg?raw=true)
