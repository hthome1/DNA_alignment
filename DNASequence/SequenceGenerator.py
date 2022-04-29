import random
import os
def SequenceGenerator(n,m,i):
     file = 'dna' + str(i)
     filepath = os.path.join("./Sequences",file)
     f = open(filepath, 'w')
     seq=[str(n)+'\n',
          str(m)+'\n',
          ''.join(random.choices(['A','T','C','G','-'],k=n))+'\n',
          ''.join(random.choices(['A','T','C','G','-'],k=m))]
     f.writelines(seq)
     f.close()
     return 0

