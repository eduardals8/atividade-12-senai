#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>

typedef struct {
	
	char estudantes_t;
	double scores[4];
	double total;
	
} estudantes_t;


void registrar_aluno(estudantes_t *est){
	       	
	char aluno[10];
	  
	    printf("Digite o nome do aluno:\n");
	    scanf("%s", aluno);
		printf("Digite a nota do aluno  %s  (de 0 ate 10): \n", aluno);
		scanf("%lf", &(est->scores)[0]);
	    scanf("%lf", &(est->scores)[1]);
	    scanf("%lf", &(est->scores)[2]);
	    scanf("%lf", &(est->scores)[3]);
	
			float nota = (est->scores[0]+ est->scores[1] + est->scores[2] + est->scores[3]);
       		float media = (nota /4);
       		est->total = media;
       
       
       	printf("A nota geral do aluno é:\n %f %f",nota, media);
       
    }
void editar_estudantes(estudantes_t *est, int _s){
 if (!_s){
   printf("Não há estudantes cadastrados! \n");
   return;
  }
  int i;

 printf("Digite qual o estudante (1 - %d):", _s);
 scanf("%d",&i);
 
 i--;
 
 if(i < 0 || i > _s - 1){
     printf("Este estudante não esta cadastrado!\n");
     return;
 }
  registrar_aluno(&est[i]);
}
void lista_estudante(estudantes_t *estudante, int _s){
  if (!_s) {
     printf ("Não há estudantes cadastrados!\n");
     return; 
  } 
  for (int i = 0; i < _s; i++){
      double media = estudante[i].total;
      printf("\nAluno (%d) - notas: %.2lf %.2lf %.2lf %.2lf - total: %.2lf - media: %.2lf \n", (i + 1), estudante[i].scores[0], estudante[i].scores[1], estudante[i].scores[2], estudante[i].scores[3], estudante[i].total, media);
      
     if (media < 4) {
	   printf("ALUNO REPROVADO \n");
	 }else if (media > 4 && media < 6) {
	        printf("ALUNO DE RECUPERACAO \n");
	   }else {
	   	printf("ALUNO APROVADO \n");
	 }
  }
}
int main() {
	setlocale(LC_ALL,"");
	estudantes_t aluno[5];
	int opcao=0, _s;

	printf("Carregando sistema..... Aguarde");
	sleep(10);
	
	while ((opcao != 1) &&(opcao != 2 )&&(opcao != 3)){
		system("cls");
		printf("\n SEJA BEM VINDO \n");
		printf("\n ----- MENU ----- \n");
		printf("1. Cadastrar Aluno \n");
		printf("2. Editar Resultado \n");
		printf("3. Sair \n");
		printf("Escolha uma opção: ");	
		scanf("%d",&opcao);
		if (opcao == 1){
	     	system("cls");
			if (_s == 5){
				printf("Limeite maximo atingido!\n");
			}  else { 
				registrar_aluno(&aluno[_s]);
				_s++;
				lista_estudante(aluno, _s);			  
			}
	     	system("pause");
	     	opcao = 0;
	    } else {
	    	if (opcao == 2){
	        	system("cls");
	        	editar_estudantes(aluno, _s);
	        	system("pause");
	        	opcao=0;
			}else {
				if (opcao == 3){
					return 0;
				}
			}
		} 
	}
	return 0;
}
