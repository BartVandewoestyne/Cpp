CXX=g++-3.4

all: programs

programs: $(basename $(wildcard *.cc))

$(basename %.cc): %.cc
	$(CXX) $^ -o $@

.PHONY: clean
clean:
	rm -f *.o a.out
realclean: clean
	rm -f $(basename $(wildcard *.cc))
