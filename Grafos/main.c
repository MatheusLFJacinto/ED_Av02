    #include <stdio.h>
    #include <stdlib.h>
    #include "module.h"
    #define MAXNUMVERTICES  100
    #define MAXNUMARESTAS   4500
    #define FALSE           0
    #define TRUE            1
    int main()
    { /*-- Programa principal --*/
    int TEMP;
    int TEMP1;
    int opcao ;

    /* -- NumVertices: definido antes da leitura das arestas --*/
    /* -- NumArestas: inicializado com zero e incrementado a --*/
    /* -- cada chamada de InsereAres --*/

    
    printf("Criador de grafos\n");
    printf("N°. vertices:");
            scanf("%d", &TEMP);
            getchar();
            NVertices = TEMP;
            printf("No. arestas:");
            scanf("%d", &NArestas);
            getchar();
            Grafo.NumVertices = NVertices;
            Grafo.NumArestas = 0;
            FGVazio(&Grafo);

            for (i = 0; i < NArestas; i++) { 
                printf("Insere V1 -- V2 -- Peso:\n");
                scanf("%d%d%d", &TEMP, &TEMP1, &Peso); 
                getchar();
                V1 = TEMP;
                V2 = TEMP1;
                Grafo.NumArestas++;
                InsereAresta(&V1, &V2, &Peso, &Grafo);   /* 1 chamada g-direcionado    */
                /*InsereAresta(V2, V1, Peso, Grafo);*/
                /* 2 chamadas g-naodirecionado*/
            }
    
           

     printf("Editor de grafos\n");
     printf("\n");
    
   do{
            

        
            
                
       
        printf("Opção 1 - Imprime grafo\n");
        printf("Opção 2 - Insere uma nova aresta no grafo\n");
        printf("Opção 3 - Mostra a lista de adjacencia de um verice\n");
        printf("Opção 4 - Remove aresta no grafo\n");
        printf("Opção 5 - Verifica se existe a aresta no grafo\n");
        printf("Opção 0 - Encerra o programa\n");
        printf("\n");
        scanf("%d",&opcao);

        if (opcao==1){
             printf("\n");
             ImprimeGrafo(&Grafo); 
             printf("\n");
        
        }
        else if (opcao ==2){
            printf("\n");
            printf("Insere V1 -- V2 -- Peso:\n");
            scanf("%d%d%d", &V1, &V2, &Peso);
            if (ExisteAresta(V1, V2, &Grafo))
            printf("Aresta ja existe\n");
            else { 
                Grafo.NumArestas++;
            InsereAresta(&V1, &V2, &Peso, &Grafo);
            /*InsereAresta(V2, V1, Peso, Grafo);*/
            }
            printf("\n");  
        
        }


        else if (opcao==3){
            printf("\n");
            printf("Lista adjacentes de:\n ");
            scanf("%d", &TEMP);
            V1 = TEMP;
            if (!ListaAdjVazia(&V1, &Grafo)){ 
                Aux = PrimeiroListaAdj(&V1, &Grafo);
                FimListaAdj = FALSE;
                while (!FimListaAdj){ 
                    ProxAdj(&V1, &Grafo, &Adj, &Peso, &Aux, &FimListaAdj);
                    printf("%2d (%d)\n", Adj, Peso);
                }
               
            }
        printf("\n");
        }

       else if (opcao==4){
        printf("\n");
        printf("Retira aresta V1 -- V2:\n");
        scanf ("%d %d", &V1, &V2);
        if (ExisteAresta(V1, V2, &Grafo)) { 
            Grafo.NumArestas--;
        RetiraAresta(&V1, &V2, &Peso, &Grafo);
        /*RetiraAresta(V2, V1, Peso, Grafo);*/
        } 
        else printf("Aresta nao existe\n");
         printf("\n");
        }

        else if (opcao==5){
        printf("\n");
        printf("Existe aresta V1 -- V2:\n");
        
        scanf("%d", &TEMP);
        scanf("%d", &TEMP1);
        getchar();
        V1 = TEMP;
        V2 = TEMP1;
        if (ExisteAresta(V1, V2, &Grafo)){
            printf(" Sim\n");    
        }
        else {
            printf(" Nao\n");    
        }
        }
        printf("\n");
    }
     while (opcao!=0);
    LiberaGrafo(&Grafo);   /* Imprime sujeira normalmente */
  
    return 0;
    }
