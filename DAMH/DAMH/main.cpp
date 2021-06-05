#include"Header.h"
#include"ConsoleProcess.h"
#include"login.h"
#include"ListClass.h"
int main() {
	FixConsoleWindow();
	ListClass();
	User user;
	repeatLogin(user);
}