#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#define MAX_LINE_LENGTH 1000

typedef struct{
    char numeroConta[20];
    char agencia[10];
    char nomeCliente[100];
    char cpfCliente[15];
    char dataNascimento_dia[3]; 
    char dataNascimento_mes[3]; 
    char dataNascimento_ano[5];
    char telefoneContato[15];
    char cep[12];
    int numeroCasa;
    char bairro[50];
    char cidade[50];
    char estado[3]; 
    float saldoPop;
}cPoupanca;

typedef struct{
    char numeroConta[20];
    char agencia[10];
    double limiteConta;
    char dataVencimento_dia[3];
    char dataVencimento_mes[3];
    char dataVencimento_ano[5];
    char nomeCliente[100];
    char cpfCliente[15];     
    char dataNascimento_dia[3]; 
    char dataNascimento_mes[3]; 
    char dataNascimento_ano[5]; 
    char telefoneContato[15];
    char cep[12];
    int numeroCasa;
    char bairro[50];
    char cidade[50];
    char estado[3];           
    float saldoCor;
}cCorrente;

typedef struct{
    char codigoFuncionario[50];
    char cargo[50];
    char nomeFuncionario[100];
    char cpfFuncionario[15];
    char dataNascimento_dia[3]; 
    char dataNascimento_mes[3]; 
    char dataNascimento_ano[5]; 
    char telefoneContato[20];
    char cep[12];
    int numeroCasa;
    char bairro[50];
    char cidade[50];
    char estado[3];
}cFuncionario;

void RelatorioExcel() {
char relatorio[100] = "start excel.exe Relatorio.xlsx";
system(relatorio);
printf("\nRelatorio gerado com sucesso!!");
}

void ExtratoExcel(){
char Extrato[100] = "start excel.exe Extrato.xlsx";
system(Extrato);
printf("\nExtrato gerado com sucesso!!");
}

void deleteLineWithFirstNumber(const char *filename, int number){
    FILE *inputFile = fopen(filename, "r");
    FILE *tempFile = fopen("temp.txt", "w");

    if (inputFile == NULL || tempFile == NULL) {
        perror("Error opening file");

    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), inputFile)) {
        int firstNumber;
        char *endPtr;

        firstNumber = strtol(line, &endPtr, 10);

        if (line != endPtr && firstNumber == number) {
            continue;
        }

        fputs(line, tempFile);
    }

    fclose(inputFile);
    fclose(tempFile);

    if (remove(filename) != 0) {
        perror("Error deleting original file");
		
    }

    if (rename("temp.txt", filename) != 0) {
        perror("Error renaming temporary file");

    }
}
char* findLineStartingWithNumber(const char *filename, int number) {
    FILE *inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), inputFile)) {
        int firstNumber;
        char *endPtr;

        firstNumber = strtol(line, &endPtr, 10);

        if (line != endPtr && firstNumber == number) {
            fclose(inputFile);
            char *matchingLine = (char *)malloc(strlen(line) + 1);
            if (matchingLine != NULL) {
                strcpy(matchingLine, line);
            }
            return matchingLine;
        }
    }

    fclose(inputFile);
    return NULL;
}
char* moveLineWithFirstNumber(const char *sourceFilename, const char *destFilename, int number) {
    FILE *sourceFile = fopen(sourceFilename, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    FILE *destFile = fopen(destFilename, "a"); // Append mode to add the line at the end of the destination file

    if (sourceFile == NULL || tempFile == NULL || destFile == NULL) {
        perror("Error opening file");
        if (sourceFile != NULL) fclose(sourceFile);
        if (tempFile != NULL) fclose(tempFile);
        if (destFile != NULL) fclose(destFile);
        
    }

    char line[MAX_LINE_LENGTH];
    int lineMoved = 0;

    while (fgets(line, sizeof(line), sourceFile)) {
        int firstNumber;
        char *endPtr;

        firstNumber = strtol(line, &endPtr, 10);

        // Check if the first number in the line is the one we're looking for
        if (!lineMoved && line != endPtr && firstNumber == number) {
            fputs(line, destFile);
            lineMoved = 1;
        } else {
            fputs(line, tempFile);
        }
    }

    fclose(sourceFile);
    fclose(tempFile);
    fclose(destFile);

    if (remove(sourceFilename) != 0) {
        perror("Error deleting original file");
        
    }

    if (rename("temp.txt", sourceFilename) != 0) {
        perror("Error renaming temporary file");
        
    }
    return NULL;
}

void apresentacao(){
    printf("\n**********************\n");
    printf("**                  **\n");
    printf("**  BANCO MALVADER  **\n");
    printf("**                  **\n");
    printf("**********************\n\n");
}
void menu_tela(){
    printf("**MENU PRINCIPAL**\n");
    printf("1 - FUNCIONARIO\n");
    printf("2 - CLIENTE\n");
    printf("3 - SAIR DO PROGRAMA\n");
    printf("\nDIGITE A OPCAO A SER EXECUTADA: ");
}
void menu_client(){
    printf("**MENU CLIENTE**\n");
    printf("1 - SALDO\n");
    printf("2 - DEPOSITO\n");
    printf("3 - SAQUE\n");
    printf("4 - EXTRATO\n");
    printf("5 - CONSULTAR LIMITE\n");
    printf("6 - SAIR\n");
    printf("\nDIGITE A OPCAO A SER EXECUTADA: ");
}
void menu_funcionario(){
	printf("**MENU FUNCIONARIO**\n");
    printf("1 - ABERTURA DE CONTA\n");
    printf("2 - ENCERRAMENTO DE CONTA\n");
    printf("3 - CONSULTAR DADOS\n");
	printf("4 - ALTERAR DADOS\n");
    printf("5 - CADASTRO DE FUNCIONARIOS\n");
    printf("6 - GERAR RELATORIOS\n");
    printf("7 - SAIR\n");
    printf("\nDIGITE A OPCAO A SER EXECUTADA: ");
}
void criafuncionariovdd(){
    printf("\n");
    printf("**************************************\n");
	printf("**  CADASTRO DE NOVO FUNCIONARIO:   **\n");
	printf("**************************************\n\n");
}

void opc_contas(){
    printf("1 - CONTA POUPANCA - CP\n");
    printf("2 - CONTA CORRENTE - CC\n");
    printf("3 - VOLTAR\n");
    printf("\nDIGITE A OPCAO A SER EXECUTADA: ");
}
void opc_contasALR(){
    printf("1 - CONTA POUPANCA - CP\n");
    printf("2 - CONTA CORRENTE - CC\n");
    printf("3 - ALTERAR TIPO DE CONTA\n");
    printf("4 - VOLTAR\n");
    printf("\nDIGITE A OPCAO A SER ALTERADA: ");
}
void opc_contaPRT(){
    printf("1 - CONTA POUPANCA -> CONTA CORRENTE\n");
    printf("2 - CONTA CORRENTE -> CONTA POUPANCA\n");
    printf("3 - VOLTAR\n");
    printf("\nDIGITE A OPCAO A SER EXECUTADA: ");
}
void opc_contaDEP(){
    printf("1 - DEPOSITAR NA CONTA POUPANCA - CP\n");
    printf("2 - DEPOSITAR NA CONTA CORRENTE - CC\n");
    printf("3 - VOLTAR\n");
    printf("\nDIGITE A OPCAO A SER EXECUTADA: ");
}

void opc_CFC1(){
    printf("1 - CONSULTAR CONTA\n");
    printf("2 - CONSULTAR FUNCIONARIO\n");
    printf("3 - CONSULTAR CLIENTE\n");
    printf("4 - VOLTAR\n");
}
void opc_CFC2(){
    printf("1 - ALTERAR CONTA\n");
    printf("2 - ALTERAR CLIENTE\n");
    printf("3 - ALTERAR FUNCIONARIO\n");
    printf("4 - VOLTAR\n");
}


void arquivo_cp(){ 
    FILE *arquivoP;
    arquivoP = fopen("arquivo1.txt", "a");
    system("cls");
    if (arquivoP == NULL){
        printf("Erro na criacao do arquivo");

	} else{ 
		printf("Sucesso na criacao do arquivo");
        fclose(arquivoP);
    }
    system("cls");
}
void arquivo_cc(){ 
    FILE *arquivoC;
    arquivoC = fopen("arquivo2.txt", "a");
    system("cls");
    if (arquivoC == NULL){
        printf("Erro na criacao do arquivo");

	} else{ 
		printf("Sucesso na criacao do arquivo");
        fclose(arquivoC);
    }
    system("cls");
}
void arquivo_cf(){ 
    FILE *arquivoF;
    arquivoF = fopen("arquivo3.txt", "a");
    system("cls");
    if (arquivoF == NULL){
        printf("Erro na criacao do arquivo");

	} else{ 
		printf("Sucesso na criacao do arquivo");
        fclose(arquivoF);
    }
    system("cls");
}

void print_arqCP(cPoupanca contap) {
    FILE *arquivoP;
    arquivoP = fopen("arquivo1.txt", "a");
    if (arquivoP == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    contap.saldoPop = 0;
    fprintf(arquivoP, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%i;%s;%s;%s;%.2f;\n", //14
            contap.numeroConta, contap.agencia, contap.nomeCliente, contap.cpfCliente, //4
            contap.dataNascimento_dia, contap.dataNascimento_mes, contap.dataNascimento_ano,  //3
            contap.telefoneContato, contap.cep, contap.numeroCasa, //3
            contap.bairro, contap.cidade, contap.estado, contap.saldoPop); //4
        

    fclose(arquivoP);
    printf("\nDados salvos com sucesso.\n");
}
void print_arqCC(cCorrente contac) {
    FILE *arquivoC;
    arquivoC = fopen("arquivo2.txt", "a");
    if (arquivoC == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    contac.saldoCor = 0;
    fprintf(arquivoC, "%s;%s;%.2f;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%i;%s;%s;%s;%.2f;\n", //18
            contac.numeroConta, contac.agencia, contac.limiteConta, contac.dataVencimento_dia, //4
            contac.dataVencimento_mes, contac.dataVencimento_ano, //2
            contac.nomeCliente, contac.cpfCliente, contac.dataNascimento_dia, //3
            contac.dataNascimento_mes, contac.dataNascimento_ano, contac.telefoneContato, //3
            contac.cep, contac.numeroCasa, contac.bairro, //3
            contac.cidade, contac.estado, contac.saldoCor); //3
        
    
    fclose(arquivoC);
    printf("\nDados salvos com sucesso.\n");
}
void print_arqCF(cFuncionario contaf) {
    FILE *arquivoF;
    arquivoF = fopen("arquivo3.txt", "a");
    if (arquivoF == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    
    fprintf(arquivoF, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%i;%s;%s;%s;\n", //13
            contaf.codigoFuncionario, contaf.cargo, contaf.nomeFuncionario, contaf.cpfFuncionario, //4
            contaf.dataNascimento_dia, contaf.dataNascimento_mes, contaf.dataNascimento_ano, //3
            contaf.telefoneContato, contaf.cep, contaf.numeroCasa, //3
            contaf.bairro, contaf.cidade, contaf.estado); //3

    
    fclose(arquivoF);
    printf("\nDados salvos com sucesso.\n");
}

void obterDadosPou(cPoupanca *contap) {
    
    getchar();
    fflush(stdin);

    printf("Digite o numero da conta: ");
    fgets(contap->numeroConta, sizeof(contap->numeroConta), stdin);
    contap->numeroConta[strcspn(contap->numeroConta, "\n")] = 0;
    getchar();

    printf("Digite a agencia: ");
    fgets(contap->agencia, sizeof(contap->agencia), stdin);
    contap->agencia[strcspn(contap->agencia, "\n")] = 0;
    getchar();

    printf("Digite o nome do cliente: ");
    fgets(contap->nomeCliente, sizeof(contap->nomeCliente), stdin);
    contap->nomeCliente[strcspn(contap->nomeCliente, "\n")] = 0;
    getchar();

    printf("Digite o CPF do cliente: ");
    fgets(contap->cpfCliente, sizeof(contap->cpfCliente), stdin);
    contap->cpfCliente[strcspn(contap->cpfCliente, "\n")] = 0;
    getchar();

    printf("Digite o dia de nascimento: ");
    fgets(contap->dataNascimento_dia, sizeof(contap->dataNascimento_dia), stdin);
    contap->dataNascimento_dia[strcspn(contap->dataNascimento_dia, "\n")] = 0;
    getchar();

    printf("Digite o mes de nascimento: ");
    fgets(contap->dataNascimento_mes, sizeof(contap->dataNascimento_mes), stdin);
    contap->dataNascimento_mes[strcspn(contap->dataNascimento_mes, "\n")] = 0;
    getchar();

    printf("Digite o ano de nascimento: ");
    fgets(contap->dataNascimento_ano, sizeof(contap->dataNascimento_ano), stdin);
    contap->dataNascimento_ano[strcspn(contap->dataNascimento_ano, "\n")] = 0;
    getchar();

    printf("Digite o telefone de contato: ");
    fgets(contap->telefoneContato, sizeof(contap->telefoneContato), stdin);
    contap->telefoneContato[strcspn(contap->telefoneContato, "\n")] = 0;
    getchar();

    printf("\nLOCAL (ENDERECO): \n\n");

    printf("Digite o CEP: ");
    fgets(contap->cep, sizeof(contap->cep), stdin);
    contap->cep[strcspn(contap->cep, "\n")] = 0;
    getchar();

    printf("Digite o numero da casa: ");
    char numeroCasa[10];
    fgets(numeroCasa, sizeof(numeroCasa), stdin);
    contap->numeroCasa = atoi(numeroCasa);
    getchar();

    printf("Digite o bairro: ");
    fgets(contap->bairro, sizeof(contap->bairro), stdin);
    contap->bairro[strcspn(contap->bairro, "\n")] = 0;
    getchar();

    printf("Digite a cidade: ");
    fgets(contap->cidade, sizeof(contap->cidade), stdin);
    contap->cidade[strcspn(contap->cidade, "\n")] = 0;
    getchar();

    printf("Digite o estado: ");
    fgets(contap->estado, sizeof(contap->estado), stdin);
    contap->estado[strcspn(contap->estado, "\n")] = 0;
    getchar();

    printf("\nA senha do cliente: senha ");

}
void obterDadosCor(cCorrente *contac) {

    getchar();
    fflush(stdin);

    printf("Digite o numero da conta: ");
    fgets(contac->numeroConta, sizeof(contac->numeroConta), stdin);
    contac->numeroConta[strcspn(contac->numeroConta, "\n")] = 0;
    getchar();
    
    printf("Digite a agencia: ");
    fgets(contac->agencia, sizeof(contac->agencia), stdin);
    contac->agencia[strcspn(contac->agencia, "\n")] = 0;
    getchar();

    printf("Digite o limite da conta: ");
    char limiteConta[20];
    fgets(limiteConta, sizeof(limiteConta), stdin);
    contac->limiteConta = atof(limiteConta);
    getchar();

    printf("Digite o dia de vencimento: ");
    fgets(contac->dataVencimento_dia, sizeof(contac->dataVencimento_dia), stdin);
    contac->dataVencimento_dia[strcspn(contac->dataVencimento_dia, "\n")] = 0;
    getchar();

    printf("Digite o mes de vencimento: ");
    fgets(contac->dataVencimento_mes, sizeof(contac->dataVencimento_mes), stdin);
    contac->dataVencimento_mes[strcspn(contac->dataVencimento_mes, "\n")] = 0;
    getchar();

    printf("Digite o ano de vencimento: ");
    fgets(contac->dataVencimento_ano, sizeof(contac->dataVencimento_ano), stdin);
    contac->dataVencimento_ano[strcspn(contac->dataVencimento_ano, "\n")] = 0;
    getchar();

    printf("Digite o nome do cliente: ");
    fgets(contac->nomeCliente, sizeof(contac->nomeCliente), stdin);
    contac->nomeCliente[strcspn(contac->nomeCliente, "\n")] = 0;
    getchar();

    printf("Digite o CPF do cliente: ");
    fgets(contac->cpfCliente, sizeof(contac->cpfCliente), stdin);
    contac->cpfCliente[strcspn(contac->cpfCliente, "\n")] = 0;
    getchar();

    printf("Digite o dia de nascimento: ");
    fgets(contac->dataNascimento_dia, sizeof(contac->dataNascimento_dia), stdin);
    contac->dataNascimento_dia[strcspn(contac->dataNascimento_dia, "\n")] = 0;
    getchar();

    printf("Digite o mes de nascimento: ");
    fgets(contac->dataNascimento_mes, sizeof(contac->dataNascimento_mes), stdin);
    contac->dataNascimento_mes[strcspn(contac->dataNascimento_mes, "\n")] = 0;
    getchar();

    printf("Digite o ano de nascimento: ");
    fgets(contac->dataNascimento_ano, sizeof(contac->dataNascimento_ano), stdin);
    contac->dataNascimento_ano[strcspn(contac->dataNascimento_ano, "\n")] = 0;
    getchar();

    printf("Digite o telefone de contato: ");
    fgets(contac->telefoneContato, sizeof(contac->telefoneContato), stdin);
    contac->telefoneContato[strcspn(contac->telefoneContato, "\n")] = 0;
    getchar();

    printf("\nLOCAL (ENDERECO): \n\n");

    printf("Digite o CEP: ");
    fgets(contac->cep, sizeof(contac->cep), stdin);
    contac->cep[strcspn(contac->cep, "\n")] = 0;
    getchar();

    printf("Digite o numero da casa: ");
    char numeroCasa[10];
    fgets(numeroCasa, sizeof(numeroCasa), stdin);
    contac->numeroCasa = atoi(numeroCasa);
    getchar();

    printf("Digite o bairro: ");
    fgets(contac->bairro, sizeof(contac->bairro), stdin);
    contac->bairro[strcspn(contac->bairro, "\n")] = 0;
    getchar();

    printf("Digite a cidade: ");
    fgets(contac->cidade, sizeof(contac->cidade), stdin);
    contac->cidade[strcspn(contac->cidade, "\n")] = 0;
    getchar();

    printf("Digite o estado: ");
    fgets(contac->estado, sizeof(contac->estado), stdin);
    contac->estado[strcspn(contac->estado, "\n")] = 0;
    getchar();

    printf("\nA senha do cliente: senha ");

}
void obterDadosFun(cFuncionario *contaf) {
    
    getchar();
    fflush(stdin);

    printf("Digite o Codigo do Funcionario: ");
    fgets(contaf->codigoFuncionario, sizeof(contaf->codigoFuncionario), stdin);
    contaf->codigoFuncionario[strcspn(contaf->codigoFuncionario, "\n")] = 0;
    getchar();

    printf("Digite o Cargo: ");
    fgets(contaf->cargo, sizeof(contaf->cargo), stdin);
    contaf->cargo[strcspn(contaf->cargo, "\n")] = 0;
    getchar();
    
    printf("Digite o Nome do Funcionario: ");
    fgets(contaf->nomeFuncionario, sizeof(contaf->nomeFuncionario), stdin);
    contaf->nomeFuncionario[strcspn(contaf->nomeFuncionario, "\n")] = 0;
    getchar();
    
    printf("Digite o CPF do Funcionario: ");
    fgets(contaf->cpfFuncionario, sizeof(contaf->cpfFuncionario), stdin);
    contaf->cpfFuncionario[strcspn(contaf->cpfFuncionario, "\n")] = 0;
    getchar();
    
    printf("Digite o dia de nascimento: ");
    fgets(contaf->dataNascimento_dia, sizeof(contaf->dataNascimento_dia), stdin);
    contaf->dataNascimento_dia[strcspn(contaf->dataNascimento_dia, "\n")] = 0;
    getchar();

    printf("Digite o mes de nascimento: ");
    fgets(contaf->dataNascimento_mes, sizeof(contaf->dataNascimento_mes), stdin);
    contaf->dataNascimento_mes[strcspn(contaf->dataNascimento_mes, "\n")] = 0;
    getchar();

    printf("Digite o ano de nascimento: ");
    fgets(contaf->dataNascimento_ano, sizeof(contaf->dataNascimento_ano), stdin);
    contaf->dataNascimento_ano[strcspn(contaf->dataNascimento_ano, "\n")] = 0;
    getchar();

    printf("Digite o Telefone de Contato: ");
    fgets(contaf->telefoneContato, sizeof(contaf->telefoneContato), stdin);
    contaf->telefoneContato[strcspn(contaf->telefoneContato, "\n")] = 0;
    getchar();
    
    printf("\nLOCAL (ENDERECO): \n\n");
    
    printf("Digite o CEP: ");
    fgets(contaf->cep, sizeof(contaf->cep), stdin);
    contaf->cep[strcspn(contaf->cep, "\n")] = 0;
    getchar();
    
    printf("Digite o Numero da Casa: ");
    char numeroCasa[10];
    fgets(numeroCasa, sizeof(numeroCasa), stdin);
    contaf->numeroCasa = atoi(numeroCasa);
    getchar();
    
    printf("Digite o Bairro: ");
    fgets(contaf->bairro, sizeof(contaf->bairro), stdin);
    contaf->bairro[strcspn(contaf->bairro, "\n")] = 0;
    getchar();
    
    printf("Digite a Cidade: ");
    fgets(contaf->cidade, sizeof(contaf->cidade), stdin);
    contaf->cidade[strcspn(contaf->cidade, "\n")] = 0;
    getchar();
    
    printf("Digite o Estado: ");
    fgets(contaf->estado, sizeof(contaf->estado), stdin);
    contaf->estado[strcspn(contaf->estado, "\n")] = 0;
    getchar();
    
    printf("\nA Senha do Funcionario: senha1 ");

}