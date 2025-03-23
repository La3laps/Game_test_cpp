all:
	g++ src/main.cpp -o program.exe -Iinclude -Llib -lglfw3dll -static
