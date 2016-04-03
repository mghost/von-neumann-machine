m=main
mc=$(m).cpp

mm=memory
mmc=$(mm).cpp
mmh=$(mm).h
mmo=$(mm).o

p=program
pc=$(p).cpp
ph=$(p).h
po=$(p).o

v=von_neumann
vc=$(v).cpp
vh=$(v).h
vo=$(v).o

run: compile
	./$(m)

compile: compile_vn $(mc)
	g++ -o $(m) $(mc) $(mmo) $(vo) $(po)

compile_vn: compile_prog $(vc) $(vh)
	g++ -o $(vo) -c $(vc)

compile_prog: compile_mem $(pc) $(ph)
	g++ -o $(po) -c $(pc)

compile_mem: $(mmc) $(mmh)
	g++ -o $(mmo) -c $(mmc)

