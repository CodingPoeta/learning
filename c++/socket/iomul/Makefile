all: select_server poll_server epoll_server  client

bin:
	mkdir bin

select_server: bin
	g++ -o bin/select_server select.cpp
poll_server: bin
	g++ -o bin/poll_server poll.cpp
epoll_server: bin
	g++ -o bin/epoll_server epoll.cpp
client: bin
	g++ -o bin/client  client.cpp
clean:
	rm -rf bin
