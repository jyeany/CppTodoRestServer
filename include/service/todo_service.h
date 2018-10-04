//
// Created by John Yeany on 6/28/18.
//

#ifndef TODO_SERVICE_H
#define TODO_SERVICE_H
#include "../model/todo.h"
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>

using namespace std;

class todo_service
{
    public:
        todo_service();
        virtual ~todo_service();
        void add_todo(todo todo);
        void update_todo(todo todo);
        todo find(boost::uuids::uuid id);
        vector<todo> find_all();
        void delete_todo(boost::uuids::uuid id);

    private:
        vector<todo> m_todos;
        int find_todo_index(boost::uuids::uuid id);
};

#endif //TODO_SERVICE_H
