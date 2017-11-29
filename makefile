# Compile/Link 
GCC = gcc 
OPTMIZE = -g -O3 -w
LIBS = -lm
#Objetos 
OBJS =  tp2.c grafo.c lista.c 
OBJS2 = tp2_1.c grafo.c lista.c 
# Nome do aplicativo 
APPNAME = tp2o
APPNAME2 = tp2h
release : ; $(GCC) $(OPTMIZE) $(OBJS) -o $(APPNAME)  $(LIBS)
	    $(GCC) $(OPTMIZE) $(OBJS2) -o $(APPNAME2)  $(LIBS)	
clean : rm -rf *.o 
run :
	make 
	./tp2o input.txt output.txt debug
	./tp2h input.txt output.txt debug
