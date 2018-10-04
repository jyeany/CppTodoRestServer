//
// Created by John Yeany on 6/28/18.
//

#ifndef ROUTER_H
#define ROUTER_H
#include <cpprest/json.h>
#include <iostream>
#include <boost/uuid/string_generator.hpp>
#include "service/todo_service.h"
#include <cpprest/json.h>
#include "model/todo.h"
#include "stdafx.h"

using namespace std;
using namespace web;
using namespace http;
using namespace http::experimental::listener;

class router
{
    public:
        router();
        void route_get(http_request message);
        void route_post(http_request message);
        void route_delete(http_request message);
        virtual ~router();

    private:
        todo_service m_todo_service;
};


#endif //ROUTER_H
