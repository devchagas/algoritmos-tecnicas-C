#include <stdio.h>
#include <stdlib.h>

//#include "list_array.h"
#include "list_enc.h"

int main(int argc, char *argv[]) {  
  /*   
   //LIST ARRAY   
   list *teste = NULL;
   int aux = 10;

   teste = create_list();
   
   insertAtFirst(&aux, teste);
   print(teste);
   
   aux = 20;
   insertAtFirst(&aux, teste);
   print(teste);
   
   aux = 5;
   insertAtLast(&aux, teste);
   print(teste);
   
   aux = 7;
   insertAtPosition(&aux, 7, teste);
   print(teste);
   
   aux = 28;
   insertAtPosition(&aux, 2, teste);
   print(teste);
   
   printf("Size: %d\n", size(teste));

   if (search(teste, 5, &aux))
       printf("Achou!!!\n");

   removeItem(teste, 0);
   print(teste);
   
   removeItem(teste, 1);
   print(teste);
   
   removeItemByKey(teste, 5);
   print(teste);

   destroy(teste);
   */
   
   //LIST_ENC
   list *teste = create_list();
   
   insertAtFirst(teste, create_node(10));
   print(teste);

   insertAtLast(teste, create_node(20));
   print(teste);

   insertAtFirst(teste, create_node(31));
   print(teste);

   insertAtPosition(teste, create_node(7), 1);
   print(teste);
   
   printf("Size: %d\n", size(teste));

   if (search(teste, 10) != NULL)
       printf("Achou!!!\n");

   removeItemByKey(teste, 31);
   print(teste);
   
   removeItemByKey(teste, 10);
   print(teste);
   
   removeItemByKey(teste, 20);
   print(teste);
   
   removeItemByKey(teste, 7);
   print(teste);
   
   destroy(&teste);
   
   
   getch();
   return 0;
}