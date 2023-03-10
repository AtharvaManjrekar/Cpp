// 2.6 Write a function to delete an element into a Doubly  Circular Linked List
#include <iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
	struct Node* prev;
};
void insert(struct Node** start, int value)
{
	if (*start == NULL)
	{
		struct Node* new_node = new Node;
		new_node->data = value;
		new_node->next = new_node->prev = new_node;
		*start = new_node;
		return;
	}
	Node* last = (*start)->prev;
	struct Node* new_node = new Node;
	new_node->data = value;

	new_node->next = *start;

	(*start)->prev = new_node;

	new_node->prev = last;

	last->next = new_node;
}

void deleteNode(struct Node** start, int key)
{
	if (*start == NULL)
		return;

	struct Node *curr = *start, *prev_1 = NULL;
	while (curr->data != key)
	{
		if (curr->next == *start)
		{
			printf("\nlist doesn't have node with value = %d", key);
			return;
		}
		prev_1 = curr;
		curr = curr->next;
	}
	if (curr->next == *start && prev_1 == NULL)
	{
		(*start) = NULL;
		free(curr);
		return;
	}
	if (curr == *start)
	{
		prev_1 = (*start)->prev;
		*start = (*start)->next;
		prev_1->next = *start;
		(*start)->prev = prev_1;
		free(curr);
	}
	else if (curr->next == *start)
	{
		prev_1->next = *start;
		(*start)->prev = prev_1;
		free(curr);
	}
	else
	{
		struct Node* temp = curr->next;
		prev_1->next = temp;
		temp->prev = prev_1;
		free(curr);
	}
}

void print(struct Node* start)
{
	struct Node* temp = start;

	while (temp->next != start)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d ", temp->data);
}

int main()
{
	int n;
	struct Node* start = NULL;
	insert(&start, 4);
	insert(&start, 5);
	insert(&start, 6);
	insert(&start, 7);
	insert(&start, 8);

	printf("List Before Deletion: ");
	print(start);
	printf("\nEnter the data you want to delete : ");
	scanf("%d", &n);
	deleteNode(&start, n);
	printf("\nList After Deleting : ");
	print(start);

	return 0;
}