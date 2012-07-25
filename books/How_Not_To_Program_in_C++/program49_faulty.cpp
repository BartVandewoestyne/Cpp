#include <iostream>
#include <string>
/************************************************
 * linked_list -- Class to handle a linked list *
 *              containing a list of strings.   *
 *                                              *
 * Member functions:                            *
 *      add -- Add an item to the list          *
 *      is_in -- Check to see if a string is    *
 *                      in the list.            *
 ************************************************/
class linked_list {
    private:
        /*
         * Node in the list
         */
        struct node {
            // String in this node
            std::string data;

            // Pointer to next node
            struct node *next;
        };
        //First item in the list
        struct node *first;
    public:
        // Constructor
        linked_list(void): first(NULL) {};
        // Destructor
        ~linked_list();
    private:
        // No copy constructor
        linked_list(const linked_list &);

        // No assignment operator
        linked_list& operator = (const linked_list &);
    public:
        // Add an item to the list
        void add(
            // Item to add
            const std::string &what
        ) {
            // Create a node to add
            struct node *new_ptr = new node;

            // Add the node
            new_ptr->next = first;
            new_ptr->data = what;
            first = new_ptr;
        }
        bool is_in(const std::string &what);
};
/************************************************
 * is_in -- see if a string is in a             *
 *      linked list.                            *
 *                                              *
 * Returns true if string's on the list,        *
 *              otherwise false.                *
 ************************************************/
bool linked_list::is_in(
    // String to check for
    const std::string &what
) {
    /* current structure we are looking at */
    struct node *current_ptr;

    current_ptr = first;

    while (current_ptr != NULL) {
        if (current_ptr->data == what)
            return (true);

        current_ptr = current_ptr->next;
    }
    return (false);
}

/************************************************
 * linked_list::~linked_list -- Delete the      *
 *      data in the linked list.                *
 ************************************************/
linked_list::~linked_list(void) {
    while (first != NULL) {
        delete first;
        first = first->next;
    }
}

int main() {
    linked_list list;   // A list to play with

    list.add("Sam");
    list.add("Joe");
    list.add("Mac");

    if (list.is_in("Harry"))
        std::cout << "Harry is on the list\n";
    else
        std::cout << "Could not find Harry\n";
    return (0);
}
