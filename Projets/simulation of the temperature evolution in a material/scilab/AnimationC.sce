tab= read("cuivre",100,101)
for i=1:50
    clf
    a=string(double(i*16/100))
    plot2d(tab(i,:),rect=[0,285,101,295],style=26)
    xtitle("Température à "+a+" sec, barre de cuivre","x","T(K)")
    sleep(100)
end
plot2d(tab(50,:),rect=[0,285,101,295],style=26)
xtitle("Température à "+sring(16)+" sec, barre de cuivre","x","T(K)")
