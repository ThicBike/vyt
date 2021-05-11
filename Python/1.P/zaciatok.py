meno = input("Tvoje meno : ")
vek = int(input("Tvoj vek : "))
print("Tvoje meno je : ", meno, "\nTvoj ve je : ",vek)
print(meno,"bude mat o rok bude",vek + 1,"\n",meno,"bude mat o 10 rokov bude ",vek + 10)

polomer = int(input("\nZadaj polomer kruhu :"))
pi = 3.141592653589793
obvod = round(2 * pi * polomer,2)
obsah = round(pi * polomer ** 2,2)
print("Obsah je ", obsah, "\nObvod je ", obvod)

cislo = int(input("\nZadaj aspon 4 ciferne cislo : "))

for i in 10, 100, 1000, 10000:
    print(int(cislo / i), cislo % i)


veta = str(input("Napis vetu :"))
for i in range(10):
    print(veta)

