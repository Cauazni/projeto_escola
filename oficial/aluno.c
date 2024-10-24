#include "utils.h"

    int menuAluno(){
            int opcao;
            printf("0-VOLTAR\n");   
            printf("1-CADASTRAR ALUNO\n");   
            printf("2-LISTAR ALUNO\n");   
            printf("3-ATUALIZAR ALUNO\n"); 
            printf("4-DELETAR ALUNO\n");
            scanf("%d", &opcao);
                            
            return opcao;
        }

    int menuGeral(){
    int opcao;
        printf("PROJETO ESCOLA\n");   
        printf("0-SAIR\n");   
        printf("1-ALUNO\n");   
        printf("2-PROFESSOR\n");   
        printf("3-DISCIPLINA\n");  
        scanf("%d", &opcao);

        return opcao;
}

    int cadastrarAluno(int qtdAluno, Aluno listarAluno[]){
                printf("CADASTRAR ALUNO\n");
                    if(qtdAluno==TAM_ALUNO){
                        return LISTA_ALUNO_CHEIA;
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
                            size_t lenn = strlen(cpf);
                            if (lenn > 0 && cpf[lenn - 1] == '\n'){
                                cpf[lenn - 1] = '\0';
                            }

                             // Verificar se o CPF já está cadastrado
                            for (i = 0; i < qtdAluno; i++) {
                                if (strcmp(listarAluno[i].cpf, cpf) == 0) {
                                    return CPF_ALUNO_JA_CADASTRADO;
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
                                return MATRICULA_ALUNO_INVALIDA;
                            }else{
                                    if(sexo=='F' || sexo=='M'){

                                        //nome do aluno
                                        strcpy(listarAluno[qtdAluno].nome, nome);

                                        //sexo do aluno
                                        listarAluno[qtdAluno].sexo = sexo;

                                        //matricula do aluno
                                        listarAluno[qtdAluno].matricula = matricula;

                                        //cpf do aluno
                                        strcpy(listarAluno[qtdAluno].cpf, cpf);

                                        //data de nascimento do aluno
                                        listarAluno[qtdAluno].diaNascimento=diaNascimento;
                                        listarAluno[qtdAluno].mesNascimento=mesNascimento;
                                        listarAluno[qtdAluno].anoNascimento=anoNascimento;

                                        //cadastrar idade
                                        listarAluno[qtdAluno].idade = idade;

                                        //data que o aluno entrou
                                        listarAluno[qtdAluno].diaAtual=diaAtual;
                                        listarAluno[qtdAluno].mesAtual=mesAtual;
                                        listarAluno[qtdAluno].anoAtual=anoAtual;

                                        //marca se o aluno está cadastrado ou não, serve para fazer exclusão logica
                                        listarAluno[qtdAluno].ativo = 1;
                                        
                                        return CAD_ALUNO_SUCESSO;
                                    }else{
                                        return SEXO_ALUNO_INVALIDO;
                                    }
                                
                            }
                        }
                    }

    int verificarAluno(int qtdAluno, Aluno listarAluno[], int * matriculaaluno)
    {
        scanf("%i", matriculaaluno);
        if(*matriculaaluno<0)
        {
            return MATRICULA_ALUNO_INVALIDA;
        }
        int achoualuno = 0;
        for(int i =0; i < qtdAluno; i++)
        {
            if(*matriculaaluno == listarAluno[i].matricula)
            {
                achoualuno = 1;
            }
        }
        if(achoualuno==1)
            return ALUNO_EXISTE;
        else
            return MATRICULA_ALUNO_INEXISTENTE;
    }

    void listarrAlunos(int qtdAluno, Aluno listarAluno[]){
        if(qtdAluno==0){
                        printf("LISTA DE ALUNO VAZIA\n");
                        }else{
                            for(int i=0; i<qtdAluno; i++){
                                if(listarAluno[i].ativo==1){
                                    printf("ALUNO %d:\n", i);
                                    printf("SEXO: %c\n", listarAluno[i].sexo);
                                    printf("MATRICULA: %d\n",listarAluno[i].matricula);
                                    printf("NOME:%s\n",listarAluno[i].nome);
                                    printf("CPF: %s\n", listarAluno[i].cpf);
                                    printf("DATA DE NASCIMENTO: %d/%d/%d\n", listarAluno[i].diaNascimento, listarAluno[i].mesNascimento, listarAluno[i].anoNascimento);
                                    printf("IDADE: %d\n", listarAluno[i].idade);
                                    printf("DATA DE CADASTRO: %d/%d/%d\n", listarAluno[i].diaAtual, listarAluno[i].mesAtual, listarAluno[i].anoAtual);
                                    printf("\n");
                                }
                            }
                        }
        
    }

    int atualizarAluno(int qtdAluno, Aluno listarAluno[]){
    printf("ATUALIZAR ALUNO\n");
                        int matricula;

                        printf("DIGITE A MATRICULA:\n");
                        scanf("%d", &matricula);
                        int achou = 0;
                        if(matricula<0){
                            return MATRICULA_ALUNO_INVALIDA;
                        }else{
                        for(int i=0; i<qtdAluno; i++){
                            if (matricula==listarAluno[i].matricula&&listarAluno[i].ativo){
                                //atualização
                                int novaMatricula;
                                char novoNome[20];
                                int newdiaNascimento;
                                int newanoNascimento;
                                int newmesNascimento;
                                char newSexo;
                                char novoCpf[15];

                                printf("DIGITE A NOVA MATRICULA:\n");
                                scanf("%d", &novaMatricula);

                                printf("NOME:\n");
                                getchar();
                                fgets(novoNome,sizeof(novoNome),stdin);

                                size_t len=strlen(novoNome);
                                if (len > 0 && novoNome[len - 1] == '\n') {
                                    novoNome[len - 1] = '\0';
                                }
                                
                                printf("DIGITE O CPF:\n");
                                getchar();
                                fgets(novoCpf,sizeof(novoCpf),stdin);
                                
                                len=strlen(novoCpf);
                                if (len > 0 && novoCpf[len - 1] == '\n') {
                                    novoCpf[len - 1] = '\0';
                                }
                                

                                printf("DIGITE SUA DATA DE NASCIMENTO (formato: DD/MM/AAAA):\n");
                                scanf("%d/%d/%d", &newdiaNascimento,&newmesNascimento, &newanoNascimento);

                                
                                printf("SEXO:\n");
                                scanf(" %c", &newSexo);

                                if(novaMatricula<0){
                            return MATRICULA_ALUNO_INVALIDA;
                        }
                                listarAluno[i].matricula=novaMatricula;
                                strcpy(listarAluno[i].nome,novoNome);
                                strcpy(listarAluno[i].cpf,novoCpf);
                                listarAluno[i].diaNascimento=newdiaNascimento;
                                listarAluno[i].mesNascimento=newmesNascimento;
                                listarAluno[i].anoNascimento=newanoNascimento;
                                listarAluno[i].sexo=newSexo;
                                achou=1;
                                break;
                            }
                            
                        }if(achou){
                            return ATUALIZADO_ALUNO_SUCESSO;
                            
                        }else{
                            return MATRICULA_ALUNO_INEXISTENTE;
                        
                        }
    
        }
    }

    int excluirAluno(int qtdAluno, Aluno listarAluno[]){
        printf("DELETAR ALUNO\n");
        printf("DIGITE A MATRICULA:\n");
        int matricula;  
        scanf("%d", &matricula);
        int achou = 0;
            if(matricula<0){
                return MATRICULA_ALUNO_INVALIDA;
            }else{
                for(int i=0; i<qtdAluno; i++){ 
                    if (matricula==listarAluno[i].matricula){
                                
                        //exclusão logica
                        listarAluno[i].ativo = -1;
                        
                        for (int j=i; j<qtdAluno-1; j++)
                        {
                        //movendo todos os alunos pra casa anterior
                            listarAluno[j].nome[20]=listarAluno[j+1].nome[20];
                            listarAluno[j].cpf[15]=listarAluno[j+1].cpf[15];
                            listarAluno[j].matricula=listarAluno[j+1].matricula;
                            listarAluno[j].sexo=listarAluno[j+1].sexo;
                            listarAluno[j].ativo=listarAluno[j+1].ativo;
                            
                        //movendo as datas de cadastro e de nascimento
                        //nascimento
                            listarAluno[j].diaNascimento=listarAluno[j+1].diaNascimento;
                            listarAluno[j].mesNascimento=listarAluno[j+1].mesNascimento;
                            listarAluno[j].anoNascimento=listarAluno[j+1].anoNascimento;
                        //cadastro
                            listarAluno[j].diaAtual=listarAluno[j+1].diaAtual;
                            listarAluno[j].mesAtual=listarAluno[j+1].mesAtual;
                            listarAluno[j].anoAtual=listarAluno[j+1].anoAtual;
                        }

                            achou=1;
                            break;
                    }
                }

                        if(achou){
                            return EXCLUSAO_ALUNO_SUCESSO;
                            
                        }else{
                                return MATRICULA_ALUNO_INEXISTENTE;
                        
                        }
                            
                }
            }
    

