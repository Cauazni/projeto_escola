#include "utils.h"



    int menuProfessor(){
            int opcao;
            printf("0-VOLTAR\n");   
            printf("1-CADASTRAR PROFESSOR\n");   
            printf("2-LISTAR PROFESSOR\n");   
            printf("3-ATUALIZAR PROFESSOR\n"); 
            printf("4-DELETAR PROFESSOR\n");
            scanf("%d", &opcao);
                            
            return opcao;
        }

    int verificarProfessor(int qtdprofessor,Professor listarProfessor[], int * matriculaprof)
    {
        scanf("%i", matriculaprof);
        if(*matriculaprof<0)
        {
            return MATRICULA_PROFESSOR_INVALIDA;
        }
        int achouprof = 0;
        for(int i =0; i < qtdprofessor; i++)
        {
            if(*matriculaprof == listarProfessor[i].matricula)
            {
                achouprof = 1;
            }
        }
        if(achouprof==1)
            return PROFESSOR_EXISTE;
        else
            return MATRICULA_PROFESSOR_INEXISTENTE;
    }

    int cadastrarProfessor(int qtdProfessor, Professor listarProfessor[]){
                printf("CADASTRAR ALUNO\n");
                    if(qtdProfessor==TAM_PROFESSOR){
                        return LISTA_PROFESSOR_CHEIA;
                    }else{
                            int matricula;
                            char cpf[15];
                            int diaNascimento, mesNascimento, anoNascimento;
                            int diaAtual, mesAtual, anoAtual;
                            char nome[20];
                            int idade;
                            char sexo;
                            int i;

                            printf("DIGITE SEU NOME:\n");
                            getchar();
                            fgets(nome,sizeof(nome),stdin);

                             // Remover a nova linha ao final da string nome, se presente
                            size_t len = strlen(nome);
                            if (len > 0 && nome[len - 1] == '\n') {
                                    nome[len - 1] = '\0';
                                }

                            printf("DIGITE A MATRICULA:\n");
                            scanf("%d", &matricula);

                            printf("DIGITE O SEXO (M/F):\n");
                            scanf(" %c", &sexo);
                            sexo = toupper(sexo);

                            printf("DIGITE SEU CPF (formato: 000.000.000-00):\n");
                            getchar();
                            fgets(cpf, sizeof(cpf), stdin);
                            len = strlen(cpf);
                            if (len > 0 && cpf[len - 1] == '\n') {
                                cpf[len - 1] = '\0';
                            }

                             // Verificar se o CPF já está cadastrado
                            for (i = 0; i < qtdProfessor; i++) {
                                if (strcmp(listarProfessor[i].cpf, cpf) == 0) {
                                    return CPF_PROFESSOR_JA_CADASTRADO;
                                }
                            }

                            printf("DIGITE SUA DATA DE NASCIMENTO (formato: DD/MM/AAAA):\n");
                            scanf("%d/%d/%d", &diaNascimento,&mesNascimento, &anoNascimento);


                            // Entrada da data atual
                            printf("DIGITE A DATA ATUAL (formato: DD/MM/AAAA):\n");
                            scanf("%d/%d/%d", &diaAtual, &mesAtual, &anoAtual);


                             // Calcular idade
                            idade = anoAtual - anoNascimento;

                            if(matricula<0){
                                return MATRICULA_PROFESSOR_INVALIDA;
                            }else{
                                    if(sexo=='F' || sexo=='M'){

                                        //nome do professor
                                        strcpy(listarProfessor[qtdProfessor].nome, nome);

                                        //sexo do professor
                                        listarProfessor[qtdProfessor].sexo = sexo;

                                        //matricula do professor
                                        listarProfessor[qtdProfessor].matricula = matricula;

                                        //cpf do professor
                                        strcpy(listarProfessor[qtdProfessor].cpf, cpf);

                                        //data de nascimento do professor
                                        listarProfessor[qtdProfessor].diaNascimento=diaNascimento;
                                        listarProfessor[qtdProfessor].mesNascimento=mesNascimento;
                                        listarProfessor[qtdProfessor].anoNascimento=anoNascimento;

                                        //cadastrar idade
                                        listarProfessor[qtdProfessor].idade = idade;

                                        //data que o professor entrou
                                        listarProfessor[qtdProfessor].diaAtual=diaAtual;
                                        listarProfessor[qtdProfessor].mesAtual=mesAtual;
                                        listarProfessor[qtdProfessor].anoAtual=anoAtual;

                                        //marca se o professor está cadastrado ou não, serve para fazer exclusão logica
                                        listarProfessor[qtdProfessor].ativo = 1;
                                        
                                        return CAD_PROFESSOR_SUCESSO;
                                    }else{
                                        return SEXO_PROFESSOR_INVALIDO;
                                    }
                                
                            }
                        }
                    }

    void listarrProfessor(int qtdProfessor, Professor listarProfessor[]){
        if(qtdProfessor==0){
                        printf("LISTA DE PROFESSORES VAZIA\n");
                        }else{
                            for(int i=0; i<qtdProfessor; i++){
                                if(listarProfessor[i].ativo==1){
                                    printf("PROFESSOR %d:\n", i);
                                    printf("SEXO: %c", listarProfessor[i].sexo);
                                    printf("MATRICULA: %d\n",listarProfessor[i].matricula);
                                    printf("NOME:%s\n",listarProfessor[i].nome);
                                    printf("CPF: %s\n", listarProfessor[i].cpf);
                                    printf("DATA DE NASCIMENTO: %d/%d/%d\n", listarProfessor[i].diaNascimento, listarProfessor[i].mesNascimento, listarProfessor[i].anoNascimento);
                                    printf("IDADE: %d\n", listarProfessor[i].idade);
                                    printf("DATA DE CADASTRO: %d/%d/%d\n", listarProfessor[i].diaAtual, listarProfessor[i].mesAtual, listarProfessor[i].anoAtual);
                                    printf("\n");
                                }
                            }
                        }
        
    }

    int atualizarProfessor(int qtdProfessor, Professor listarProfessor[]){
    printf("ATUALIZAR PROFESSOR\n");
                        int matricula;

                        printf("DIGITE A MATRICULA:\n");
                        scanf("%d", &matricula);
                        int achou = 0;
                        if(matricula<0){
                            return MATRICULA_PROFESSOR_INVALIDA;
                        }else{
                        for(int i=0; i<qtdProfessor; i++){
                            if (matricula==listarProfessor[i].matricula&&listarProfessor[i].ativo){
                                //atualização
                                int novaMatricula;
                                char novoNome[20];
                                int newdiaNascimento;
                                int newanoNascimento;
                                int newmesNascimento;
                                char newSexo;
                                printf("DIGITE A NOVA MATRICULA:\n");
                                scanf("%d", &novaMatricula);
                                printf("NOME:\n");
                                getchar();
                                fgets(novoNome,sizeof(novoNome),stdin);

                                size_t len=strlen(novoNome);
                                if (len > 0 && novoNome[len - 1] == '\n') {
                                    novoNome[len - 1] = '\0';
                                }
                                
                                printf("DIGITE SUA DATA DE NASCIMENTO (formato: DD/MM/AAAA):\n");
                                scanf("%d/%d/%d", &newdiaNascimento,&newmesNascimento, &newanoNascimento);

                                
                                printf("SEXO:\n");
                                scanf(" %c", &newSexo);

                                if(novaMatricula<0){
                                    return MATRICULA_PROFESSOR_INVALIDA;
                                }
                                listarProfessor[i].matricula=novaMatricula;
                                strcpy(listarProfessor[i].nome,novoNome);
                                listarProfessor[i].diaNascimento=newdiaNascimento;
                                listarProfessor[i].mesNascimento=newmesNascimento;
                                listarProfessor[i].anoNascimento=newanoNascimento;
                                listarProfessor[i].sexo=newSexo;
                                achou=1;
                                break;
                            }
                            
                        }if(achou){
                            return ATUALIZADO_PROFESSOR_SUCESSO;
                            
                        }else{
                            return MATRICULA_PROFESSOR_INEXISTENTE;
                        
                        }
    
        }
    }
    
    int excluirProfessor(int qtdProfessor, Professor listarProfessor[]){
        printf("DELETAR PROFESSOR\n");
        printf("DIGITE A MATRICULA:\n");
        int matricula;  
        scanf("%d", &matricula);
        int achou = 0;
            if(matricula<0){
                return MATRICULA_PROFESSOR_INVALIDA;
            }else{
                for(int i=0; i<qtdProfessor; i++){ 
                    if (matricula==listarProfessor[i].matricula){
                                
                        //exclusão logica
                        listarProfessor[i].ativo = -1;
                    
                        for (int j=i; j<qtdProfessor-1; j++)
                        {
                        //movendo todos os professores pra casa anterior
                            listarProfessor[j].nome[20]=listarProfessor[j+1].nome[20];
                            listarProfessor[j].cpf[15]=listarProfessor[j+1].cpf[15];
                            listarProfessor[j].matricula=listarProfessor[j+1].matricula;
                            listarProfessor[j].sexo=listarProfessor[j+1].sexo;
                            listarProfessor[j].ativo=listarProfessor[j+1].ativo;
                            
                        //movendo as datas de cadastro e de nascimento
                        //nascimento
                            listarProfessor[j].diaNascimento=listarProfessor[j+1].diaNascimento;
                            listarProfessor[j].mesNascimento=listarProfessor[j+1].mesNascimento;
                            listarProfessor[j].anoNascimento=listarProfessor[j+1].anoNascimento;
                        //cadastro
                            listarProfessor[j].diaAtual=listarProfessor[j+1].diaAtual;
                            listarProfessor[j].mesAtual=listarProfessor[j+1].mesAtual;
                            listarProfessor[j].anoAtual=listarProfessor[j+1].anoAtual;
                        }

                            achou=1;
                            break;
                    }
                }

                        if(achou){
                            return EXCLUSAO_PROFESSOR_SUCESSO;
                            
                        }else{
                            return MATRICULA_PROFESSOR_INEXISTENTE;
                        
                        }
                            
                }
            }
    
