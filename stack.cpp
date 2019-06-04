#include <iostream>

template <typename TYPE>
class stack
{
public:
    struct stack_struct
    {
        TYPE element;
        struct stack_struct * next_element;
    };

    stack_struct * main_struct;
public:
    stack(TYPE first_element);

    void push(TYPE new_element);

    TYPE pop();

    unsigned int size();

    void show_stack();

    ~stack();
};

using namespace std;

template <typename TYPE>
stack<TYPE>::stack(TYPE first_element)
{
    main_struct = new stack_struct;
    main_struct->element = first_element;
    main_struct->next_element = NULL;
}

template <typename TYPE>
void stack<TYPE>::push(TYPE new_element)
{
    stack_struct * new_struct = new stack_struct;

    new_struct->element = new_element;
    new_struct->next_element = main_struct;
    main_struct = new_struct;
}

template <typename TYPE>
TYPE stack<TYPE>::pop()
{
    if (main_struct->next_element == NULL)
    {
        cout << main_struct->next_element << endl;
        cout << "no elements" << endl;
        return 0;
    }

    else
    {
        TYPE value = main_struct->element;

        stack_struct * tmp_struct = main_struct;

        main_struct = main_struct->next_element;

        delete tmp_struct;

        return value;
    }
}

template <typename TYPE>
unsigned int stack<TYPE>::size()
{
    unsigned int size = 0;

    stack_struct * tmp_struct = main_struct;

    while(tmp_struct->next_element != NULL)
    {
        size++;
        tmp_struct = tmp_struct->next_element;
    }
    return size;
}

template <typename TYPE>
void stack<TYPE>::show_stack()
{
    if (main_struct->next_element == NULL)
    {
        cout << "No elements" << endl;
    }

    else
    {
        stack_struct * tmp_struct = main_struct;

        while(tmp_struct->next_element != NULL)
        {
            cout << tmp_struct->element << "; ";
            tmp_struct = tmp_struct->next_element;
        }
        cout << endl;
    }
}

template <typename TYPE>
stack<TYPE>::~stack()
{
    stack_struct * tmp_struct = main_struct;

    while(tmp_struct->next_element != NULL)
    {
        stack_struct * tmp_struct_1 = tmp_struct;
        delete tmp_struct_1;
        tmp_struct = tmp_struct->next_element;
    }
    delete tmp_struct;
    cout << endl;
}

int main()
{
    stack <char> S(0);

    S.push('f');
    S.push('h');
    S.push('k');

    S.show_stack();
    cout << "Size: " << S.size() << endl;

    cout << S.pop() << endl;
    cout << "Size: " << S.size() << endl;
    cout << S.pop() << endl;
    cout << "Size: " << S.size() << endl;
    cout << S.pop() << endl;
    cout << "Size: " << S.size() << endl;

    S.show_stack();

    return 0;
}
