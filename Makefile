
CMP = g++
CLASS = lifeboard
MAIN = life
EXEC = playlife

$(EXEC): $(CLASS).o $(MAIN).o
	$(CMP) $(CLASS).o $(MAIN).o -o $(EXEC)

$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CMP) -std=c++11 -c $(CLASS).cpp -o $(CLASS).o

$(MAIN).o: $(MAIN).cpp $(CLASS).h
	$(CMP) -std=c++11 -c $(MAIN).cpp -o $(MAIN).o

clean:
	rm *.o
	rm $(EXEC)

