#include "funcionario.c"

void print_saldo1() {
    cCorrente contacc;
    cPoupanca contacp;
    int opc_aux8;
    int numberc;

    Sleep(2000);
    system("cls");
    fflush(stdin);

    opc_contas();
    scanf("%d", &opc_aux8);
    printf("\n");
    fflush(stdin);

    switch (opc_aux8){
        case 1:
            
            printf("Digite a conta para ser mostrada: ");
            scanf("%i", &numberc);
            

            sscanf(findLineStartingWithNumber("arquivo1.txt", numberc), 
            "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%i;%[^;];%[^;];%[^;];%f;", 
            contacp.numeroConta, contacp.agencia, contacp.nomeCliente, contacp.cpfCliente,
            contacp.dataNascimento_dia, contacp.dataNascimento_mes, contacp.dataNascimento_ano, 
            contacp.telefoneContato, contacp.cep, &contacp.numeroCasa, 
            contacp.bairro, contacp.cidade, contacp.estado, &contacp.saldoPop); 
            

            printf("\nTIPO DE CONTA: Poupanca \n");
            printf("SALDO DA CONTA: %.2f\n", contacp.saldoPop);
            
            getchar();

            fflush(stdin);
            while(getchar() != '\n');

            break;

        case 2:
            
            printf("Digite a conta para ser mostrada: ");
            scanf("%i", &numberc);
           

            sscanf(findLineStartingWithNumber("arquivo2.txt", numberc), 
            "%[^;];%[^;];%lf;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%i;%[^;];%[^;];%[^;];%f;",
            contacc.numeroConta, contacc.agencia, &contacc.limiteConta, contacc.dataVencimento_dia, 
            contacc.dataVencimento_mes, contacc.dataVencimento_ano, 
            contacc.nomeCliente, contacc.cpfCliente, contacc.dataNascimento_dia, 
            contacc.dataNascimento_mes, contacc.dataNascimento_ano, contacc.telefoneContato, 
            contacc.cep, &contacc.numeroCasa, contacc.bairro, 
            contacc.cidade, contacc.estado, &contacc.saldoCor);


            printf("\nTIPO DE CONTA: Corrente\n");
            printf("SALDO DA CONTA: %.2f\n", contacc.saldoCor);

            getchar();

            fflush(stdin);
            while(getchar() != '\n');

            break;

        case 3:
            printf("\nSaindo...\n\n\n");
            Sleep(3000);
            system("cls");
            return;
            break;

        default:
            printf("\n**Opcao invalida.**\n\n\n\n");
            Sleep(2000);
            system("cls");
            break;
    }
}

void print_deposito1() {
    cCorrente contacc;
    cPoupanca contacp;
    int opc_aux8;
    int numberc;
    float deposito;

    Sleep(2000);
    system("cls");
    fflush(stdin);

    opc_contas();
    scanf("%d", &opc_aux8);
    printf("\n");
    fflush(stdin);

    switch (opc_aux8){
        case 1:
            
            printf("Digite a conta para ser depositada: ");
            scanf("%i", &numberc);
            

            sscanf(findLineStartingWithNumber("arquivo1.txt", numberc), 
            "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%i;%[^;];%[^;];%[^;];%f;", 
            contacp.numeroConta, contacp.agencia, contacp.nomeCliente, contacp.cpfCliente,
            contacp.dataNascimento_dia, contacp.dataNascimento_mes, contacp.dataNascimento_ano, 
            contacp.telefoneContato, contacp.cep, &contacp.numeroCasa, 
            contacp.bairro, contacp.cidade, contacp.estado, &contacp.saldoPop); 


            deleteLineWithFirstNumber("arquivo1.txt", numberc);
            
            printf("\nTIPO DE CONTA: Poupanca \n");
            printf("Digite o valor a ser depositada: ");
            scanf("%f", &deposito);
            printf("\n");

            contacp.saldoPop += deposito;

            printf("SALDO POS DEPOSITO: %.2f\n", contacp.saldoPop);
            print_arqCP(contacp);
            printf("VALORES REGISTRADOS NO BANCO DE DADOS");

            getchar();

            fflush(stdin);
            while(getchar() != '\n');

            break;

        case 2:
            
            printf("Digite a conta para ser depositada: ");
            scanf("%i", &numberc);
            

            sscanf(findLineStartingWithNumber("arquivo2.txt", numberc), 
            "%[^;];%[^;];%lf;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%i;%[^;];%[^;];%[^;];%f;",
            contacc.numeroConta, contacc.agencia, &contacc.limiteConta, contacc.dataVencimento_dia, 
            contacc.dataVencimento_mes, contacc.dataVencimento_ano, 
            contacc.nomeCliente, contacc.cpfCliente, contacc.dataNascimento_dia, 
            contacc.dataNascimento_mes, contacc.dataNascimento_ano, contacc.telefoneContato, 
            contacc.cep, &contacc.numeroCasa, contacc.bairro, 
            contacc.cidade, contacc.estado, &contacc.saldoCor);


            deleteLineWithFirstNumber("arquivo2.txt", numberc);

            printf("\nTIPO DE CONTA: Corrente\n");
            printf("Digite o valor a ser depositada: ");
            scanf("%f", &deposito);
            printf("\n");

            contacc.saldoCor += deposito;
            
            printf("SALDO POS DEPOSITO: %.2f\n", contacc.saldoCor);
            print_arqCC(contacc);
            printf("VALORES REGISTRADOS NO BANCO DE DADOS");

            getchar();
            

            fflush(stdin);
            while(getchar() != '\n');

            break;

        case 3:
            printf("\nSaindo...\n\n\n");
            Sleep(3000);
            system("cls");
            return;
            break;

        default:
            printf("\n**Opcao invalida.**\n\n\n\n");
            Sleep(2000);
            system("cls");
            break;
    }
}

void print_saque1(){
    cCorrente contacc;
    cPoupanca contacp;
    int opc_aux8;
    int numberc;
    float saque;

    Sleep(2000);
    system("cls");
    fflush(stdin);

    opc_contas();
    scanf("%d", &opc_aux8);
    printf("\n");
    fflush(stdin);

    switch (opc_aux8){
        case 1:
            
            printf("Digite a conta para ser debitada: ");
            scanf("%i", &numberc);
            
   

            sscanf(findLineStartingWithNumber("arquivo1.txt", numberc), 
            "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%i;%[^;];%[^;];%[^;];%f;", 
            contacp.numeroConta, contacp.agencia, contacp.nomeCliente, contacp.cpfCliente,
            contacp.dataNascimento_dia, contacp.dataNascimento_mes, contacp.dataNascimento_ano, 
            contacp.telefoneContato, contacp.cep, &contacp.numeroCasa, 
            contacp.bairro, contacp.cidade, contacp.estado, &contacp.saldoPop); 
            
            
            printf("\nTIPO DE CONTA: Poupanca \n");
            printf("Digite o valor a ser debitado: ");
            scanf("%f", &saque);
            printf("\n");

            deleteLineWithFirstNumber("arquivo1.txt", numberc);

            if (saque > contacp.saldoPop){
                printf("SALDO INSUFICIENTE");
                return;
            }
            contacp.saldoPop -= saque;
            
            printf("VALOR SERA DEBITADO DO SALDO");
            printf("VALOR POS SAQUE: %.2f\n", contacp.saldoPop);
            
            print_arqCP(contacp);

            getchar();

            fflush(stdin);
            while(getchar() != '\n');

            break;

        case 2:
            
            printf("Digite a conta para ser debitada: ");
            scanf("%i", &numberc);
            

            sscanf(findLineStartingWithNumber("arquivo2.txt", numberc), 
            "%[^;];%[^;];%lf;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%i;%[^;];%[^;];%[^;];%f;",
            contacc.numeroConta, contacc.agencia, &contacc.limiteConta, contacc.dataVencimento_dia, 
            contacc.dataVencimento_mes, contacc.dataVencimento_ano, 
            contacc.nomeCliente, contacc.cpfCliente, contacc.dataNascimento_dia, 
            contacc.dataNascimento_mes, contacc.dataNascimento_ano, contacc.telefoneContato, 
            contacc.cep, &contacc.numeroCasa, contacc.bairro, 
            contacc.cidade, contacc.estado, &contacc.saldoCor);

            printf("\nTIPO DE CONTA: Corrente\n");
            printf("Digite o valor a ser debitado: ");
            scanf("%f", &saque);
            printf("\n");

            deleteLineWithFirstNumber("arquivo2.txt", numberc);
            
            if (saque > contacc.saldoCor){
                printf("SALDO INSUFICIENTE");
                return;
            }
            contacc.saldoCor -= saque;

            printf("VALOR SERA DEBITADO DO SALDO");
            printf("VALOR POS SAQUE: %.2f\n", contacc.saldoCor);

            print_arqCC(contacc);
            getchar();
            

            fflush(stdin);
            while(getchar() != '\n');

            break;

        case 3:
            printf("\nSaindo...\n\n\n");
            Sleep(3000);
            system("cls");
            return;
            break;

        default:
            printf("\n**Opcao invalida.**\n\n\n\n");
            Sleep(2000);
            system("cls");
            break;
    }
}

void print_limite1() {
    cCorrente contacc;
    cPoupanca contacp;
    int opc_aux8;
    int numberc;

    Sleep(2000);
    system("cls");
    fflush(stdin);

    opc_contas();
    scanf("%d", &opc_aux8);
    printf("\n");
    fflush(stdin);

    switch (opc_aux8){
        case 1:
            
            printf("Digite a conta para ser mostrada: ");
            scanf("%i", &numberc);
            

            sscanf(findLineStartingWithNumber("arquivo1.txt", numberc), 
            "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%i;%[^;];%[^;];%[^;];%f;", 
            contacp.numeroConta, contacp.agencia, contacp.nomeCliente, contacp.cpfCliente,
            contacp.dataNascimento_dia, contacp.dataNascimento_mes, contacp.dataNascimento_ano, 
            contacp.telefoneContato, contacp.cep, &contacp.numeroCasa, 
            contacp.bairro, contacp.cidade, contacp.estado, &contacp.saldoPop); 
            

            printf("\nTIPO DE CONTA: Poupanca \n");
            
            printf("LIMITE INDISPONIVEL");
            getchar();

            fflush(stdin);
            while(getchar() != '\n');

            break;

        case 2:
            
            printf("Digite a conta para ser mostrada: ");
            scanf("%i", &numberc);
            

            sscanf(findLineStartingWithNumber("arquivo2.txt", numberc), 
            "%[^;];%[^;];%lf;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%i;%[^;];%[^;];%[^;];%f;",
            contacc.numeroConta, contacc.agencia, &contacc.limiteConta, contacc.dataVencimento_dia, 
            contacc.dataVencimento_mes, contacc.dataVencimento_ano, 
            contacc.nomeCliente, contacc.cpfCliente, contacc.dataNascimento_dia, 
            contacc.dataNascimento_mes, contacc.dataNascimento_ano, contacc.telefoneContato, 
            contacc.cep, &contacc.numeroCasa, contacc.bairro, 
            contacc.cidade, contacc.estado, &contacc.saldoCor);

            printf("\nTIPO DE CONTA: Corrente\n");
            if ( contacc.dataNascimento_dia == 0 && contacc.dataNascimento_mes == 0 && contacc.dataNascimento_ano == 0 ){
            printf("LIMITE INDISPONIVEL");

            } else {
            printf("LIMITE DISPONIVEL: %.2f\n", contacc.limiteConta);
            printf("DATA DE VENCIMENTO: %s/%s/%s \n", contacc.dataVencimento_dia, contacc.dataVencimento_mes, contacc.dataVencimento_ano);

            }
            getchar();

            fflush(stdin);
            while(getchar() != '\n');

            break;

        case 3:
            printf("\nSaindo...\n\n\n");
            Sleep(3000);
            system("cls");
            return;
            break;

        default:
            printf("\n**Opcao invalida.**\n\n\n\n");
            Sleep(2000);
            system("cls");
            break;
    }
}

void funcaoCliente() {
    arquivo_cp();
    arquivo_cc();
    int opcCliente;
    char senhaClient[] = "senha";
    char senha_dig3[20];
    char opc_aux2[30];
    int j = 0;
    char ch;

    while (1) {
        menu_client();
        scanf("%d", &opcCliente);

        printf("\n");

        fflush(stdin);
                printf("Informe o seu nome: ");
                scanf("%s", opc_aux2);
                getchar();

                printf("BEM VINDO ");
                while (opc_aux2[j]) {
                ch = opc_aux2[j];
                putchar(toupper(ch));
                j++;
                }
                
                system("cls");
                getchar();

        switch (opcCliente) {
            case 1: //saldo
                fflush(stdin);
                printf("Digite a senha: ");
                scanf("%s", senha_dig3);
                printf("\n");

                if (strcmp(senhaClient, senha_dig3) == 0) {
                	Sleep(1000);
                    system("cls"); 
                    print_saldo1();
                    getchar();

                    printf("\n");


                    Sleep(2000);
                    system("cls");
                } else {
                    printf("**senha invalida**\n\n\n\n");
                    Sleep(2000);
                    system("cls"); 
                }
                break;

            case 2: //deposito
                fflush(stdin);
                printf("\n");

                print_deposito1();
                getchar();

                Sleep(2000);
                system("cls");
            	break;

            case 3: //saque
                fflush(stdin);
                printf("Digite a senha: ");
                scanf("%s", senha_dig3);
                printf("\n");

                if (strcmp(senhaClient, senha_dig3) == 0) {
                	Sleep(1000);
                    system("cls"); 
                    print_saque1();
                    getchar();

                    printf("\n");


                    Sleep(2000);
                    system("cls");
                } else {
                    printf("**senha invalida**\n\n\n\n");
                    Sleep(2000);
                    system("cls"); 
                }
                break;
                
            case 4:
                printf("Digite a senha: ");
                scanf("%s", senha_dig3);
                printf("\n");

                if (strcmp(senhaClient, senha_dig3) == 0) {
                	Sleep(1000);
                    system("cls"); 
                    ExtratoExcel();
                    getchar();

                    printf("\n");


                    Sleep(2000);
                    system("cls");
                } else {
                    printf("**senha invalida**\n\n\n\n");
                    Sleep(2000);
                    system("cls"); 
                }
                break;

            case 5:

                printf("Digite a senha: ");
                scanf("%s", senha_dig3);
                printf("\n");

                if (strcmp(senhaClient, senha_dig3) == 0) {
                	Sleep(1000);
                    system("cls"); 
                    print_limite1();

                    printf("\n");

                    Sleep(2000);
                    system("cls");
                } else {
                    printf("**senha invalida**\n\n\n\n");
                    Sleep(2000);
                    system("cls"); 
                }

                break;

            case 6:
                printf("\nSaindo...\n\n\n");
                Sleep(3000);
                system("cls");
                return;
                break;

            default:
                printf("\n**Opcao invalida.**\n\n\n\n");
                Sleep(3000);
                system("cls");
                break;
        }

    }

}