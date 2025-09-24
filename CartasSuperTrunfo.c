#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

int main() {
  // Área para definição das variáveis para armazenar as propriedades das cidades
  char codCidade1[3];
  char nome1[20];
  int populacao1;
  float area1;
  float pib1;
  int numPontosTuristicos1;

  char codCidade2[3];
  char nome2[20];
  int populacao2;
  float area2;
  float pib2;
  int numPontosTuristicos2;

  
  // Área para entrada de dados
  printf("######################################################\n");
  printf("##### Cadastro de cartas - SUPER TRUNFO CIDADES ######\n");
  printf("######################################################\n\n");

  printf("## INSIRA OS DADO DA CARTA 1:\n");
  printf("# Código: ");
  scanf("%s", codCidade1);
  printf("\n");

  printf("# Nome: ");
  scanf("%s", nome1);
  printf("\n");

  printf("# População: ");
  scanf("%d", &populacao1);
  printf("\n");

  printf("# Área: ");
  scanf("%f", &area1);
  printf("\n");

  printf("# PIB: ");
  scanf("%f", &pib1);
  printf("\n");

  printf("# Quantidade de pontos turísticos: ");
  scanf("%d", &numPontosTuristicos1);
  printf("\n");

  // CARTA 2
  printf("## INSIRA OS DADO DA CARTA 2:\n");
  printf("# Código: ");
  scanf("%s", codCidade2);
  printf("\n");

  printf("# Nome: ");
  scanf("%s", nome2);
  printf("\n");

  printf("# População: ");
  scanf("%d", &populacao2);
  printf("\n");

  printf("# Área: ");
  scanf("%f", &area2);
  printf("\n");

  printf("# PIB: ");
  scanf("%f", &pib2);
  printf("\n");

  printf("# Quantidade de pontos turísticos: ");
  scanf("%d", &numPontosTuristicos2);
  printf("\n");

  // Área para exibição dos dados da cidade
  printf("########################################\n");
  printf("######### 'CIDADE 1' ########\n");
  printf("########################################\n");

  printf("# CODIGO - ", codCidade1);
  printf("# NOME - ", nome1);
  printf("# POPULACAO - %d", populacao1);
  printf("# AREA - %.2f", area1);
  printf("# PIB - %.2f", pib1);
  printf("# PONTOS TURISTICOS - %d", numPontosTuristicos1);
  printf("########################################\n");
  printf("########################################\n\n\n");


  printf("########################################\n");
  printf("######### 'CIDADE 2' ########\n");
  printf("########################################\n");

  printf("# CODIGO - ", codCidade2);
  printf("# NOME - ", nome2);
  printf("# POPULACAO - %d", populacao2);
  printf("# AREA - %.2f", area2);
  printf("# PIB - %.2f", pib2);
  printf("# PONTOS TURISTICOS - %d", numPontosTuristicos2);
  printf("########################################\n");
  printf("########################################\n");

return 0;
} 
