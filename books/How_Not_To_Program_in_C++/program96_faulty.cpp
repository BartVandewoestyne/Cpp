// TODO: find a nice way to fix this.
/************************************************
 * simple linked list test.                     *
 ************************************************/
#include <iostream>
#include <malloc.h>
#include <string>
/************************************************
 * list -- Linked list class.                   *
 *      Stores a pointer to void so you can     *
 *      stick any data you want to in it.       *
 *                                              *
 * Member functions:                            *
 *      clear -- clear the list                 *
 *      add_node -- Add an item to the list     *
 ************************************************/
class list {
    private:
        /*
         * Node -- A node in the linked list
         */
        class node {
            private:
                // Data for this node
                void *data;

                // Pointer to next node
                class node *next;

                // List class does the work
                friend class list;
                // Constructor defaults
                // Destructor defaults

                // No copy constructor
                node(const node &);

                // No assignment operator
                node &operator = (const node &);
            public:
                node(void) :
                   data(NULL), next(NULL) {}
        };
        //--------------------------------------

        node *first;    // First node in the list

        /*
         * Delete the data for the node.
         * Because we don't know what type of
         * data we have, the derived class does
         * the work of deleting the data
         * through the delete_data function.
         */
        virtual void delete_data(void *data) = 0;
    public:
        // Delete all the data in the list
        void clear(void) {
            while (first != NULL)
            {
                // Pointer to the next node
                class node *next;

                next = first->next;
                delete_data(first->data);
                delete first;
                first = next;
            }
        }

        // Constructor
        list(void): first(NULL) {};

        // Destructor. Delete all data
        virtual ~list(void) {
            clear();
        }

        // Add a node to the list
        void add_node(
            void *data  // Data to be added
        ) {
            class node *new_node;

            new_node = new node;
            new_node->data = data;
            new_node->next = first;
            first = new_node;
        }
};
/************************************************
 * string_list -- A linked list containing      *
 *      strings.                                *
 *                                              *
 * Uses the list class to provide a linked list *
 * of strings.                                  *
 *                                              *
 * Member functions:                            *
 *      add_node -- Adds a node to the list.    *
 ************************************************/
class string_list : private list
{
    private:
        // Delete a node
        void delete_data(
            void *data           // Data to delete
        ) {
            free(data);
            data = NULL;
        }
    public:
        // Add a new node to the list
        void add_node(
            // String to add
            const char *const data
        ) {
            list::add_node((void *)strdup(data));
        }
};

int main()
{
    // List to test things with
    string_list *the_list = new string_list;

    the_list->add_node("Hello");
    the_list->add_node("World");

    delete the_list;
    the_list = NULL;
    return (0);
}
