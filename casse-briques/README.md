#
Le programme utilise de la programmation Orienté Object pour structurer et encapsuler les détails de la SDL.

main.cpp : 
==========
	Le point d'entrée du programme, contenant la méthode main(). Ici on instancie une instance de la classe App, 
	et on lance la boucle de jeu.


La classe App :
===============
	Qui implémente la logique de jeu, elle encapsule les détaille de la SDL, et instancie des objets des classes
	Player, Ball et une liste de briques (la classe Brick)

	Cette classe, fait un update des objets, elle prépare le dessin dans l'objet renderer, et elle actualise l'affichage.

	Cette classe utilise la classe EventHandler pour détecter les différents évènements : fermeture de la fenête, clavier et/ou souris.

La classe EventHandler :
=========================
	Elle s'occupe de détecter les évènement et envoie des message à l'instance de la classe Player pour modifier sa position (selon les touches claviers et le déplacement de la souris).

La classe GameElement :
========================
	C'est la classe mère des classes qui représente des éléments dynamiques du jeu, comme Player, Ball et Brick.
	Elle contient une méthode virtuelle : virtual void draw();
	Elle contient la position ainsi que la taille d'un élément de jeu (a game element) (factoriser cette aspect entre player, ball et briques)

La classe Player :
===================
	Elle maintient des informations sur le joeurs, comme : la vitesse de déplacement, nombre de vies et le score.
	Elle hérite de la classe GameElement.

La classe Ball :
===================
	Elle maintient des informations sur la bale : la vitesse, la vélocité sur l'axe des X et la vélocité sur l'axe des Y

La classe Brick :
===================
	Elle maintient des informations sur brique : niveau de résistance (avec la quelle on déduit la couleur)
		Rouge : niveau 1 (le plus faible)
		Vert : niveau 2 (le moyen)
		Bleu : niveau 3 (le plus fort)



# Compilation:

Outils:
* CMake 3.6 min
* g++ /clang++/ visual-studio compatible C++17

Testé sous:

* linux
* windows
* mac
* virtual-box


Compilation linux-bash:

```

mkdir build_tp
cd build_tp
cmake ../basetp_progav
make -j4
```

Sinon QtCreator permet de lire les projets CMake



