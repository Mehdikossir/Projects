tab= read("fer",100,101)
for i=1:50
    clf
    a=string(double(i*16/100))
    plot2d(tab(i,:),rect=[0,285,101,296],style=2)
    xtitle("Température à "+a+" sec, barre de fer","x","T(K)")
    sleep(100)
end
plot2d(tab(50,:),rect=[0,285,101,296],style=2)
xtitle("Température à "+string(a)+" sec, barre de fer ","x","T(K)")
