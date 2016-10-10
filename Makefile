passwordManager: PasswordDriver.o PasswordManager.o
	g++ PasswordDriver.o PasswordManager.o -o passwordManager

PasswordDriver.o: PasswordDriver.cpp PasswordManager.h
	g++ -c PasswordDriver.cpp

PasswordManager.o: PasswordManager.cpp PasswordManager.h
	g++ -c PasswordManager.cpp 
