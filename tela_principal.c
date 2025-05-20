#include "cliente.c"

void tela_principal() {
    int opc;
    char senhaF[] = "funct";
    char senhaC[] = "senha";
    char senha_dig[20];
    
    while (1) {
        menu_tela();
        scanf("%d", &opc);
        
        printf("\n");
        
        switch (opc) {
            case 1:
            	printf("Digite a senha: ");
                scanf("%s", senha_dig);
                printf("\n");

                if (strcmp(senhaF, senha_dig) == 0) {
                	Sleep(2000);
                    system("cls"); 
					funcaoFuncionario();
                } else {
                    printf("**senha invalida**\n\n\n\n");
                    Sleep(2000);
                    system("cls"); 
                }
                break;
                
            case 2:
                printf("Digite a senha: ");
                scanf("%s", senha_dig);
                printf("\n");
                
                if (strcmp(senhaC, senha_dig) == 0) {
                	Sleep(2000);
                    system("cls"); 
                    funcaoCliente();
                } else {
                    printf("**senha invalida**\n\n\n\n");
                    Sleep(2000);
                    system("cls"); 
                }
                break;
                
            case 3:
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
}