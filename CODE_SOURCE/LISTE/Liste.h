/**
 * @name NANMEGNI_NGASSAM
 * @file Liste.h
 * @date 10/10/22
 * @brief Defintion du type produit et primitives permettant la manipulation de ce type
*/


#ifndef LISTE_H
#define LISTE_H
#include<stdlib.h>
#include<stdio.h>
#define true 1
#define false 0

//Definition du type Produit
typedef struct prod
{
  int codeP;
  int quantP;
  float prixP;
  struct prod *next;
}Prod;

// Definition du type liste chainée de Produit
typedef Prod *List;


/* ENTETE DES METHODES USUELLES SUR LES PRODUITS */

//Elle ajoute un produit(code, quantité et prix) en tête d'une liste chainée
List add_head(List l, int code, int quantity, float price);

//Elle ajoute un produit(code, quantité et prix) en queue d'une liste chainée
List add_tail(List l, int code, int quantity, float price);

// Elle supprime le premier produit d'une liste chainée de produits
List delete_head(List l);

//Elle supprime le dernier produit d'une liste chainée de produits
List delete_tail(List l);

//retourne la liste privé de son premier element
List remain(List l);

//supprime tous les elements d'une liste
void deleteAll(List *l);

//supprime tous les elements d'une liste(sous-programme récursif)
void RDeleteAll(List *l);

//renvoie le code du i-ème élément de la liste
int codeElement(List l, int position);

//renvoie le code du i-ème élément de la liste (sous-programme recursif)
int RcodeElement(List l, int position); 

//Retourne le nombre d'éléments d'une liste 
int count(List l);

//retourne le nombre d'éléments d'une liste (sous-programme récursif)
int RCount(List l);

//retourne le nombre d'occurences d'un produit dans une liste
int nombreOccurences(List l, int code);

//retourne le nombre d'occurences d'un produit dans une liste (sous-programme recursif)
int RnombreOccurences(List l, int code);

//Elle vous indique si oui(1) ou non(0), un produit est present dans la liste
int search(List l, int code);

//Elle affiche l'ensemble des elements d'une liste
void display(List l);


#endif // LISTE_H