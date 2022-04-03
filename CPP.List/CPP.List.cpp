
#include <iostream>
#include "List.h"

using namespace std;


int main()
{

	system("chcp 1251");

	List* list = new List("alphbet");

	list->AddNode('a', 0);
	list->AddNode('b', 1);
	list->AddNode('a', 2);
	list->AddNode('e', 3);
	list->AddNode('e', 4);
	list->AddNode('e', 5);

	list->ExcludeByAlphabet();


	list->Print();

}
