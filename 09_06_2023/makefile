all: main main2
main: clockexcept clock main.cpp
	g++ -pedantic-errors -g main.cpp clock clockexcept -o main
clock: clock.cpp clock.h
	g++ -pedantic-errors -g -c clock.cpp -o clock
clockexcept: clockexcept.h clockexcept.cpp
	g++ -pedantic-errors -g -c clockexcept.cpp -o clockexcept
main2: donut donutExcept drink order main2.cpp
	g++ -pedantic-errors -g main2.cpp donut drink donutExcept order -o main
order: order.h order.cpp
	g++ -pedantic-errors -g -c order.cpp -o order