//// XORlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include <iostream>
//#define SIZE 20
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
//void insert_at_beg(struct node** head, struct node** tail, struct node** actual, int data, int* size)
//{
//	struct node* new_node = (struct node*)malloc(sizeof(struct node));
//
//	if (new_node != nullptr)
//	{
//		new_node->data = data;
//		new_node->nextPrev = *head;//the newnode now points to the first item
//		(*size)++;
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
//	else
//	{
//		free(new_node);
//	}
//}
//
//
//void insert_at_end(struct node** head, struct node** tail, struct node** actual, int data, int* size)
//{
//	struct node* new_node;
//	struct node* current = *head;
//	struct node* prev = nullptr;
//	struct node* next = nullptr;
//
//	new_node = (struct node*)malloc(sizeof(struct node));
//	new_node->data = data;
//	(*size)++;
//	if (current != nullptr)
//	{
//		while (XOR(prev, (*current).nextPrev) != nullptr)//traverses list to the second last data item
//		{
//			next = XOR(prev, (*current).nextPrev);
//			prev = current;
//			current = next;
//		}
//		new_node->nextPrev = XOR(current, nullptr);
//		current->nextPrev = XOR((*current).nextPrev, new_node);
//		*tail = new_node;//setting the tail, to the item added at the end
//	}
//	else if (new_node != nullptr && *head == nullptr)
//	{
//		new_node->nextPrev = XOR(current, nullptr);
//		//current->nextPrev = XOR((*current).nextPrev, new_node);
//		*head = new_node;
//		*actual = new_node;
//		if (*tail == nullptr)//only 2 be done when tail is empty
//		{
//			*tail = new_node;
//		}
//	}
//	else
//	{
//		free(new_node);
//		(*size)--;
//	}
//}
//
//
//void insert_b4_act(struct node** head, struct node** tail, struct node** actual, int data, int* size)
//{
//	struct node* new_node;
//	struct node* current = *head;
//	struct node* prev = nullptr;
//	struct node* next = nullptr;
//
//	new_node = (struct node*)malloc(sizeof(struct node));
//
//	if (new_node != nullptr && current != nullptr)
//	{
//		new_node->data = data;
//		if (*actual != *head) {
//			(*size)++;
//			while (*actual != current)
//			{
//				next = XOR(prev, (*current).nextPrev);
//				prev = current;
//				current = next;
//			}
//			new_node->nextPrev = XOR(prev, next);//the new_node holds the XOR of the actual and previous
//			prev->nextPrev = XOR(XOR(prev->nextPrev, next), new_node);//the inner XOR, gives the address of the previous previous, then outer hold the address of the previous and new_node
//			next->nextPrev = XOR(new_node, XOR(prev, next->nextPrev));//the inner XOR, returns the address of the next next node, the outer returns
//		}
//		else if (*actual == *tail)
//		{
//			insert_at_end(head, tail, actual, data, size);
//		}
//		else // here actual is always equal to head
//		{
//			insert_at_beg(head, tail, actual, data, size);
//		}
//
//	}
//	else if (current == nullptr)
//	{
//		insert_at_beg(head, tail, actual, data, size);
//	}
//
//}
//
//
//void del_at_beg(struct node** head, struct node** tail, struct node** actual, int* size)
//{
//	struct node* current = *head;
//	struct node* prev = nullptr;
//	struct node* next = nullptr;
//	if (*head == *tail)//meaning theres only one item in list
//	{
//		free(*head);
//		(*size)--;
//		*head = NULL;
//		*tail = NULL;
//		*actual = NULL;
//	}
//	else if (current != nullptr && XOR(prev, (*current).nextPrev) != nullptr)
//	{
//		next = XOR(prev, (*current).nextPrev);
//		prev = current;
//		current = next;
//		current->nextPrev = XOR(nullptr, XOR(prev, (*current).nextPrev)); //we do XOR bcoz we cant access the values of the next address otherwise, by simply (*current).nextPrev
//		if (*head == *actual)
//		{
//			*actual = *tail;
//		}
//		free(*head); //deletes the node 
//		*head = current;
//		(*size)--;
//	}
//}
//
//
//void del_at_end(struct node** head, struct node** tail, struct node** actual, int* size)
//{
//	struct node* current = *head;
//	struct node* prev = nullptr;
//	struct node* next = nullptr;
//	struct node* prevPrev = nullptr;
//	if (*head == *tail)//meaning there's only one item in list
//	{
//		free(*head);
//		*head = NULL;
//		*tail = NULL;
//		*actual = NULL;
//		(*size)--;
//	}
//	else if (current != nullptr) {//when list isn't empty
//		while (XOR(prev, (*current).nextPrev) != nullptr) //traversing the list to second last
//		{
//			next = XOR(prev, (*current).nextPrev);
//			prev = current;
//			current = next;
//		}
//		prevPrev = XOR(current, prev->nextPrev);
//		prev->nextPrev = XOR(prevPrev, nullptr); //we do XOR bcoz we cant access the values of the prev address otherwise, by simply (*current).nextPrev
//		if (*actual == *tail)
//		{
//			*actual = prev;
//		}
//		*tail = prev;
//		free(next); //deletes the last node 
//		next = NULL;
//		(*size)--;
//	}
//}
//
//
//void del_val(struct node** head, struct node** tail, struct node** actual, int data, int* size)
//{
//	struct node* current = *head;
//	struct node* prev = nullptr;
//	struct node* prevPrev = nullptr;
//	struct node* next = nullptr;
//	struct node* nextNext = nullptr;
//	while (current != nullptr)
//	{
//		if (current->data == data)
//		{
//			if (current == *head)
//			{
//				del_at_beg(head, tail, actual, size);
//				prev = nullptr;
//				current = *head;//reset current to point to new head
//			}
//			else if (current == *tail)
//			{
//				prevPrev = XOR(prev->nextPrev, current);
//				del_at_end(head, tail, actual, size);
//				current = *tail;//reset current to point to new tail
//				prev = prevPrev;
//			}
//			else
//			{
//				next = XOR(prev, current->nextPrev);
//				nextNext = XOR(current, next->nextPrev);
//				prevPrev = XOR(prev->nextPrev, current);
//				prev->nextPrev = XOR(prevPrev, next);
//				next->nextPrev = XOR(prev, nextNext);
//				free(current);
//				current = prev;
//				prev = prevPrev;
//				(*size)--;
//			}
//		}
//		else if (current->nextPrev != nullptr) {
//			next = XOR(prev, (*current).nextPrev);
//			prev = current;
//			current = next;
//		}
//		else break;
//	}
//}
//
//
//void del_act(struct node** head, struct node** tail, struct node** actual, int* size)
//{
//	struct node* current = *head;
//	struct node* prev = nullptr;
//	struct node* prevPrev = nullptr;
//	struct node* next = nullptr;
//	struct node* nextNext = nullptr;
//	while (current != *actual)
//	{
//		next = XOR(prev, (*current).nextPrev);
//		prev = current;
//		current = next;
//	}
//	if (current == *head)
//	{
//		del_at_beg(head, tail, actual, size);
//		prev = nullptr;
//		current = *head;//reset current to point to new head
//	}
//	else if (current == *tail)
//	{
//		del_at_end(head, tail, actual, size);
//		current = *tail;//reset current to point to new tail
//	}
//	else {
//		next = XOR(prev, current->nextPrev);
//		nextNext = XOR(current, next->nextPrev);
//		prevPrev = XOR(prev->nextPrev, current);
//		prev->nextPrev = XOR(prevPrev, next);
//		next->nextPrev = XOR(prev, nextNext);
//		free(current);
//		*actual = prev;
//		(*size)--;
//	}
//}
//
//
//void prev(struct node** tail, struct node** actual)
//{
//	struct node* current = *tail;
//	struct node* prev = nullptr;
//	struct node* next = nullptr;
//	while (*actual != current)//gets the actual element
//	{
//		prev = XOR(current->nextPrev, next);
//		next = current;
//		current = prev;
//	}
//	prev = XOR(current->nextPrev, next);
//	if (prev == nullptr)
//	{
//		*actual = *tail;
//	}
//	else {
//		*actual = prev;
//	}
//	printf_s("%d\n", (*actual)->data);
//}
//
//
//void next(struct node** head, struct node** actual)
//{
//	struct node* current = *head;
//	struct node* prev = nullptr;
//	struct node* next = nullptr;
//	while (*actual != current)
//	{
//		next = XOR(prev, (*current).nextPrev);
//		prev = current;
//		current = next;
//	}
//	next = XOR(prev, (*current).nextPrev);
//	if (next == nullptr)
//	{
//		*actual = *head;
//	}
//	else
//	{
//		*actual = next;
//	}
//	printf_s("%d\n", (*actual)->data);
//}
//
//
//
//void print_list_forw(struct node** head)
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
//	printf_s("\n");
//
//}
//
//
//void print_list_back(struct node** tail)
//{
//	struct node* current = *tail;
//	struct node* prev = nullptr;
//	struct node* next = nullptr;
//	while (current != nullptr)
//	{
//		printf_s("%d ", (*current).data);
//		prev = XOR(next, (*current).nextPrev);
//
//		next = current;
//		current = prev;
//	}
//	printf_s("\n");
//}
//
//
//void freeMem(struct node** head, struct node** tail)
//{
//	struct node* current = *head;
//	struct node* prev = nullptr;
//	struct node* next = nullptr;
//	bool del = false;
//	while (current != nullptr)
//	{
//		next = XOR(prev, (*current).nextPrev);
//
//		prev = current;
//		current = next;
//		if (del == true) {
//			free(XOR(next, prev->nextPrev));
//		}
//		del = true;
//	}
//	if (current != NULL) {
//		free(prev);
//	}
//	if (*head == *tail)//if only one item is in list
//	{
//		free(*head);
//	}
//}
//
//
//int main()
//{
//	struct node* head{}, * tail{}, * actual{};
//	int size = 0;
//	actual = nullptr; //not supposed to change if we don't add anything to list
//	char option[SIZE];
//	int data;
//	while (cin >> option)
//	{
//		if (strcmp(option, "ACTUAL") == false)
//		{
//			if (actual == nullptr)
//			{
//				printf_s("NULL\n");
//			}
//			else
//			{
//				printf_s("%d\n", actual->data);
//			}
//		}
//		else if (strcmp(option, "PREV") == false)
//		{
//			if (head == nullptr)
//			{
//				printf_s("NULL\n");
//			}
//			else
//				prev(&tail, &actual);
//		}
//		else if (strcmp(option, "NEXT") == false)
//		{
//			if (head == nullptr)
//			{
//				printf_s("NULL\n");
//			}
//			else
//				next(&head, &actual);
//		}
//		else if (strcmp(option, "ADD_BEG") == false)
//		{
//			scanf_s("%d", &data);
//			insert_at_beg(&head, &tail, &actual, data, &size);
//		}
//		else if (strcmp(option, "ADD_END") == false)
//		{
//			scanf_s("%d", &data);
//			insert_at_end(&head, &tail, &actual, data, &size);
//		}
//		else if (strcmp(option, "ADD_ACT") == false)
//		{
//			scanf_s("%d", &data);
//			insert_b4_act(&head, &tail, &actual, data, &size);
//		}
//		else if (strcmp(option, "DEL_BEG") == false)
//		{
//			del_at_beg(&head, &tail, &actual, &size);
//		}
//		else if (strcmp(option, "DEL_END") == false)
//		{
//			del_at_end(&head, &tail, &actual, &size);
//		}
//		else if (strcmp(option, "DEL_VAL") == false)
//		{
//			scanf_s("%d", &data);
//			del_val(&head, &tail, &actual, data, &size);
//		}
//		else if (strcmp(option, "DEL_ACT") == false)
//		{
//			del_act(&head, &tail, &actual, &size);
//		}
//		else if (strcmp(option, "SIZE") == false)
//		{
//			printf_s("SIZE: %d\n", size);
//		}
//		else if (strcmp(option, "PRINT_FORWARD") == false)
//		{
//			if (head == nullptr)
//			{
//				printf_s("NULL\n");
//			}
//			else
//				print_list_forw(&head);
//		}
//		else if (strcmp(option, "PRINT_BACKWARD") == false)
//		{
//			if (head == nullptr)
//			{
//				printf_s("NULL\n");
//			}
//			else
//				print_list_back(&tail);
//		}
//	}
//
//	freeMem(&head, &tail);
//	return 0;
//}
