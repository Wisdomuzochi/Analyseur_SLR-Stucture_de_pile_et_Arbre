# Analyseur Syntaxique SLR & Constructeur d'AST 

Un analyseur syntaxique ascendant (Bottom-Up) robuste implémenté en **langage C**. Ce projet simule un automate à pile pour analyser des structures grammaticales basées sur des tables d'analyse LR et construit dynamiquement un Arbre Syntaxique Abstrait (AST).

Réalisé dans le cadre du module de **Compilation** (Master 1).

##  Fonctionnalités Clés

* ** Algorithme Décalage/Réduction :** Implémentation d'un automate à pile déterministe piloté par une table d'analyse LR.
* ** Génération d'AST :** Construction dynamique de l'Arbre Syntaxique Abstrait (Abstract Syntax Tree) au fur et à mesure de l'analyse.
* ** Robustesse et Fiabilité :**
    * **Compatibilité Multi-plateforme :** Réécriture du module de lecture (`read_file.c`) pour gérer automatiquement les formats de fichiers **Windows (CRLF)** et Unix (LF).
    * **Sanitisation des Entrées :** Filtrage intelligent des lignes vides et des caractères parasites pour prévenir les erreurs de segmentation (Segfaults).
    * **Gestion de la Mémoire :** Nettoyage complet de la pile et des structures arborescentes en fin d'exécution (Zéro fuite mémoire / Memory Leaks).

##  Installation et Compilation

### Prérequis
* Compilateur GCC
* Make

### Compilation
Exécutez simplement la commande `make` à la racine du projet pour compiler l'ensemble :

```bash
make
