all:
	mkdir -p bin
	g++ examples/llv3.cpp src/lidarlite_v3.cpp -I . -o bin/llv3.out
	g++ examples/llv3_socket_master.cpp src/lidarlite_v3.cpp -I . -o bin/llv3_socket_master.out
	g++ examples/llv3_flush_out.cpp src/lidarlite_v3.cpp -I . -o bin/llv3_flush_out.out
	g++ examples/llv3_socket_slave.cpp src/lidarlite_v3.cpp -I . -o bin/llv3_socket_slave.out
