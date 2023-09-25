/*
    @file       :   single_linked_list.h
    @brief      :   This module has the declaration of all functions that we need in using linked list
    @details    :   This program is to store data of employees using linked list
    @author     :   Silvana Karim Fayez Asaad    
*/

/****************************** File Guard *************************/
#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H
/*****************************************************************/

/***************************** Link Section ********************/
#include <stdio.h>
#include <stdlib.h>
/*************************************************************/

/********************* Global declaration section ******************/

//Struct of the employee includes all data of each employee
typedef struct employee_data{
    char name[40];
    int age;
    float salary;
    char title[50];
    int id;
} data_t; 

//Struct of the node includes all data of each node in the single linked list
typedef struct node {
    data_t* data ; 
    struct node* next; 
} node_t ; 

//Struct of the linked list includes all data of the single linked list
typedef struct single_linked_list { 
    node_t* head ; 
    unsigned int size ; 
} sll_t ; 

//Enum to display all the possible status for the linked list
typedef enum sll_status { 
    SLL_EMPTY,
    SLL_NULL_POINTER,
    SLL_NODE_NOT_CREATED, 
    SLL_OK, 
    SLL_NODE_NOT_FOUND,
    SLL_INVALID_POSITION,
    SLL_NOT_OK,
    APPEND_FLAG
} sll_status_t ; 

/****************************************************************************/

/********************** User Define Functions Section **********************/

//Function to create linked list and return its address
sll_t* create_sll () ; 

//Function to create node to be added in the linked list
node_t* create_sll_node (data_t* value) ; 

//Function to remove linked list from the heap memory
void free_sll_list (sll_t* list) ; 

//Function to print all data of each employee
void print_struct (data_t* value) ;

//Function to append node at the last of the linked list
sll_status_t append_sll_node (sll_t* list, data_t* value) ; 

//Function to display all data in all nodes of the linked list
sll_status_t display_sll_list (sll_t* list); 

//Function to take certian ID and serach for this ID in all nodes of linked list
node_t* search_sll_node (sll_t* list, int id_to_search) ;

//Function to take Modify certian ID in linked list with a new ID
sll_status_t modify_ID_in_sll (sll_t* list, int old_id, int new_id)  ;

//Function to delete certian node in linked list (determined by ID)
sll_status_t delete_sll_node_by_value (sll_t* list, int required_ID) ; 

/************************************************************************/

#endif