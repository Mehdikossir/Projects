tab= read("verre",100,101)
for i=1:100
    clf
    a=string(double(i*16/100))
    plot2d(tab(i,:),rect=[0,285,101,304])
    xtitle("Température à "+a+" sec, barre de verre","x","T(K)")
    sleep(100)
end
plot2d(tab(100,:),rect=[0,285,101,304])
xtitle("Température à "+string(16)+" sec, barre de verre","x","T(K)")
