/*
 * Primeiro laboratório de Computadores e Programação
 *
 * A ideia do laboratório é mostrar ao aluno outras formas de fazer as operações
 * que ele já está acostumado a fazer, mas de formas diferentes.
 * Criamos esse desafio com o objetivo de fazê-lo pensar em diferentes formas de se
 * atingir o mesmo resultado. Se possível, tentando pensar em qual seria mais
 * eficiente.
 *
 * O aluno deverá usar apenas um subset de operações de C para realizar o que
 * for pedido no enunciado.
 *
 * Todas as operações permitidas serão especificadas em cada questão.
 *
 * Forma de avaliação:
 *      - Quantas operações o aluno utlizou para realizar a tarefa (dentro da quantidade aceitável)
 *      - Explicação do código -- deverá ser o mais claro possível (como qualquer
 *          código), imaginando que qualquer pessoa sem conhecimento prévio da
 *          matéria consiga entender o que foi feito.
 *      - As resoluções com menos operações do que a do monitor terão bonificação.
 *
 * Assinatura:
 *      Aluno: Carolina Naccarato
 *      DRE: 117220395
 *
 *      Aluno: Milton Quillinan
 *      DRE: 118144649
 *
 *      versão do GCC utilizada: gcc (GCC) 11.1.0
 *
 */

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <stdio.h>
#include <stdint.h>


/* Número é par ou não
 *      Permitido:
 *          Operações: ~ & ^ | << >>
 *
 *      Número máximo de operações: 3
 *      Monitor: 2
 *
 *      Retorna 1 se x é par, retorna 0 caso contrário
 *
 *      Exemplo:
 *          ehPar(0) -> 1
 *          ehPar(2) -> 1
 *          ehPar(7) -> 0
 */
int32_t ehPar(int32_t x) {
/*
 * Para esta funcao usamos dois operadores: "&" e "~"
 *
 * Primeiramente utilizamos o operador "&" (bitwise AND) pois 
 * ele compara dois valores usando suas representacoes binarias,
 * retornando um novo valor: cada bit eh comparado, de forma a 
 * retornar 1 quando ambos os bits forem iguais a 1; caso contrario,
 * 0. Comparar x com a representacao binaria de 1 eh util pois estamos
 * testando o bit menos significativo. Essa operacao ira retornar 1 
 * se x for impar; 0, se for par. 

 * Como gostariamos que a funcao retorne 1 caso x for par, precisamos
 * inverter os valores. Para fazer isso, utilizamos o operador "~"
 * (bitwise NOT) pois o mesmo tem como funcao inverter cada um dos
 * bits de um determinado valor em sua representacao binaria. Apesar
 * desse operador inverter o sinal da variavel x, ele serve para o
 * nosso proposito, que eh inverter o bit menos significativo de forma
 * que, quando fazemos (~x & 1), a funcao retorne 1 caso x for par;
 * 0, caso for impar.
 */
    return (~x & 1);
}

/*
 * Módulo 8
 *      Permitido:
 *          Operações: ~ & ^ | ! << >>
 *
 *      Número máximo de operações: 3
 *      Monitor: 1
 *
 *      Retorna x % 8
 *
 *      Exemplo:
 *          mod8(1) -> 1
 *          mod8(7) -> 7
 *          mod8(10) -> 2
 */
int32_t mod8(int32_t x) {
/*
 * Para esta funcao usamos um operador: "&"
 * 
 * Na aritmetica modular, representamos os numeros como polinomios,
 * de forma que cada digito eh um dos coeficientes do polinomio.
 * Portanto, na arquitetura de 32 bits, se x for positivo, ele pode 
 * ser representado na forma: 2^31 * x_31 + ... 2^2 * x_2 + 2^1 + x_1 + 2^0 + x_0,
 * onde x_31...x_0 sao os bits do numero.
 * 
 * Como desejamos encontrar x modulo 8, temos que dividir x por 8 e printar o resto
 * dessa divisao. Ou seja, escrever x = 8 * quociente + resto. Tendo em mente que 8 = 2^3,
 * podemos colocar o mesmo em evidencia: 
 * x = 8 * (2^28 * x_31 + ... + 2^0 * x_3) + 2^2 * x_2 + 2^1 * x_1 + 2^0 + x_0
 * de forma que o resto da divisao por 8 considera apenas os ultimos 3 bits do numero.
 * Portanto, podemos aplicar uma mascara 0b0...0111 que ira zerar todos os primeiros bits
 * do numero, exceto os ultimos 3, que eh exatamente o resto que queremos da operacao x mod 8.
 * 
 * Se x for um numero negativo, representando-o em complemento a dois, podemos escreve-lo como
 * x = -2^31 * x_31 + ... 2^2 * x_2 + 2^1 * x_1 + 2^0 * x_0
 * e, de maneira analoga, tambem conseguimos obter x mod 8 ao aplicar essa mascara.
 */
    return (x & 0x7);
}

/* Negativo sem -
 *      Permitido:
 *          Operações: ~ & ^ | ! << >> +
 *
 *      Número máximo de operações: 5
 *      Monitor: 2
 *
 *      Retorna -x
 *
 *      Exemplo:
 *          negativo(1) -> -1
 *          negativo(42) -> -42
 */
int32_t negativo(int32_t x) {
/*
 * Para esta funcao usamos um operador: "~"
 * 
 * Sabemos que uma das formas de representar numeros negativos utilizando
 * numeros binarios eh atraves do complemento a dois. Para obter a representacao
 * negativa de um numero temos que inverter todos os bits desse numero e somar 1.
 * 
 * Portanto, conseguimos facilmente aplicar esse algoritmo com o auxilio do operador
 * "~" (NOT), que percorre o numero bit a bit, invertendo-os. Apos isso, basta
 * somarmos 1 a negacao de x para obtermos o negativo dessa variavel.
 */
    return ~x + 1;
}

/* Implementação do & usando bitwise
 *      Permitido:
 *          Operações: ~ ^ | ! << >>
 *
 *      Número máximo de operações: 7
 *      Monitor: 4
 *
 *      Retorna x & y
 *
 *      Exemplo:
 *          bitwiseAnd(1, 2) -> 0
 *              01 & 10 -> 00
 *          bitwiseAnd(3, 11) -> 3
 *              11 & 1011 -> 0011
 */
int32_t bitwiseAnd(int32_t x, int32_t y) {
/*
 * Para esta funcao usamos dois operadores: "~" e "|"
 * 
 * Sabemos que existe uma relacao entre os operadores "&" e "|" a partir do Teorema
 * de De Morgan. Uma de suas leis diz que: ~(A & B) = ~A | ~B. No entanto, o resultado
 * que queremos eh (A & B). Portanto, temos que negar ambos os lados da equacao a fim
 * de obter o resultado desejado:
 * ~(~(A & B)) = ~(~A | ~B)
 * ~(~(A & B)) = ~(~A | ~B) = A & B
 * 
 * Substituindo por x e y, para implementar o operador AND bitwise (x & y), temos que 
 * a expressao desejada eh ~(~x | ~y)
 */
    return ~(~x | ~y);
}

/* Igual sem ==
 *      Permitido:
 *          Operações: ~ & ^ | << >> !
 *
 *      Número máximo de operações: 3
 *      Monitor: 2
 *
 *      Retorna 1 se x == y, 0 caso contrário
 *
 *      Exemplo:
 *          ehIgual(10, 10) -> 1
 *          ehIgual(16, 8) -> 0
 */
int32_t ehIgual(int32_t x, int32_t y) {
/*
 * Para esta funcao usamos dois operadores: "^" e "!"
 * 
 * O operador "^" (XOR) compara dois valores utilizando suas representacoes binarias,
 * retornando um novo valor. Para formar esse valor de retorno, cada bit eh comparado,
 * retornando 1 quando os bits forem diferentes; 0, caso contrario. Portanto, quando
 * os numeros forem identicos, o resultado sera 0. Quando eles forem diferentes, o resultado
 * da operacao bit a bit sera qualquer coisa diferente de 0.
 * 
 * Dessa forma, ao fazer !(x ^ y), quando os numeros forem identicos, transformaremos o 0 em 1.
 * Caso contrario, o que for diferente de 0 sera transformado em 0, que eh exatamente o que 
 * queremos.
 */
    return !(x ^ y);
}

/* Limpa bit n
 *      Permitido:
 *          Operações: ~ & ^ | ! << >>
 *
 *      Número máximo de operações: 4
 *      Monitor: 3
 *
 *      Retorna o x com o bit n = 0,
 *      n pode variar entre 0 e 31, do LSB ao MSB
 *
 *      Exemplo:
 *          limpaBitN(3, 0) -> 2
 *          limpaBitN(3, 1) -> 1
 */
int32_t limpaBitN(int32_t x, int8_t n) {
/*
 * Para esta funcao usamos tres operadores: "&", "~" e "<<"
 * 
 * O operador "<<" (bitwise left shift) desliza os bits para a esquerda,
 * de forma que quando fazemos $a << 3, estamos multiplicando $a por 2
 * tres vezes. Por exemplo, se fizermos: (1 << 3)
 * Entrada: 00000001 = 1
 * Saida:   00001000 = 8

 * Portanto, se fizermos (1 << n), estamos deslocando o numero 00000001
 * n casas decimais para a esquerda. No entanto, para limpar o bit n de x,
 * precisamos de um numero que possua fatores em comum em todas as casas exceto
 * na casa n. Assim, precisamos exatamente do inverso, fazendo ~(1 << n)
 * 
 * Uma vez que geramos esse numero, basta aplicarmos a operacao "&" (AND), pois
 * a mesma retorna 1 somente quando os bits forem iguais. Como, obrigatoriamente,
 * a casa n esta zerada, isso implica que o bit n retornara limpo, enquanto os 
 * demais bits do numero x nao sao alterados.
 * 
 */
    return x & ~(1 << n);
}

/*
 * Bit na posição p do inteiro x
 *      Permitido:
 *          Operações bitwise: << >> | & + -
 *
 *      Número máximo de operações: 6
 *      Monitor: 2
 *
 *      Retorna o valor do bit na posição p no inteiro x
 *      Valor de retorno pode ser apenas 0 ou 1
 *
 *      p será um valor entre 0 e 31
 *
 *      Exemplo:
 *          23 em binário: 0   0 ... 0 1 0 1 1 1
 *               posições: 31 30 ... 5 4 3 2 1 0
 *
 *          bitEmP(23, 31) -> 0
 *          bitEmP(23, 5) -> 0
 *          bitEmP(23, 4) -> 1
 *          bitEmP(23, 3) -> 0
 *          bitEmP(23, 2) -> 1
 *          bitEmP(23, 1) -> 1
 *          bitEmP(23, 0) -> 1
 *
 */
int32_t bitEmP(int32_t x, uint8_t p) {
/*
 * Para esta funcao usamos dois operadores: ">>" e "&"
 * 
 * Para executar essa operacao, usaremos o operador ">>" (right shift),
 * que funciona de forma analoga ao left shift, mas, dessa vez, deslocando
 * o numero para a direita. Por exemplo, se fizermos (45 >> 3), temos
 * Entrada: 00101101
 * Saida:   00000101
 * 
 * Portanto, quando fazemos (x >> p), estamos deslocando o bit que ocupa
 * a casa p p casas para a direita, de forma que esse numero passa a ocupar
 * a posicao 0, se tornando o bit menos significativo.
 *
 * Isto feito, aplicaremos uma mascara para ignorar todos os bits que nao
 * o LSB
 */
    return (x >> p) & 0x1;
}

/*
 * Byte na posição p do inteiro x
 *      Permitido:
 *          Operações: << >> | ! &
 *
 *      Número máximo de operações: 6
 *      Monitor: 3
 *
 *      Retorna o valor do bit na posição p no inteiro x
 *      Valor de retorno pode ser entre 0 e 0xFF
 *
 *      p será um valor entre 0 e 3
 *      0 retorna LSB
 *      3 retorna MSB
 *
 *      Exemplo:
 *          byteEmP(0x12345678, 0) -> 0x78
 *          byteEmP(0x12345678, 1) -> 0x56
 *          byteEmP(0x12345678, 2) -> 0x34
 *          byteEmP(0x12345678, 3) -> 0x12
 *
 */
int32_t byteEmP(int32_t x, uint8_t p) {
    return x >> (p << 3) & 0xFF;
}

/*
 * Seta byte na posição p do inteiro x como y
 *      Permitido:
 *          Operações: << >> | ~ ! &
 *
 *      Número máximo de operações: 7
 *      Monitor: 5
 *
 *      Retorna x com o valor y no byte da posição p
 *
 *      p será um valor entre 0 e 3
 *      0 retorna LSB
 *      3 retorna MSB
 *
 *      Exemplo:
 *          setaByteEmP(0x12345678, 0xFF, 0) -> 0x123456FF
 *          setaByteEmP(0x12345678, 0xFF, 1) -> 0x1234FF78
 *          setaByteEmP(0x12345678, 0xFF, 2) -> 0x12FF5678
 *          setaByteEmP(0x12345678, 0xFF, 3) -> 0xFF345678
 *
 */
int32_t setaByteEmP(int32_t x, int32_t y, uint8_t p) {
    return -1;
}

/*
 * Minimo
 *      Permitido:
 *          Operações: << >> | ^ < > ~ ! & -
 *
 *      Número máximo de operações: 15
 *      Monitor: 5
 *
 *      Retorna o menor numero entre x e y
 *
 *      Exemplo:
 *          minimo(10, 15) -> 10
 *          minimo(-2, -1) -> -2
 *          minimo(-1, 2) -> -1
 *
 */
int32_t minimo(int32_t x, int32_t y) {
/*
 * Para esta funcao utilizamos os operadores: "^", "&" e "<"
 * 
 * A expressao -(x < y) representa o seguinte: Se x for menor que y
 * (condicional eh verdadeira), logo a expressao no parenteses eh 1,
 * e toda a expressao eh -1. Caso contrario, a expressao possui valor 0.
 * 
 * Olhando para essa mesma expressao no contexto da subexpressao do
 * proximo nivel, ((x ^ y) & -(x < y)), temos que:
 * ((x ^ y) & 0) => x eh maior ou igual a y
 * ((x ^ y) & 1) => y eh maior que x
 * 
 * Se realizarmos um AND bit a bit com 0, isso resulta em todos os bits
 * do resultado sendo 0, entao a primeira expressao sera 0. O valor -1,
 * assumindo a representacao de complemento de dois, tem todos os bits
 * definidos como 1. Portanto, realizar um AND bit a bit com -1 resultara
 * no valor do outro operando.
 * 
 * Olhando para a proxima expressao, y ^ ((x ^ y) & -(x < y)), temos que:
 * y ^ (0) => x eh maior ou igual a y
 * y ^ (x ^ y) => y eh maior que x
 * 
 * No primeiro caso, se fizermos um XOR com 0, resultano valor do outro
 * operando, portanto, o resultado final eh y. No segundo caso, o ou 
 * exclusivo eh associativo, entao podemos olhar ele como (y ^ y) ^ x.
 * Sabemos que se fizermos um ou exclusivo de um numero com ele mesmo,
 * isso resulta em 0. E, portanto, a expressao (0 ^ x) eh igual a x.
 * 
 * Dessa forma, a expressao y ^ ((x ^ y) & -(x < y)) fornece o menor numero
 * entre as variaveis x e y.
 */
    return y ^ ((x ^ y) & -(x < y));
}

/*
 * Negação lógica sem !
 *      Permitido:
 *          Operações: << >> | & + ~
 *
 *      Número máximo de operações: 15
 *      Monitor: 5
 *
 *      Retorna 1 se x == 0, retorna 0 caso contrário
 *
 *      Exemplo:
 *          negacaoLogica(0) -> 1
 *          negacaoLogica(37) -> 0
 *
 */
int32_t negacaoLogica(int32_t x) {
/*
 * Para esta funcao, utilizamos os operadores: "|", "~" e ">>"
 * 
 * Assumindo que x eh um signed int de 32 bits, a negacao logica
 * dessa incognita (!x) deve retornar 0 para qualquer numero diferente
 * de zero e 1 para zero.
 * 
 * Como sabemos que x eh um numero inteiro com sinal (posendo ser positivo 
 * ou negativo, temos que trabalhar com o right shift (>>), que realiza um
 * deslicamento aritmetico. Portanto, deslocando x para a direita por 31 e
 * sua negacao por 31:
 * (x >> 31) | ((~x + 1) >> 31) 
 * Um desses dois valores sera necessariamente um numero negativo e, portanto,
 * deslocado para a direita em 31 sera 0xFFFFFFFF (se x = 0, o deslocamento para
 * a direita sera igual a 0x0, que eh o que desejamos)
 * 
 * Portanto, a logica por tras dessa expressao eh que, como nao sabemos se x ou a
 * sua negacao eh um numero negativo, quando combinamos esses dois valores com o
 * auxilio do operador logico "|" (OR), que percorre o numero bit a bit, retornando
 * 1 se um dos bits comparados forem iguais a 1; 0, caso contrario
 * 
 * Para chegar no resultado final, temos que somar 1. Isso acontece pois, se o 
 * resultado parcial for zero, o resultado final sera 1. Se x for diferente de zero,
 * o resultado parcial sera -2 ^ 31. Para corrigir isso, forcaremos um overflow e o 
 * resultado final sera 0. Dessa forma, preservamos o bit mais significativo, seja
 * quando x = 0 ou quando x != 0, que eh exatamente o que desejamos
 */
  return ((x >> 31) | ((~x + 1) >> 31)) + 1;
}

void teste(int32_t saida, int32_t esperado) {
    static uint8_t test_number = 0;
    test_number++;
    if(saida == esperado)
        printf(ANSI_COLOR_GREEN "PASSOU! Saída: %-10d\t Esperado: %-10d\n" ANSI_COLOR_RESET,
            saida, esperado);

    else
        printf(ANSI_COLOR_RED "%d: FALHOU! Saída: %-10d\t Esperado: %-10d\n" ANSI_COLOR_RESET,
            test_number, saida, esperado);
}

int main() {
    puts(ANSI_COLOR_BLUE "Primeiro lab - bits" ANSI_COLOR_RESET);
    puts("");

    puts("Teste: ehPar");
    teste(ehPar(2), 1);
    teste(ehPar(1), 0);
    teste(ehPar(3), 0);
    teste(ehPar(13), 0);
    teste(ehPar(100), 1);
    teste(ehPar(125), 0);
    teste(ehPar(1024), 1);
    teste(ehPar(2019), 0);
    teste(ehPar(2020), 1);
    teste(ehPar(-1), 0);
    teste(ehPar(-27), 0);
    teste(ehPar(-1073741825), 0);
    teste(ehPar(1073741824), 1);
    teste(ehPar(2147483647), 0);
    teste(ehPar(-2147483648), 1);
    teste(ehPar(0), 1);
    puts("");

    puts("Teste: mod8");
    teste(mod8(0), 0);
    teste(mod8(4), 4);
    teste(mod8(7), 7);
    teste(mod8(8), 0);
    teste(mod8(-1), 7);
    teste(mod8(-8), 0);
    teste(mod8(2147483647), 7);
    teste(mod8(-2147483648), 0);
    puts("");

    puts("Teste: negativo");
    teste(negativo(0), 0);
    teste(negativo(1), -1);
    teste(negativo(-1), 1);
    teste(negativo(2147483647), -2147483647);
    teste(negativo(-2147483647), 2147483647);
    teste(negativo(-2147483648), 2147483648);
    puts("");

    puts("Teste: bitwiseAnd");
    teste(bitwiseAnd(1, 3), 1);
    teste(bitwiseAnd(-1, 0), 0);
    teste(bitwiseAnd(-1, 0x7FFFFFFF), 0x7FFFFFFF);
    teste(bitwiseAnd(0b0100, 0b1100), 0b0100);
    puts("");

    puts("Teste: ehIgual");
    teste(ehIgual(1,1), 1);
    teste(ehIgual(1,0), 0);
    teste(ehIgual(0,1), 0);
    teste(ehIgual(-1,1), 0);
    teste(ehIgual(-1,-1), 1);
    teste(ehIgual(2147483647,-1), 0);
    teste(ehIgual(2147483647,-2147483647), 0);
    teste(ehIgual(2147483647,-2147483648), 0);
    teste(ehIgual(2147483647,-2147483648), 0);
    puts("");

    puts("Teste: limpaBitN");
    teste(limpaBitN(1,0), 0);
    teste(limpaBitN(0b1111,1), 0b1101);
    teste(limpaBitN(15,3), 7);
    teste(limpaBitN(-1,31), 2147483647);
    teste(limpaBitN(-1,0), -2);
    teste(limpaBitN(2147483647, 30), 1073741823);
    puts("");

    puts("Teste: bitEmP");
    teste(bitEmP(1, 0), 1);   //    b01 => retorna 1
    teste(bitEmP(1, 1), 0);   //    b01 => retorna 0
    teste(bitEmP(2, 0), 0);   //    b10 => retorna 0
    teste(bitEmP(2, 1), 1);   //    b10 => retorna 1
    teste(bitEmP(9, 2), 0);   //  b1001 => retorna 0
    teste(bitEmP(-4194305, 22), 0);
    teste(bitEmP(9, 3), 1);
    teste(bitEmP(16, 3), 0);
    teste(bitEmP(0x1 << 5, 4), 0);
    teste(bitEmP(0x1 << 31, 31), 1);
    teste(bitEmP(-1073741825, 30), 0);
    teste(bitEmP(-1073741825, 31), 1);
    puts("");

    puts("Teste: byteEmP");
    teste(byteEmP(0x766B, 1), 0x76);
    teste(byteEmP(0x766B, 0), 0x6B);
    teste(byteEmP(0x8420, 0), 0x20);
    teste(byteEmP(0x12345678, 3), 0x12);   // retorna 0x12
    teste(byteEmP(0x12345678, 2), 0x34);   // retorna 0x34
    teste(byteEmP(0x12345678, 1), 0x56);   // retorna 0x56
    teste(byteEmP(0x12345678, 0), 0x78);   // retorna 0x78
    teste(byteEmP(0x321, 1), 0x03);        // retorna 0x03
    teste(byteEmP(0x321, 0), 0x21);        // retorna 0x21
    puts("");

    puts("Teste: setaByteEmP");
    teste(setaByteEmP(0x00, 0xFF, 0), 0x000000FF);
    teste(setaByteEmP(0x00, 0xFF, 1), 0x0000FF00);
    teste(setaByteEmP(0x00, 0xFF, 2), 0x00FF0000);
    teste(setaByteEmP(0x00, 0xFF, 3), 0xFF000000);
    teste(setaByteEmP(0x01234567, 0x33, 2), 0x01334567);
    teste(setaByteEmP(0xdeadbeef, 0x00, 0), 0xdeadbe00);
    teste(setaByteEmP(0xdeadbeef, 0x00, 1), 0xdead00ef);
    puts("");

    puts("Teste: minimo");
    teste(minimo(0,1), 0);
    teste(minimo(0,10), 0);
    teste(minimo(1, 128), 1);
    teste(minimo(-1, 0), -1);
    teste(minimo(-1, -2), -2);
    teste(minimo(2147483647, 2147483646), 2147483646);
    teste(minimo(-2147483648, -2147483647), -2147483648);
    teste(minimo(-2147483648, -1), -2147483648);
    puts("");

    puts("Teste: negacaoLogica");
    teste(negacaoLogica(0), 1);
    teste(negacaoLogica(1), 0);
    teste(negacaoLogica(-1), 0);
    teste(negacaoLogica(64), 0);
    teste(negacaoLogica(-64), 0);
    teste(negacaoLogica(2147483647), 0);
    teste(negacaoLogica(-2147483648), 0);
    puts("");

}
