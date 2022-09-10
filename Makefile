output = Enigma


src := $(wildcard ./src/*.cpp)


$(output):$(src)
	g++ $(src) -std=c++17 -o $(output)

clean:
	rm $(output)




