#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
typedef struct Node {
 int data;
 struct Node *next;
}Node,*LinkList;

Node *CreateLoopLinkList(int n){
    Node *head=(Node*)malloc(sizeof(Node));
    head->data=1;
    head->next=NULL;
    Node*tail=head;
    int i;
    for(i=1;i<n;i++){
        Node *individual=(Node*)malloc(sizeof(Node));
        individual->data=i+1;
        individual->next=NULL;
        tail->next=individual;
        tail=tail->next;
    }
    tail->next=head;
    return head;
}

void Josephus(Node*head,int m){
    Node*tail=head;
    while (tail->next!=head) {
        tail=tail->next;
    }
    while (head->next!=head) {
        for (int i=1; i<m; i++) {
            tail=head;
            head=head->next;
        }
        tail->next=head->next;//从链表上将p结点摘下来
        printf("出列人的编号为:%d\n",head->data);
        free(head);
        head=tail->next;
    }
    printf("出列人的编号为:%d\n",head->data);
free(head);
}


int main(){
    printf("输入人数n:");
    int n;
//    scanf("%d",&n);
    n = 12000;
    Node *head=CreateLoopLinkList(n);
    printf("数到m的人出列：");
    int m;
    srand(time(0));
    m=rand()%50;
    printf("%d",m);
    Josephus(head,m);
    return 0;
}
