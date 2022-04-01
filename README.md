# BuscaAleatoria
Para a busca aleatoria seguimos o seguinte psudo-codigo:
```
1. Gerar uma subsequencia sb=b[j,j+1,...,j+k] de b, de tamanho aleatório k, 1<=k<=m, e 0<=j<=m 
2. Gerar um número aleatório inteiro positivo p
3. Gerar p subsequencias sa=a[i,i+1,...,i+k] de a, com tamanho k calculado no passo (1), 0<=i<=n
4. Calcular os scores de cada par (sa,sb) com os pesos wmat, wmis e wgap
5. Devolver o score máximo m entre os scores do passo (4) e as subsequencias associadas a ele
```
Lembrando que K nao pode ser maior que m ou n.

## Gerando Sequencia de DNAs
Primeiro passa eh rodar o comando
```python3 SequenceGenerator.py```
O codigo gera um arquivo contendo o tamanho de cada sequencia e o dna em si.
Os tamanhos das sequencias de DNA sao de 100 e 200, porem no codigo podem ser alterados para o numero que escolher.

## Compilando o codigo
Rodar o comando 
```g++ -Wall -o3 LocalSearchAlignment.cpp -o LSA```

## Rodando o codigo

```./LSA < dna.seq```

LSA o arquivo gerado pela compilacao e o dna.seq o arquivo gerado pelo codigo em python

## Output
O output sera as duas sequencias de DNA  e o score maximo.

### obs:
No diretorio tambem ha um arquivo chamado LocalSeatchExploratory.cpp. Esse pode ser rodado de forma analoga ao descrito a cima
Nele, temos um loop, no qual a simulacao eh feita pra 200 K's diferentes.

## Conclusao:
Apos os testes com diversos valores de K, em nenhum caso o algoritmo de busca local foi mais acertivo que o smith and waterman.