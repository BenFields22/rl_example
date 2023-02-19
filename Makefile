default:
	g++ source.cpp Utils.cpp -g --std=c++11 -o run
runner:
	cat ./input.txt | ./run
clean:
	rm ./run
