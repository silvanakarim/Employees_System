/*
    @file       :   needed_functions.h
    @brief      :   This module has the declaration of all functions that we will need in main.c
    @details    :   This program is to store data of employees using linked list
    @author     :   Silvana Karim Fayez Asaad    
*/

/****************************** File Guard *************************/
#ifndef NEEDED_FUNCTIONS_H
#define NEEDED_FUNCTIONS_H
/*****************************************************************/

/***************************** Link Section ********************/
#include "single_linked_list.h"
#include <string.h>
#include <conio.h>
/*************************************************************/

/********************* Global declaration section ******************/

// Enum to check the operation which the user choosed
typedef enum operations
{
    ADD_NEW_EMPLOYEE = 1,
    DELETE_DATA_OF_EMPLOYEE,
    MODIFY_DATA_OF_EMPLOYEE,
    VIEW_DATA_OF_EMPLOYEE,
    VIEW_ALL_EMPLOYEES_DATA,
    EXIT
} operations_t;

// Declaration of all variables
int operation, id_to_check_unique;
int required_ID_to_delete, old_ID_to_modify, new_ID_after_modify, ID_to_view;
int start_index_of_employees_arr;
unsigned int number_of_employees, number_of_extra_employees;
node_t *struct_to_view_data;

/****************************************************************************/

/********************** User Define Functions Section **********************/

//Function to call the function of creating linked list
sll_t *creating_linked_list();

//Function to show all operations to make the user choose what operation he need
void show_list_of_operations(sll_t *list, data_t *employees_arr);

//Function to switch of operations and make the suitable action for each operation
void switch_of_operations(int operation, sll_t *list, data_t *employees_arr);

/************************************************************************/

#endif