#include <iostream>
using namespace std;
#include "Product.h"
#include "Medicine.h"

int main(){

	Product p("Benuron", "Muito gostoso", 32.3, 0.2, 21);
	cout << p;
	Medicine m("Benuron", "Muito gostoso", 32.3, 0.2, 21, 1, false);
	cout << m;
	return 0;
}
