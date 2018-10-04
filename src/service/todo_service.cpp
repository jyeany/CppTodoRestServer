//
// Created by John Yeany on 6/28/18.
//

#include <include/service/todo_service.h>

todo_service::todo_service()
{
    //ctor
}

todo_service::~todo_service()
{
    //dtor
}

void todo_service::add_todo(todo todo)
{
    m_todos.push_back(todo);
}

void todo_service::update_todo(todo updated)
{
    int index = find_todo_index(updated.id());
    m_todos.at(index).description(updated.description());
    m_todos.at(index).is_complete(updated.is_complete());
}

todo todo_service::find(boost::uuids::uuid id)
{
    int index = find_todo_index(id);
    return m_todos.at(index);
}

vector<todo> todo_service::find_all()
{
    return m_todos;
}

void todo_service::delete_todo(boost::uuids::uuid id)
{
    int index = find_todo_index(id);
    m_todos.erase(m_todos.begin() + index);
}

int todo_service::find_todo_index(boost::uuids::uuid id)
{
    int to_return = -1;
    bool found = false;
    int index = 0;
    vector<todo>::iterator it;
    for (it = m_todos.begin(); it != m_todos.end(); it++, index++)
    {
        if (to_string(id) == to_string(it->id()))
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        to_return = index;
    }
    return to_return;
}