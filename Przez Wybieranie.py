#sortowanie przez wybieranie
import datetime

lista = [int(x) for x in input().split()]
def sortowanie_przez_wybieranie(lista):
    for i in range(len(lista)):
        numer = i
        for j in range(i+1,len(lista)):
            if lista[numer]> lista[j]:
                numer = j
                lista[i],lista[numer]= lista[numer], lista[i]
    return lista

czas1 = datetime.datetime.utcnow().timestamp()
sortowanie_przez_wybieranie(lista)
czas2 = datetime.datetime.utcnow().timestamp()
print(sortowanie_przez_wybieranie(lista))
print((czas2-czas1), 'seconds')

