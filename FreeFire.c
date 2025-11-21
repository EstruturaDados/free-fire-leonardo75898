#include <stdio.h>
#include <string.h>

#define TAM 10

// Struct para representar um item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Função para limpar '\n' do fgets
void limparEnter(char *str) {
    size_t len = strlen(str);
    if(len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Função para adicionar item
void adicionarItem(Item mochila[], int *total) {
    if (*total >= TAM) {
        printf("⚠️ Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    printf("\n🔹 Adicionando novo item:\n");
    printf("Nome: ");
    fgets(mochila[*total].nome, 30, stdin);
    limparEnter(mochila[*total].nome);

    printf("Tipo: ");
    fgets(mochila[*total].tipo, 20, stdin);
    limparEnter(mochila[*total].tipo);

    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);
    getchar(); // Limpa o '\n' do buffer

    (*total)++;
    printf("✅ Item adicionado com sucesso!\n");
}

// Função para remover item pelo nome
void removerItem(Item mochila[], int *total) {
    char nome[30];
    int encontrado = 0;

    printf("\n🗑️ Nome do item a remover: ");
    fgets(nome, 30, stdin);
    limparEnter(nome);

    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            for (int j = i; j < *total - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*total)--;
            encontrado = 1;
            printf("✅ Item removido com sucesso.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("❌ Item não encontrado na mochila.\n");
    }
}

// Função para listar todos os itens
void listarItens(Item mochila[], int total) {
    printf("\n🎒 Itens na Mochila (%d):\n", total);
    printf("-------------------------------\n");

    if (total == 0) {
        printf("📭 Mochila vazia!\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("-------------------------------\n");
}

int main() {
    Item mochila[TAM];
    int total = 0;
    int opcao;

    do {
        printf("\n=== MENU - MOCHILA DE SOBREVIVÊNCIA ===\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch (opcao) {
            case 1:
                adicionarItem(mochila, &total);
                break;
            case 2:
                removerItem(mochila, &total);
                break;
            case 3:
                listarItens(mochila, total);
                break;
            case 0:
                printf("🏁 Saindo da mochila. Boa sorte na ilha!\n");
                break;
            default:
                printf("❌ Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
