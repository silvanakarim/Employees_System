/*
    @file       :   needed_functions.c
    @brief      :   This module has all functions that we will need in main.c
    @details    :   This program is to store data of employees using linked list
    @author     :   Silvana Karim Fayez Asaad
*/

#include "needed_functions.h"

/*
    @brief  :   This function is to call function of creating linked list
    @param  :   Non "Void"
    @return :   Pointer to the new created linked list
*/

sll_t *creating_linked_list()
{
    sll_t *employees_list = create_sll();

    // Check if the list is created or not
    if (employees_list == NULL)
    {
        printf("Creating linked list failed!\n");
        exit(0);
    }

    // Return the address of the new linked lis
    return employees_list;
}

/*
    @brief  :   This function is to show list of operation to make the user choose number
                of operation which he need, This will be continously until user choose exit.
    @param  :   pointer to linked list and pointer to array of struct of empolyees
    @return :   Non "Void"
*/

void show_list_of_operations(sll_t *list, data_t *employees_arr)
{
    /*List of operation must appear continuously until user choose exit,
    we use do-while because we don't know number of iterations */
    do
    {
        printf("Press the number of the operation you need\n");
        printf(" 1 --> Add a new employee data\n");
        printf(" 2 --> Delete the data of an employee \n");
        printf(" 3 --> Modify the data of an employee\n");
        printf(" 4 --> View the data of an employee \n");
        printf(" 5 --> View all the employee's data\n");
        printf(" 6 --> Exit \n");

        scanf("%d", &operation);

        switch_of_operations(operation, list, employees_arr);

    } while (operation != 6);
}

/*
    @brief  :   This function is to switch of the operations to make the suitable action
                for the number of operation which user has choosed
    @param  :   Number of operation which the user has choosed, pointer to linked list
                and pointer to the array of struct of employees.
    @return :   Non "Void"
*/

void switch_of_operations(int operation, sll_t *list, data_t *employees_arr)
{

    switch (operation)
    {

    case ADD_NEW_EMPLOYEE:

        /******************************* Add New Employee start ***************************************/

        printf("How many new empolyees would you enter? \n");

        // If the list is empty, so we must add this data at the first of the list
        if (list->head == NULL)
        {
            scanf("%u", &number_of_employees);

            // We start from index = 0 because we don't have old data in list
            start_index_of_employees_arr = 0;

            /*We need to create dynamic array with size of number of employess to make
            struct for each employee in the array and each employee has an
            index of this array*/
            employees_arr = (data_t *)calloc(number_of_employees, sizeof(data_t));
        }

        // User has already entered data before, so this data will not start from index zero
        else
        {
            scanf("%u", &number_of_extra_employees);
            start_index_of_employees_arr = number_of_employees;
            number_of_employees += number_of_extra_employees;

            // We already create the dynamic array before, so now we need to reallocate array
            data_t *temp = (data_t *)realloc(employees_arr, number_of_employees * sizeof(data_t));

            // Check if the dynamic reallocation is done or not
            if (temp == NULL)
            {
                printf("Dynamic memory reallocation failed!\n");
                exit(0);
            }

            else
            {
                employees_arr = temp;
            }
        }

        // Take data from the user for all employees in the dynamic array
        for (int i = start_index_of_employees_arr; i < number_of_employees; i++)
        {
            printf("\nPlease enter the data of employee number %d\n", i + 1);

            printf("Name: ");
            fflush(stdin);
            fgets(employees_arr[i].name, 150, stdin);

            printf("Age: ");
            scanf("%d", &employees_arr[i].age);

            printf("Salary: ");
            scanf("%f", &employees_arr[i].salary);

            printf("Title: ");
            fflush(stdin);
            fgets(employees_arr[i].title, 100, stdin);

            printf("ID: ");
            scanf("%d", &id_to_check_unique);

            //To check unique ID 
            while (search_sll_node(list, id_to_check_unique) != NULL)
            {
                // Here, this ID is already used before
                printf("\nYou entered this ID before! You must enter unique ID \n\n");
                printf("Please enter unique id\n");
                scanf("%d", &id_to_check_unique);
            }

            // After loop, ID is not used before, so we can take it
            employees_arr[i].id = id_to_check_unique;

            /*After taking all data of the employee from the user, append this employe
            to the linked list */
            append_sll_node(list, &employees_arr[i]);

        }

        printf("\nAdding data of %d employees is done!\n\n", number_of_employees - number_of_extra_employees);

        break;

        /******************************* Add New Employee end ***************************************/

    case DELETE_DATA_OF_EMPLOYEE:

        /******************************* Delete Employee start ***********************************/

        // If list is empty so there is no data for employees to delete
        if (list->head == NULL)
        {
            printf("\nYou must add data employee first! No data to delete!\n\n");
            break;
        }

        printf("Please enter ID of the employee which you need to delete \n");
        scanf("%d", &required_ID_to_delete);

        if (delete_sll_node_by_value(list, required_ID_to_delete) == SLL_OK)
        {
            printf("\nDeleting employee with ID %d is Done! \n\n", required_ID_to_delete);
        }

        else
        {
            printf("\nInvalid ID, please enter correct ID!\n\n");
        }

        break;

        /******************************* Delete Employee start ***********************************/

    case MODIFY_DATA_OF_EMPLOYEE:

        /******************************* Modify Employee start *********************************/

        // If list is empty, so there is no employees to modify his data
        if (list->head == NULL)
        {
            printf("\nYou must add data employee first! No data to modify\n\n");
            break;
        }

        printf("Please enter the ID of the employee which you need to modify \n");
        scanf("%d", &old_ID_to_modify);

        // First, we must check if the old ID is correct or not
        if (search_sll_node(list, old_ID_to_modify) != NULL)
        {
            // Here, we sure that old is correct so we can ask for the new ID
            printf("Enter the new ID\n");
            scanf("%d", &new_ID_after_modify);

            modify_ID_in_sll(list, old_ID_to_modify, new_ID_after_modify);

            printf("\nModifying data is done\n");
            printf("Employee with ID %d, has now new ID %d \n\n", old_ID_to_modify, new_ID_after_modify);
        }

        // Here, the old ID is incorrect, so we can't do the modifying
        else
        {
            printf("\nInvalid ID, please enter correct ID!\n\n");
        }

        break;

        /******************************* Modify Employee end *********************************/

    case VIEW_DATA_OF_EMPLOYEE:

        /******************************* View Employee Data start **************************/

        // If list is empty, so there is no data employee to view
        if (list->head == NULL)
        {
            printf("\nYou must add data first! No data to view\n\n");
            break;
        }

        printf("Please enter ID to view the employee's data \n");
        scanf("%d", &ID_to_view);

        struct_to_view_data = search_sll_node(list, ID_to_view);

        if (struct_to_view_data == NULL)
        {
            printf("\nID not Found! Please enter corret ID \n\n");
        }

        else
        {
            printf("\nData of employee with ID %d: \n\n", ID_to_view);
            print_struct(struct_to_view_data->data);
        }

        break;

        /******************************* View Employee Data end **************************/

    case VIEW_ALL_EMPLOYEES_DATA:

        // If the list is empty, so there is no employees data to view
        if (list->head == NULL)
        {
            printf("\nYou must add data first! No data to view\n\n");
            break;
        }

        display_sll_list(list);

        break;

    case EXIT:

        break;

    default:

        printf("\nPlease enter valid number of operation from 1 to 6 \n\n");
        break;
    }
}
