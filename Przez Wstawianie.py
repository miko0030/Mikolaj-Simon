#sortowanie przez wstawianie
import time

lista = [int(x) for x in input().split()]
def sortowanie_przez_wstawianie(lista):
    for i in range(1, len(lista)):
        while lista[i-1] > lista[i] and i>0:
            lista[i], lista[i-1] = lista[i-1], lista[i]
            i = i-1

    return lista

print(time.process_time_ns())
print(sortowanie_przez_wstawianie(lista))
