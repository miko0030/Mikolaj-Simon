#sortowanie przez wstawianie
import datetime

lista = [int(x) for x in input().split()]
def sortowanie_przez_wstawianie(lista):
    for i in range(1, len(lista)):
        while lista[i-1] > lista[i] and i>0:
            lista[i], lista[i-1] = lista[i-1], lista[i]
            i = i-1

    return lista

czas1 = datetime.datetime.utcnow().timestamp()
sortowanie_przez_wstawianie(lista)
czas2 = datetime.datetime.utcnow().timestamp()
print(sortowanie_przez_wstawianie(lista))
print((czas2-czas1), 'seconds')
