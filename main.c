/*
    @file       :   main.c
    @brief      :   This module has main function of the program
    @details    :   This program is to store data of employees using linked list
    @author     :   Silvana Karim Fayez Asaad    
*/

#include "needed_functions.h"

/*********************** Main Program Section ******************/

int main()
{
    //Creating a linked list for employees
    sll_t *employees_linked_list = creating_linked_list();

    //Creating a dynamic array to store the data of the employees
    data_t *employees_arr = NULL ;
    
    show_list_of_operations(employees_linked_list, employees_arr);

    //Free Heap memory
    free(employees_arr);
    employees_arr = NULL;
    free_sll_list(employees_linked_list);

    return 0 ; 
    
}

/**************************************************************/

