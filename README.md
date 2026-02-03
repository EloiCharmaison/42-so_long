# so_long

## 🕹️ Description

**so_long** est un petit jeu 2D développé en C dans le cadre du cursus de l’école 42.  
Le but du projet est de créer un jeu simple en utilisant la **MiniLibX**, tout en respectant des règles strictes de parsing de map, de gestion des événements et de rendu graphique.

Le joueur doit collecter tous les objets présents sur la carte avant de rejoindre la sortie.

---

## 🎯 Objectifs du jeu

- Se déplacer sur une carte 2D
- Collecter tous les collectibles (`C`)
- Rejoindre la sortie (`E`) **uniquement après** avoir tout collecté
- Éviter de traverser les murs (`1`)
- Compter et afficher le nombre de mouvements

---

## 🗺️ La map

La map est fournie via un fichier `.ber` et doit respecter les règles suivantes :

- La map doit être **rectangulaire**
- Elle doit être **entourée de murs**
- Elle doit contenir au minimum :
  - **1 joueur** (`P`)
  - **1 sortie** (`E`)
  - **1 collectible** (`C`)
- Les caractères autorisés sont uniquement :
  - `0` : sol vide
  - `1` : mur
  - `C` : collectible
  - `E` : sortie
  - `P` : joueur
- Une **ligne vide finale est autorisée**

### Exemple de map valide :
111111
1P0C01
100001
1C0E01
111111

## ⌨️ Contrôles

| Touche | Action        |
|------|---------------|
| W / ↑ | Monter        |
| S / ↓ | Descendre     |
| A / ← | Aller à gauche|
| D / → | Aller à droite|
| ESC   | Quitter le jeu|

---

## 🧠 Gestion des événements

- Le joueur ne peut pas traverser les murs
- La sortie est bloquée tant que tous les collectibles ne sont pas récupérés
- Chaque déplacement valide incrémente le compteur de mouvements
- La fermeture de la fenêtre quitte proprement le programme

---

## 🛠️ Compilation

### Prérequis
- Linux ou WSL
- MiniLibX
- X11 libraries

### Compilation
```bash
make

### Execution
./so_long maps/map.ber