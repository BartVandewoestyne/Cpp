// TODO: implement this using a balanced binary tree instead of an unbalanced
//       one.

/************************************************
 * find_word -- find a word in the dictionary.  *
 *                                              *
 * Usage:                                       *
 *     find_word <word-start> [<word-start>...] *
 ************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include <cstdlib>

/************************************************
 * tree -- A simple binary tree class           *
 *                                              *
 * Member functions:                            *
 *      enter -- Add an entry to the tree       *
 *      find -- See if an entry is in the tree. *
 ************************************************/
class tree
{
    private:
        // The basic node of a tree
        class node {
            private:
                // tree to the right
                node    *right;

                // tree to the left
                node    *left;
            public:
                // data for this tree
                char    *data;

            public:
                node() :
                    right(NULL), left(NULL),
                    data(NULL) {}
                // Destructor defaults
            private:
                // No copy constructor
                node(const node &);

                // No assignment operator
                node & operator = (const node &);

            // Let tree manipulate our data
            friend class tree;

        };

        // the top of the tree
        node *root;

        // Enter a new node into a tree or
        // sub-tree
        void enter_one(
           // Node of sub-tree to look at
           node *&node,

           // Word to add
           const char *const data
        );

        // Find an item in the tree
        void find_one(
            // Prefix to search for
            const char start[],

            // Node to start search
            const node *const node,

            // Keep looking flag
            const bool look
        );
    public:
        tree(void) { root = NULL;}
        // Destructor defaults
    private:
        // No copy constructor
        tree(const tree &);

        // No assignment operator
        tree & operator = (const tree &);

    public:
        // Add a new data to our tree
        void enter(
            // Data to add
            const char *const data
        ) {
            enter_one(root, data);
        }

        // Find all words that start
        // with the given prefix
        void find(
            const char start[]  // Starting string
        )
        {
            find_one(start, root, true);
        }
};

/************************************************
 * tree::enter_one -- enter a data into         *
 *      the tree                                *
 ************************************************/
void tree::enter_one(
   node *&new_node,       // Sub-tree to look at
   const char *const data // Word to add
)
{
    int  result;        // result of strcmp

    // see if we have reached the end
    if (new_node == NULL) {
        new_node = new node;

        new_node->left = NULL;
        new_node->right = NULL;
        new_node->data = strdup(data);
    }

    result = strcmp(new_node->data, data);
    if (result == 0) {
        return;
    }

    if (result < 0)
        enter_one(new_node->right, data);
    else
        enter_one(new_node->left, data);
}

/************************************************
 * tree::find_one -- find words that match this *
 *                      one in the tree.        *
 ************************************************/
void tree::find_one(
        const char start[],   // Start of the work
        const node *const top,// Top node
        const bool look       // Keep looking
)
{
    if (top == NULL)
        return;                 // short tree

    // Result of checking our prefix
    // against the word
    int cmp = strncmp(start,
            top->data, strlen(start));

    if ((cmp < 0) && (look))
        find_one(start, top->left, true);
    else if ((cmp > 0) && (look))
        find_one(start, top->right, true);

    if (cmp != 0)
        return;

    /*
     * We found a string that starts this one.
     * Keep searching and print things.
     */
    find_one(start, top->left, false);
    std::cout << top->data << '\n';
    find_one(start, top->right, false);
}

int main(int argc, char *argv[])
{
    // A tree to hold a set of words
    tree dict_tree;

    // The dictionary to search
    std::ifstream dict_file("/usr/share/dict/words");

    if (dict_file.bad()) {
        std::cerr <<
            "Error: Unable to open "
            "dictionary file\n";
        exit (8);
    }

    /*
     * Read the dictionary and construct the tree
     */
    while (1) {
        char line[100]; // Line from the file

        dict_file.getline(line, sizeof(line));

        if (dict_file.eof())
            break;

        dict_tree.enter(strdup(line));
    }
    /*
     * Search for each word
     */
    while (argc > 1) {
        std::cout << "------ " << argv[1] << '\n';
        dict_tree.find(argv[1]);
        ++argv;
        --argc;
    }
    return (0);
}
