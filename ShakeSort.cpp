//============================================================================================================
//=======================                                                =====================================
//=======================  LUCAS LAMOUNIER G DUARTE - 2016012688         =====================================
//=======================                                                =====================================
//============================================================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct {
    int numeroMatricula;
    DATA data;
    char sexo;
    char *nomeCurso;
    char *nomeCompleto;
}DADOS_ALUNO;

typedef DADOS_ALUNO  INFO_NO;

typedef struct NO {
  INFO_NO infoNo;
  struct NO *proximo;
  struct NO *anterior;
  int indice;
}LISTA_ALUNO;

void leitura_dados(LISTA_ALUNO**);//======================================================================================
void inicializarLista ( LISTA_ALUNO **);//==========================                       ===============================
void incluirNo ( DADOS_ALUNO, LISTA_ALUNO **);//==================== PROTÓTIPOS DE FUNÇÃO  ===============================
void mostrarLista ( LISTA_ALUNO *, const char *);//=================                       ===============================
void ordenarShakeSort ( LISTA_ALUNO *, LISTA_ALUNO **);//=================================================================


void leitura_dados(LISTA_ALUNO** lista1){

  LISTA_ALUNO *aux;
  FILE *arq;
  INFO_NO no;
  char* nome_arq;
  int nro;


  nome_arq = (char*)calloc(30, sizeof(char));


  printf("Informe o nome do arquivo.\n");//=====================================================================
  scanf("%s", nome_arq);//=====================  RECEBE O NOME DO ARQUIVO  =====================================


  arq=fopen(nome_arq, "rt");


  if(!arq){ //==========================================================================================================
    printf("ERRO!\nO arquivo não pode ser aberto.\n");//============ MENSSAGEM DE ======================================
    system("cls");//======================================================== ERRO NA ABERTURA   ========================
    exit(1);//==========================================================================================================
  }
  no.nomeCurso    = ( char * ) calloc ( 30, sizeof (char));
  no.nomeCompleto = ( char * ) calloc ( 50, sizeof (char));
  rewind(arq);
  while(!feof(arq)){
    fscanf(arq,"%d %c %s %d/%d/%d %[^\n]", &no.numeroMatricula, &no.sexo, no.nomeCurso, &no.data.dia, &no.data.mes, &no.data.ano, no.nomeCompleto);
      incluirNo(no,lista1); //========================= RECOLHENDO OS DADOS DO ARQUIVO ==================================
  }

  fclose(arq);
}

LISTA_ALUNO *criarNo ( DADOS_ALUNO dadosAluno ){
  LISTA_ALUNO *noLista;

     noLista = ( LISTA_ALUNO* ) calloc ( 1, sizeof ( LISTA_ALUNO ));//================================================
    noLista->infoNo.nomeCurso    = ( char * ) calloc ( 30, sizeof (char));//==========================================
    noLista->infoNo.nomeCompleto = ( char * ) calloc ( 50, sizeof (char));//==========================================
    noLista->infoNo.sexo  = dadosAluno.sexo;//========================================================================
    noLista->infoNo.data.dia  = dadosAluno.data.dia;//==================                           ===================
    noLista->infoNo.data.mes  = dadosAluno.data.mes;//================== CRIAÇÃO DE UM NÓ PARA     ===================
    noLista->infoNo.data.ano = dadosAluno.data.ano;//=================== A FUTURA INSERÇÃO NA      ===================
    noLista->infoNo.numeroMatricula = dadosAluno.numeroMatricula;//=====          LISTA            ===================
    strcpy ( noLista->infoNo.nomeCurso, dadosAluno.nomeCurso );//=======                           ===================
    strcpy ( noLista->infoNo.nomeCompleto, dadosAluno.nomeCompleto );//===============================================
    noLista->indice  = 0;//===========================================================================================
    noLista->proximo  = NULL;//============================ PONTEIRO SETADOS PARA NULL PARA NÃO    ===================
    noLista->anterior = NULL;//================== CORRE  RISCO DE HAVER LIXO NA HORA DA INCLUSÃO   ===================

  return ( noLista );
}

void inicializarLista ( LISTA_ALUNO **listaAlunos ){
  *listaAlunos = NULL;
}

void incluirNo ( DADOS_ALUNO dadosAluno, LISTA_ALUNO **listaAlunos){
  LISTA_ALUNO *p, *q, *novoNo;

  novoNo =  criarNo( dadosAluno );
  p      = *listaAlunos;
  q      =  p;

  while ( p != NULL ) {//===================================================================================
    q = p;//======================= BUSCA O FIM DA LISTA PARA INSERÇÃO =====================================
    p = p->proximo;//=======================================================================================
  }

  if ( q == NULL ) {
    novoNo->indice = 1;//===================================================================================
    *listaAlunos = novoNo;//=========== INSERE NA UNICA POSIÇÃO SE FOR O PRIMEIRO NÓ =======================
  }
  else {
    q->proximo = novoNo;//===================================================================================
    novoNo->anterior = q;//========= INSERE ASSIM QUE ACHAR O ULTIMO ELEMENTO DA LISTA   ====================
    novoNo->indice = q->indice + 1;//========================================================================
  }
}

void copiarLista ( LISTA_ALUNO *listaEntrada, LISTA_ALUNO **listaSaida){
  LISTA_ALUNO     *pE;
  DADOS_ALUNO   valor;

  pE = listaEntrada;

  while ( pE != NULL ) {//===================================================================================
    valor = pE->infoNo;//====================== CRIA UMA CÓPIA PARA MANTER A INTEGRIDADE ====================
    incluirNo ( valor, listaSaida );//================ DOS DADOS  ===========================================
    pE = pE->proximo;//======================================================================================
  }
}

void mostrarLista ( LISTA_ALUNO *listaAlunos, const char *cabecalho){
  LISTA_ALUNO *p;

  printf ( "\n%s\n\n", cabecalho );

  p = listaAlunos;
  if ( p == NULL ) printf ( "LISTA VAZIA\n" );
  else {
    while ( p != NULL ) {
      printf ( "%d -) %5d - %c - %s - %2d/%2d/%4d - %s\n", p->indice,//=================================================
        p->infoNo.numeroMatricula, p->infoNo.sexo, p->infoNo.nomeCurso,//======= PRINTA OS VALORES DA ==================
        p->infoNo.data.dia, p->infoNo.data.mes, p->infoNo.data.ano,//=================== LISTA =========================
        p->infoNo.nomeCompleto//========================================================================================
      );
      p = p->proximo;
    }
  }
}

void ordenarShakeSort (  LISTA_ALUNO *listaDados, LISTA_ALUNO **listaOrdenada){
  LISTA_ALUNO   *a, *u, *ini;
  int chave, chaveAnterior, troca = 1;

  inicializarLista ( listaOrdenada );//================================================================
  copiarLista( listaDados, listaOrdenada );//== CÓPIA PARA ORDENAÇÃO ==================================

  ini = *listaOrdenada;
  a =   ini;

  int maximo,auxIndice, minimo;

  while(a->proximo != NULL){
    a = a->proximo;
  }
  maximo = a->indice;
  a = ini;
  u = a->proximo;
  minimo = 1;

  while ( troca == 1) {
    troca = 0;
    u = a->proximo;
    while(a->indice != maximo){

      if((u->infoNo.data.ano < a->infoNo.data.ano) ||
          (u->infoNo.data.ano == a->infoNo.data.ano && u->infoNo.data.mes < a->infoNo.data.mes) ||
          (u->infoNo.data.ano == a->infoNo.data.ano && u->infoNo.data.mes == a->infoNo.data.mes && u->infoNo.data.dia < a->infoNo.data.dia) ||
          (u->infoNo.data.ano == a->infoNo.data.ano && u->infoNo.data.mes == a->infoNo.data.mes && u->infoNo.data.dia == a->infoNo.data.dia && u->infoNo.numeroMatricula < a->infoNo.numeroMatricula)){

        troca = 1;
        if(a == ini){//======================================================================================
                    //=======================================================================================
          *listaOrdenada = ini = u;//========================================================================
          a->proximo = u->proximo;//=========================================================================
          if(u->proximo){//==================================================================================
            u->proximo->anterior = a;//======================================================================
          }//================================================================================================
        }//==================================================================================================
        else{//==============================================================================================
          u->anterior = a->anterior;//============                                 ==========================
                    if(a->anterior){//============ PERCORRE A LISTA DO INICIO      ==========================
            a->anterior->proximo = u;//=========== AO FIM FAZENDO AS MUDANÇAS      ==========================
          }//===================================== NECESSÁRIAS                     ==========================
          a->proximo = u->proximo;//==============                                 ==========================
          if(u->proximo){//==================================================================================
            u->proximo->anterior = a;//======================================================================
          }//================================================================================================
        }//==================================================================================================
        u->proximo = a;//====================================================================================
        a->anterior = u;//===================================================================================
        auxIndice = u->indice;//=============================================================================
        u->indice = a->indice;//=============================================================================
        a->indice = auxIndice;//=============================================================================
      }//====================================================================================================
      a = u;//===============================================================================================
      u = u->proximo;//======================================================================================
    }//======================================================================================================
    maximo--;//======================       DIMINUI O TAMANHO POIS O ULTIMO VALOR JA ESTA NA POSIÇÃO ===========

    a = a->anterior;
    u = a->anterior;
    while(a->indice != minimo){

      if((a->infoNo.data.ano < u->infoNo.data.ano) ||
          (a->infoNo.data.ano == u->infoNo.data.ano &&  a->infoNo.data.mes < u->infoNo.data.mes) ||
          (a->infoNo.data.ano == u->infoNo.data.ano && a->infoNo.data.mes == u->infoNo.data.mes && a->infoNo.data.dia < u->infoNo.data.dia) ||
          (a->infoNo.data.ano == u->infoNo.data.ano && a->infoNo.data.mes == u->infoNo.data.mes && a->infoNo.data.dia == u->infoNo.data.dia && a->infoNo.numeroMatricula < u->infoNo.numeroMatricula)){

        troca = 1;
        if(u == ini){//==========================================================================================
                //===============================================================================================
          *listaOrdenada = ini = a;//============================================================================
          u->proximo = a->proximo;//=============================================================================
          if(a->proximo){//======================================================================================
            a->proximo->anterior = u;//==========================================================================
          }//===================================================                              ===================
        }//===================================================== PERCORRE A LISTA FAZENDO     ===================
        else{//================================================= AS TROCAS NECESSÁRIAS DO     ===================
          u->proximo = a->proximo;//============================ FIM PARA O COMEÇO            ===================
          if(a->proximo){//=====================================                              ===================
            a->proximo->anterior = u;//==========================================================================
          }//====================================================================================================
          a->anterior = u->anterior;//===========================================================================
          if(u->anterior){//=====================================================================================
            u->anterior->proximo = a;//==========================================================================
          }//====================================================================================================
        }//======================================================================================================
        u->anterior = a;//=======================================================================================
        a->proximo = u;//========================================================================================
        auxIndice = u->indice;//=================================================================================
        u->indice = a->indice;//=================================================================================
        a->indice = auxIndice;//=================================================================================
      }//========================================================================================================
      a = u;//===================================================================================================
      u = u->anterior;//=========================================================================================
    }//==========================================================================================================
    minimo++;//======================    DIMINUI O TAMANHO MINIMO MENOR VALOR JA ESTA NA POSIÇÃO  ==================

  }
}

int main(){
  LISTA_ALUNO *lista1, *lista2;

  inicializarLista(&lista1);//INICIALIZAÇÃO DA LISTA DESORDENADA

  inicializarLista(&lista2);//INICIALIZAÇÃO DA LISTA DESORDENADA

  leitura_dados(&lista1);//LEITURA DOS DADOS NA LISTA DESORDENADA

  mostrarLista(lista1, "================== LISTA DESORDENADA ==================");//IMPRIME OS DADOS DA LISTA DESORDENADA

  ordenarShakeSort (lista1, &lista2);//FAZ A ORDENAÇÃO DA LISTA UTILIZANDO SHAKESORT

  mostrarLista(lista2, "================== LISTA ORDENADA ==================");//IMPRIME A LISTA ORDENADA

}
