# The name of the main file and executable
mainFileName = main
# Files that have .h and .cpp versions
classFiles =
# Files that only have the .h version
justHeaderFiles =
# Compilation flags
OPTIMIZATION_FLAG = -O0


# Auxiliary
filesObj = $(addsuffix .o, $(mainFileName) $(classFiles))
filesH = $(addsuffix .h, $(classFiles) $(justHeaderFiles))


all: cleanExe $(mainFileName)


# Compilation
%.o: %.cpp $(filesH)
	g++ $(OPTIMIZATION_FLAG) -c $< -std=c++17

# Execution
$(mainFileName): $(filesObj)
	g++ $(OPTIMIZATION_FLAG) $^ -o $@ -std=c++17


# Utils
clean:
	rm -f *.o $(mainFileName)

cleanExe:
	rm -f $(mainFileName)
