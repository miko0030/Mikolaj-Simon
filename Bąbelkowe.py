#sortowanie babelkowe
import datetime

lista = [int(x) for x in input().split()]
def sortowanie_babelkowe(lista):
    for i in range(len(lista)):
        for j in range(0, len(lista)-i-1):
            if lista[j]>lista[j+1]:
                lista[j], lista[j+1]= lista[j+1], lista[j]
    return lista



czas1 = datetime.datetime.utcnow().timestamp()
sortowanie_babelkowe(lista)
czas2 = datetime.datetime.utcnow().timestamp()
print(sortowanie_babelkowe(lista))
print((czas2-czas1), 'seconds')
