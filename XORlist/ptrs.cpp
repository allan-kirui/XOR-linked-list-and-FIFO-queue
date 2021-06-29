////// XORlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
//
//class List
//{
//
//public:
//
//	node* head, * tail, * actual, * front, * back;
//	size_t size, count;
//
//	List()
//	{
//		head = tail = actual = front = back = nullptr;
//		size = count = 0;
//	}
//
//
//	node* XOR(node* b4, node* aft)
//	{
//		return (node*)((uintptr_t)(b4) ^ (uintptr_t)(aft));
//	}
//
//
//
//	void insert_at_end(int data)
//	{
//		node* new_node;
//		node* current = head;
//		node* prev = nullptr;
//		node* next = nullptr;
//
//		new_node = (node*)malloc(sizeof(node));
//		new_node->data = data;
//		size++;
//
//		if (current != nullptr)
//		{
//			while (XOR(prev, current->nextPrev) != nullptr)//traverses list to the second last data item
//			{
//				next = XOR(prev, current->nextPrev);
//				prev = current;
//				current = next;
//			}
//			new_node->nextPrev = XOR(current, nullptr);
//			current->nextPrev = XOR(current->nextPrev, new_node);
//			tail = new_node;//setting the tail, to the item added at the end
//		}
//		else if (new_node != nullptr && head == nullptr)
//		{
//			new_node->nextPrev = XOR(current, nullptr);
//			head = new_node;
//			actual = new_node;
//			if (tail == nullptr)//only 2 be done when tail is empty
//			{
//				tail = new_node;
//			}
//		}
//		else
//		{
//			free(new_node);
//			size--;
//		}
//	}
//
//
//	void insert_at_beg(int data, bool in_queue)
//	{
//		node* new_node = (node*)malloc(sizeof(node));
//
//		new_node->data = data;
//		new_node->nextPrev = head;//the newnode now points to the first item
//		size++;
//		if (head != nullptr)//when list is not empty
//		{
//			(head)->nextPrev = XOR(new_node, (head)->nextPrev);
//			head = new_node;
//			if (in_queue == true)
//			{
//				back = new_node;
//			}
//		}
//		else
//		{
//			head = actual = tail = new_node;
//			if (in_queue == true)//situation where list n queue are empty
//			{
//				front = back = new_node;
//			}
//		}
//	}
//
//
//
//	void insert_b4_act(int data, bool in_queue)
//	{
//		node* new_node;
//		node* current = head;
//		node* prev = nullptr;
//		node* next = nullptr;
//
//		new_node = (node*)malloc(sizeof(node));
//
//		if (new_node != nullptr && current != nullptr)
//		{
//			new_node->data = data;
//
//			if (actual != head)
//			{
//				size++;
//				while (actual != current)
//				{
//					next = XOR(prev, current->nextPrev);
//					prev = current;
//					current = next;
//				}
//				new_node->nextPrev = XOR(prev, next);//the new_node holds the XOR of the actual and previous
//				prev->nextPrev = XOR(XOR(prev->nextPrev, next), new_node);//the inner XOR, gives the address of the previous previous, then outer hold the address of the previous and new_node
//				next->nextPrev = XOR(new_node, XOR(prev, next->nextPrev));//the inner XOR, returns the address of the next next node, the outer returns
//			}
//			else if (actual == tail)
//			{
//				insert_at_end(data);
//			}
//			else // here actual is always equal to head
//			{
//				insert_at_beg(data, in_queue);
//			}
//
//		}
//		else if (current == nullptr)
//		{
//			insert_at_beg(data, in_queue);
//		}
//
//	}
//
//	void push(int data, bool in_queue)
//	{
//		if (count == size && back == head)
//		{
//			insert_at_beg(data, in_queue);
//
//		}
//		else if (head != nullptr && back == nullptr)//when list is not empty and queue is empty
//		{
//			back = front = tail;
//			back->data = data;
//
//		}
//		else
//		{
//			node* current = tail;
//			node* prev = nullptr;
//			node* next = nullptr;
//
//
//			while (current != back)//locates back
//			{
//				prev = XOR(next, current->nextPrev);
//
//				next = current;
//				current = prev;
//			}
//			prev = current;
//			current = XOR(next, current->nextPrev);
//			if (current == nullptr && front != tail)//situation where there are items in list not in queue
//			{
//				back = tail;
//			}
//			else if (current != front)//if there are values behind back not in queue
//			{
//				back = current;
//			}
//			else //where the queue is same to list but back != head
//			{
//				//prev = XOR();
//				node* new_node = (node*)malloc(sizeof(node));
//				new_node->nextPrev = XOR(current, prev);
//				node* prev_Prev = XOR(current->nextPrev, prev);
//				node* next_Next = XOR(current, prev->nextPrev);
//				current->nextPrev = XOR(prev_Prev, new_node);
//				prev->nextPrev = XOR(new_node, next_Next);
//				back = new_node;
//				size++;
//			}
//			back->data = data;
//
//
//		}
//		count++;
//
//	}
//
//
//	void pop()
//	{
//		node* current = tail;
//		node* prev = nullptr;
//		node* next = nullptr;
//
//		if (front == nullptr)
//		{
//			printf_s("NULL\n");
//			count++;
//		}
//		else if (front == back)
//		{
//
//			printf_s("%d\n", front->data);
//			front = back = nullptr;
//		}
//		else
//		{
//			while (current != front)
//			{
//				next = XOR(prev, current->nextPrev);
//				prev = current;
//				current = next;
//				if (current == nullptr && current != back)
//				{
//					current = tail;
//					prev = nullptr;
//				}
//			}
//			next = XOR(prev, current->nextPrev);
//			prev = current;
//			current = next;
//			if (current == nullptr && current != back)
//			{
//				current = tail;
//				prev = nullptr;
//				printf_s("%d\n", head->data);
//			}
//			else
//			{
//				printf_s("%d\n", prev->data);
//			}
//			front = current;
//		}
//		count--;
//	}
//
//
//	void del_at_beg()
//	{
//		node* current = head;
//		node* prev = nullptr;
//		node* next = nullptr;
//		if (head == tail)//meaning theres only one item in list
//		{
//			if (head == front)
//			{
//				back = front = nullptr;
//				count--;
//			}
//			free(head);
//			size--;
//			head = tail = actual = nullptr;
//		}
//		else if (current != nullptr && XOR(prev, (*current).nextPrev) != nullptr)
//		{
//			next = XOR(prev, (*current).nextPrev);
//			prev = current;
//			current = next;
//			current->nextPrev = XOR(nullptr, XOR(prev, (*current).nextPrev)); //we do XOR bcoz we cant access the values of the next address otherwise, by simply (*current).nextPrev
//			if (head == actual)
//			{
//				actual = tail;
//			}
//			if (prev == back)
//			{
//				back = next;
//				count--;
//			}
//			else if (prev == front)
//			{
//				front = next;
//				count--;
//			}
//			free(head); //deletes the node 
//			head = current;
//			size--;
//		}
//	}
//
//
//	void del_at_end()
//	{
//		node* current = head;
//		node* prev = nullptr;
//		node* next = nullptr;
//		node* prevPrev = nullptr;
//		if (head == tail)//meaning there's only one item in list
//		{
//			if (head == front)
//			{
//				back = front = nullptr;
//				count--;
//			}
//			free(head);
//			head = tail = actual = nullptr;
//			(size)--;
//		}
//		else if (current != nullptr) //when list isn't empty
//		{
//			while (XOR(prev, (*current).nextPrev) != nullptr) //traversing the list to second last
//			{
//				next = XOR(prev, (*current).nextPrev);
//				prev = current;
//				current = next;
//			}
//			prevPrev = XOR(current, prev->nextPrev);
//			prev->nextPrev = XOR(prevPrev, nullptr); //we do XOR bcoz we cant access the values of the prev address otherwise, by simply (*current).nextPrev
//			if (actual == tail)
//			{
//				actual = prev;
//			}
//			if (current == back)
//			{
//				if (back == tail && back != front)
//				{
//					back = head;
//				}
//				else
//				{
//					back = prev;
//				}
//				count--;
//			}
//
//			tail = prev;
//			free(next); //deletes the last node 
//			next = nullptr;
//			(size)--;
//		}
//	}
//
//
//	void del_val(int data)
//	{
//		node* current = head;
//		node* prev = nullptr;
//		node* prevPrev = nullptr;
//		node* next = nullptr;
//		node* nextNext = nullptr;
//
//		while (current != nullptr)
//		{
//			if (current->data == data)
//			{
//				if (current == head)
//				{
//					del_at_beg();
//					prev = nullptr;
//					current = head;//reset current to point to new head
//				}
//				else if (current == tail)
//				{
//					prevPrev = XOR(prev->nextPrev, current);
//					del_at_end();
//					current = tail;//reset current to point to new tail
//					prev = prevPrev;
//				}
//				else
//				{
//					next = XOR(prev, current->nextPrev);
//					nextNext = XOR(current, next->nextPrev);
//					prevPrev = XOR(prev->nextPrev, current);
//					prev->nextPrev = XOR(prevPrev, next);
//					next->nextPrev = XOR(prev, nextNext);
//					free(current);
//					current = prev;
//					prev = prevPrev;
//					(size)--;
//				}
//			}
//			else if (current->nextPrev != nullptr)
//			{
//				next = XOR(prev, (*current).nextPrev);
//				prev = current;
//				current = next;
//			}
//			else break;
//		}
//	}
//
//
//	void del_act()
//	{
//		node* current = head;
//		node* prev = nullptr;
//		node* prevPrev = nullptr;
//		node* next = nullptr;
//		node* nextNext = nullptr;
//		while (current != actual)
//		{
//			next = XOR(prev, (*current).nextPrev);
//			prev = current;
//			current = next;
//		}
//		if (current == head)
//		{
//			del_at_beg();
//			prev = nullptr;
//			current = head;//reset current to point to new head
//		}
//		else if (current == tail)
//		{
//			del_at_end();
//			current = tail;//reset current to point to new tail
//		}
//		else
//		{
//			next = XOR(prev, current->nextPrev);
//			nextNext = XOR(current, next->nextPrev);
//			prevPrev = XOR(prev->nextPrev, current);
//			prev->nextPrev = XOR(prevPrev, next);
//			next->nextPrev = XOR(prev, nextNext);
//			free(current);
//			actual = prev;
//			(size)--;
//		}
//	}
//
//	void garbage_soft()
//	{
//		node* current = tail;
//		node* prev = nullptr;
//		node* next = nullptr;
//		if (current != front && current != back)
//		{
//			while (prev != back)
//			{
//				next = XOR(prev, current->nextPrev);
//				prev = current;
//				current = next;
//				if (current == nullptr && current != back)
//				{
//					current = tail;
//					prev = nullptr;
//				}
//			}
//			while (current != front)
//			{
//				next = XOR(prev, current->nextPrev);
//
//				prev = current;
//				current = next;
//
//				prev->data = 0;
//			}
//		}
//	}
//
//	void garbage_hard()
//	{
//		node* current = tail;
//		node* prev = nullptr;
//		node* next = nullptr;
//		node* prevPrev = nullptr;
//		node* prevPrevPrev = nullptr;
//
//		if (current != front && current != back)
//		{
//			while (prev != back)
//			{
//				next = XOR(prev, current->nextPrev);
//				prev = current;
//				current = next;
//				if (current == nullptr && current != back)
//				{
//					current = tail;
//					prev = nullptr;
//				}
//			}
//			while (current != front)
//			{
//				next = XOR(prev, current->nextPrev);
//
//				prev = current;
//				current = next;
//
//				if (prev == head)
//				{
//					del_at_beg();
//					prev = nullptr;
//					current = head;
//				}
//				else if (prev == tail)
//				{
//					del_at_end();
//					prev = nullptr;
//					current = head;
//				}
//				else
//				{
//					next = XOR(prev, current->nextPrev);
//
//					prevPrev = XOR(prev->nextPrev, current);
//					prevPrevPrev = XOR(prevPrev->nextPrev, prev);
//					prevPrev->nextPrev = XOR(prevPrevPrev, current);
//					current->nextPrev = XOR(prevPrev, next);
//
//					free(prev);
//					prev = prevPrev;
//					size--;
//				}
//
//			}
//		}
//	}
//
//	void prev()
//	{
//		node* current = tail;
//		node* prev = nullptr;
//		node* next = nullptr;
//		while (actual != current)//gets the actual element
//		{
//			prev = XOR(current->nextPrev, next);
//			next = current;
//			current = prev;
//		}
//		prev = XOR(current->nextPrev, next);
//		if (prev == nullptr)
//		{
//			actual = tail;
//		}
//		else {
//			actual = prev;
//		}
//		printf_s("%d\n", (actual)->data);
//	}
//
//
//	void next()
//	{
//		node* current = head;
//		node* prev = nullptr;
//		node* next = nullptr;
//		while (actual != current)
//		{
//			next = XOR(prev, current->nextPrev);
//			prev = current;
//			current = next;
//		}
//		next = XOR(prev, current->nextPrev);
//		if (next == nullptr)
//		{
//			actual = head;
//		}
//		else
//		{
//			actual = next;
//		}
//		printf_s("%d\n", (actual)->data);
//	}
//
//
//
//	void print_list_forw()
//	{
//		node* current = head;
//		node* prev = nullptr;
//		node* next = nullptr;
//		while (current != nullptr)
//		{
//			printf_s("%d ", current->data);
//			next = XOR(prev, current->nextPrev);
//
//			prev = current;
//			current = next;
//		}
//		printf_s("\n");
//
//	}
//
//
//	void print_list_back()
//	{
//		node* current = tail;
//		node* prev = nullptr;
//		node* next = nullptr;
//		while (current != nullptr)
//		{
//			printf_s("%d ", current->data);
//			prev = XOR(next, current->nextPrev);
//
//			next = current;
//			current = prev;
//		}
//		printf_s("\n");
//	}
//
//	void print_queue()
//	{
//		node* current = tail;
//		node* prev = nullptr;
//		node* next = nullptr;
//		while (current != front)
//		{
//			next = XOR(prev, current->nextPrev);
//			prev = current;
//			current = next;
//			if (current == nullptr && current != back)
//			{
//				current = tail;
//				prev = nullptr;
//			}
//		}
//		while (current != back)
//		{
//			printf_s("%d ", current->data);
//			next = XOR(prev, current->nextPrev);
//
//			prev = current;
//			current = next;
//			if (current == nullptr && current != back)
//			{
//				current = tail;
//				prev = nullptr;
//			}
//		}
//		printf_s("%d ", current->data);
//		printf_s("\n");
//	}
//
//
//
//	~List()
//	{
//		node* current = head;
//		node* prev = nullptr;
//		node* next = nullptr;
//		bool del = false;
//		while (current != nullptr)
//		{
//			next = XOR(prev, current->nextPrev);
//
//			prev = current;
//			current = next;
//			if (del == true) {
//				free(XOR(next, prev->nextPrev));
//			}
//			del = true;
//		}
//		if (current != nullptr)
//		{
//			free(prev);
//		}
//		if (head == tail)//if only one item is in list
//		{
//			free(head);
//		}
//		head = tail = nullptr;
//	}
//
//
//};
//
//int main()
//{
//	List list;
//
//	char option[SIZE];
//	int data;
//
//	while (cin >> option)
//	{
//		bool in_queue = false;
//		if (strcmp(option, "ACTUAL") == false)
//		{
//			if (list.actual == nullptr)
//			{
//				printf_s("NULL\n");
//			}
//			else
//			{
//				printf_s("%d\n", list.actual->data);
//			}
//		}
//		else if (strcmp(option, "PREV") == false)
//		{
//			if (list.head == nullptr)
//			{
//				printf_s("NULL\n");
//			}
//			else
//				list.prev();
//		}
//		else if (strcmp(option, "NEXT") == false)
//		{
//			if (list.head == nullptr)
//			{
//				printf_s("NULL\n");
//			}
//			else
//				list.next();
//		}
//		else if (strcmp(option, "ADD_BEG") == false)
//		{
//			scanf_s("%d", &data);
//			list.insert_at_beg(data, in_queue);
//		}
//		else if (strcmp(option, "ADD_END") == false)
//		{
//			scanf_s("%d", &data);
//			list.insert_at_end(data);
//		}
//		else if (strcmp(option, "ADD_ACT") == false)
//		{
//			scanf_s("%d", &data);
//			list.insert_b4_act(data, in_queue);
//		}
//		else if (strcmp(option, "PUSH") == false)
//		{
//			scanf_s("%d", &data);
//			in_queue = true;
//			list.push(data, in_queue);
//		}
//		else if (strcmp(option, "POP") == false)
//		{
//			list.pop();
//		}
//		else if (strcmp(option, "DEL_BEG") == false)
//		{
//			list.del_at_beg();
//		}
//		else if (strcmp(option, "DEL_END") == false)
//		{
//			list.del_at_end();
//		}
//		else if (strcmp(option, "DEL_VAL") == false)
//		{
//			scanf_s("%d", &data);
//			list.del_val(data);
//		}
//		else if (strcmp(option, "DEL_ACT") == false)
//		{
//			list.del_act();
//		}
//		else if (strcmp(option, "GARBAGE_SOFT") == false)
//		{
//			list.garbage_soft();
//		}
//		else if (strcmp(option, "GARBAGE_HARD") == false)
//		{
//			list.garbage_hard();
//		}
//		else if (strcmp(option, "SIZE") == false)
//		{
//			printf_s("%lu\n", list.size);
//		}
//		else if (strcmp(option, "COUNT") == false)
//		{
//			printf_s("%lu\n", list.count);
//		}
//		else if (strcmp(option, "PRINT_FORWARD") == false)
//		{
//			if (list.head == nullptr)
//			{
//				printf_s("NULL\n");
//			}
//			else
//			{
//				list.print_list_forw();
//			}
//		}
//		else if (strcmp(option, "PRINT_BACKWARD") == false)
//		{
//			if (list.head == nullptr)
//			{
//				printf_s("NULL\n");
//			}
//			else
//				list.print_list_back();
//		}
//		else if (strcmp(option, "PRINT_QUEUE") == false)
//		{
//
//			if (list.front == nullptr)
//			{
//				printf_s("NULL\n");
//			}
//			else
//				list.print_queue();
//		}
//	}
//
//
//	return 0;
//}
