// Incluir as bibliotecas de C utilizadas no codigo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Estrutura dos dados de login
typedef struct login{
    char usuario[30];
    char senha[30];
    } login; login l[1];

int main()
{


    //variaveis de login
    char usuario[30];
    char senha[30];

    //Atribuicao de usuario e senha no sistema.
    strcpy(l[0].usuario, "admin");
    strcpy(l[0].senha, "admin");


    //inicializacao do programa
    printf("\n -------------------------------------------------------------------------\n");
    printf("\n Bem vindo ao sistema de cadastro de pacientes diagnosticados com COVID-19\n");
    printf("\n -------------------------------------------------------------------------\n\n");
    printf("Por favor, digite usuario e senha\n\n\n");


    printf("usuario:");
    scanf("%s",usuario);
    printf("senha:");
    scanf("%s",senha);




    //validacao de usuario e senha
    if ((strcmp(usuario,l[0].usuario)==0) && (strcmp(senha,l[0].senha)==0)){
        printf("\n\n login efetuado com sucesso\n\n");
        system("pause");
        }
    else {
        printf("\n\n login incorreto\n\n");
        system("pause");
        return 0; //Desliga o sistema após  apresentar mensagem de login incorreto.
    }



    //Limpar a tela para continuar o processo de cadastro
    system("cls");



    //Verifica se o cadastro e necessario
    int diag;

    printf("\n Paciente diagnosticado com COVID-19? \n\n\n");
    printf("\n 1 - SIM \n");
    printf("\n 2 - NAO \n\n");
    scanf("%d", &diag);


    if (diag == 1){

        printf("\n -------------------------------------------------------------------------\n");
        printf("\n\n Paciente com covid, continuar para cadastro \n\n");
        printf("\n -------------------------------------------------------------------------\n\n\n");
        system("pause");
    }

    else {
        printf("\n -------------------------------------------------------------------------\n");
        printf("\n\n Nao fazer cadastro deste paciente. \n\n Obrigado! \n\n");
        printf("\n -------------------------------------------------------------------------\n\n\n");
        system("pause");
        return 0; //Desliga o sistema após apresentar mensagem.
    }


    //limpar a tela para continuar o processo de cadastro
    system("cls");

    //Limpar buffer teclado para continuar o processo de cadastro
    fflush(stdin);


    char nome[100], ender[100], compl[100], bairro[100], cid[100], est[100], email[100], cep[100], comorbids[200], cpf[100],tel[100], num[100];
    int dian, mesn, anon, diac, mesc, anoc, idade, comorbid;

    FILE*arq;

    if((arq = fopen("cadastro_covid19.txt","w")) ==NULL)
    {
        printf("\nErro ao abrir o arquivo");
    }
    else
    {

        printf("\n Nome Completo: ");
        scanf(" %[^\n]s", &nome);

        fflush(stdin);

        printf("\n CPF (somente numeros): ");
        scanf(" %[^\n]s", &cpf);

        fflush(stdin);


        printf("\n Telefone (xx xxxxxxxxx): ");
        scanf(" %[^\n]s", &tel);

        fflush(stdin);

        printf("\n Endereco: ");
        scanf(" %[^\n]s", &ender);

        fflush(stdin);

        printf("\n Numero: ");
        scanf(" %[^\n]s", &num);

        fflush(stdin);

        printf("\n Complemento: ");
        scanf(" %[^\n]s", &compl);

        fflush(stdin);

        printf("\n Bairro: ");
        scanf(" %[^\n]s", &bairro);

        fflush(stdin);

        printf("\n Cidade: ");
        scanf(" %[^\n]s", &cid);

        fflush(stdin);

        printf("\n Estado: ");
        scanf(" %[^\n]s", &est);

        fflush(stdin);

        printf("\n CEP: ");
        scanf(" %[^\n]s", &cep);

        fflush(stdin);

        printf("\n E-mail: ");
        scanf(" %[^\n]s", &email);

        fflush(stdin);

        printf("\n Paciente apresenta comorbidades? \n\n");

        printf("\n 1 - SIM \n");
        printf("\n 2 - NAO \n\n");
        scanf("%d", &comorbid);

        if (comorbid==1){

            printf("\n Informar comorbidades: ");
            scanf(" %[^\n]s", &comorbids);

        }


        fflush(stdin);

        printf("\n Data de Nascimento (somente numeros dd/mm/aaaa)\n");
        printf("\n dia: ");
        scanf(" %d", &dian);

        fflush(stdin);


        printf("\n mes: ");
        scanf(" %d", &mesn);

        fflush(stdin);


        printf("\n ano: ");
        scanf(" %d", &anon);

        fflush(stdin);

        printf("\n Data do Diagnostico de Covid-19 (somente numeros dd/mm/aaaa):");
        printf("\n dia: ");
        scanf(" %d", &diac);

        fflush(stdin);

        printf("\n mes: ");
        scanf("%d", &mesc);

        fflush(stdin);


        printf("\n ano: ");
        scanf("%d", &anoc);

        idade = anoc - anon;

        printf("\n\nIdade do paciente: %d", idade);
        printf("\n\n");

        system("pause");

       //gravacao de dados no arquivo texto de cadastro

        fprintf(arq, "%s", "Nome: ");
        fprintf(arq, "%s", nome);
        putc('\n', arq);
        fprintf(arq, "%s", "CPF: ");
        fprintf(arq, "%s", cpf);
        putc('\n', arq);
        fprintf(arq, "%s", "Telefone: ");
        fprintf(arq,"%s", tel);
        putc('\n', arq);
        fprintf(arq, "%s", "Endereco: ");
        fprintf(arq, "%s", ender);
        putc('\t', arq);
        fprintf(arq, "%s", num);
        putc('\t', arq);
        fprintf(arq, "%s", compl);
        putc('\n', arq);
        fprintf(arq, "%s", "Bairro: ");
        fprintf(arq, "%s", bairro);
        putc('\n', arq);
        fprintf(arq, "%s", "Cidade: ");
        fprintf(arq, "%s", cid);
        putc('\n', arq);
        fprintf(arq, "%s", "Estado: ");
        fprintf(arq, "%s", est);
        putc('\n', arq);
        fprintf(arq, "%s", "CEP: ");
        fprintf(arq, "%s", cep);
        putc('\n', arq);
        fprintf(arq, "%s", "E-mail: ");
        fprintf(arq, "%s", email);
        putc('\n', arq);
        fprintf(arq, "%s", "Comorbidades: ");
        fprintf(arq, "%s", comorbids);
        putc('\n', arq);
        fprintf(arq, "%s", "Data de Nascimento: ");
        fprintf(arq, "%d", dian);
        fprintf(arq, "%s", "/");
        fprintf(arq, "%d", mesn);
        fprintf(arq, "%s", "/");
        fprintf(arq, "%d", anon);
        putc('\n', arq);
        fprintf(arq, "%s", "Idade: ");
        fprintf(arq, "%d", idade);
        putc('\n', arq);
        fprintf(arq, "%s", "Data diagnostico Covid-19: ");
        fprintf(arq, "%d", diac);
        fprintf(arq, "%s", "/");
        fprintf(arq, "%d", mesc);
        fprintf(arq, "%s", "/");
        fprintf(arq, "%d", anoc);
        putc('\n', arq);

        fclose(arq);

    }

    fflush(stdin);
    system("cls");



     //Elaboracao do arquivo texto para envio a sec de saude, se necessario

     if ((idade > 65 )||((comorbid)==1))

     {
         printf("\n -------------------------------------------------------------------------\n");
         printf("Paciente do Grupo de Risco.\n\nEnviar arquivo para secretaria de saude!\n" );
         printf("\n -------------------------------------------------------------------------\n");

         FILE*arqsec;
         arqsec = fopen("covid19_secsaude.txt","w");
         fprintf(arqsec, "%s", "CEP: ");
         fprintf(arqsec, "%s", cep);
         putc('\n', arqsec);
         fprintf(arqsec, "%s", "Idade: ");
         fprintf(arqsec, "%d", idade);
         putc('\n', arqsec);

         fclose(arqsec);


         printf("\n\nCadastro Finalizado com sucesso\n" );
         printf("\n -------------------------------------------------------------------------\n");

         system("pause");


     }
     else {

            printf("\n\nCadastro Finalizado com sucesso\n" );
            printf("\n -------------------------------------------------------------------------\n");
            system("pause");

     }


    return 0; //Fim do cadastro

    }

