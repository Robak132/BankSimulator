BankApp: Main.o Tools.o Timer.o Stand.o SmallStands.o Operation.o ID.o Employeet.o Client.o Bank.o Account.o BankStats.o Error.o EStand.o
	g++ -o BankApp Main.o Tools.o Timer.o Stand.o SmallStands.o Operation.o ID.o Employeet.o Client.o Bank.o Account.o BankStats.o Error.o EStand.o

BankStats.o: BankStats.cpp BankStats.h Client.h OpEnum.h
	g++ -c BankStats.cpp
Main.o: Main.cpp Bank.h ID.h Error.h Timer.h Tools.h
	g++ -c Main.cpp
Tools.o: Tools.cpp Tools.h
	g++ -c Tools.cpp
Timer.o: Timer.cpp Timer.h
	g++ -c Timer.cpp
Stand.o: Stand.cpp Stand.h
	g++ -c Stand.cpp
SmallStands.o: SmallStands.cpp Stand.h
	g++ -c SmallStands.cpp
Operation.o: Operation.cpp Operation.h
	g++ -c Operation.cpp
ID.o: ID.cpp ID.h
	g++ -c ID.cpp
EStand.o: EStand.cpp Stand.h
	g++ -c EStand.cpp
Error.o: Error.cpp Error.h
	g++ -c Error.cpp
Employeet.o: Employeet.cpp Employeet.h
	g++ -c Employeet.cpp
Client.o: Client.cpp Client.h OpEnum.h Stand.h Tools.h
	g++ -c Client.cpp
Bank.o: Bank.cpp Bank.h Client.h Stand.h Tools.h
	g++ -c Bank.cpp
Account.o: Account.cpp Account.h
	g++ -c Account.cpp

clean: BankApp
	rm *.o
	rm BankApp