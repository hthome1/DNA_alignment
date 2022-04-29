from SequenceGenerator import SequenceGenerator
tamanhos = list(range(10, 510,10))
i = 0
for e in tamanhos:
    x = SequenceGenerator(e,e,i)
    i+=1