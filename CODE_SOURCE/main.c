#include<stdio.h>
#include<stdlib.h>
#include"LISTE/Liste.h"

int main()
{
  printf("*****Creation d'une nouvelle liste vide*****\n");
  List shop;
  shop = NULL;
  display(shop); 


  //Adding to shop a new items, book( code: 4587, quantity: 234, price: 2.5) shirt( code : 7, quantity : 1, price : 20.04)
  int code = 4587, quantity = 234;
  float price = 2.5;
  shop = add_head(shop, code, quantity, price);
  shop = add_head(shop,07,01,20.04);
  shop = add_head(shop,9,01,10.04);

  
  display(shop);

  int fin = codeElement(shop, 5);
  if (fin == -1)
  {
    printf("La taille entree est superieur a celle du tableau");
  }
  else
  {
    printf("Le code correspondant a la position renseigne est %d", fin);
  }
  

  return(0);
}