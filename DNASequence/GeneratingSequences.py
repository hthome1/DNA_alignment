from SequenceGenerator import SequenceGenerator
tamanhos = list(range(10, 600,7))
i = 0
for e in tamanhos:
    x = SequenceGenerator(e,e,i)
