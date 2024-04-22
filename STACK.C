#include <stdio.h>
#include <stdlib.h>

//Function Declaration
void push(int);
int  pop();
int  peek();
void display();

//Node structure 
struct node
{
  int data;
  struct node* next;
};

//Stack pointer is empty initially,so assigned to NULL
struct node* top = NULL;

void main() 
{
  int value;
  printf("\n\n***Stack Implementation using singly linked list***\n\n");
  
  while(1)
  {
    printf("\nEnter the choice:");
    scanf("%d",&value);
    switch(value)
    {
      case 1:
        printf("Enter the value to push into Stack:");
        scanf("%d", &value);
        push(value);
        break;
        
      case 2:
        pop();
        break;
      
      case 3:
        peek();
        break;
      
      case 4:
        printf("Displaying All the stack element:\n");
        display();
        break;
      
      default:
        printf("Please Enter the Correct Choice...\n");
        break;
    }
  }
  
}

void push(int data)
{
  //Creating a new node
  struct node* new_node =(struct node*)malloc(sizeof(struct node));
  
  if(new_node != NULL)
  {
    //Update the data
    new_node->data = data;
    
    if(top == NULL)
    {
      new_node->next = NULL;
    }
    else
    {
      new_node->next = top; 
    }
    
    //Update the top
    top = new_node;
    
    printf("New element inserted in Stack, Value :%d\n", new_node->data);
  }
  else
  {
    printf("Push : Malloc Error\n");
  }
}

int pop()
{
  int data = 0;
  
  //Checking whether the stack is underflow or not 
  if(top == NULL)
  {
    printf("Stack is Empty : Stack Underflow\n");
  }
  else
  {
    struct node* temp = top;
    data = top->data;
    top  = top->next;
    free(temp);
    printf("The popped value is:%d\n", data);
  }
  
  return( data );
}

int peek()
{
  int data = 0;
  
  if(top == NULL)
  {
    printf("Stack is Empty\n");
  }
  else
  {
    data = top->data;
    printf("The top node value is:%d\n",data);
  }
  
  return( data );
}

void display()
{
  if(top == NULL)
  {
    printf("Stack is Empty\n");
  }
  else
  {
    struct node *temp = top;
    while(temp->next != NULL) 
    {
      printf("%d-->", temp->data);
      temp = temp->next;
    }
    printf("%d-->NULL\n", temp->data);
  }
}