#include <stdio.h>
#include <string.h>


struct Pet {
    char nome[50];
    char especie[30];
    int idade;
};


void cadastrarPet(struct Pet* pet) {
    printf("Digite o nome do pet: ");
    scanf("%s", pet->nome);
    printf("Digite a espécie do pet: ");
    scanf("%s", pet->especie);
    printf("Digite a idade do pet: ");
    scanf("%d", &pet->idade);  

}


void listarPet(struct Pet* pet) {
    printf("\n--- Informações do Pet ---\n");
    printf("Nome: %s\n", pet->nome);
    printf("Espécie: %s\n", pet->especie);
    printf("Idade: %d anos\n", pet->idade);
}


void editarPet(struct Pet* pet) {
    printf("Digite o novo nome do pet: ");
    scanf("%s", pet->nome);
    printf("Digite a nova espécie do pet: ");
    scanf("%s", pet->especie);
    printf("Digite a nova idade do pet: ");
    scanf("%d", &pet->idade);  
}


void exibirMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Cadastrar pet\n");
    printf("2. Listar pet\n");
    printf("3. Editar pet\n");
    printf("4. Sair\n");
}

int main() {
    struct Pet pets[5];  
    int opcao = 0;
    int indice = 0;

    while (opcao != 4) {
        exibirMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: 
                if (indice < 5) {
                    cadastrarPet(&pets[indice]);  
                    indice++;  
                } else {
                    printf("Limite de pets cadastrados atingido.\n");
                }
                break;
            
            case 2: 
                if (indice == 0) {
                    printf("Nenhum pet cadastrado.\n");
                } else {
                    for (int i = 0; i < indice; i++) {
                        listarPet(&pets[i]);
                    }
                }
                break;
            
            case 3:
                if (indice == 0) {
                    printf("Nenhum pet cadastrado.\n");
                } else {
                    printf("Digite o índice do pet a ser editado (0 a %d): ", indice - 1);
                    int i;
                    scanf("%d", &i);
                    if (i >= 0 && i < indice) {
                        editarPet(&pets[i]);
                    } else {
                        printf("Índice inválido.\n");
                    }
                }
                break;
            
            case 4:
                printf("Saindo do sistema...\n");
                break;
            
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}

