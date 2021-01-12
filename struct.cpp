#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node
{
    char name[255];
    int score;
    Node *next; // menunjuk ke node selanjutnya
} *head, *tail; // global variable
// head: awal node
// tail: akhir node

Node *createNode(const char *name, int score){
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name,name);
    newNode->score=score;
    newNode->next=NULL;
    return newNode; 
}

void pushHead(const char *name, int score){
    Node *temp=createNode(name,score); //buat nodenya
    if(!head){ //jika tidak ada head
        head = temp; // head = tail = temp
        tail = temp; 
    }else{ //jika ada head
        temp->next=head; // node menunjuk ke head yang lama
        head=temp; // node akan menjadi head yang baru
    }
}

void pushTail(const char *name, int score){
    Node *temp=createNode(name,score); //buat nodenya
    if(!head){ //jika tidak ada head
        tail = temp; // head = tail = temp
        head = temp; 
    }else{ //jika ada head
        tail->next=temp; // node menunjuk ke tail yang lama
        tail=temp; // node akan menjadi tail yang baru
    }
}

void popHead(){
    if(!head){
        return;
    }else if(head==tail){
        free(head);
        head=tail=NULL;
    }else{
        Node *temp = head->next;
        free(head);
        head=temp;
    }
}

void popTail(){
    if(!head){
        return;
    }else if(head==tail){
        free(head);
        head=tail=NULL;
    }else{
        Node *temp = head;
        while(temp->next != tail){
            temp=temp->next; // jalan terus
        }
        temp->next=NULL;
        free(tail);
        tail=temp;
    }
} 

void printList(){
    Node *curr=head;
    while(curr){
        printf("%s %d -> ",curr->name,curr->score);
        curr=curr->next;
    }
    puts("NULL");
}

int main(){
    pushHead("Anjing",100);
    pushTail("Monyet",95);
    pushHead("Kuning",75);
    printList();
    return 0;
}