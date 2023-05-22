#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef int element;
typedef struct ListNode //노드 타입 구조체로 정의
{
	element data;
	struct ListNode* link;
}ListNode;

void error(char* message);
ListNode* insert_first(ListNode* head, element value);
ListNode* insert(ListNode* head, ListNode* pre, element value);
ListNode* delete_first(ListNode* head);
ListNode* delete(ListNode* head, ListNode* pre);
void print_list(ListNode* head);

int main(void)
/*{
ListNode *head = NULL;
for (int i = 0; i < 5; i++) {
head = insert_first(head, i);
print_list(head);
}
for (int i = 0; i < 5; i++) {
head = delete_first(head);
print_list(head);
}
return 0;*/
{
	ListNode* list = NULL;
	int num, num2, pos = 0;
	while (1)
	{
		printf("\n====Menu====\n");
		printf("(1) Insert\n");
		printf("(2) Delete\n");
		printf("(3) Print\n");
		printf("(0) Exit\n");
		printf("Enter the menu: ");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			printf("Enter the number and position: ");
			scanf("%d %d", &num2, &pos);

			if (is_empty(list) && pos != 0)
			{
				error("List is empty. Insert at position 0.\n");
			}

			else if (is_empty(list) && pos == 0)
			{
				list = insert_first(list, num2);
			}

			else
			{
				list = insert(list, pos, num2);
			}

			break;

		case 2:
			if (is_empty(list))
			{
				error("List is empty.");
			}
			else
				scanf("%d, %d", &pos);
			delete(&list, pos);
			break;

		case 3:
			print_list(list);
			break;

		case 0:
			exit(0);
			break;

		default:
			error("Invalid Menu. Please select again.");
		}

	}

}


void error(char* message)
{
	fprintf(stderr, "%s\n", message);
}
/*ListNode* list_create(ListNode* head)
{
	ListNode* head = NULL; //노드를 가리키는 포인터 head 정의(연결리스트 생성)
					   //아직 연결이 안되었으므로 NULL
					   //리스트가 공백인지 검사하려면 head의 값이 NULL인지 검사하면 됨

//노드 생성
	head = (ListNode*)malloc(sizeof(ListNode)); //head가 새로운 node를 가리키고 있음
	//동적메모리의 주소를 head에 저장

	ListNode* p;
	p->data = 20;
	p->link = NULL;
	head->data = 10;
	head->link = p;
}*/

ListNode* insert_first(ListNode* head, element value)
{
	//새로운 리스트노드 p를 만든 후, p->data에 value집어넣기
	//  head->link의 값을 p->link에 집어넣음
	//p의 주소를 head->link에 집어넣음
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p;
	return head;
}

ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link;
	pre->link = p;
	return head;
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}

ListNode* delete(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;;
	free(removed);
	return head;
}

void print_list(ListNode* head)
{

	ListNode* p;

	for (p = head; p != NULL; p = p->link)
	{
		printf("%d->", p->data);
	}
	printf("NULL\n");
}

int is_empty(ListNode* head)
{
	return head == NULL;
}
