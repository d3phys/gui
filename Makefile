TARGETS := gui gui-d

OBJ := main.o linalg.o canvas.o arrow.o

SFML := sfml-system sfml-window sfml-graphics

include txxflags.makefile
CXXFLAGS := -Wall # $(TXXFLAGS)

all: gui

gui: $(OBJ)
	$(CXX) -o $@ $(OBJ) $(addprefix -l, $(SFML))

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGETS)
	rm -f *.o


