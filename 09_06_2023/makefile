all: main main2
main: clockexcept clock main.cpp
	g++ -pedantic-errors -g main.cpp clock clockexcept -o main
clock: clock.cpp clock.h
	g++ -pedantic-errors -g -c clock.cpp -o clock
clockexcept: clockexcept.h clockexcept.cpp
	g++ -pedantic-errors -g -c clockexcept.cpp -o clockexcept
main2: donut donutExcept drink order main.cpp
	g++ -pedantic-errors -g main.cpp donut drink donutExcept order -o main
donut: donut.h donut.cpp 
	g++ -pedantic-errors -g -c donut.cpp -o donut
donutExcept: donutExcept.h donutExcept.cpp
	g++ -pedantic-errors -g -c donutExcept.cpp -o donutExcept
drink: drink.h drink.cpp
	g++ -pedantic-errors -g -c drink.cpp -o drink
order: order.h order.cpp
	g++ -pedantic-errors -g -c order.cpp -o order