#sortowanie przez scalanie
import datetime

lista = [int(x) for x in input().split()]
def sortowanie_przez_scalanie(lista):
    if len(lista)>1:
        srodek = len(lista)//2
        lewa = lista[:srodek]
        prawa = lista[srodek:]
        sortowanie_przez_scalanie(lewa)
        sortowanie_przez_scalanie(prawa)
        i=0
        j=0
        k=0
        while i < len(lewa) and j < len(prawa):
            if lewa[i] <= prawa[j]:
                lista[k]=lewa[i]
                i=i+1
            else:
                lista[k]=prawa[j]
                j=j+1
            k=k+1
        while i < len(lewa):
            lista[k]=lewa[i]
            i=i+1
            k=k+1
        while j < len(prawa):
            lista[k]=prawa[j]
            j=j+1
            k=k+1
    return lista

czas1 = datetime.datetime.utcnow().timestamp()
sortowanie_przez_scalanie(lista)
czas2 = datetime.datetime.utcnow().timestamp()
print(sortowanie_przez_scalanie(lista))
print((czas2-czas1), 'seconds')
