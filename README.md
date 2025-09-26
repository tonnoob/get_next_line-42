![Foto do projeto](img/get_next_line.png)

# Get_next_line-42  

📌 **get_next_line**  
O **get_next_line** é um projeto da 42 que tem como objetivo criar uma função que retorna, linha por linha, de um arquivo de texto (File descriptor - fd).
Permitindo a leitura do arquivo somente por blocos até a quebra de linha (\n) ou até o fim do arquivo (quando todos os caracteres já foram lidos).
A função deve retornar a linha completa, incluindo o \n quando existir.

---
### 🎯 Objetivo  
- Escrever uma função que retorna uma linha lida de um file descriptor, respeitando algunas regras. 
- Desenvolver melhor compreensão sobre manipulação de strings, macros (`BUFFER_SIZE`), organização de código, corrigir vazamentos de memórias e formatação de saída.  
- Melhor entendimento da função `read`.
---

### 🚀 Como compilar

O projeto vem dividido em arquivos (se for o bônus vai ter `_bonus` no nome):

`get_next_line.c`

`get_next_line_utils.c`

`get_next_line.h`

---

### 🛠️ Crie sua Main.c

📌 Aqui, o `main.c` é um arquivo de teste que você mesmo cria para chamar a função get_next_line. (Dentro da pasta project)
```
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd = open("teste.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}

```
Crie qualquer arquivo `.txt` dentro da pasta aonde está o projeto, com qualquer conteudo (não esqueça de dar enter para quebrar a linha).

E coloque o nome do seu arquivo entre aspas nessa linha na `main.c`.

```int fd = open("teste.txt", O_RDONLY);```

Para compilar, no terminal use o gcc com o `BUFFER_SIZE` definido. Exemplo:

```gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl```

Depois de compilado rode:

```./gnl```

Testar vazamento de memória:

```valgrind --leak-check=full --show-leak-kinds=all ./gnl```

E se tudo estiver correto vai mostrar essa informação:

```All heap blocks were freed -- no leaks are possible```

---

### ✅ Checklist de correção

- Compila sem erros `-Wall -Wextra -Werror`

- Funciona com diferentes tamanhos de `BUFFER_SIZE`

- Lê arquivos de diferentes tamanhos

- Funciona em múltiplos FDs abertos ao mesmo tempo

- Não apresenta leaks de memória

---

### 🎁 Bônus

Agora a `get_next_line()` precisa controlar separadamente o progresso de leitura de cada file descriptor.
Ou seja, se você alternar entre fd3, fd4 e fd5, ela deve lembrar onde parou em cada arquivo, sem misturar linhas nem perder dados.

Dentro da pasta `project_with_bonus` tem o bônus do projeto, então agora faça uma `main.c` assim:
```
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    char *line1;
    char *line2;

    if (fd1 < 0 || fd2 < 0)
        return (1);

    while (1)
    {
        line1 = get_next_line(fd1);
        line2 = get_next_line(fd2);

        if (!line1 && !line2)
            break;
        if (line1)
        {
            printf("file1: %s", line1);
            free(line1);
        }
        if (line2)
        {
            printf("file2: %s", line2);
            free(line2);
        }
    }
    close(fd1);
    close(fd2);
    return (0);
}

```
(não esqueça que nas linhas que possui `open("file1.txt", O_RDONLY);`, colocar o nome do seu arquivo `.txt` que você quer exibir a linha)

Agora compile:

```gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus```

Executar normalmente:

```./gnl_bonus```

Checar vazamentos de memória: 

```valgrind --leak-check=full --show-leak-kinds=all ./gnl_bonus```

---

📅 **Período de desenvolvimento**  
- Início: 02/09/2025  
- Término: 24/09/2025  

---

![Foto projeto concluído](img/gnl_finish.png)

---
## English
Here goes the English version

![Foto do projeto](img/get_next_line.png)

(Reading a line from a dfile descriptor is very tedious.)

# Get_next_line-42  

📌 **get_next_line**
**get_next_line** is a 42 project that aims to create a function that returns a file line by line from a text file (File descriptor - fd).
The function reads the file in blocks until a newline character (\n) or the end of the file is reached (when all characters have been read).
The function should return the complete line, including the \n if it exists.

---
### 🎯 Objective  
- Write a function that returns a line read from a file descriptor, following some rules.
- Improve understanding of string manipulation, macros (`BUFFER_SIZE`), code organization, memory leak correction, and output formatting. 
- Gain a better understanding of the `read` function.

---
### 🚀 How to compile

The project is divided into files (if it's the bonus version, the files will have `_bonus` in the name):

`get_next_line.c`

`get_next_line_utils.c`

`get_next_line.h`

---

### 🛠️ Create your Main.c

📌 Here, `main.c` is a test file that you create to call the `get_next_line` function (inside the project folder):
```
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}

```
Create any `.txt` file inside the project folder, with any content (don’t forget to press enter at the end to create a newline).

And put the name of your file in quotes in this line in `main.c`:

```int fd = open("test.txt", O_RDONLY);```

To compile, use `gcc` in the terminal with the `BUFFER_SIZE` defined. Example:

```gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl```

After compilation, run:

```./gnl```

To check for memory leaks:

```valgrind --leak-check=full --show-leak-kinds=all ./gnl```

If everything is correct, it will show:

```All heap blocks were freed -- no leaks are possible```

---

### ✅ Checklist

- Compiles without errors (-Wall -Wextra -Werror)

- Works with different BUFFER_SIZE values

- Reads files of different sizes

- Works with multiple FDs opened at the same time

- No memory leaks

---

### 🎁 Bonus

Now `get_next_line()` must separately track the reading progress of each file descriptor.
That is, if you switch between fd3, fd4, and fd5, it must remember where it left off in each file, without mixing lines or losing data.

Inside the folder `project_with_bonus` is the bonus version of the project. Create a `main.c` like this:
```
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd1 = open("file1.txt", O_RDONLY);
    int fd2 = open("file2.txt", O_RDONLY);
    char *line1;
    char *line2;

    if (fd1 < 0 || fd2 < 0)
        return (1);

    while (1)
    {
        line1 = get_next_line(fd1);
        line2 = get_next_line(fd2);

        if (!line1 && !line2)
            break;
        if (line1)
        {
            printf("file1: %s", line1);
            free(line1);
        }
        if (line2)
        {
            printf("file2: %s", line2);
            free(line2);
        }
    }
    close(fd1);
    close(fd2);
    return (0);
}

```
(Don’t forget to replace `"file1.txt"` and `"file2.txt"` with the `.txt` files you want to read line by line.)

Now compile:

```gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus```

Run normally:

```./gnl_bonus```

Check memory leaks:

```valgrind --leak-check=full --show-leak-kinds=all ./gnl_bonus```

---

📅 **Development period**  
- Start: 09/02/2025
- End: 09/24/2025

---

![Foto projeto concluído](img/gnl_finish.png)


