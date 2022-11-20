/**
 * @name NANMEGNI_NGASSAM
 * @file Liste.h
 * @date 10/10/22
 * @brief Implémentation des primitives permettant la manipulation de ce type
*/

#include"Liste.h" // Inclusion du fichier d'interface ou header

//AJOUT DE PRODUIT EN TETE
List add_head(List l, int code, int quantity, float price)
{
  printf("\nAjout d'un produit en tete (code : %d quantity : %d price : %f)\n", code, quantity, price);

  //Declaration d'un pointeur sur un produit
  Prod *temp;
  temp = (Prod *)malloc(sizeof(Prod));

  //remplissage de ses champs
  temp->codeP = code;
  temp->quantP = quantity;
  temp->prixP = price;
  temp->next = l;

  return temp;
}

//AJOUT DE PRODUIT EN QUEUE
List add_tail(List l,int code, int quantity, float price)
{
  printf("\nAjout d'un produit en queue (code : %d quantity : %d price : %f)\n", code, quantity, price);

  //Declaration d'un pointeur sur un produit
  Prod *temp;
  temp = (Prod*)malloc(sizeof(Prod));

  //remplissage de ses champs
  temp->codeP = code;
  temp->quantP = quantity;
  temp->prixP = price;
  temp->next = NULL;

  //recherche du dernier element de la liste
  if( l == NULL)// La liste est initialement vide
  {
    return temp;
  }
  else
  {
    Prod *d;
    d = l;
    while (d->next != NULL) // tant que d est pas le dernier produit de la liste
    {
      d = d->next; // d passe au produit qui le suit
    }
    // sortant de la boucle, d pointera vers le dernier produit de la liste
    d -> next = temp; // on fait pointer l'ancien produit element vers le produit nouvellement crée
    
    return l;
  }
}

//SUPPRESSION EN TETE
List delete_head(List l)
{
  printf("\nSuppression d'un produit en tete\n");

  if(l == NULL) // La liste est initialement vide
  {
    return NULL;
  }
  else
  {
    /*un pointeur reste sur le premier produit, la liste se déplace sur le deuxième
    et le premier produit est libéré*/
    Prod *p;
    p = l;
    l = l -> next; 
    free(p); //Liberation du premier produit
    return l;
  }
}

//SUPPRESSION EN QUEUE
List delete_tail(List l)
{
  printf("\nSuppression d'un produit en queue\n");

  if( l == NULL || l->next == NULL) //Liste vide ou contenant un seul produit
  {
    return NULL;
  }
  else
  {
    /*Un pointeur qui parcourt la liste deux produits devant lui pour avoir toujours
    en memoire l'avant dernier et le dernier*/
    Prod *d = l;

    while (d->next->next != NULL)
    {
      d = d -> next; //passage au produit suivant
    }
    free(d->next->next);
    d -> next = NULL;
    
    return l;
  }
}

//RETOURNE LE RESTE D'UNE LISTE CHAINEE
List remain(List l)
{
  if(l == NULL)
  {
    return l;
  }
  else
  {
    return (l->next);
  }
}

//SUPPRESSION DE TOUS LES ELEMENTS D'UNE LISTE
void deleteAll(List *l)
{
  Prod *temp = *l;
  Prod *current = *l;
  while (current != NULL)
  {
    temp = current;
    free(current);
    current = NULL;
    current = temp->next;
  }
  *l = NULL;
}

//SUPPRESSION DE TOUS LES ELEMENTS D'UNE LISTE (sous-programme récursif)
void RDeleteAll(List *l)
{
  if(*l == NULL)
  {
  }
  else
  {
    List current = *l;
    free(*l);
    *l = NULL;
    RDeleteAll(&(current->next));
  }
}

//RENVOIE LE CODE DU I-ème PRODUIT DE LA LISTE
int codeElement(List l, int position)
{
  int current_position = 1;
  Prod *current = l;

  while (current != NULL && current_position < position)
  {
    current_position++;
    current = current ->next;
  }

  if (current_position < position)
  {
    return -1;
  }
  else
  {
    return current ->codeP;
  }
}

//DECOMPTE DES ELEMENTS D'UNE LISTE
int count(List l)
{
  Prod* temp;
  temp = l;
  int nombreElements = 0;

  while(temp != NULL)
  {
    nombreElements++;
    temp = temp -> next;
  } 
  return nombreElements;
}

//DECOMPTE DES ELEMENTS D'UNE LISTE (PROGRAMME RECURSIF)
int RCount(List l)
{
  if(l == NULL)
  {
    return 0;
  }
  else
  {
    return (1 + RCount(l->next));
  }
}

//DECOMPTE NOMBRE D'OCCURENCE D'UN CODE DANS UNE LISTE
int nombreOccurences(List l, int code)
{
  int nombreOccurence = 0;
  Prod *current = l;

  while (current != NULL)
  {
    if(current->codeP == code)
    {
      nombreOccurence++;
    }
    current = current->next;
  }
  return nombreOccurence;
}

//DECOMPTE NOMBRE D'OCCURENCES D'UN CODE DANS UNE LISTE (Sous-programme recursif)
int RnombreOccurences(List l, int code)
{
  if(l == NULL)
  {
    return 0;
  }
  else
  {
    if(l->codeP == code)
    {
      return (1 + RnombreOccurences(l->next, code));
    }
    else
    {
      return (RnombreOccurences(l->next, code));
    }
  }
}



//RECHERCHE PRODUIT
int search(List l, int code)
{
  printf("\nRecherche du produit ( code : %d)\n", code);
  int searchStatus = false;
  if(l != NULL)
  {
    //creation d'un pointeur pour le parcours de liste
    Prod *current;
    current = (Prod*)malloc(sizeof(Prod));
    current = l;

    /*Le pointeur parcourt la liste et s'il trouve le code rechercher,
    il fait passer l'indicateur de recherche à true*/
    while (current != NULL && searchStatus == false)
    {
      if(current->codeP == code)
      {
        searchStatus = true;
      }
      else
      {
        current = current->next;
      }
      
    }
  }

  return searchStatus;
}

//AFFICHAGE DES PRODUITS D'UNE LISTE
void display(List l)
{
  printf("*****AFFICHAGE DES PRODUITS DU MAGASIN*****\n");
  // Parcourt la liste et formate les caractéristiques des produits en console
  // creation d'un pointeur pour parcourir la liste
  Prod *current;
  current = l;

  if(current == NULL)
  {
    printf("Votre liste ne contient aucun produit\n");
  }

  while (current != NULL)
  {
    printf("Produit: \n");
    printf("code : %d  quantity : %d  price: %f\n", (current->codeP), (current->quantP), (current->prixP) );
    current = current->next;
  }
}