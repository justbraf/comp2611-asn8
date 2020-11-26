compile:
	@g++ -std=c++17 *.cpp -o adtApp `wx-config --libs --cxxflags`
run:
	@./adtApp
mem:
	@valgrind ./adtApp
clean:
	@rm -rf adtApp