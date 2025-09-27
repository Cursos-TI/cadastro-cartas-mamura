#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de cada carta
typedef struct {
  char codCidade[4];
  char nome[20];
  int populacao;
  float area;
  float pib;
  int numPontosTuristicos;
  float densidadeDemografica;
  float pibPerCapita;
} Card;


// Função para ler uma carta
void lerCarta(Card *c)
{
  printf("## INSIRA OS DADOS DA CARTA:\n");

  printf("# Código (ex.: A01): ");
  scanf("%3s", c->codCidade);

  printf("# Nome: ");
  scanf("%19s", c->nome);

  printf("# População: ");
  scanf("%d", &c->populacao);

  printf("# Área: ");
  scanf("%f", &c->area);

  printf("# PIB: ");
  scanf("%f", &c->pib);

  printf("# Quantidade de pontos turísticos: ");
  scanf("%d", &c->numPontosTuristicos);

  // ---- Calculados  ----
  c->densidadeDemografica = (c->area > 0.0f) ? (c->populacao / c->area) : 0.0f;
  c->pibPerCapita          = (c->populacao > 0) ? (c->pib / c->populacao) : 0.0f;

  printf("\n");
}

// Menu de atributo
void mostraAtributos()
{
    printf("\nEscolha um atributo para comparação:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Demográfica\n");
    printf("5 - Pontos Turísticos\n");
}

// Lê uma opção válida [1..5] e (se for o segundo atributo) impede repetir a primeira
int lerOpcaoAtributo(const char *prompt, int proibido)
{
  int opcao;
  do {
    mostraAtributos();
    printf("%s", prompt);

    if (scanf("%d", &opcao) != 1) {
      // limpa entrada inválida
      int ch;
      while ((ch = getchar()) != '\n' && ch != EOF);
      opcao = 0;
    }

    if (opcao < 1 || opcao > 5 || opcao == proibido) {
      if (opcao == proibido) {
        printf("Opção repetida. Escolha um atributo diferente.\n");
      } else {
        printf("Opção inválida. Tente novamente.\n");
      }
    }
  } while (opcao < 1 || opcao > 5 || opcao == proibido);

  return opcao;
}

float obterValorAtributo(const Card *c, int atributo)
{
  switch (atributo) {
    case 1: return (float)c->populacao;
    case 2: return c->area;
    case 3: return c->pib;
    case 4: return c->densidadeDemografica;
    case 5: return (float)c->numPontosTuristicos;
    default: return 0.0f;
  }
}

// Converte código do atributo em nome (só para exibir bonito)
const char* nomeAtributo(int atributo)
{
  switch (atributo) {
    case 1: return "População";
    case 2: return "Área";
    case 3: return "PIB";
    case 4: return "Densidade Demográfica";
    case 5: return "Pontos Turísticos";
    default: return "Desconhecido";
  }
}

void jogarRodada(Card card1, Card card2)
{
  int attribute1, attribute2;

  int atributo1 = lerOpcaoAtributo("\nEscolha o primeiro atributo (1-5): ", 0);
  int atributo2 = lerOpcaoAtributo("\nEscolha o segundo atributo (1-5, diferente do primeiro): ", atributo1);

  float a1_c1 = obterValorAtributo(&card1, atributo1);
  float a1_c2 = obterValorAtributo(&card2, atributo1);
  float a2_c1 = obterValorAtributo(&card1, atributo2);
  float a2_c2 = obterValorAtributo(&card2, atributo2);

  int pontos1 = 0, pontos2 = 0;

  printf("\n===== COMPARAÇÃO =====\n");
  printf(
    "%s -> Carta1: %.2f | Carta2: %.2f => %s\n",
    nomeAtributo(atributo1), 
    a1_c1, // atributi 1 da carta 1
    a1_c2, // atributo 1 da carta 2
    (a1_c1 > a1_c2) ? "Carta1 vence" : (a1_c2 > a1_c1) ? "Carta2 vence" : "Empate"
  );

  if (a1_c1 > a1_c2) {
    pontos1++;
  }  else if (a1_c2 > a1_c1) {
    pontos2++;
  }

  printf(
    "%s -> Carta1: %.2f | Carta2: %.2f => %s\n",
    nomeAtributo(atributo2),
    a2_c1, // atributo 2 da carta 1
    a2_c2, // atributo 2 da carta 2
    (a2_c1 > a2_c2) ? "Carta1 vence" : (a2_c2 > a2_c1) ? "Carta2 vence" : "Empate"
  );

  if (a2_c1 > a2_c2) {
    pontos1++;
  } else if (a2_c2 > a2_c1) {
    pontos2++;
  }

  printf("\n===== RESULTADO FINAL =====\n");
  if (pontos1 > pontos2) {
    printf("Vencedor: CARTA 1 (%d x %d)\n", pontos1, pontos2);
  } else if (pontos2 > pontos1) {
    printf("Vencedor: CARTA 2 (%d x %d)\n", pontos2, pontos1);
  } else {
    printf("Empate geral (%d x %d)\n", pontos1, pontos2);
  }                        

  return;  
}


int main() {
  Card carta1, carta2;
  
  // Área para entrada de dados
  printf("######################################################\n");
  printf("##### Cadastro de cartas - SUPER TRUNFO CIDADES ######\n");
  printf("######################################################\n\n");

  lerCarta(&carta1);
  lerCarta(&carta2);

  jogarRodada(carta1, carta2);
  
  return 0;
} 
