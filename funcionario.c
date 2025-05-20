#include "file.h"

void opc1client() {
    arquivo_cp();
    arquivo_cc();
    cPoupanca conta_p;
    cCorrente conta_c;

	while (1) {
        int opclient;
        opc_contas();
        scanf("%d", &opclient);

        printf("\n");
        Sleep(2000);
        system("cls");

        switch (opclient) {
            case 1:
                printf("Digite os dados da conta poupanca:\n\n");
                obterDadosPou(&conta_p);
                print_arqCP(conta_p);

                Sleep(2000);
                system("cls");
                break;
            case 2:
                printf("Digite os dados da conta corrente:\n\n");
                obterDadosCor(&conta_c);
                print_arqCC(conta_c);

                Sleep(2000);
                system("cls");
                break;
            case 3:
                printf("\nSaindo...\n\n\n");
                Sleep(2000);
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
}

void opc2client() {
    int opc_aux3;
    int number;

    printf("1 -  CONTA POUPANCA   - CP\n");
    printf("2 -  CONTA CORRENTE   - CC\n");
    printf("3 - CONTA FUNCIONARIO - CF\n");
    printf("4 - VOLTAR\n");
    printf("\nDigite a opcao para encerramento de conta: ");
    scanf("%d", &opc_aux3);

    printf("\n");

        switch (opc_aux3){
            case 1:
            printf("Digite a conta para encerramento: ");
            scanf("%d", &number);

            deleteLineWithFirstNumber("arquivo1.txt", number);
            printf("Conta encerrada com sucesso.");

            Sleep(2000);
            system("cls"); 
            break;

            case 2:
            printf("Digite a conta para encerramento: ");
            scanf("%d", &number);

            deleteLineWithFirstNumber("arquivo2.txt", number);
            printf("Conta encerrada com sucesso.");

            Sleep(2000);
            system("cls"); 
            break;

            case 3:
            printf("Digite a conta para encerramento: ");
            scanf("%d", &number);

            deleteLineWithFirstNumber("arquivo3.txt", number);
            printf("Conta encerrada com sucesso."); 

            Sleep(2000);
            system("cls"); 
            break;

            case 4:
                printf("\nSaindo...\n");
                Sleep(2000);
                return;
                break;

            default:
            printf("\n**Opcao invalida.**\n\n\n\n");
            Sleep(2000);
            system("cls");
            break;
    }
}

void opc3client1() {
    cCorrente contac;
    cPoupanca contap;
    int opc_aux5;
    int number;

    opc_contas();
    scanf("%d", &opc_aux5);
    printf("\n");
    Sleep(2000);
    system("cls");
    
    switch (opc_aux5){
        case 1:
            fflush(stdin);
            printf("Digite a conta para ser mostrada: ");
            scanf("%d", &number);
			
			
            sscanf(findLineStartingWithNumber("arquivo1.txt", number), 
            "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%i;%[^;];%[^;];%[^;];%f;", 
            contap.numeroConta, contap.agencia, contap.nomeCliente, contap.cpfCliente, //4
            contap.dataNascimento_dia, contap.dataNascimento_mes, contap.dataNascimento_ano, //3
            contap.telefoneContato, contap.cep, &contap.numeroCasa, //3
            contap.bairro, contap.cidade, contap.estado, &contap.saldoPop); //4
            
            Sleep(2000);
            system("cls");

            printf("\nTIPO DE CONTA: Poupanca \n");
            printf("NOME DO CLIENTE: %s\n", contap.nomeCliente);
            printf("CPF DO CLIENTE: %s\n", contap.cpfCliente);
            printf("SALDO DA CONTA: %.2f\n", contap.saldoPop);
            printf("LIMITE DISPONIVEL: SEM LIMITES\n");
            printf("DATA DE VENCIMENTO: 00/00/00 \n");
            getchar();

            fflush(stdin);
            while(getchar() != '\n');
            break;

        case 2:
            fflush(stdin);
            printf("Digite a conta para ser mostrada: ");
            scanf("%d", &number);

            sscanf(findLineStartingWithNumber("arquivo2.txt", number), 
            "%[^;];%[^;];%lf;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%i;%[^;];%[^;];%[^;];%f;",
            contac.numeroConta, contac.agencia, &contac.limiteConta, contac.dataVencimento_dia, 
            contac.dataVencimento_mes, contac.dataVencimento_ano, 
            contac.nomeCliente, contac.cpfCliente, contac.dataNascimento_dia, 
            contac.dataNascimento_mes, contac.dataNascimento_ano, contac.telefoneContato, 
            contac.cep, &contac.numeroCasa, contac.bairro, 
            contac.cidade, contac.estado, &contac.saldoCor); 

            Sleep(2000);
            system("cls");

            printf("\nTIPO DE CONTA: Corrente\n");
            printf("NOME DO CLIENTE: %s\n", contac.nomeCliente);
            printf("CPF DO CLIENTE: %s\n", contac.cpfCliente);
            printf("SALDO DA CONTA: %.2f\n", contac.saldoCor);
            printf("LIMITE DISPONIVEL: %.2f\n", contac.limiteConta);
            printf("DATA DE VENCIMENTO: %s/%s/%s \n", contac.dataVencimento_dia, contac.dataVencimento_mes, contac.dataVencimento_ano);
            getchar();

            fflush(stdin);
            while(getchar() != '\n');
            break;

        default:
            printf("\n**Opcao invalida.**\n\n\n\n");
            Sleep(2000);
            system("cls");
            break;
    }
}
void opc3funcionario() {
    cFuncionario contaf;
    int number2;
    Sleep(2000);
    system("cls");
    
    fflush(stdin);
    printf("Digite a conta para ser mostrada: ");
    scanf("%d", &number2);

    sscanf(findLineStartingWithNumber("arquivo3.txt", number2),
    "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%i;%[^;];%[^;];%[^;];", //13
    contaf.codigoFuncionario, contaf.cargo, contaf.nomeFuncionario, contaf.cpfFuncionario, //4
    contaf.dataNascimento_dia, contaf.dataNascimento_mes, contaf.dataNascimento_ano, //3
    contaf.telefoneContato, contaf.cep, &contaf.numeroCasa, //3
    contaf.bairro, contaf.cidade, contaf.estado); //3
    getchar();

    Sleep(2000);
    system("cls");

    printf("CONTA DE FUNCIONARIO NUMERO: %d\n", number2);
    printf("CODIGO DO FUNCIONARIO: %s\n", contaf.codigoFuncionario);
    printf("CARGO: %s\n", contaf.cargo);
    printf("NOME DO FUNCIONARIO: %s\n", contaf.nomeFuncionario);
    printf("CPF DO FUNCIONARIO: %s\n", contaf.cpfFuncionario);
    printf("DATA DE NASCIMENTO: %s/%s/%s\n", contaf.dataNascimento_dia, contaf.dataNascimento_mes, contaf.dataNascimento_ano);
    printf("TELEFONE: %s\n", contaf.telefoneContato);
    printf("\nLOCAL (ENDERECO)\n");
    printf("CEP: %s\n", contaf.cep);
    printf("NUMERO DA CASA: %i\n", contaf.numeroCasa);
    printf("BAIRRO: %s\n", contaf.bairro);
    printf("CIDADE: %s\n", contaf.cidade);
    printf("ESTADO: %s\n", contaf.estado);
    getchar();

    fflush(stdin);
    while(getchar() != '\n');

}
void opc3client2() {
    cCorrente contac;
    cPoupanca contap;
    int opc_aux5;
    int number = 0;

    Sleep(2000);
    system("cls");

    opc_contas();
    scanf("%d", &opc_aux5);
    printf("\n");
    
    switch (opc_aux5){
        case 1:
            
            printf("Digite a conta para ser mostrada: ");
            scanf("%d", &number);

            sscanf(findLineStartingWithNumber("arquivo1.txt", number), 
            "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%i;%[^;];%[^;];%[^;];%f;", 
            contap.numeroConta, contap.agencia, contap.nomeCliente, contap.cpfCliente, //4
            contap.dataNascimento_dia, contap.dataNascimento_mes, contap.dataNascimento_ano,  //3
            contap.telefoneContato, contap.cep, &contap.numeroCasa, // 3
            contap.bairro, contap.cidade, contap.estado, &contap.saldoPop); //4
            
            Sleep(2000);
            system("cls");

            printf("\nNOME DO CLIENTE: %s\n", contap.nomeCliente);
            printf("CPF DO CLIENTE: %s\n", contap.cpfCliente);
            printf("DATA DE NASCIMENTO: %s/%s/%s \n", contap.dataNascimento_dia, contap.dataNascimento_mes, contap.dataNascimento_ano);
            printf("TELEFONE: %s\n", contap.telefoneContato);

            printf("\nLOCAL (ENDERECO)\n");
            printf("NUMERO DA CASA: %i\n", contap.numeroCasa);
            printf("CEP: %s\n", contap.cep);
            printf("BAIRRO: %s\n", contap.bairro);
            printf("CIDADE: %s\n", contap.cidade);
            printf("ESTADO: %s\n", contap.estado);
            getchar();

            fflush(stdin);
            while(getchar() != '\n');
            break;

        case 2:
            
            printf("Digite a conta para ser mostrada: ");
            scanf("%d", &number);

            sscanf(findLineStartingWithNumber("arquivo2.txt", number), 
            "%[^;];%[^;];%lf;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%i;%[^;];%[^;];%[^;];%f;",
            contac.numeroConta, contac.agencia, &contac.limiteConta, contac.dataVencimento_dia, //4
            contac.dataVencimento_mes, contac.dataVencimento_ano, //2
            contac.nomeCliente, contac.cpfCliente, contac.dataNascimento_dia, //3
            contac.dataNascimento_mes, contac.dataNascimento_ano, contac.telefoneContato, //3
            contac.cep, &contac.numeroCasa, contac.bairro, //3
            contac.cidade, contac.estado, &contac.saldoCor); //3
            
            Sleep(2000);
            system("cls");

            printf("\nNOME DO CLIENTE: %s\n", contac.nomeCliente);
            printf("CPF DO CLIENTE: %s\n", contac.cpfCliente);
            printf("DATA DE NASCIMENTO: %s/%s/%s \n", contac.dataNascimento_dia, contac.dataNascimento_mes, contac.dataNascimento_ano);
            printf("TELEFONE: %s\n", contac.telefoneContato);

            printf("\nLOCAL (ENDERECO)\n");
            printf("NUMERO DA CASA: %i\n", contac.numeroCasa);
            printf("CEP: %s\n", contac.cep);
            printf("BAIRRO: %s\n", contac.bairro);
            printf("CIDADE: %s\n", contac.cidade);
            printf("ESTADO: %s\n", contac.estado);
            getchar();

            fflush(stdin);
            while(getchar() != '\n');
            
            break;

        default:
            printf("\n**Opcao invalida.**\n\n\n\n");
            Sleep(2000);
            system("cls");
            break;
    
}

}

void opc4troca(){
    int number;

    opc_contaPRT();
    scanf("%d", &number);

    switch (number){
        
            case 1:
                printf("CONTA POUPANCA -> CONTA CORRENTE\n");
                moveLineWithFirstNumber("arquivo1.txt", "arquivo2.txt", number);
                getchar();
                
                printf("\nDados salvos com sucesso.\n");
    
                Sleep(2000);
                system("cls");
            break;

            case 2:
                printf("CONTA CORRENTE -> CONTA POUPANCA\n");
                moveLineWithFirstNumber("arquivo2.txt", "arquivo1.txt", number);
                getchar();
                
                printf("\nDados salvos com sucesso.\n");

                Sleep(2000);
                system("cls");
            break;

            case 3:
                printf("\nSaindo...\n\n\n");
                Sleep(2000);
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
void opc4alterar(){
    arquivo_cp();
    arquivo_cc();
    cPoupanca contap;
    cCorrente contac;
    int numbero;

    fflush(stdin);
    printf("Sera mostrado: \nOs dados anteriores da conta para a alteracao \n(priorize salvar estes dados em algum lugar)\n");
    getchar();

    
    printf("\nprocessando... \n\n\n");
    Sleep(3000);
    system("cls");

    printf("Por favor informe: \n\n");

    opc3client1();
	Sleep(3000);
    system("cls");

	opc_contasALR();
    scanf("%i", &numbero);

    printf("\n");

    Sleep(3000);
    system("cls");

    switch (numbero){
        case 1: ///////////////////////////////////////////////////conta poupansa
        
        deleteLineWithFirstNumber("arquivo1.txt", numbero);

        system("cls");
        fflush(stdin);
        
        printf("Alterando a Conta %i", numbero);
        printf("\nPor favor informe: \n\n");

        while (1) { 
        system("cls");

                printf("Digite os dados da conta poupanca:\n\n");
                obterDadosPou(&contap);
                print_arqCP(contap);

                Sleep(2000);
                system("cls");

        }
        break;

        case 2: ///////////////////////////////////////conta corrente

        deleteLineWithFirstNumber("arquivo2.txt", numbero);
        
        system("cls");
        fflush(stdin);

        printf("Alterando a Conta %i", numbero);
        printf("\nPor favor informe: \n\n");

        while (1) {
            system("cls");

            printf("Digite os dados da conta corrente:\n\n");
            obterDadosCor(&contac);
            print_arqCC(contac);

            Sleep(2000);
            system("cls");

        }
        break;

        case 3: //////////////////////////////tipo de conta

            opc4troca();
        
            Sleep(2000);
            system("cls");
            break;

        case 4:
            printf("\nSaindo...\n\n\n");
            Sleep(2000);
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
void opc4funcionario(){
    arquivo_cf();
    cFuncionario contaf;
    int numberi;
    
    fflush(stdin);
    printf("Sera mostrado: \n Os dados anteriores da conta para a alteracao \n(priorize salvar estes dados em algum lugar)\n");
    getchar();

    printf("\nprocessando... \n\n\n");
    Sleep(3000);
    system("cls");

    printf("Por favor informe: \n\n\n");


    opc3funcionario();
    Sleep(2000);
    system("cls");

    printf("\nInforme o numero da conta: ");
    scanf("%i", &numberi);

    printf("\n");

    deleteLineWithFirstNumber("arquivo3.txt", numberi);
    Sleep(2000);
    system("cls");

    printf("Digite os Dados necessario: \n\n\n");
	getchar();
			
    obterDadosFun(&contaf);
    print_arqCF(contaf);
    getchar();

    system("cls");
}

void funcaoFuncionario(){
    arquivo_cp();
    arquivo_cc();
    arquivo_cf();
    cFuncionario conta_f;

    char senhaADM[] = "adm123";
    char senhaFunc[] = "senha1";
    char senha_aux[20];
    int opcao;
    int opcg_aux2;

    while (1) {
		menu_funcionario();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: ////////////////////////////// criar conta
                opc_contas();
                opc1client();

                Sleep(2000);
                system("cls");
                break;

            case 2: ///////////////////////////////// excluir conta
                Sleep(1000);
                system("cls"); 

                printf("Digite a senha de administrador: ");
                scanf("%s", senha_aux);

                Sleep(1000);
                system("cls"); 

                if (strcmp(senhaADM, senha_aux) == 0) {

                    opc2client();

                	Sleep(2000);
                    system("cls"); 
                } else {
                    printf("**senha invalida**\n\n\n\n");
                    Sleep(2000);
                    system("cls");
                }
                break;

            case 3: /////////////////////////////////////////////CONSULTA DADOS
                Sleep(1000);
                system("cls");

                opc_CFC1();

                printf("\nDigite a opcao para consulta: ");
                scanf("%i", &opcg_aux2);
                printf("\n");

                switch (opcg_aux2){

                    case 1:
					
					Sleep(2000);
    				system("cls");
    				
                    opc3client1();

                    Sleep(2000);
                    system("cls");
                    break;

                    case 2:

                    opc3funcionario();

                    Sleep(2000);
                    system("cls");

                    break;

                    case 3:

                    opc3client2();

                    Sleep(2000);
                    system("cls");
                    break;

                    case 4:
                    printf("\nSaindo...\n\n\n");
                    Sleep(2000);
                    system("cls");
                    return;
                    break;

                    default:
                    printf("\n**Opcao invalida.**\n\n\n\n");
                    Sleep(2000);
                    system("cls");
                    break;
                }

                Sleep(2000);
                system("cls");
                break;

            case 4: ///////////////////////////////////////////////////////////alterar conta
    			system("cls");
    			
                opc_CFC2();
                
                printf("\nDigite a opcao para se alterar: ");
                scanf("%i", &opcg_aux2);
                
                printf("\n");
                
                switch (opcg_aux2){
                	
                	case 1:
                		printf("Digite a senha de administrador: ");
                		scanf("%s", senha_aux);

                		Sleep(1000);
                		system("cls"); 

                		if (strcmp(senhaADM, senha_aux) == 0) {
						
                    	opc4alterar();

                		Sleep(2000);
                    	system("cls"); 
                		} else {
                    	printf("**senha invalida**\n\n\n\n");
                    	Sleep(2000);
                    	system("cls");
                    	}
                		break;
                		
                	case 2:
                		printf("Digite a senha de administrador: ");
                		scanf("%s", senha_aux);

                		Sleep(1000);
                		system("cls"); 

                		if (strcmp(senhaADM, senha_aux) == 0) {

                    	opc4alterar();

                		Sleep(2000);
                    	system("cls"); 
                		} else {
                    	printf("**senha invalida**\n\n\n\n");
                    	Sleep(2000);
                    	system("cls");
                		}
                		break;
                		
                	case 3:
                		printf("Digite a senha de administrador: ");
                		scanf("%s", senha_aux);

                		Sleep(1000);
                		system("cls"); 

                		if (strcmp(senhaADM, senha_aux) == 0) {

                    	opc4funcionario();

                		Sleep(2000);
                    	system("cls"); 
                		} else {
                    	printf("**senha invalida**\n\n\n\n");
                    	Sleep(2000);
                    	system("cls");
						}
                		break;

                    case 4:
                        printf("\nSaindo...\n\n\n");
                        Sleep(2000);
                        system("cls");
                        return;
                        break;
                	
                	default:
                		printf("\n**Opcao invalida.**\n\n\n\n");
                		Sleep(2000);
                		system("cls");
                		break;
                		
            	}
                Sleep(2000);
                system("cls");
                break;
				
            case 5:
            	Sleep(2000);
                system("cls");

                criafuncionariovdd();
				
				printf("Digite os Dados necessario: \n\n\n");
				getchar();
			
                obterDadosFun(&conta_f);
                print_arqCF(conta_f);
				
                Sleep(2000);
                system("cls");
                break;
                
            case 6:
            	
                printf("Digite a senha: ");
                scanf("%s", senha_aux);
                printf("\n");

                if (strcmp(senhaFunc, senha_aux) == 0) {
                	printf("O relatorio sera aberto \n\n");
					RelatorioExcel();
                    getchar();

                    printf("O relatorio foi aberto \n");

					Sleep(2000);
                    system("cls"); 

                } else {
                    printf("**senha invalida**\n\n\n\n");
                    Sleep(2000);
                    system("cls"); 
                    
                }
                Sleep(2000);
                system("cls");
                break;

            case 7:
                printf("\nSaindo...\n\n\n");
                Sleep(2000);
                system("cls");
                return;

            default:
                printf("\n**Opcao invalida.**\n\n\n\n");
                Sleep(2000);
                system("cls");
                break;
        }
    }
}