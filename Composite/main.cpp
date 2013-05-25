#include "classes.h"
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	list1 * l1 = new list1;
	list1 * l2 = new list1;
	list1 * l3 = new list1;
	list2 * l4 = new list2;
	list2 * l5 = new list2;
	con1 * c1 = new con1;
	con1 * c2 = new con1;
	con2 * c3 = new con2;
	con2 * c4 = new con2;
	con2 * c5 = new con2;
	con2 * main = new con2;
	
	main->Add(c1);
	main->Add(l1);
	main->Add(c2);
	main->Add(c3);
	c2->Add(l2);
	c2->Add(c4);
	c2->Add(c5);
	c2->Add(l3);
	c5->Add(l4);
	c5->Add(l5);
	
	main->Show();
	cout << endl;
	delete main;
	
	return 0;
}

/*
Результат выполнения:

container type 2
    container type 1
    list type 1
    container type 1
        list type 1
        container type 2
        container type 2
            list type 2
            list type 2
        list type 1
    container type 2

deleted con2
deleted con1
deleted list1
deleted con1
deleted list1
deleted con2
deleted con2
deleted list2
deleted list2
deleted list1
deleted con2

*/
