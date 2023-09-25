/*
    @file       :   single_linked_list.c
    @brief      :   This module has all the function what we will need to use the linked list
    @details    :   This program is to store data of employees using linked list
    @author     :   Silvana Karim Fayez Asaad    
*/

#include "single_linked_list.h"

/*
    @brief  :   This function is to create the linked list in heap memory
    @param  :   Non "Void"
    @return :   Pointer to the linked list (Address of linked list)
*/

sll_t* create_sll () { 
    
    //Create linked list in heap memory
    sll_t* list = (sll_t*) calloc ( 1, sizeof(sll_t) ) ; 

    //check if the dynamid memory allocation is done or not
    if (list==NULL) { 
        printf ("Dynamic memory allocation failed! \n");
        return NULL;  
    }

    //Initialize head and size of the linked list
    list->head = NULL ; 
    list->size = 0 ; 

    //Return the address of the linked list to point to it 
    return list; 

}


/*
    @brief  :   This function is to create node (has data and next) in heap memory
    @param  :   pointer to struct which has the data to added in node in linked list
    @return :   Pointer to the node (Address of node)
*/

node_t* create_sll_node (data_t* value)  { 

    //Creating node in the heap memory
    node_t* new_node = (node_t*) calloc ( 1, sizeof(node_t) ) ; 

    //Check if the dynamic memory allocation of the node is done or not
    if (new_node==NULL) { 
        printf("Dynamic memory allocation failed!\n");
        return NULL; 
    }

    //Put sent data of the employee in the new node 
    new_node->data = value ; 
    new_node->next = NULL; 

    //Return the address of the new node to point to it 
    return new_node; 

}


/*
    @brief  :   This function is to free linked list and remove it from the heap memory
    @param  :   pointer to linked list which we need to remove and free
    @return :   Non "Void"
*/

void free_sll_list (sll_t* list) { 

    //If the sent pointer is equal null, so there is no list to remove
    if (list==NULL) { 
        return; 
    }

    //If head == null, this is an empty list and there is no list to remove
    if (list->head==NULL) { 
        return; 
    }

    //Make a current pointer to can move on all nodes and assume that it at the first of linked list
    node_t* current = list->head ; 

    //Loop on all nodes of the linked list to remove each node and decrease the size
    while(current!=NULL) { 
        list->head = list->head->next; 
        free(current) ; 
        current = list->head ; 
        list->size-- ; 
    }
    
    //After while loop, all nodes are free so now we can free the linked list 
    free(list) ; 

} 


/*
    @brief  :   This function is to append a new node in the last of the linked list 
    @param  :   pointer to the linked list and pointer to struct which has data to add in the linked list
    @return :   status to show if the appending process is done or not
*/

sll_status_t append_sll_node (sll_t* list, data_t* value) { 

    //To check if the sent pointer is equal null, so we can not append a node 
    if(list==NULL) { 
        return SLL_NULL_POINTER; 
    }
    
    //To append a new node, we need to create a new node and take its address 
    node_t* new_node = create_sll_node (value) ; 

    //Check if the new node is created or not 
    if (new_node==NULL) { 
        return SLL_NODE_NOT_CREATED ; 
    }

    //If the list is empty, so the appended node must be the first node 
    if (list->head==NULL) { 
        list->head = new_node ; 
    }

    else { 
        node_t* current = list->head; 

        while (current->next != NULL) { 
            current = current->next;  
        }

        //After looping, current now pointing to last element in the linked list
        current->next = new_node ; 
    }

    //Increasing size because we add new node 
    list->size ++ ; 

    return SLL_OK; 

}


/*
    @brief  :   This function is to print the data of any employee
    @param  :   pointer to struct which has data to print
    @return :   Non "Void"
*/

void print_struct (data_t* value) {

    printf("\nName: %sAge: %d\nSalary: %.2f\nTitle: %sID: %d\n", 
    value->name, value->age, value->salary, value->title, value->id);
    printf("\n");

}


/*
    @brief  :   This function is to display the data of all employees in the linked list
    @param  :   pointer to the linked list to show all data 
    @return :   status to show if the showing process is done or not
*/

sll_status_t display_sll_list (sll_t* list) { 

    //If pointer is equal null, so there is no list to display
    if (list==NULL) { 
        return SLL_NULL_POINTER ; 
    }

    //If the linked list is empty, so there is no data to view in the linked list 
    if (list->head==NULL) { 
        return SLL_EMPTY; 
    }

    //Make a cuurent pointer to loop on each element in the linked list 
    node_t* current = list->head;

    //Loop on the linked list to print data of each node in the linked list 
    while(current!=NULL) { 
        print_struct(current->data) ; 
        current = current->next;
    }

    printf("\n"); 

    return SLL_OK; 

}


/*
    @brief  :   This function is to take an ID and search for it in the linked list
    @param  :   pointer to the linked list and ID of the employee which we need to found
    @return :   Pointer to node which has the needed ID
*/

node_t* search_sll_node (sll_t* list, int id_to_search) { 

    //If the point equal null, so there is no list to search for ID
    if (list==NULL) { 
        return NULL ; 
    }

    //If linked list is empty so there is no data to search for ID
    if (list->head==NULL) { 
        return NULL; 
    }

    node_t* current = list->head ; 

    while(current!=NULL) { 

        if (current->data->id == id_to_search) { 
            return current; 
        }

        current = current->next; 
    }

    /*If while loop end without return, so we did not found the needed ID
    and we need to return null because there is no node has this ID*/  
    return NULL ; 

}


/*
    @brief  :   This function is to take a new ID and put it instead of old ID for certian employee
    @param  :   pointer to the linked list, old ID and new ID
    @return :   status to show if the modifying process is done or not
*/

sll_status_t modify_ID_in_sll (sll_t* list, int old_id, int new_id)  { 

    //If pointer equal null, so there is no list to modify
    if (list==NULL) { 
        return SLL_NULL_POINTER; 
    }

    //If list is empty, there is no data to modify
    if (list->head==NULL) { 
        return SLL_EMPTY; 
    }

    //To modify, we must get the address of the node which has the nedded ID
    node_t* found_node = search_sll_node(list, old_id) ; 

    //Check if there is a node with this ID or not 
    if (found_node==NULL) { 
        return SLL_NODE_NOT_FOUND;
    }

    //Put new ID instead Of old ID
    found_node->data->id = new_id ;

    return SLL_OK;

}


/*
    @brief  :   This function is to delete certian employee determined by his ID
    @param  :   pointer to the linked list and ID of the employee which we need to delete
    @return :   status to show if the removing process is done or not
*/

sll_status_t delete_sll_node_by_value (sll_t* list, int required_ID) { 

    //If pointer equal null, so there is no list to delete employee
    if (list==NULL) { 
        return SLL_NULL_POINTER;
    }

    //If the list is null, so there is no employee data to delete 
    if (list->head==NULL) { 
        return SLL_EMPTY;
    }

    node_t* current = list->head, *prev; 

    //If required ID at the head node
    if(list->head->data->id == required_ID) { 
        list->head = list->head->next; 
        free(current);
        list->size--;
        return SLL_OK;  
    }
    
    //Here, required ID is not at the first of the list 
    while (current!=NULL) {
        if (current->data->id == required_ID) {
            //we found the required ID
            break ; 
        }
        prev = current ; 
        current = current->next; 
    }

    /*Now, we have two options:
    1- Current is at the end of the linked list */ 
    if (current==NULL) { 
        return SLL_NODE_NOT_FOUND; 
    }

    // 2- current is at the node which we need to delete 
    prev->next = current->next; 
    free(current); 
    list->size--; 

    return SLL_OK;

}

