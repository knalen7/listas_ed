Para armazenar um número variável de strings lidas do teclado em C, é melhor declarar um vetor de ponteiros. Isso ocorre porque o número de strings pode variar, e usar um vetor de ponteiros permite uma flexibilidade maior na alocação de memória para cada string.

1. Matriz de caracteres (vetor bidimensional):
   - Se você sabe o número máximo de caracteres que suas strings terão, pode declarar uma matriz de caracteres (vetor bidimensional). Por exemplo, `char strings[MAX_STRINGS][MAX_LENGTH];`.
   - No entanto, isso limita o número total de strings que você pode armazenar à capacidade da matriz e desperdiça espaço de memória se nem todas as strings tiverem o comprimento máximo.

2. Vetor de ponteiros:
   - Usar um vetor de ponteiros permite uma alocação dinâmica de memória para cada string, adaptando-se ao tamanho real de cada uma.
   - Cada elemento do vetor pode apontar para uma string alocada dinamicamente.
   - Isso permite economia de espaço de memória, já que apenas o espaço necessário para armazenar cada string é alocado.
   - Além disso, permite uma manipulação mais flexível das strings, como a liberação de memória quando não forem mais necessárias.