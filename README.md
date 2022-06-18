# Fzip

<div align="center">
<img src="https://i.imgur.com/Uf8KKjU.jpg">
</div>

<div align="center">
<img src="https://img.shields.io/tokei/lines/github/reinaldoassis/dscodebase?color=blueviolet&style=for-the-badge">

</div>

## 📖 Sobre

Projeto de Estrutura de Dados (Lecionada pelo professor Marcio Ribeiro) que visa colocar em prática não somente o conhecimento das estruturas e suas implementações, como também por em teste organização, estrutura e planejamento.

Há duas faces a este projeto: a codificação de huffman e o experimento de _time complexity_. O experimento pode ser encontrado na subpasta "lib", já a codificação de huffman em "huffman" - ambas na pasta raíz "src".

Equipe: Reinaldo Assis, Maria Fernanda, Matheus Moreira, Guilherme de Oliveira.

## ⏱ Complexidade de tempo

Para o nosso experimento de complexidade de tempo comparamos as estruturas Fila de prioridade com lista encadeada e Fila de prioridade com heap. O algoritmo pode ser rodado executando o programa com a flag "--benchmarking", dois arquivos serão gerados dentro da pasta "ferramentas", são eles: HeapQmarking.txt e LinkedQmarking.txt, contêm as informações das ações realizadas com a implementação com heap e com a implementação com fila, respectivamente.

## 🎱 Codificação de Huffman

A nossa implementação de huffman pode ser estudada através da nossa [documentação](https://github.com/ReinaldoAssis/DSCodebase/wiki/Codifica%C3%A7%C3%A3o-de-Huffman).

## ⚡️ Testes unitários

A framework utilizada para nossos testes unitários foi a [CuTest](https://github.com/ennorehling/cutest), simples, completa e fácil de utilizar. Os testes podem ser encontrados na subpasta "test" e são rodados ao incluir a flag "--debug" ao programa.
