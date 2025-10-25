# Systeme de Gestion de Bibliotheque

Une application de gestion de bibliotheque developpee en C++ avec Qt, utilisant des fichiers de donnees pour la persistence.

## Fonctionnalites Principales

### Gestion des Livres
- Ajout, modification et suppression de livres
- Recherche de livres par titre, auteur ou ISBN
- Gestion des informations livres dans `livre.dat`
- Suivi du stock disponible

### Gestion des Lecteurs
- Inscription et gestion des lecteurs
- Informations stockees dans `lecteur.dat`
- Historique des emprunts par lecteur
- Statut d'adhesion

### Systeme d'Emprunt
- Pret et retour de livres
- Gestion des emprunts dans `pret.dat`
- Calcul des dates de retour
- Suivi des retards

### Interface Utilisateur
- Interface graphique intuitive avec Qt
- Navigation par onglets ou menus
- Recherche en temps reel
- Generation de rapports

## Installation et Configuration

### Prérequis
- Qt 5.15 ou superieur
- Compilateur C++ (g++ ou MinGW)
- CMake (optionnel)

### Installation

**Cloner le depot :**
```bash
>> git clone https://github.com/gyvenolaan360x-debug/bibliotheque-gestion.git
cd bibliotheque-gestion

# Avec qmake
>> qmake bibliotheque-gestion.pro
    make

    # Ou avec CMake
>> mkdir build
    cd build
    cmake ..
    make

./bibliotheque-gestion
