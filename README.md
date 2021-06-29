# XOR-linked-list
Implementation of a bidirectional list using XOR. 
The task is based on implement a bidirectional list. 
A classic bidirectional list stores successor and predecessor addresses in nodes. Doubly Linked List vs. XOR linked list
In our task the list stores only xor of these addresses in nodes. This
saves approximately 50% of memory used by the list structure.Adding elements to list (at begin or end)
• ADD_BEG N - adding an element with value N to the beginning of the list.
• ADD_END N - adding an element with value N to the end of the list.
• ADD_ACT N - adding an element with the value of N as a predecessor of the currently selected
item (ACTUAL) .NEXT, PREV, ACTUAL commands
• ACTUAL - value of the currently pointed element. For an empty list it is NULL and after adding the
first node to the list ACTUAL returns the value of that element as long as it is not moved by other
operations.
• NEXT - prints the value of the ACTUAL successor setting it ACTUAL at the same time. If ACTUAL
points to the last element of the queue, its successor will be the first element of the queue.
• PREV - prints the value of the predecessor ACTUAL setting it ACTUAL at the same time. If ACTUAL
points to the first element of a queue, its predecessor will be the last element of the queue.
• PRINT_FORWARD - prints the contents of the list from the first to the last element.
• PRINT_BACKWARD - prints the contents of the list from the last to the first element.
PRINT_FORWARD - 3 4 1 2
PRINT_BACKWARD - 2 1 4 3Deleting elements from list (at begin or end)
• DEL_BEG - removes the first node from the list.
• DEL_END - removes the last node from the list.
• DEL_VAL N - removes from the list all nodes whose value is equal to N.
• DEL_ACT - removes from the list the node that ACTUAL points to, simultaneously setting ACTUAL
is PREV. In the case of the PREV does not exist (ACTUAL was the first element of the list) ACTUAL
shows the last element of the list.
• DEL_BEG, DEL_END, DEL_VAL, and DEL_ACT commands for an empty list do not
remove anything.
• In each of these cases, removing the currently pointed element (ACTUAL
command) should result in moving the currently pointed element pointer to the
preceding element, and if it does not exist, to the last element of the list.


# List-based FIFO queue

The task is based on implement a FIFO queue based on a Circular
Linked list. It can be also a classic Linked list, non-circular but pop and
push operations must detect the end of the list and return to its
beginning. It can also be a Doubly Linked List, but since the front and
back of the queue always follow in one direction, the prev pointers will
not be used.Push element to FIFO
• PUSH N - add element N to the end of the queue. Push element to FIFO
• PUSH N - add element N to the end of the queue. Pop element from FIFO
• POP - remove the first element from the queue.Empty FIFO
• After creating the queue, both the list and the queue are empty and the front and back pointers
are set to nullptr.
• Before the first element is pushed to the queue, a new element should be added to the list (as
part of the PUSH N command), creating space for a new element of the queue.
• After the first element is added to the queue, the first and back pointers indicate the added
element, everything seems to look good.Empty FIFO
• But what if we want to pop from the queue just pushed element?
• After the last element of the queue is popped, the pointers cannot be moved, so you have to
otherwise remember that the queue is empty, e.g. using an additional logical variable or assign
the nulptr value to the front pointer (or both front and back) .Empty FIFO
• When adding another element using the PUSH N command (in the case of a full list, when the
front pointer indicate the successor of the back pointer), you need to enlarge the list by 1 item,
adding a new element as a successor of the back pointer.Empty FIFO
• Move forward the front pointer after removing the element item from FIFO, or not? Empty FIFO
• In the second case, we will have to update one of both pointers during removing element from 2-
element list and during opposite operation (adding second item to a 1-element list).
• In the first case, the interpretation of pointers is clear, in the second, it depends on the number of
items in the queue.
• PRINT_QUEUE - Prints all elements starting with front and ending with back.
• When front and back indicate to the same element, it is printed when isEmpty variable contains
the value of false.
• GARBAGE_SOFT - Change the values of all elements of the list that do not belong to the queue to 0.
• GARBAGE_HARD - Remove all elements from the list that does not belong to the queue
