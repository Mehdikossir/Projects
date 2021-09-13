tab= read("polystyrene",100,101)
for i=1:50
    clf
    a=string(double(i*16/100))
    plot2d(tab(i,:),rect=[0,285,101,315],style=14)
    xtitle("Température à "+a+" sec, barre de polystyrène","x","T(K)")
    sleep(100)
end
plot2d(tab(50,:),rect=[0,285,101,315],style=14)
xtitle("Température à "+string(a)+" sec, barre de polystyrène","x","T(K)")
