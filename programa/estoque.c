#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    FILE *w, *waux ;
    char b, nome[50], aux[50], AUX[50];
    int A, rep=1, quant, B, tem, C, D, aux_, E;
while(rep==1){
rep=0;
printf("================================\n   Controle de Estoque\n================================\nSelecione uma opção:\n1. Adicionar Item\n2. Remover Item\n3. Listar Estoque\n4. Sair\nOpção:");
scanf("%d",&A);
if(A==1){
    printf("Digite o nome do item:") ;
   scanf("%s", nome);
   strcat(nome,"\n");
   printf("Digite a quantidade: ") ;
   scanf("%d", &quant);
   w=fopen("estoque.txt","r");
waux=fopen("aux.txt","w");
C=0;
   while(fgets(aux, 50, w) != NULL){
    fprintf(waux, "%s", aux);
    if(strcmp(aux,nome)==0){
 fgets(aux,50,w);
 B=atoi(aux);
 B=B+quant;
 fprintf(waux,"%d\n", B);
 C=1;
    }
}
if(C==0){
    fprintf(waux,"%s%d\n", nome, quant);
}
fclose(waux);
fclose(w);
waux=fopen("aux.txt","r");
   w=fopen("estoque.txt","w");
   while(fgets(aux, 50, waux) != NULL){
fprintf(w, "%s", aux);
   }  
   fclose(waux);
fclose(w);
printf("Item adicionado com sucesso!\n");
}



else if(A==2){
printf("Digite o nome do item:") ;
   scanf("%s", nome);
   strcat(nome,"\n");
   printf("Digite a quantidade a ser removida: ") ;
   scanf("%d", &quant);
   w=fopen("estoque.txt","r");
waux=fopen("aux.txt","w");
D=0;
E=0;

   while(fgets(aux, 50, w) != NULL){
    if(strcmp(aux,nome)==0){
strcpy(AUX, aux);
 fgets(aux,50,w);
 B=atoi(aux);
 aux_=B;
 B=B-quant;
 if(B==0){
   D=1;
    E=1;
printf("Item removido do estoque!\n");
 }
 else if(B<0){
    E=1;
printf("Estoque insuficiente. Quantidade disponível: %d\n", aux_);
break;
 }
 else{
    E=1;
D=1;
fprintf(waux,"%s%d\n", AUX, B);
printf("Quantidade atualizada com sucesso!\n");
 }
 
    }
    else{
    fprintf(waux, "%s", aux);  
    }
}


fclose(waux);
fclose(w);


   if(D==1){
      waux=fopen("aux.txt","r");
   w=fopen("estoque.txt","w");
   while(fgets(aux, 50, waux) != NULL){
fprintf(w, "%s", aux);
   }  
   fclose(waux);
fclose(w);
   }
if(E!=1){
    printf("Item não encontrado.\n");
}
}



else if(A==3){
   E=0;
w=fopen("estoque.txt", "r");
while(fgets(aux, 50, w)!= NULL){
   if(E==0){
      printf("=============================\n        Estoque Atual\n=============================\n");
   }
E=1;
printf("Nome: %s", aux);
fgets(aux, 50, w);
printf("Quantidade: %s\n", aux);
}
if(E!=1){
printf("O estoque está vazio.\n");

}


}



else if(A==4){
printf("Obrigado por usar o Controle de Estoques! Até a próxima.");
return 1;
}
else{
printf("Opção inválida! Tente novamente.\n");
rep=1;
continue;
}
printf("Deseja realizar outra operação? (s/n):");
scanf(" %c", &b);
if(b=='s' || b=='S'){
    rep=1;
}
else{
printf("Obrigado por usar o Controle de Estoques! Até a próxima.");
return 1;
}
}
}
