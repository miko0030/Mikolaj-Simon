#sortowanie przez zliczanie
import datetime

lista = [int(x) for x in input().split()]
wartosc_maks = max(lista)
def sortowanie_przez_zliczanie(lista, wartosc_maks):
    zasieg = wartosc_maks +1
    zliczanie = [0] * zasieg
    for x in lista:
        zliczanie[x] += 1
    i = 0
    for a in range(zasieg):
        for b in range(zliczanie[a]):
            lista[i] = a
            i += 1

    return lista

czas1 = datetime.datetime.utcnow().timestamp()
sortowanie_przez_zliczanie(lista,wartosc_maks)
czas2 = datetime.datetime.utcnow().timestamp()
print(sortowanie_przez_zliczanie(lista,wartosc_maks))
print((czas2-czas1), 'seconds')

