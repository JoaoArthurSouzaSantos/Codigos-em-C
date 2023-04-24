#include <stdio.h>
#include <stdlib.h>

typedef struct aluno TAluno;
struct aluno {
  char nome[30];
  int id;
  float media;
};

typedef struct materia TMateria;
struct materia {
  char nome[30];
  int id_m;
  int creditos;
};

typedef struct materia_aluno TRelacionamento;
struct materia_aluno {
  int id_al;
  int id_mat;
  int valor;
};

void ler_aluno(TAluno *al);
void imprimir_aluno(TAluno *al);
void alterar_aluno(TAluno *al);
void gravar_aluno(TAluno *al);
TAluno *encontrar_aluno(int id);
void listar_alunos();
void gravar_media(TAluno *al);

void ler_materia(TMateria *ma);
void imprimir_materia(TMateria *ma);
void alterar_materia(TMateria *ma);
void gravar_materia(TMateria *ma);
TMateria *encontrar_materia(int id_m);
void listar_materias();
void gravar_creditos(TMateria *ma);

void ler_Relacionamento(TRelacionamento *m_al);
void imprimir_Relacionamento(TRelacionamento *m_al);
void alterar_Relacionamento(TRelacionamento *m_al);
void gravar_Relacionamento(TRelacionamento *m_al);
TRelacionamento *encontrar_Relacionamento(int id);
void listar_Relacionamentos();
void gravar_Relacionamento(TRelacionamento *m_al);

int main() {
  int opcao, mat;
  TAluno *a;
  TMateria *b;
  TRelacionamento *c;

  do {
    printf("1 - Cadastrar aluno.\n");
    printf("2 - Listar alunos.\n");
    printf("3 - Exibir aluno.\n");
    printf("4 - Alterar media.\n");
    printf("5 - Cadastrar materia.\n");
    printf("6 - Listar materias.\n");
    printf("7 - Exibir materia.\n");
    printf("8 - Alterar media.\n");
    printf("9 - Cadastrar relação.\n");
    printf("10 - Listar relação.\n");
    printf("11- Exibir relação.\n");
    printf("12- Alterar valor.\n");
    printf("0 - Sair.\n");
    printf("Opcao: \n");
    scanf("%i", &opcao);
    switch (opcao) {
    case 1:
      a = (TAluno *)malloc(sizeof(TAluno));
      ler_aluno(a);
      gravar_aluno(a);
      free(a);
      break;
    case 2:
      listar_alunos();
      break;
    case 3:
      printf("Digite id: ");
      scanf("%i", &mat);
      a = encontrar_aluno(mat);
      if (a != NULL) {
        imprimir_aluno(a);
      } else {
        printf("\nAluno nao encontrado!!!!\n\n");
      }
      break;
    case 4:
      printf("Digite id: ");
      scanf("%i", &mat);
      a = encontrar_aluno(mat);
      if (a != NULL) {
        alterar_aluno(a);
        gravar_media(a);
        free(a);
      } else {
        printf("\nAluno nao encontrado!!!!\n\n");
      }
      break;
    case 5:
      b = (TMateria *)malloc(sizeof(TMateria));
      ler_materia(b);
      gravar_materia(b);
      free(b);
      break;
    case 6:
      listar_materias();
      break;
    case 7:
      printf("Digite id: ");
      scanf("%i", &mat);
      b = encontrar_materia(mat);
      if (b != NULL) {
        imprimir_materia(b);
      } else {
        printf("\nMateria nao encontrado!!!!\n\n");
      }
      break;
    case 8:
      printf("Digite id: ");
      scanf("%i", &mat);
      b = encontrar_materia(mat);
      if (b != NULL) {
        alterar_materia(b);
        gravar_media(b);
        free(b);
      } else {
        printf("\nMateria nao encontrado!!!!\n\n");
      }
      break;
      case 9:
      c = (TRelacionamento *)malloc(sizeof(TRelacionamento));
      ler_Relacionamento(c);
      gravar_Relacionamento(c);
      free(c);
      break;
    case 10:
      listar_Relacionamentos();
      break;
    case 11:
      printf("Digite id: ");
      scanf("%i", &mat);
      c = encontrar_Relacionamento(mat);
      if (c != NULL) {
        imprimir_Relacionamento(c);
      } else {
        printf("\nMateria nao encontrado!!!!\n\n");
      }
      break;
    case 12:
      printf("Digite id: ");
      scanf("%i", &mat);
      c = encontrar_Relacionamento(mat);
      if (c != NULL) {
        alterar_Relacionamento(c);
        gravar_Relacionamento(c);
        free(c);
      } else {
        printf("\nMateria nao encontrado!!!!\n\n");
      }
      break;
    defalt:
    printf("Error");
    }

  } while (opcao > 0 && opcao <= 12);

  return 0;
}

void ler_aluno(TAluno *al) {
  printf("Nome: ");
  scanf("%s", al->nome);
  printf("Matricula: ");
  scanf("%i", &al->id);
}

void imprimir_aluno(TAluno *al) {
  printf("Nome: %s\n", al->nome);
  printf("Matricula: %i\n", al->id);
  printf("\n\n\n");
}

void alterar_aluno(TAluno *al) {
  printf("Digite nova media: ");
  scanf("%d", &al->media);
}

void gravar_aluno(TAluno *al) {
  FILE *p;
  if ((p = fopen("aluno.bin", "a+b")) == NULL) {
    printf("Arquivo nao pode ser aberto\n");
  } else {
    fwrite(al, sizeof(TAluno), 1, p);
    fclose(p);
  }
}

TAluno *encontrar_aluno(int id) {
  FILE *p;
  TAluno *a = malloc(sizeof(TAluno));

  if ((p = fopen("aluno.bin", "rb")) == NULL) {
    printf("Arquivo nao pode ser aberto\n");
  } else {
    while (fread(a, sizeof(TAluno), 1, p) != 0) {
      if (a->id == id) {
        return a;
      }
    }
    fclose(p);
    free(a);
    return NULL;
  }
}

void listar_alunos() {
  FILE *p;
  TAluno *a = (TAluno *)malloc(sizeof(TAluno));

  if ((p = fopen("aluno.bin", "rb")) == NULL) {
    printf("Arquivo nao pode ser aberto\n");
  } else {
    while (fread(a, sizeof(TAluno), 1, p) != 0) {
      imprimir_aluno(a);
    }
    fclose(p);
    free(a);
  }
}

void gravar_media(TAluno *al) {
  FILE *p;
  TAluno *a = (TAluno *)malloc(sizeof(TAluno));

  if ((p = fopen("aluno.bin", "r+b")) == NULL) {
    printf("Arquivo nao pode ser aberto\n");
  } else {
    while (fread(a, sizeof(TAluno), 1, p) != 0) {
      if (a->id == al->id) {
        fseek(p, sizeof(TAluno) * -1, SEEK_CUR);
        fwrite(al, sizeof(TAluno), 1, p);
        break;
      }
    }
    fclose(p);
    free(a);
  }
}

void ler_materia(TMateria *ma) {
  printf("Nome: ");
  scanf("%s", ma->nome);
  printf("Matricula: ");
  scanf("%i", &ma->id_m);
  printf("Media: ");
  scanf("%d", &ma->creditos);
}

void imprimir_materia(TMateria *ma) {
  printf("Nome: %s\n", ma->nome);
  printf("Id: %i\n", ma->id_m);
  printf("Creditos: %d\n\n", ma->creditos);
  printf("\n\n\n");
}

void alterar_materia(TMateria *ma) {
  printf("Digite nova creditos: ");
  scanf("%d", &ma->creditos);
}

void gravar_materia(TMateria *ma) {
  FILE *p;
  if ((p = fopen("materia.bin", "a+b")) == NULL) {
    printf("Arquivo nao pode ser aberto\n");
  } else {
    fwrite(ma, sizeof(TMateria), 1, p);
    fclose(p);
  }
}

TMateria *encontrar_materia(int id_m) {
  FILE *p;
  TMateria *a = malloc(sizeof(TMateria));

  if ((p = fopen("materia.bin", "rb")) == NULL) {
    printf("Arquivo nao pode ser aberto\n");
  } else {
    while (fread(a, sizeof(TMateria), 1, p) != 0) {
      if (a->id_m == id_m) {
        return a;
      }
    }
    fclose(p);
    free(a);
    return NULL;
  }
}

void listar_materias() {
  FILE *p;
  TMateria *a = (TMateria *)malloc(sizeof(TMateria));

  if ((p = fopen("materia.bin", "rb")) == NULL) {
    printf("Arquivo nao pode ser aberto\n");
  } else {
    while (fread(a, sizeof(TMateria), 1, p) != 0) {
      imprimir_materia(a);
    }
    fclose(p);
    free(a);
  }
}

void gravar_creditos(TMateria *ma) {
  FILE *p;
  TMateria *a = (TMateria *)malloc(sizeof(TMateria));

  if ((p = fopen("materia.bin", "r+b")) == NULL) {
    printf("Arquivo nao pode ser aberto\n");
  } else {
    while (fread(a, sizeof(TMateria), 1, p) != 0) {
      if (a->id_m == ma->id_m) {
        fseek(p, sizeof(TMateria) * -1, SEEK_CUR);
        fwrite(ma, sizeof(TMateria), 1, p);
        break;
      }
    }
    fclose(p);
    free(a);
  }
}

void ler_Relacionamento(TRelacionamento *m_al) {
  printf("id:aluno\n ");
  scanf("%d", &m_al->id_al);
  printf("id:materia ");
  scanf("%d", &m_al->id_mat);
  printf("Media: ");
  scanf("%d", &m_al->valor);
}

void imprimir_Relacionamento(TRelacionamento *m_al) {
  printf("Id_aluno: %d\n", m_al->id_al);
  printf("Id_materia: %d\n", m_al->id_mat);
  printf("Creditos: %d\n\n", m_al->valor);
  printf("\n\n\n");
}

void alterar_Relacionamento(TRelacionamento *m_al) {
  printf("Digite nova valor: ");
  scanf("%d", &m_al->valor);
}

void gravar_Relacionamento(TRelacionamento *m_al) {
  FILE *p;
  if ((p = fopen("Relacionamento.bin", "a+b")) == NULL) {
    printf("Arquivo nao pode ser aberto\n");
  } else {
    fwrite(m_al, sizeof(TRelacionamento), 1, p);
    fclose(p);
  }
}

TRelacionamento *encontrar_Relacionamento(int id_mat) {
  FILE *p;
  TRelacionamento *c = malloc(sizeof(TRelacionamento));

  if ((p = fopen("Relacionamento.bin", "rb")) == NULL) {
    printf("Arquivo nao pode ser aberto\n");
  } else {
    while (fread(c, sizeof(TRelacionamento), 1, p) != 0) {
      if (c->id_mat == id_mat) {
        return c;
      }
    }
    fclose(p);
    free(c);
    return NULL;
  }
}

void listar_Relacionamentos() {
  FILE *p;
  TRelacionamento *c = (TRelacionamento *)malloc(sizeof(TRelacionamento));

  if ((p = fopen("Relacionamento.bin", "rb")) == NULL) {
    printf("Arquivo nao pode ser aberto\n");
  } else {
    while (fread(c, sizeof(TRelacionamento), 1, p) != 0) {
      imprimir_Relacionamento(c);
    }
    fclose(p);
    free(c);
  }
}

void gravar_Relacionamentos(TRelacionamento *m_al) {
  FILE *p;
  TRelacionamento *c = (TRelacionamento *)malloc(sizeof(TRelacionamento));

  if ((p = fopen("Relacionamento.bin", "r+b")) == NULL) {
    printf("Arquivo nao pode ser aberto\n");
  } else {
    while (fread(c, sizeof(TRelacionamento), 1, p) != 0) {
      if (c->id_mat == m_al->id_mat) {
        fseek(p, sizeof(TRelacionamento) * -1, SEEK_CUR);
        fwrite(m_al, sizeof(TRelacionamento), 1, p);
        break;
      }
    }
    fclose(p);
    free(c);
  }
}

