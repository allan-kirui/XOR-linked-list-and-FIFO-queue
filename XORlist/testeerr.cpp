//// XORlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include <iostream>
//using namespace std;
//
//
//struct node
//{
//	struct node* nextPrev;
//	int data;
//};
//
//struct node* XOR(struct node* b4, struct node* aft)
//{
//	return (struct node*)((uintptr_t)(b4) ^ (uintptr_t)(aft));
//}
//
//void insert_at_beg(struct node** head, struct node** tail, struct node** actual)
//{
//	struct node* new_node = (struct node*)malloc(sizeof(struct node));
//	int data;
//
//	if (new_node != nullptr)
//	{
//		printf_s("Enter data val:\n ");
//		scanf_s("%d", &data);
//		new_node->data = data;
//		new_node->nextPrev = *head;//the newnode now points to the first item
//		if (*head != nullptr)//when list is not empty
//		{
//			(*head)->nextPrev = XOR(new_node, (*head)->nextPrev);
//			*head = new_node;
//		}
//		else
//		{
//			*head = new_node;
//			*actual = new_node;
//		}
//		if (*tail == nullptr)//only 2 be done when tail is empty
//		{
//			*tail = new_node;
//		}
//	}
//}
//
//
//void insert_at_end(struct node** head, struct node** tail, struct node** before)
//{
//	struct node* new_node;
//	struct node* current = *head;
//	struct node* prev = nullptr;
//	struct node* next = nullptr;
//	int data;
//	new_node = (struct node*)malloc(sizeof(struct node));
//
//	if (new_node != nullptr && current != nullptr)
//	{
//		printf_s("Enter data val:\n ");
//		scanf_s("%d", &data);
//		new_node->data = data;
//		while (XOR(prev, (*current).nextPrev) != nullptr)//traverses list to the second last data item
//		{
//			next = XOR(prev, (*current).nextPrev);
//			prev = current;
//			current = next;
//		}
//		new_node->nextPrev = XOR(current, nullptr);
//		current->nextPrev = XOR((*current).nextPrev, new_node);
//		*tail = new_node;//setting the tail, to the item added at the end
//		if (*before == nullptr)
//		{
//			*before = new_node;//so as to be used in prev function
//		}
//	}
//	else
//	{
//		free(new_node);
//	}
//}
//
//void del_at_beg(struct node** head)
//{
//	struct node* current = *head;
//	struct node* prev = nullptr;
//	struct node* next = nullptr;
//	if (current != nullptr && XOR(prev, (*current).nextPrev) != nullptr)
//	{
//		next = XOR(prev, (*current).nextPrev);
//		prev = current;
//		current = next;
//		current->nextPrev = XOR(nullptr, XOR(prev, (*current).nextPrev)); //we do XOR bcoz we cant access the values of the next address otherwise, by simply (*current).nextPrev
//		free(*head); //deletes the node 
//		*head = current;
//	}
//}
//
//
//void del_at_end(struct node** head)
//{
//	struct node* current = *head;
//	struct node* prev = nullptr;
//	struct node* next = nullptr;
//	if (current != nullptr) {//when list isn't empty
//		while (XOR(prev, (*current).nextPrev) != nullptr) //traversing the list to second last
//		{
//			next = XOR(prev, (*current).nextPrev);
//			prev = current;
//			current = next;
//		}
//
//		prev->nextPrev = XOR(XOR(current, prev->nextPrev), nullptr); //we do XOR bcoz we cant access the values of the prev address otherwise, by simply (*current).nextPrev
//		free(next); //deletes the last node 
//
//	}
//}
//
//void prev(struct node** head, struct node** tail, struct node** actual, struct node** before)
//{
//	struct node* current = *actual;
//	struct node* prev = nullptr;
//	struct node* next = nullptr;
//	if (*before == nullptr && *actual == *tail)//situation where actual is the last item
//	{
//		prev = nullptr;
//		*before = current;
//		next = XOR(prev, current->nextPrev);
//	}
//	else if (*before != nullptr)
//	{
//		prev = *before; //we use the previous address to get the next item
//		*before = current;
//		next = XOR(prev, current->nextPrev);
//	}
//	if (next != nullptr) {
//		*actual = next; // we set our next to actual
//	}
//	else
//	{
//		*before = nullptr;
//		*actual = *tail;
//	}
//	cout << "Prev is:" << (*actual)->data << endl;
//}
//
//void print_list(struct node** head)
//{
//	struct node* current = *head;
//	struct node* prev = nullptr;
//	struct node* next = nullptr;
//	while (current != nullptr)
//	{
//		printf_s("%d ", (*current).data);
//		next = XOR(prev, (*current).nextPrev);
//
//		prev = current;
//		current = next;
//	}
//
//}
//
//int main()
//{
//	struct node* head{}, * actual{}, * before{}, * tail{};
//	actual = nullptr; //not supposed to change if we dont add anything to list
//	insert_at_beg(&head, &tail, &actual);
//	insert_at_beg(&head, &tail, &actual);
//	insert_at_end(&head, &tail, &before);
//	insert_at_beg(&head, &tail, &actual);
//	insert_at_beg(&head, &tail, &actual);
//	insert_at_end(&head, &tail, &before);
//	cout << endl;
//	cout << "Actual is: " << actual->data;
//	cout << endl;
//	cout << endl;
//	cout << "Head is: " << head->data;
//	cout << endl;
//	cout << endl;
//	cout << "Tail is: " << tail->data;
//	cout << endl;
//	print_list(&head);
//	prev(&head, &tail, &actual, &before);
//	prev(&head, &tail, &actual, &before);
//	prev(&head, &tail, &actual, &before);
//	prev(&head, &tail, &actual, &before);
//	cout << endl;
//	cout << "Actual is: " << actual->data;
//	cout << endl;
//	cout << endl;
//	cout << "Head is: " << head->data;
//	cout << endl;
//	cout << endl;
//	cout << "Tail is: " << tail->data;
//	cout << endl;
//	prev(&head, &tail, &actual, &before);
//
//
//
//	//del_at_end(&head);
//	print_list(&head);
//	cout << endl;
//	cout << actual->data;
//	return 0;
//}
