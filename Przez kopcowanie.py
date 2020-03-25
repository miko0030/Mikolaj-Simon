#sortowanie przez kopcowanie
import datetime

lista = [int(x) for x in input().split()]
def zamiana(i, j):
    lista[i], lista[j] = lista[j], lista[i]

def kopiec(ilosc,i):
    lewa=2 * i + 1
    prawa=2 * (i + 1)
    max=i
    if lewa < ilosc and lista[i] < lista[lewa]:
        max = lewa
    if prawa < ilosc and lista[max] < lista[prawa]:
        max = prawa
    if max != i:
        zamiana(i, max)
        kopiec(ilosc, max)

def sortowanie_przez_kopcowanie():
    ilosc = len(lista)
    start = ilosc // 2 - 1
    for i in range(start, -1, -1):
        kopiec(ilosc, i)
    for i in range(ilosc-1, 0, -1):
        zamiana(i, 0)
        kopiec(i, 0)
    return lista


czas1 = datetime.datetime.utcnow().timestamp()
sortowanie_przez_kopcowanie()
czas2 = datetime.datetime.utcnow().timestamp()
print(sortowanie_przez_kopcowanie())
print((czas2-czas1), 'seconds')
